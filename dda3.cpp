// Author - Pratyay Sarkar
// Program - 3
// Draw two lines by using DDA algorithm when a common starting point,
// their slopes (unequal) and number of iterations are given.

#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include "header.h"

float X,Y,slope1,slope2;
int iterations;
int GAP = 0;

void draw_pixel(int x, int y)
{
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void DDA_Algorithm()
{
    float incX1,incY1,incX2,incY2,x1 = X,y1 = Y,x2 = X,y2 = Y;

    if(abs(slope1) < 1)
    {
        incX1 = 1;
        incY1 = slope1;
    }
    else
    {
        incX1 = 1/slope1;
        incY1 = 1;
    }

    if(abs(slope2) < 1)
    {
        incX2 = 1;
        incY2 = slope2;
    }
    else
    {
        incX2 = 1/slope2;
        incY2 = 1;
    }

    while (iterations--)
    {
        draw_pixel((int)x1,(int)y1);
        draw_pixel((int)x2,(int)y2);
        
        x1 += (incX1 + GAP);
        y1 += (incY1 + GAP);
            
        x2 += (incX2 + GAP);
        y2 += (incY2 + GAP);
    
    }
}

void myDisplay()
{
    DDA_Algorithm();
    glFlush();
}

int main(int argc, char **argv)
{
    printf("Enter the point:\n");
	scanf("%f%f",&X,&Y);
    printf("Enter the slope of the first line:\n");
    scanf("%f",&slope1);
    printf("Enter the slope of the second line:\n");
    scanf("%f",&slope2);
    printf("Enter the number of iterations:\n");
    scanf("%d",&iterations);
    
    // Initialize GLUT
    initializeGLUT(&argc, argv, myDisplay);

    return 0;
}