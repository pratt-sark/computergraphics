// Author - Pratyay Sarkar
// Program - 7
// Draw a circle by using Midpoint Circle Drawing Algorithm

#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

float radius, X, Y;
int num_points;
int *x_values, *y_values;

// Function to draw pixel
void draw_pixel(int x, int y)
{
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

// Midpoint Circle Drawing Algorithm
void draw_circle()
{

    float p = (5 / 4.0) - radius;
    float start_X = 0, start_Y = radius;
    int index = 0;
    while (start_X <= start_Y)
    {
        x_values[index] = start_X;
        y_values[index] = start_Y;
        index++;
        float next_p;
        if (p < 0)
            next_p = p + 2 * (start_X + 1) + 1;
        else
        {
            next_p = p + 2 * (start_X + 1) + 1 - 2 * (start_Y - 1);
            start_Y -= 1;
        }
        p = next_p;
        start_X += 1;
    }

    int rev_index = index - 2;
    while (rev_index >= 0)
    {
        start_X = x_values[rev_index];
        start_Y = y_values[rev_index];
        draw_pixel(start_Y + X, start_X + Y);
        x_values[index] = start_Y;
        y_values[index] = start_X;
        index++;
        rev_index--;
    }

    rev_index = index - 2;
    while (rev_index >= 0)
    {
        start_X = x_values[rev_index];
        start_Y = -y_values[rev_index];
        x_values[index] = start_X;
        y_values[index] = start_Y;
        index++;
        rev_index--;
    }

    rev_index = index - 2;
    while (rev_index >= 0)
    {
        start_X = -x_values[rev_index];
        start_Y = y_values[rev_index];
        x_values[index] = start_X;
        y_values[index] = start_Y;
        index++;
        rev_index--;
    }

    draw_pixel(X, Y);
    for (int i = 0; i < index; i++)
        draw_pixel(x_values[i] + X, y_values[i] + Y);
}

void myDisplay()
{
    draw_circle();
    glFlush();
}

int main(int argc, char **argv)
{
    printf("Enter the center:\n");
    scanf("%f%f", &X, &Y);
    printf("Enter the radius of the circle:\n");
    scanf("%f", &radius);

    num_points = radius * 8;
    x_values = (int *)calloc(num_points, sizeof(int));
    y_values = (int *)calloc(num_points, sizeof(int));

    // Initialize GLUT
    initializeGLUT(&argc, argv, myDisplay);

    return 0;
}
