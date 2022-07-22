// Author - Pratyay Sarkar
// Program - 29
// Midpoint Subdivision Algorithm

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

bool equality(float a, float b, bool flag)
{
    return flag ? (b > a) : (a > b);
}

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

float distance(Point *p1, Point *p2)
{
    return sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));
}

void recursive_func(Point *p1, Point *p2)
{
    string a = computeEndCode(p1->x, p1->y);
    string b = computeEndCode(p2->x, p2->y);
    string c = AND(a, b);

    // Completely invisible case
    if (isThere1In(c))
        return;
    // Completely visible case
    else if (!isThere1In(a) and !isThere1In(b))
        draw_line(p1->x, p1->y, p2->x, p2->y);
    else
    {
        if (distance(p1, p2) <= 1)
            draw_line(p1->x, p1->y, p2->x, p2->y);
        else
        {
            Point *mid = (Point *)calloc(1, sizeof(Point));
            mid->x = (p1->x + p2->x) / 2;
            mid->y = (p1->y + p2->y) / 2;

            recursive_func(p1, mid);
            recursive_func(mid, p2);
        }
    }
}

void midpoint_subdivision()
{
    string a = computeEndCode(point1->x, point1->y);
    string b = computeEndCode(point2->x, point2->y);
    string c = AND(a, b);

    // Completely invisible case
    if (isThere1In(c))
    {
        cout << "The line is completely outside the clipping window\n";
        return;
    }
    // Completely visible case
    else if (!isThere1In(a) and !isThere1In(b))
    {
        cout << "The line is completely inside the clipping window\n";
        draw_line(point1->x, point1->y, point2->x, point2->y);
        return;
    }
    // Partial visibility case

    recursive_func(point1, point2);
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

    // Do the clipping
    glColor3ub(255, 0, 0);
    midpoint_subdivision();

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
