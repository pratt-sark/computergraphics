// Author - Pratyay Sarkar
// Program - 28
// Cohen Sutherland Algorithm

#include <iostream>
#include <cmath>
#include "header.h"

using namespace std;

void draw_pixel(int x, int y)
{
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

struct PointStructure
{
    float x, y;
} typedef Point;

float T, B, R, L, slope;
Point *point1, *point2;

string computeEndCode(float px, float py)
{
    string code = "0000";

    if (px < L)
        code[3] = '1';
    else if (px > R)
        code[2] = '1';

    if (py < B)
        code[1] = '1';
    else if (py > T)
        code[0] = '1';
    return code;
}

string AND(string a, string b)
{
    for (int i = 0; i < 4; i++)
    {
        if (a[i] == '0' || b[i] == '0')
            a[i] = '0';
        else
            a[i] = '1';
    }
    return a;
}

bool isThere1In(string a)
{
    for (int i = 0; i < 4; i++)
        if (a[i] == '1')
            return true;
    return false;
}

void draw_line(float x1, float y1,float x2,float y2)
{
    glPointSize(2);
    glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd();
}

void cohenSutherland()
{
    string a = computeEndCode(point1->x, point1->y);
    string b = computeEndCode(point2->x, point2->y);
    string c = AND(a, b);
    // printf("%f %f %f %f\n", point1->x, point1->y, point2->x, point2->y);
    // Completely invisible case
    if (isThere1In(c))
    {
        cout << "The line is completely outside the clipping window\n";
        glColor3ub(255, 0, 0);
        draw_line(point1->x, point1->y, point2->x, point2->y);
        glColor3ub(255, 255, 255);
        return;
    }
    // Completely visible case
    else if (!isThere1In(a) and !isThere1In(b))
    {
        cout << "The line is completely inside the clipping window.\n";
        glColor3ub(255, 0, 0);
        draw_line(point1->x, point1->y, point2->x, point2->y);
        glColor3ub(255, 255, 255);
        return;
    }
    // Partial visibility case
    else
    {
        cout << "The line is partially visible inside the clipping window.\n";
        // Clipping  point1
        if (a[3] == '1') //Left Edge
        {
            float y = point1->y + slope * (L - point1->x);
            if (y >= B && y <= T) //for valid value of y, P1 becomes an edge point
            {
                point1->x = L;
                point1->y = y;
            }
        }
        if (a[2] == '1')//Right Edge
        {
            float y = point1->y + slope * (R - point1->x);
            if (y >= B && y <= T)//for valid value of y, P1 becomes an edge point
            {
                point1->x = R;
                point1->y = y;
            }
        }
        if (a[1] == '1')
        {
            float x = point1->x + (B - point1->y) / slope;
            if (x >= L && x <= R)
            {
                point1->x = x;
                point1->y = B;
            }
        }
        if (a[0] == '1')
        {
            float x = point1->x + (T - point1->y) / slope;
            if (x >= L && x <= R)
            {
                point1->x = x;
                point1->y = T;
            }
        }

        // Clipping point 2
        if (b[3] == '1')
        {
            float y = point2->y + slope * (L - point2->x);
            if (y >= B && y <= T)
            {
                point2->x = L;
                point2->y = y;
            }
        }
        if (b[2] == '1')
        {
            float y = point2->y + slope * (R - point2->x);
            if (y >= B && y <= T)
            {
                point2->x = R;
                point2->y = y;
            }
        }
        if (b[1] == '1')
        {
            float x = point2->x + (B - point2->y) / slope;
            if (x >= L && x <= R)
            {
                point2->x = x;
                point2->y = B;
            }
        }
        if (b[0] == '1')
        {
            float x = point2->x + (T - point2->y) / slope;
            if (x >= L && x <= R)
            {
                point2->x = x;
                point2->y = T;
            }
        }
    }
    cout<<"\n\nThe Visible Segment of the line is from P("<<round(point1->x)<<","<<round(point1->y);
    cout<<") and Q("<<round(point2->x)<<","<<round(point2->y)<<").\n";
    // printf("%f %f %f %f\n", point1->x, point1->y, point2->x, point2->y);
}

void generateWindow()
{
    draw_line(L, B, L, T);
    draw_line(L, T, R, T);
    draw_line(R, T, R, B);
    draw_line(R, B, L, B);
}

void myDisplay()
{
    glColor3ub(255, 0, 255);
    generateWindow();
    glColor3ub(255, 255, 255);

    draw_line(point1->x, point1->y, point2->x, point2->y);

    // Clipping Algorithm
    cohenSutherland();

    glColor3ub(255, 0, 0);
    draw_line(point1->x, point1->y, point2->x, point2->y);
    glColor3ub(255, 255, 255);

    glFlush();
}

int main(int argc, char **argv)
{
    cout<<"Enter Window Dimesions:\nLeft = ";
    cin>>L;
    cout<<"\nRight = "; cin>>R;
    cout<<"\nBottom = "; cin>>B;
    cout<<"\nTop = "; cin>>T;

    point1 = (Point *)calloc(1, sizeof(Point));
    point2 = (Point *)calloc(1, sizeof(Point));

    printf("Enter the starting point of line:\n");
    cin >> point1->x >> point1->y;
    printf("Enter the end point of line:\n");
    cin >> point2->x >> point2->y;

    slope = (point2->y - point1->y) / (point2->x - point1->x);
    // Initialize GLUT
    initializeGLUT(&argc, argv, myDisplay);

    return 0;
}
