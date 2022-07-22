#include <iostream>
#include "header.h"

using namespace std;
int n;
double shearY,xref;

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

void shear()
{
    //A coordinate position (x, y) is shifted vertically 
    //by an amount proportional to its perpendicular
    //distance (x value) from the y axis.
    for(int i=0;i<n;i++)
        points[i].y =  points[i].y + shearY*(points[i].x - xref);
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

void myDisplay()
{
    drawPolygon();
    shear();
    drawPolygon();
    glFlush();
}

int main(int argc, char **argv)
{
    // Take all inputs here
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

    printf("Enter the shear value along y direction:\n");
    scanf("%lf", &shearY);
    printf("Enter the value of reference line parallel to the y axis:\n");
    scanf("%lf", &xref);

    // Initialize GLUT
    initializeGLUT(&argc, argv, myDisplay);

    return 0;
}
