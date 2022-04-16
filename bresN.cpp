// Author - Pratyay Sarkar
// Program - 6
// Program : Draw an n-sided polygon by using Bresenham’s 
// line drawing algorithm when n points are given as input.


#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include "header.h"

#define SMALL 0.00001

// Function to draw pixel
void draw_pixel(int x, int y)
{
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

//Structure representing a point (x,y)
struct PointStructure
{
    float x,y;
}typedef Point;

Point *points;
int N;

bool equality(float a,float b)
{
    return abs(b-a) > SMALL ? true : false;
}

//Implements the Bresenheim Algorithm
void Bresenhams_Algorithm(float X1,float Y1,float X2,float Y2)
{
    float dX = abs(X2-X1);
	float dY = abs(Y2-Y1);

    if(dY < dX)
    {
        float prev_p = 2*dY - dX;
    	float X = X1,Y = Y1;

        while(equality(X,X2))
        {
        	draw_pixel((int)X,(int)Y);
            
            if(X2 > X1)X += 1;
            else X -= 1;

        	if(prev_p > 0)
            {
        		prev_p += (2*dY - 2*dX);
                if(Y2 > Y1)Y += 1;
                else Y -= 1;
        	}
            else
        		prev_p += 2*dY;
        }
    }
    else
    {
        float prev_p = 2*dX - dY;
        float X = X1,Y = Y1;

        while(equality(Y,Y2))
        {
            draw_pixel((int)X,(int)Y);

            if(Y2 > Y1)Y += 1;
            else Y -= 1;

            if(prev_p > 0)
            {
                prev_p += (2*dX - 2*dY);
                if(X2 > X1)X += 1;
                else X -= 1;
            }
            else
                prev_p += 2*dX;
        }
    }
}

void Draw_Polygon()
{
    int i;
    for(i=0;i<N-1;i++)
        Bresenhams_Algorithm(points[i].x,points[i].y,points[i+1].x,points[i+1].y);
    Bresenhams_Algorithm(points[N-1].x,points[N-1].y,points[0].x,points[0].y);
}

void myDisplay()
{
    Draw_Polygon();
    glFlush();
}

int main(int argc, char **argv)
{
    printf("Enter number of sides of the polygon:\n");
	scanf("%d",&N);

    points = (Point *)calloc(N,sizeof(Point));
    printf("Enter %d points(x,y):\n",N);
    for(int i=0;i<N;i++)
    {
        float a,b;
        scanf("%f%f",&a,&b);
        points[i].x = a;
        points[i].y = b; 
    }
    
    // Initialize GLUT
    initializeGLUT(&argc, argv, myDisplay);

    return 0;
}