//Author - Pratyay Sarkar
//Program - 2
//Draw a line by using DDA algorithm when starting point,
//slope and number of iterations are given.

#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include "header.h"

float X,Y,slope;
int iterations;
int GAP = 0;

// Function to draw a pixel
void draw_pixel(int x, int y)
{
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

//Implements the DDA Algorithm
void DDA_Algorithm()
{
    // Clears buffers to preset values
    glClear(GL_COLOR_BUFFER_BIT);

    //Set diameter of pixels
    glPointSize(2);
    float incX ,incY, x = X,y = Y;

    if(abs(slope) < 1){
        incX = 1;
        incY = slope;
    }
    else{
        incX = 1/slope;
        incY = 1;
    }

    while (iterations--){
        draw_pixel((int)x,(int)y);
        x += (incX + GAP);
        y += (incY + GAP);
    }
}

void myDisplay()
{
    DDA_Algorithm();
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    printf("Enter the point:\n");
	scanf("%f%f",&X,&Y);
    printf("Enter the slope of the line:\n");
    scanf("%f",&slope);
    printf("Enter the number of iterations:\n");
    scanf("%d",&iterations);
    
    // Initialize GLUT
    initializeGLUT(&argc, argv, myDisplay);

    return 0;
}