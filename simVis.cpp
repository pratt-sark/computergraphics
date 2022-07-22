// Author - Pratyay Sarkar
// Program - 25
// Simple Visibility Algorithm for a straight line

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

Point *points;
window win;
bool visible;
bool partial;

void drawLine()
{
    glPointSize(2);
    glColor3f(1,0,0); //red
    glBegin(GL_LINES);
    glVertex2f(points[0].x,points[0].y);
    glVertex2f(points[1].x,points[1].y);
    glEnd();
}

void drawPolygon()
{
    glPointSize(2);
    glColor3f(1,1,1); //white
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
    visible = true; partial = false;

    //completely invisible cases
    if (points[0].x<win.L && points[1].x<win.L)
        visible = false;
    else if (points[0].x>win.R && points[1].x>win.R)
        visible = false;
    else if (points[0].y>win.T && points[1].y>win.T)
        visible = false;
    else if (points[0].y<win.B && points[1].y<win.B)
        visible = false;
    
    if(!visible)
    {
        cout<<"\nLine is totally invisible."<<endl;
        drawLine();
    }   
    else
    {
        //partially invisible cases
        if (points[0].x<win.L || points[0].x>win.R)
            partial = true;
        else if (points[1].x<win.L || points[1].x>win.R)
            partial = true;
        else if (points[0].y<win.B || points[0].y>win.T)
            partial = true;
        else if (points[1].y<win.B || points[1].y>win.T)
            partial = true;
    }
    
    if (partial)
    {
        cout<<"\nLine is partially visible."<<endl;
        drawLine();
    }
    
    else if (visible) //completely visible case
    {
        cout<<"\nLine is completely visible."<<endl;
        drawLine();
    }    
}

void myDisplay()
{
    simpleVisible();
    drawPolygon();
    glFlush();
}

int main(int argc, char **argv)
{
    points = (Point *)calloc(2, sizeof(Point));
    
    cout<<"Enter Window Dimesions:\nLeft = ";
    cin>>win.L;
    cout<<"\nRight = "; cin>>win.R;
    cout<<"\nBottom = "; cin>>win.B;
    cout<<"\nTop = "; cin>>win.T;

    for (int i = 0; i < 2; i++)
    {
        cout<<"\nEnter point "<<i+1<<" of the line: "<<endl;
        float a, b;
        scanf("%f%f", &a, &b);
        points[i].x = a;
        points[i].y = b;
    }

    // Initialize GLUT
    initializeGLUT(&argc, argv, myDisplay);

    return 0;
}