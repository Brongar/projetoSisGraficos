# Guarita Sistemas Gráficos

Requer OpenGL e Glut

Para Windows, pode-se utilizar MSYS2 instalando as dependencias com pacman

Comando Windows:
```gcc guarita.c -lopengl32 -lfreeglut```

Comando Linux:
```gcc guarita.c -lGL -lglut -lm```

## Comandos

### Translação
- w: Translação para +y
- a: Translação para -x
- s: Translação para -y
- d: Translação para +x
- q: Translação para +z
- e: Translação para -z

### Rotação
- r: Rotação no eixo x
- t: Rotação no eixo y
- y: Rotação no eixo z

### Escala
- z: Aumento da dimensão x
- x: Aumento da dimensão y
- c: Aumento da dimensão z

### Projeções (Reset)
- l: Projeção Frustum/Perspectiva
- k: Projeção Ortogonal
