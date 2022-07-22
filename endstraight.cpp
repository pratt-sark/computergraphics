// Author - Pratyay Sarkar
// Program - 27
// End Point Code Line Visibility Check Algorithm

#include <iostream>
#include "header.h"

using namespace std;

struct PointStructure
{
    float x, y;
    int endp[4];
} typedef Point;

struct WindowStructure
{
    float L,R,B,T;
} typedef window;

Point point1,point2;
window win;
int logicalAND[4];

void draw_pixel(int x, int y)
{
    glPointSize(2);
    glColor3f(1,0,0); //white
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void draw_line()
{
    glPointSize(2);
    glColor3f(1,0,0); //white
    glBegin(GL_LINES);
    glVertex2i(point1.x,point1.y);
    glVertex2i(point2.x,point2.y);
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

bool allZeroes(Point point)
{
    for(int i=0;i<4;i++)
        if (point.endp[0]==1)
            return false;
    return true;
}

void findAND()
{
    for(int i=0;i<4;i++)
        logicalAND[i] = point1.endp[i]*point2.endp[i];
}

void verifyAND()
{
    bool visible=true;
    for(int i=0;i<4;i++)
    {
        if(logicalAND[i]==1)
        {
            cout<<"\nLine is trivially invisible.\n";
            visible = false;
        }
    }
    if(visible && allZeroes(point1) && allZeroes(point2))
        cout<<"\nLine is completely visible.\n";
    else
        cout << "\nLine is partially visible or totally invisible.\n";
}

void endPoint(Point point)
{
    if (point.y>win.T)
    {
        cout<<"1";
        point.endp[0]=1;
    }    
    else
        cout<<"0";
    
    if (point.y<win.B)
    {
        cout<<"1";
        point.endp[1]=1;
    }
    else
        cout<<"0";
    
    if (point.x>win.R)
    {
        cout<<"1";
        point.endp[2]=1;
    }
    else
        cout<<"0";
    
    if (point.x<win.L)
    {
        cout<<"1";
        point.endp[3]=1;
    }
    else
        cout<<"0";
}

void myDisplay()
{
    cout<<"\nEnd Point Code for Point 1: ";
    endPoint(point1);
    cout<<"\nEnd Point Code for Point 2: ";
    endPoint(point2);
    draw_line();
    drawPolygon();
    findAND();
    verifyAND();
    glFlush();
}

int main(int argc, char **argv)
{  
    cout<<"Enter Window Dimesions:\nLeft = ";
    cin>>win.L;
    cout<<"\nRight = "; cin>>win.R;
    cout<<"\nBottom = "; cin>>win.B;
    cout<<"\nTop = "; cin>>win.T;

    cout<<"Enter point 1:\n";
    cin>>point1.x>>point1.y;
    cout<<"Enter point 2:\n";
    cin>>point2.x>>point2.y;

    // Initialize GLUT
    initializeGLUT(&argc, argv, myDisplay);

    return 0;
}