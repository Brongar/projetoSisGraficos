// Trabalho Gráficos

#define GLMATRIX(m, row, col) m[col*4+row]
#define PI 3.141592654

void frustum(float *array, float l, float r, float b, float t, float n, float f){
    // null matrix
    for(int i = 0; i < 16; i++)
    {
        array[i] = 0;
    }
    GLMATRIX(array, 0, 0) = (2 * n)/(r - l);
    GLMATRIX(array, 1, 1) = (2 * n)/(t - b);
    GLMATRIX(array, 2, 2) = -(f + n)/(f - n);
    GLMATRIX(array, 3, 2) = -1;
    GLMATRIX(array, 0, 2) = (r + l)/(r - l);
    GLMATRIX(array, 1, 2) = (t + b)/(t - b);
    GLMATRIX(array, 2, 3) = -(2 * f * n)/(f - n);
}

void ortho(float *array, float l, float r, float b, float t, float n, float f){
    // null matrix
    for(int i = 0; i < 16; i++)
    {
        array[i] = 0;
    }
    GLMATRIX(array, 0, 0) = (2)/(r - l);
    GLMATRIX(array, 1, 1) = (2)/(t - b);
    GLMATRIX(array, 2, 2) = (-2)/(f - n);
    GLMATRIX(array, 3, 3) = 1;
    GLMATRIX(array, 0, 3) = -(r + l)/(r - l);
    GLMATRIX(array, 1, 3) = -(t + b)/(t - b);
    GLMATRIX(array, 2, 3) = -(f + n)/(f - n);
}

void scale(float *array, float strengthX, float strengthY, float strengthZ){
    // null matrix
    for(int i = 0; i < 16; i++)
    {
        array[i] = 0;
    }
    GLMATRIX(array, 0, 0) = strengthX;
    GLMATRIX(array, 1, 1) = strengthY;
    GLMATRIX(array, 2, 2) = strengthZ;
    GLMATRIX(array, 3, 3) = 1;
}

void translate(float *array, float strengthX, float strengthY, float strengthZ){
    // null matrix
    for(int i = 0; i < 16; i++)
    {
        array[i] = 0;
    }
    GLMATRIX(array, 0, 0) = 1;
    GLMATRIX(array, 1, 1) = 1;
    GLMATRIX(array, 2, 2) = 1;
    GLMATRIX(array, 3, 3) = 1;

    // Translation
    GLMATRIX(array, 0, 3) = strengthX;
    GLMATRIX(array, 1, 3) = strengthY;
    GLMATRIX(array, 2, 3) = strengthZ;
}

void rotateX(float *array, float strength){
    // null matrix
    for(int i = 0; i < 16; i++)
    {
        array[i] = 0;
    }
    GLMATRIX(array, 0, 0) = 1;
    GLMATRIX(array, 1, 1) = 1;
    GLMATRIX(array, 2, 2) = 1;
    GLMATRIX(array, 3, 3) = 1;

    // Rotation
    GLMATRIX(array, 1, 1) = cos((strength * PI)/180.0);
    GLMATRIX(array, 1, 2) = -sin((strength * PI)/180.0);
    GLMATRIX(array, 2, 1) = sin((strength * PI)/180.0);
    GLMATRIX(array, 2, 2) = cos((strength * PI)/180.0);
}

void rotateY(float *array, float strength){
    // null matrix
    for(int i = 0; i < 16; i++)
    {
        array[i] = 0;
    }
    GLMATRIX(array, 0, 0) = 1;
    GLMATRIX(array, 1, 1) = 1;
    GLMATRIX(array, 2, 2) = 1;
    GLMATRIX(array, 3, 3) = 1;

    // Rotation
    GLMATRIX(array, 0, 0) = cos((strength * PI)/180.0);
    GLMATRIX(array, 0, 2) = -sin((strength * PI)/180.0);
    GLMATRIX(array, 2, 0) = sin((strength * PI)/180.0);
    GLMATRIX(array, 2, 2) = cos((strength * PI)/180.0);
}

void rotateZ(float *array, float strength){
    // null matrix
    for(int i = 0; i < 16; i++)
    {
        array[i] = 0;
    }
    GLMATRIX(array, 0, 0) = 1;
    GLMATRIX(array, 1, 1) = 1;
    GLMATRIX(array, 2, 2) = 1;
    GLMATRIX(array, 3, 3) = 1;

    // Rotation
    GLMATRIX(array, 0, 0) = cos((strength * PI)/180.0);
    GLMATRIX(array, 0, 1) = -sin((strength * PI)/180.0);
    GLMATRIX(array, 1, 0) = sin((strength * PI)/180.0);
    GLMATRIX(array, 1, 1) = cos((strength * PI)/180.0);
}


// ############### Triangulo retangulo ###############

void createTrianglePoly(float *pointA, float *pointB){

    glNormal3f(0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
        glVertex3f(pointA[0], pointA[1], pointA[2]);
        glVertex3f(pointB[0], pointA[1], pointA[2]);
        glVertex3f(pointB[0], pointB[1], pointB[2]);
        glVertex3f(pointA[0], pointB[1], pointB[2]);
    glEnd();

    glNormal3f(0.0, 0.0, -1.0);
    glBegin(GL_QUADS);
        glVertex3f(pointA[0], pointA[1], pointA[2]);
        glVertex3f(pointB[0], pointA[1], pointA[2]);
        glVertex3f(pointB[0], pointB[1], pointA[2]);
        glVertex3f(pointA[0], pointB[1], pointA[2]);
    glEnd();

    glNormal3f(0.0, -1.0, 0.0);
    glBegin(GL_QUADS);
        glVertex3f(pointA[0], pointB[1], pointA[2]);
        glVertex3f(pointB[0], pointB[1], pointA[2]);
        glVertex3f(pointB[0], pointB[1], pointB[2]);
        glVertex3f(pointA[0], pointB[1], pointB[2]);
    glEnd();

    glNormal3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);        
        glVertex3f(pointB[0], pointA[1], pointA[2]);
        glVertex3f(pointB[0], pointB[1], pointA[2]);
        glVertex3f(pointB[0], pointB[1], pointB[2]);
    glEnd();

    glNormal3f(-1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);        
        glVertex3f(pointA[0], pointA[1], pointA[2]);
        glVertex3f(pointA[0], pointB[1], pointA[2]);
        glVertex3f(pointA[0], pointB[1], pointB[2]);
    glEnd();

}

void createTrianglePolyRight(float *pointA, float *pointB){

    glNormal3f(0.0, 0.0, 1.0);
// Frente
    glBegin(GL_TRIANGLES);
        glVertex3f(pointA[0], pointA[1], pointB[2]);
        glVertex3f(pointA[0], pointB[1], pointB[2]);
        glVertex3f(pointB[0], pointB[1], pointB[2]);
    glEnd();

    glNormal3f(0.0, 0.0, -1.0);
    // Costas
    glBegin(GL_TRIANGLES);
        glVertex3f(pointA[0], pointA[1], pointA[2]);
        glVertex3f(pointA[0], pointB[1], pointA[2]);
        glVertex3f(pointB[0], pointB[1], pointA[2]);

    glNormal3f(0.0, -1.0, 0.0);
    // Inferior
    glBegin(GL_QUADS);
        glVertex3f(pointA[0], pointB[1], pointA[2]);
        glVertex3f(pointB[0], pointB[1], pointA[2]);
        glVertex3f(pointB[0], pointB[1], pointB[2]);
        glVertex3f(pointA[0], pointB[1], pointB[2]);
    glEnd();

    glNormal3f(-1.0, 0.0, 0.0);
    // Quadrado esquerdo
    glBegin(GL_QUADS);        
        glVertex3f(pointA[0], pointA[1], pointA[2]);
        glVertex3f(pointA[0], pointA[1], pointB[2]);
        glVertex3f(pointA[0], pointB[1], pointB[2]);
        glVertex3f(pointA[0], pointB[1], pointA[2]);
    glEnd();

    glNormal3f(1.0, 0.0, 0.0);
    // Quadrado direito
    glBegin(GL_QUADS);        
        glVertex3f(pointA[0], pointA[1], pointA[2]);
        glVertex3f(pointA[0], pointA[1], pointB[2]);

        glVertex3f(pointB[0], pointB[1], pointB[2]);
        glVertex3f(pointB[0], pointB[1], pointA[2]);
    glEnd();

}


// ###############  Retangulo ###############


void createPoly(float *pointA, float *pointB){
    // A face -- z fixed
    // normal to Az direction
    if(pointA[2] > pointB[2]){
        glNormal3f(0.0, 0.0, 1.0);
    } else {
        glNormal3f(0.0, 0.0, -1.0);
    }
    
    glBegin(GL_QUADS);
        glVertex3f(pointA[0], pointA[1], pointA[2]);
        glVertex3f(pointA[0], pointB[1], pointA[2]);
        glVertex3f(pointB[0], pointB[1], pointA[2]);
        glVertex3f(pointB[0], pointA[1], pointA[2]);
    glEnd();

    // B face -- z fixed
    // normal to Bz direction
    if(pointB[2] > pointA[2]){
        glNormal3f(0.0, 0.0, 1.0);
    } else {
        glNormal3f(0.0, 0.0, -1.0);
    }

    glBegin(GL_QUADS);
        glVertex3f(pointA[0], pointA[1], pointB[2]);
        glVertex3f(pointA[0], pointB[1], pointB[2]);
        glVertex3f(pointB[0], pointB[1], pointB[2]);
        glVertex3f(pointB[0], pointA[1], pointB[2]);
    glEnd();

    // A-B face -- Ay fixed
    // normal to Ay direction
    if(pointA[1] > pointB[1]){
        glNormal3f(0.0, 1.0, 0.0);
    } else {
        glNormal3f(0.0, -1.0, 0.0);
    }
    glBegin(GL_QUADS);
        glVertex3f(pointA[0], pointA[1], pointA[2]);
        glVertex3f(pointA[0], pointA[1], pointB[2]);
        glVertex3f(pointB[0], pointA[1], pointB[2]);
        glVertex3f(pointB[0], pointA[1], pointA[2]);
    glEnd();

    // A-B face -- By fixed
    // normal to By direction
    if(pointB[1] > pointA[1]){
        glNormal3f(0.0, 1.0, 0.0);
    } else {
        glNormal3f(0.0, -1.0, 0.0);
    }

    glBegin(GL_QUADS);
        glVertex3f(pointA[0], pointB[1], pointA[2]);
        glVertex3f(pointA[0], pointB[1], pointB[2]);
        glVertex3f(pointB[0], pointB[1], pointB[2]);
        glVertex3f(pointB[0], pointB[1], pointA[2]);
    glEnd();

    // A-B face -- Ax fixed
    // normal to Ax direction
    if(pointA[0] > pointB[0]){
        glNormal3f(1.0, 0.0, 0.0);
    } else {
        glNormal3f(-1.0, 0.0, 0.0);
    }

    glBegin(GL_QUADS);
        glVertex3f(pointA[0], pointA[1], pointA[2]);
        glVertex3f(pointA[0], pointA[1], pointB[2]);
        glVertex3f(pointA[0], pointB[1], pointB[2]);
        glVertex3f(pointA[0], pointB[1], pointA[2]);
    glEnd();

    // A-B face -- Bx fixed
    // normal to Bx direction
    if(pointB[0] > pointA[0]){
        glNormal3f(1.0, 0.0, 0.0);
    } else {
        glNormal3f(-1.0, 0.0, 0.0);
    }

    glBegin(GL_QUADS);
        glVertex3f(pointB[0], pointA[1], pointA[2]);
        glVertex3f(pointB[0], pointA[1], pointB[2]);
        glVertex3f(pointB[0], pointB[1], pointB[2]);
        glVertex3f(pointB[0], pointB[1], pointA[2]);
    glEnd();
}
