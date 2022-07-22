// Author - Pratyay Sarkar
// Program - 24
// Point Visibility algorithm

#include <iostream>
#include "header.h"

using namespace std;

struct PointStructure
{
    float x, y;
} typedef Point;

struct WindowStructure
{
    float L,R,B,T;
} typedef window;

Point point;
window win;

void draw_pixel(int x, int y)
{
    glPointSize(4);
    glColor3f(1,0,0); //white
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void drawPolygon()
{
    glPointSize(3);
    glColor3f(1,1,1); //red
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_POLYGON);
        glVertex2f(win.L, win.B);
        glVertex2f(win.R, win.B);
        glVertex2f(win.R, win.T);
        glVertex2f(win.L, win.T);
    glEnd();
}

void simpleVisible()
{
    if (point.x<win.L || point.x>win.R || point.y>win.T || point.y<win.B)
        cout<<"\nPoint is totally invisible."<<endl;
    else
        cout<<"\nPoint is totally visible."<<endl;
}

void myDisplay()
{
    draw_pixel(point.x,point.y);
    simpleVisible();
    drawPolygon();
    glFlush();
}

int main(int argc, char **argv)
{  
    cout<<"Enter Window Dimesions:\nLeft = ";
    cin>>win.L;
    cout<<"\nRight = "; cin>>win.R;
    cout<<"\nBottom = "; cin>>win.B;
    cout<<"\nTop = "; cin>>win.T;

    cout<<"Enter the point:\n";
    cin>>point.x>>point.y;

    // Initialize GLUT
    initializeGLUT(&argc, argv, myDisplay);

    return 0;
}