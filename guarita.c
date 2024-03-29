// Trabalho Gráficos
// Requer OpenGL e Glut
// Para Windows, pode-se utilizar MSYS2 instalando as dependencias com pacman
// Comando Windows: gcc guarita.c -lopengl32 -lfreeglut
// Comando Linux: gcc guarita.c -lGL -lglut -lm

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

    // Define material utilizado
    GLfloat ambientM[4]={0.329412, 0.223529, 0.027451, 1.0}; 
    GLfloat diffuseM[4]={0.780392, 0.568627, 0.113725, 1.0};
    GLfloat specularM[4]={0.992157, 0.941176, 0.807843, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambientM);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseM);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specularM);
    glMaterialf(GL_FRONT, GL_SHININESS, 0.21794872 * 128.0);  

    // #######################    Frente    #######################

    //estrutura corpo inferior
    float pointA[3] = {-0.45, 0, 0.45};
    float pointB[3] = {0.45, 1, 0.4};    
    createPoly(pointA, pointB); 

    //Parede interior inferior
    float pointAint[3] = {0, 0, -0.1};
    float pointBint[3] = {0.45, 0.6, 0};    
    createPoly(pointAint, pointBint);   

    //Chão 1º andar
    float pointChao[3] = {-0.4, 0.6, -0.4};
    float pointDao[3] = {0.4, 0.65, 0.45};
    createPoly(pointChao, pointDao);

    //Viga lateral direita
    float pointAfvld[3] = {0.35, 0, 0.45};
    float pointBfvld[3] = {0.45, 1.4, 0.4};    
    createPoly(pointAfvld, pointBfvld);

    //Viga lateral esquerda
    float pointAVfd[3] = {-0.45, 0, 0.45};
    float pointBVfd[3] = {-0.35, 1.4, 0.4};    
    createPoly(pointAVfd, pointBVfd);

    //Parede central a cima da janela superior
    float pointAfPC[3] = {-0.35, 1.3, 0.45};
    float pointBfPC[3] = {0.35, 1.4, 0.4};
    createPoly(pointAfPC, pointBfPC);



    // ###  Muro Frente escada ###

    //Muro inferior direito
    
    float pointAMID[3] = {-0.1, 0, 0.65};
    float pointBMID[3] = {0.45, 0.275, 0.6};
    createPoly(pointAMID, pointBMID);

    //Muro inferior esquerdo
    float pointAMIE[3] = {-0.45, 0, 0.65};
    float pointBMIE[3] = {-0.25, 0.275, 0.6};
    createPoly(pointAMIE, pointBMIE);

     //Muro inferior viguinha
    float pointAMIV[3] = {-0.25, 0.225, 0.65};
    float pointBMIV[3] = {-0.1, 0.275, 0.6};
    createPoly(pointAMIV, pointBMIV);

    //muro superior esquerdo
    float pointAMSE[3] = {-0.65, 0.35, 0.65};
    float pointBMSE[3] = {-0.45, 0.65, 0.6};
    createPoly(pointAMSE, pointBMSE);


    // ####################### Escadas #######################

    //8 degraus de 0.1125 por 0.05
    float alturaDegrau = 0.05;    
    float comprimentoDegrau = 0.1125;
    float xMax = 0.45;

    // ########### Escada Frente ###########   

    //#####  Degraus #####  

    int x = 1;
    while (x<=8)
    {   
        float pointADegrau1[3] = {xMax-comprimentoDegrau, alturaDegrau*(x-1)    , 0.6};
        float pointBDgrau1[3]  = {xMax                      , alturaDegrau*x        , 0.45};
        createPoly(pointADegrau1, pointBDgrau1);

        xMax         =   xMax-comprimentoDegrau;
        
        x=x+1;

    }

    // 1º plano escada
    float pointApe[3] = {-0.65, 0.35, 0.65};
    float pointBpe[3] = {-0.45, 0.4, 0.45};
    createPoly(pointApe, pointBpe);



    //Muro escada
     //Triangulo superior
    float pointATS2[3] = {-0.45, 0.65, 0.65 };
    float pointBTS2[3] = {0.45, 0.275, 0.6};
    createTrianglePolyRight(pointATS2, pointBTS2);


     // ########### Escada lateral esquerda ###########

    float zMax = 0.55;
    int y = 1;
    while (y<=6)
    {   
        
        float pointADegrau2[3] = {-0.60, 0.35 + (alturaDegrau*(y-1)), zMax-comprimentoDegrau};

        float pointBDgrau2[3]  = {-0.45, 0.4  + (alturaDegrau*(y-1)) ,zMax};

        createPoly(pointADegrau2, pointBDgrau2);

        zMax         =   zMax-comprimentoDegrau;
        
        y=y+1;

    }

    // mini piso primeiro andar, da escada para a porta
    float pointApele[3] = {-0.65, 0.6, -0.115};
    float pointBpele[3] = {-0.45, 0.65, -0.45};
    createPoly(pointApele, pointBpele);

     //Vigas da escada 
    float pointAVE[3] = {-0.65, 0.28, 0.45};
    float pointBVE[3] = {-0.45, 0.35, 0.5};    
    createPoly(pointAVE, pointBVE);

    float pointAVE2[3] = {-0.65, 0.45, -0.45};
    float pointBVE2[3] = {-0.45, 0.65, -0.40};    
    createPoly(pointAVE2, pointBVE2);


    // ########### Muro Escada Lateral esquerda ###########
    
    //frente LE1 "Guarda-corpo"
    float pointAMuroP[3] = {-0.65, 0.6 , 0};
    float pointBMuroP[3] = {-0.6 , 0.95, -0.45};    
    createPoly(pointAMuroP, pointBMuroP);

     //frente  tapa "soca-soca" (em baixo da escada  da frente)
    float pointAMuroEscadinha[3] = {-0.45, 0 , 0.45};
    float pointBMuroEscadinhaP[3] = {-0.4 , 0.35, 0.6};    
    createPoly(pointAMuroEscadinha, pointBMuroEscadinhaP);

    //Triangulo superior
    float pointATS[3] = {-0.65, 0.95, 0 };
    float pointBTS[3] = {-0.60, 0.65, 0.65};
    createTrianglePoly(pointATS, pointBTS);

    //Triangulo inferior
    float pointATI[3] = {-0.65, 0.35, 0.45 };
    float pointBTI[3] = {-0.60, 0.55, 0};
    createTrianglePoly(pointATI, pointBTI);



    //frente LE2
    float pointAMuroP2[3] = {-0.65, 0.35 , 0.65};
    float pointBMuroP2[3] = {-0.6 , 0.65,  0.45};    
    createPoly(pointAMuroP2, pointBMuroP2);

    //frente LE3 muro fino central
    float pointAMuroP3[3] = {-0.65,  0.55 , 0.65};
    float pointBMuroP3[3] = {-0.6 , 0.65,  -0.45};  
    createPoly(pointAMuroP3, pointBMuroP3);

     
    //Lateral LE
    float pointAMuroPLE[3] = {-0.65, 0.6  ,  -0.4 };
    float pointBMuroPLE[3] = {-0.45, 0.95 ,  -0.45};    
    createPoly(pointAMuroPLE, pointBMuroPLE);


    // ####################### Costas #######################

    //estrutura corpo costas
    float pointABack[3] = {-0.45, 0, -0.4};
    float pointBBack[3] = {0.45, 1, -0.45};    
    createPoly(pointABack, pointBBack);

    //Viga lateral direita
    float pointABvld[3] = {-0.45, 0, -0.4};
    float pointBBvld[3] = {-0.35, 1.4, -0.45};    
    createPoly(pointABvld, pointBBvld);

    //Viga lateral esquerda
    float pointAVBd[3] = {0.35, 0, -0.4};
    float pointBVBd[3] = {0.45, 1.4,-0.45};    
    createPoly(pointAVBd, pointBVBd);

    //Parede central a cima da janela superior
    float pointABPC[3] = {-0.35, 1.3, -0.45};
    float pointBBPC[3] = {0.35, 1.4, -0.4};
    createPoly(pointABPC, pointBBPC);


    // ####################### Lateral esquerda #######################


    //estrutura corpo lateral esquerda
    float pointAlee[3] = {-0.45, 0, 0.4};
    float pointBlee[3] = {-0.4, 0.65, -0.4};    
    createPoly(pointAlee, pointBlee);

    //estrutura corpo a baixo da janela
    float pointAbj[3] = {-0.45,0.65, -0.1};
    float pointBbj[3] = {-0.4, 1, 0.45};    
    createPoly(pointAbj, pointBbj);



    //Viga lateral direita
    float pointAVled[3] = {-0.45, 0, 0.45};
    float pointBVled[3] = {-0.4, 1.4, 0.35};    
    createPoly(pointAVled, pointBVled);

    //Viga lateral esquerda
    float pointAVlee[3] = {-0.45, 0, -0.45};
    float pointBVlee[3] = {-0.4, 1.4, -0.35};    
    createPoly(pointAVlee, pointBVlee);    

    //Parede central a cima da janela superior
    float pointAPCle[3] = {-0.45, 1.3, 0.4};
    float pointBPCle[3] = {-0.4, 1.4, -0.45};
    createPoly(pointAPCle, pointBPCle);

    
    // ####################### Lateral direita #######################
    
    //Viga lateral esquerda
    float pointAVle[3] = {0.4, 0, 0.45};
    float pointBVle[3] = {0.45, 1.4, 0.35};    
    createPoly(pointAVle, pointBVle);

    //Viga lateral direita
    float pointAVld[3] = {0.4, 0, -0.45};
    float pointBVld[3] = {0.45, 1.4, -0.35};    
    createPoly(pointAVld, pointBVld);


    //Viga Central
    float pointAVC[3] = {0.4, 0, 0.05};
    float pointBVC[3] = {0.45, 0.55, -0.05};    
    createPoly(pointAVC, pointBVC);


    //Parede central a baixo da janela superior
    float pointAPCjs[3] = {0.4, 0.55, 0.4};
    float pointBPCjs[3] = {0.45, 1, -0.45};
    createPoly(pointAPCjs, pointBPCjs);
    

    //Parede central a cima da janela superior
    float pointAPC[3] = {0.4, 1.3, 0.4};
    float pointBPC[3] = {0.45, 1.4, -0.45};
    createPoly(pointAPC, pointBPC);


    //Parede a baixo da janela inferior
    float pointAPJ[3] = {0.4, 0, -0.05};
    float pointBPJ[3] = {0.45, 0.4, -0.45};
    createPoly(pointAPJ, pointBPJ);
    

    // ####################### Topo #######################
    //estrutura cabeça
    float pointC[3] = {-0.55, 1.4, -0.55};
    float pointD[3] = {0.55, 1.5, 0.55};
    createPoly(pointC, pointD);

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
    frustum(initMatrixP, -0.55, 0.55, -0.55, 0.55, 0.2, 20.0);
    glMultMatrixf(initMatrixP);

    // Move o objeto em cena
    float initMatrixT [16] = {0};
    translate(initMatrixT, 0, -0.25, -1.5);
    glMultMatrixf(initMatrixT);

    // Projeção ortogonal
    //float initMatrixO [16] = {0};
    //ortho(initMatrixO, -1.1, 1.1, -1.1, 1.1, 0.2, 20.0);
    //glMultMatrixf(initMatrixO);

    // Move o objeto em cena
    //float initMatrixT [16] = {0};
    //translate(initMatrixT, 0, -0.45, -1.5);
    //glMultMatrixf(initMatrixT);
}

// Controle da cena pelo teclado
void keyboard(unsigned char key, int x, int y)
{        
    switch (key) {
         case 'd': // Transladar para a direita
            {
            printf("Translação em +x.\n");
            float matrixTXP [16] = {0};
            translate(matrixTXP, 0.2, 0, 0);
            glMultMatrixf(matrixTXP);
            break;
            }
        case 'w': // Transladar para cima
            {
            printf("Translação em +y.\n");
            float matrixTYP [16] = {0};
            translate(matrixTYP, 0, 0.2, 0);
            glMultMatrixf(matrixTYP);
            break;
            }

        case 'a': // Transladar para a esquerda
            {
            printf("Translação em -x.\n");
            float matrixTXN [16] = {0};
            translate(matrixTXN, -0.2, 0, 0);
            glMultMatrixf(matrixTXN);
            break;
            }
        case 's': // Transladar para baixo
            {
            printf("Translação em -y.\n");
            float matrixTYN [16] = {0};
            translate(matrixTYN, 0, -0.2, 0);
            glMultMatrixf(matrixTYN);
            break;
            }
        case 'q': // Transladar para a tela ("near")
            {
            printf("Translação em +z.\n");
            float matrixTZP [16] = {0};
            translate(matrixTZP, 0, 0, 0.2);
            glMultMatrixf(matrixTZP);
            break;
            }
        case 'e': // Transladar para longe ("far")
            {
            printf("Translação em -z.\n");
            float matrixTZN [16] = {0};
            translate(matrixTZN, 0, 0, -0.2);
            glMultMatrixf(matrixTZN);
            break;
            }
        case 'r': // Rotação em volta do eixo X
            {
            printf("Rotação no eixo x.\n");
            float matrixRX [16] = {0};
            rotateX(matrixRX, 5);
            glMultMatrixf(matrixRX);
            break;
            }
        case 't': // Rotação em volta do eixo Y
            {
            printf("Rotação no eixo y.\n");
            float matrixRY [16] = {0};
            rotateY(matrixRY, 5);
            glMultMatrixf(matrixRY);
            break;
            }
        case 'y': // Rotação em volta do eixo Z
            {
            printf("Rotação no eixo z.\n");
            float matrixRZ [16] = {0};
            rotateZ(matrixRZ, 5);
            glMultMatrixf(matrixRZ);
            break;
            }
        case 'z': // Escala do eixo X
            {
            printf("Aumento da dimensão x.\n");
            float matrixSX [16] = {0};
            scale(matrixSX, 1.2, 1, 1);
            glMultMatrixf(matrixSX);
            break;
            }
        case 'x':
            { // Escala do eixo Y
            printf("Aumento da dimensão y.\n");
            float matrixSY [16] = {0};
            scale(matrixSY, 1, 1.2, 1);
            glMultMatrixf(matrixSY);
            break;
            }
        case 'c': // Escala do eixo Z
            {
            printf("Aumento da dimensão z.\n");
            float matrixSZ [16] = {0};
            scale(matrixSZ, 1, 1, 1.2);
            glMultMatrixf(matrixSZ);
            break;
            }
        case 'l': // Projeção Frustum/Perspectiva
            {
            printf("Reset - Projeção Frustum/Perspectiva\n");
            glLoadIdentity();
            float matrixP [16] = {0};
            // left right bottom top near far
            frustum(matrixP, -0.55, 0.55, -0.55, 0.55, 0.2, 20.0);
            glMultMatrixf(matrixP);

            // Move o objeto em cena
            float rMatrixTP [16] = {0};
            translate(rMatrixTP, 0, -0.25, -1.5);
            glMultMatrixf(rMatrixTP);
            break;
            }
        case 'k': // Projeção Ortogonal
            {
            printf("Reset - Projeção Ortogonal\n");
            glLoadIdentity();
            float matrixO [16] = {0};
            // left right bottom top near far
            ortho(matrixO, -1.1, 1.1, -1.1, 1.1, 0.2, 20.0);
            glMultMatrixf(matrixO);

            // Move o objeto em cena
            float rMatrixTO [16] = {0};
            translate(rMatrixTO, 0, -0.45, -1.5);
            glMultMatrixf(rMatrixTO);
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
    // Tonalizacao interpolativa para o modelo de Gouraud
    // Ja que nosso modelo se constitui de retangulos, nao temos vertices suficientes para
    // que todos os efeitos da iluminacao tenham um resultado bom
    glShadeModel (GL_SMOOTH);

    // Modelo Phong (combinação de ambiente, difusa e especular)
    // Luz 1 verde em +x infinito de raios paralelos
    GLfloat ambientL[4] = {0.15, 0.15, 0.15, 1.0}; 
    GLfloat diffuseL[4] = {0.2, 0.9, 0.2, 1.0};
    GLfloat specularL[4] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light1[4] = {1.0, 0.0, 0.0, 0}; // 1 on [3] for point location instead of infinity

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientL); 
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseL);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularL);
    glLightfv(GL_LIGHT0, GL_POSITION, light1);

    // Luz 2 vermelha em -x infinito de raios paralelos
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
    glutInitWindowSize(800,800);
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
