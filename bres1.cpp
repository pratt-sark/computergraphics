// Author - Pratyay Sarkar
// Program - 4
// Program : Draw a line by using Bresenham’s line drawing algorithm when two points are given.

#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include "header.h"

#define SMALL 0.00001

float X1,X2,Y1,Y2,yy;

// Function to draw pixel
void draw_pixel(int x, int y){
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

bool equality(float a,float b){
    return (b-a) > SMALL ? true : false;
}

//Implements the Bresenheim Algorithm
void Bresenhams_Algorithm(){
    
	float dX = abs(X2-X1);
	float dY = abs(Y2-Y1);

	float prev_p = 2*dY - dX;
	float X = X1,Y = Y1;

    while(equality(X,X2))
    {
    	draw_pixel((int)X,(int)Y);
        draw_pixel((int)X,(int)yy);
    	X += 1;
    	if(prev_p > 0)
        {
    		prev_p += (2*dY - 2*dX);
    		Y += 1;
    	}
        else
    		prev_p += 2*dY;
    }
}

void myDisplay()
{
    Bresenhams_Algorithm();
    glFlush();
}

int main(int argc, char **argv)
{
    printf("Enter the points:\n");
	scanf("%f%f%f%f",&X1,&Y1,&X2,&Y2);

    printf("Enter the y-shift:");
    scanf("%f",&yy);
    
    // Initialize GLUT
    initializeGLUT(&argc, argv, myDisplay);

    return 0;
}