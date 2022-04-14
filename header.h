// Author - Pratyay Sarkar
// Description - Header File for OpenGL Initialisation

#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

// Initialize the window
void myInit(int width, int height)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, width, 0, height);
}

//Initialize GLUT
void initializeGLUT(int *argc, char **argv,void myDisplay(void))
{
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    int WINDOW_WIDTH, WINDOW_HEIGHT;
    printf("Give window height and width:\n");
    scanf("%d %d", &WINDOW_WIDTH, &WINDOW_HEIGHT);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OPENGL Program");
    myInit(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutDisplayFunc(myDisplay);
	glutMainLoop();
}