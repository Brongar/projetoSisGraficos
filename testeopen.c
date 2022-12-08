
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926535

/* Criar circulo */

void circle(void){
	int circle_points  = 100;

	glBegin(GL_LINE_LOOP);
	for (int i = 0 ; i< circle_points ; i++){
		float angle = (2*PI*i)/circle_points;
		glVertex2f(cos(angle),sin(angle));
	}
	glEnd();
}


void displayMe(void){
    glClear(GL_COLOR_BUFFER_BIT);

    /* indica a ordem de como os vértices são associados */
    glBegin(GL_POLYGON);

     /* glVertex "nº de componentes" "tipo de dado" (x,x,x); */
        glVertex3f(0.5, 0.0, 0.5);
        glVertex3f(0.5, 0.0, 0.0);
        glVertex3f(0.0, 0.5, 0.0);
        glVertex3f(0.0, 0.0, 0.5);
    glEnd();
    glFlush();
}


/* Gerenciamento de janelas */
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hello world!");

    /* Função será executada quando a janela é alterada */
    glutDisplayFunc(circle);

    /* Processamento de eventos */
    glutMainLoop();

    return 0;
}
