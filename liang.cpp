// Author - Pratyay Sarkar
// Program - 31
// Liang-Barsky algorithm

#include <iostream>
#include <math.h>
#include "header.h"
#include <vector>
#include <utility>

using namespace std;

// Function to draw pixel
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

float T, B, R, L;
Point *point1, *point2;

void draw_line(float x1, float y1,float x2,float y2)
{
    glPointSize(2);
    glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd();
}

bool clip(float d, float q, float *tL, float *tU)
{
    if (d == 0 and q < 0)
        return false;
    float t = q / d;
    if (d < 0)
    {
        if (t < *tU)
            *tL = (*tL > t) ? *tL : t;
        else
            return false;
    }
    else
    {
        if (t > *tL)
            *tU = (*tU < t) ? *tU : t;
        else
            return false;
    }
    return true;
}

Point *parametric_solution(float t)
{
    Point *temp = (Point *)calloc(1, sizeof(Point));
    temp->x = point1->x + (point2->x - point1->x) * t;
    temp->y = point1->y + (point2->y - point1->y) * t;
    return temp;
}

void liang_barsky()
{
    float deltaX = point2->x - point1->x;
    float deltaY = point2->y - point1->y;

    float q1 = point1->x - L;
    float q2 = R - point1->x;
    float q3 = point1->y - B;
    float q4 = T - point1->y;

    float tL = 0, tU = 1;
    bool flag = true;
    flag &= clip(-deltaX, q1, &tL, &tU);
    flag &= clip(deltaX, q2, &tL, &tU);
    flag &= clip(-deltaY, q3, &tL, &tU);
    flag &= clip(deltaY, q4, &tL, &tU);

    if (flag == false)
    {
        cout << "The line is completely invisible\n";
        return;
    }

    Point *start = parametric_solution(tL);
    Point *end = parametric_solution(tU);

    cout<<"\n\nThe Visible Segment of the line is from P("<<round(start->x)<<","<<round(start->y);
    cout<<") and Q("<<round(end->x)<<","<<round(end->y)<<").\n";
    glColor3ub(255, 0, 0);
    draw_line(start->x, start->y, end->x, end->y);
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
    liang_barsky();

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

    // Initialize GLUT
    initializeGLUT(&argc, argv, myDisplay);

    return 0;
}
