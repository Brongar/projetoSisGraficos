// Trabalho Gráficos
// Requer OpenGL e Glut
// Para Windows, pode-se utilizar MSYS2 instalando as dependencias com pacman
// gcc guarita.c -lopengl32 -lfreeglut

#define GLMATRIX(m, row, col) m[col*4+row]
#define PI 3.141592654

void frustum(float *array, float l, float r, float b, float t, float n, float f){
    // Identity matrix
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
    // Identity matrix
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
    // Identity matrix
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
    // Identity matrix
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
    // Identity matrix
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
    // Identity matrix
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
    // Identity matrix
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
