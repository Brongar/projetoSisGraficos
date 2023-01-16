// Trabalho Gráficos
// Requer OpenGL e Glut
// Para Windows, pode-se utilizar MSYS2 instalando as dependencias com pacman
// gcc guarita.c -lopengl32 -lfreeglut

//Linux-ubuntu 18.04
// gcc -o guarita guarita.c -lGL -lglut -lm
// ./guarita

#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>
#include <stdio.h>
#include "guarita.h"

// Manipulações matriciais em guarita.h

// Função de desenho
void display(void)
{
    // Habilita visibilidade Z-buffer
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glEnable(GL_DEPTH_TEST);  

    // Define material do cubo -- brass
    GLfloat ambientM[4]={0.329412, 0.223529, 0.027451, 1.0}; 
    GLfloat diffuseM[4]={0.780392, 0.568627, 0.113725, 1.0};
    GLfloat specularM[4]={0.992157, 0.941176, 0.807843, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambientM);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseM);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specularM);
    glMaterialf(GL_FRONT, GL_SHININESS, 0.21794872 * 128.0);

    // Define um cubo
    // Cubo tem 8 vertices, o que, para as luzes utilizadas, não é aplicado specularidade.
    // Para corrigir isso tem que fazer uma subdivisão do cubo em triangulos com um certo passo (ex: 0.05x triangulos)
    //float pointA[3] = {-0.3, -0.3, -0.3};
    //float pointB[3] = {0.3, 0.3, 0.3};
    //createPoly(pointA, pointB);
    glutSolidTeapot(0.5f);

    glFlush();
    glutSwapBuffers();
 }

// Função de inicialização e modificação da janela
void reshape(GLsizei w, GLsizei h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Projeção frustum/perspectiva
    float initMatrixP [16] = {0};
    frustum(initMatrixP, -0.5, 0.5, -0.5, 0.5, 0.5, 20.0);
    glMultMatrixf(initMatrixP);

    // Projeção ortogonal
    //float initMatrixO [16] = {0};
    //ortho(initMatrixO, -1, 1, -1, 1, 0.5, 20.0);
    //glMultMatrixf(initMatrixO);

    // Move o objeto em cena
    float initMatrixT [16] = {0};
    translate(initMatrixT, 0, 0, -1.5);
    glMultMatrixf(initMatrixT);
}

// Controle da cena pelo teclado
void keyboard(unsigned char key, int x, int y)
{        
    switch (key) {
         case 'd': // Transladar para a direita
            {
            float matrixTXP [16] = {0};
            translate(matrixTXP, 0.2, 0, 0);
            glMultMatrixf(matrixTXP);
            break;
            }
        case 'w': // Transladar para frente
            {
            float matrixTYP [16] = {0};
            translate(matrixTYP, 0, 0.2, 0);
            glMultMatrixf(matrixTYP);
            break;
            }

        case 'a': // Transladar para a esquerda
            {
            float matrixTXN [16] = {0};
            translate(matrixTXN, -0.2, 0, 0);
            glMultMatrixf(matrixTXN);
            break;
            }
        case 's': // Transladar para baixo
            {
            float matrixTYN [16] = {0};
            translate(matrixTYN, 0, -0.2, 0);
            glMultMatrixf(matrixTYN);
            break;
            }
        case 'q': // Transladar para a tela ("near")
            {
            float matrixTZP [16] = {0};
            translate(matrixTZP, 0, 0, 0.2);
            glMultMatrixf(matrixTZP);
            break;
            }
        case 'e': // Transladar para longe ("far")
            {
            float matrixTZN [16] = {0};
            translate(matrixTZN, 0, 0, -0.2);
            glMultMatrixf(matrixTZN);
            break;
            }
        case 'r': // Rotação em volta do eixo X
            {
            float matrixRX [16] = {0};
            rotateX(matrixRX, 5);
            glMultMatrixf(matrixRX);
            break;
            }
        case 't': // Rotação em volta do eixo Y
            {
            float matrixRY [16] = {0};
            rotateY(matrixRY, 5);
            glMultMatrixf(matrixRY);
            break;
            }
        case 'y': // Rotação em volta do eixo Z
            {
            float matrixRZ [16] = {0};
            rotateZ(matrixRZ, 5);
            glMultMatrixf(matrixRZ);
            break;
            }
        case 'z': // Escala do eixo X
            {
            float matrixSX [16] = {0};
            scale(matrixSX, 1.2, 1, 1);
            glMultMatrixf(matrixSX);
            break;
            }
        case 'x':
            { // Escala do eixo Y
            float matrixSY [16] = {0};
            scale(matrixSY, 1, 1.2, 1);
            glMultMatrixf(matrixSY);
            break;
            }
        case 'c': // Escala do eixo Z
            {
            float matrixSZ [16] = {0};
            scale(matrixSZ, 1, 1, 1.2);
            glMultMatrixf(matrixSZ);
            break;
            }
        case 'l': // Projeção Frustum/Perspectiva
            {
            glLoadIdentity();
            float matrixP [16] = {0};
            // left right bottom top near far
            frustum(matrixP, -0.5, 0.5, -0.5, 0.5, 0.5, 20.0);
            glMultMatrixf(matrixP);

            // Move o objeto em cena
            float rMatrixTP [16] = {0};
            translate(rMatrixTP, 0, 0, -1.5);
            glMultMatrixf(rMatrixTP);
            break;
            }
        case 'k': // Projeção Ortogonal
            {
            glLoadIdentity();
            float matrixO [16] = {0};
            // left right bottom top near far
            ortho(matrixO, -1, 1, -1, 1, 0.5, 20.0);
            glMultMatrixf(matrixO);

            // Move o objeto em cena
            float rMatrixTO [16] = {0};
            translate(rMatrixTO, 0, 0, -2);
            glMultMatrixf(rMatrixTO);
            break;
            }
        case 'm': // Reset
            {
            glLoadIdentity();
            break;
            }
        default:
            printf("Comando invalido! %d\n",key);
    };
    // Evento para redesenhar a tela
    glutPostRedisplay();
}

// Função para forçar a animação
void update(int value) {
    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}

// Função para determinar parâmetros de iluminação
void renderingConfig() {
    glClearColor (0.0, 0.0, 0.0, 1.0);
    glShadeModel (GL_SMOOTH);

    GLfloat ambientL[4] = {0.15, 0.15, 0.15, 1.0}; 
    GLfloat diffuseL[4] = {0.2, 0.9, 0.2, 1.0};
    GLfloat specularL[4] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light1[4] = {1.0, 0.0, 0.0, 0}; // 1 on [3] for point location instead of infinity

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientL); 
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseL);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularL);
    glLightfv(GL_LIGHT0, GL_POSITION, light1);

    GLfloat light2[4] = {-1.0, 0.0, 0.0, 0}; 
    GLfloat diffuseL2[4] = {0.9, 0.2, 0.2, 1.0};

    glLightfv(GL_LIGHT1, GL_AMBIENT, ambientL); 
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseL2);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specularL);
    glLightfv(GL_LIGHT1, GL_POSITION, light2);

    //glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
}

// Programa Principal
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(400,400);
    glutInitWindowPosition (10, 10);
    glutCreateWindow("Guarita");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    renderingConfig();
    glutTimerFunc(25, update, 0);
    glutMainLoop();
    return 0;
}
//git reset --hard [sua branch]
//git add .
//git commit -m "...blablabla"
//git push origin [sua branch]
//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