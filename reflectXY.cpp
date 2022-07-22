//Reflection wrt y=x

#include <iostream>
#include "header.h"

using namespace std;
int n;

struct PointStructure
{
    float x, y;
} typedef Point;

Point *points;

// Function to draw pixel
void draw_pixel(int x, int y)
{
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void reflect()
{
    for(int i=0;i<n;i++)
    {
        double temp = points[i].x;
        points[i].x =  points[i].y;
        points[i].y =  temp;
    }
}

void drawPolygon()
{
    glPointSize(2);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_POLYGON);
    int i;
    for (i=0;i<n;i++)
    {
        glVertex2f(points[i].x, points[i].y);
        cout<<points[i].x<<" "<<points[i].y<<endl;
    }
    glEnd();
}

void drawLine()
{
    glPointSize(2);
    glBegin(GL_LINES);
    glVertex2f(0,0);
    glVertex2f(w,h);
    glEnd();
}

void myDisplay()
{
    drawPolygon();
    drawLine();
    reflect();
    
    drawPolygon();
    glFlush();
}

int main(int argc, char **argv)
{
    printf("Enter number of sides of the polygon:\n");
    scanf("%d", &n);

    points = (Point *)calloc(n, sizeof(Point));
    printf("Enter %d points(x,y):\n", n);
    for (int i = 0; i < n; i++)
    {
        float a, b;
        scanf("%f%f", &a, &b);
        points[i].x = a;
        points[i].y = b;
    }

    // Initialize GLUT
    initializeGLUT(&argc, argv, myDisplay);

    return 0;
}