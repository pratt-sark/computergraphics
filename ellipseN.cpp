// Author - Pratyay Sarkar
// Program - 10
// Draw 'n' concentric ellipses by using Midpoint Ellipse Drawing Algorithm

#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

int n;
float *RX,*RY;
float xc, yc,rx,ry;

// Function to draw a pixel
void draw_pixel(int x, int y)
{
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

// Midpoint Ellipse Drawing Algorithm
void midEllipse()
{
    float dx, dy, d1, d2, x, y;
    x = 0;
    y = ry;
 
    // Initial decision parameter of region 1
    d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;
 
    // For region 1
    while (dx < dy)
    {
        // Print points based on 4-way symmetry
        draw_pixel(x+xc,y+yc);
        draw_pixel(-x+xc,y+yc);
        draw_pixel(x+xc,-y+yc);
        draw_pixel(-x+xc,-y+yc);
 
        // Checking and updating value of decision parameter based on algorithm
        if (d1 < 0)
        {
            x++;
            dx = dx + (2 * ry * ry);
            d1 = d1 + dx + (ry * ry);
        }
        else
        {
            x++;
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d1 = d1 + dx - dy + (ry * ry);
        }
    }
 
    // Decision parameter of region 2
    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) +
         ((rx * rx) * ((y - 1) * (y - 1))) -
          (rx * rx * ry * ry);
 
    // Plotting points of region 2
    while (y >= 0)
    {
 
        // Print points based on 4-way symmetry
        draw_pixel(x+xc,y+yc);
        draw_pixel(-x+xc,y+yc);
        draw_pixel(x+xc,-y+yc);
        draw_pixel(-x+xc,-y+yc);
 
        // Checking and updating parameter value based on algorithm
        if (d2 > 0)
        {
            y--;
            dy = dy - (2 * rx * rx);
            d2 = d2 + (rx * rx) - dy;
        }
        else
        {
            y--;
            x++;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d2 = d2 + dx - dy + (rx * rx);
        }
    }
}

void myDisplay()
{
    for (int i = 0; i < n; i++)
    {
        rx = RX[i];
        ry = RY[i];
        midEllipse();
    }    
    glFlush();
}

void generateRadii(int x,int y,int sf)
{
    for(int i=1;i<n;i++)
    {
        RY[i]=y+sf*i;
        RX[i]=x+sf*i;
    }
}
 
int main(int argc, char **argv)
{
    printf("Enter the center:\n");
    scanf("%f%f", &xc, &yc);
    printf("Enter the number of ellipses: \n");
    scanf("%d", &n);
    printf("Enable same Major Radius/Minor Radius for all concentric ellipses?\n(1 for Yes, Any other number for No)\n");
    int choice; scanf("%d",&choice);

    RY = (float *)calloc(n, sizeof(float));
    RX = (float *)calloc(n, sizeof(float));
    for (int i = 0; i < n; i++)
    {
        if(choice!=1)
        {
            printf("\n\n----ELLIPSE %d----\n",i+1);
            printf("Enter the Major radius of the ellipse:\n");
            scanf("%f", &RY[i]);
            printf("Enter the Minor radius of the ellipse:\n");
            scanf("%f", &RX[i]);
        }
        
        else
        {
            printf("Enter the Major radius of the ellipse:\n");
            scanf("%f", &RY[i]);
            printf("Enter the Minor radius of the ellipse:\n");
            scanf("%f", &RX[i]);
            printf("Enter scaling factor(distance between concentric radii):\n");
            float sf; scanf("%f", &sf);
            printf("\nSame Major/Minor Radius Ratio will be used for rest of the ellipses.\n");
            generateRadii(RX[i],RY[i],sf);
            break;
        }
    }

    printf("Enter '1' for vertically elongated ellipses\nOR\nAny other number for horizontally elongated ellipses.\n\n");
    scanf("%d",&choice);
    if(choice!=1)
    {
        float *temp=RX;
        RX=RY;
        RY=temp;
    }

    // Initialize GLUT
    initializeGLUT(&argc, argv, myDisplay);
    midEllipse();
 
    return 0;
}