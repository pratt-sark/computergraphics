//Author - Pratyay Sarkar
//Program - 1
//Draw a line by using DDA algorithm when two points are given

#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

//Coordinates of Points between which the line is to be drawn
double X1, Y1, X2, Y2;

//Returns the rounded-off value of parameter
float round_value(float v)
{
  return floor(v + 0.5);
}

//Implements the DDA Algorithm
void DDA_Algorithm()
{
  double dx=(X2-X1); //distance between abscissa of points
  double dy=(Y2-Y1); //distance between ordinates of points
  double steps;
  float xInc,yInc,x=X1,y=Y1;

  // Find out whether to increment x or y
  steps=(abs(dx)>abs(dy))?(abs(dx)):(abs(dy));
  xInc=dx/(float)steps;
  yInc=dy/(float)steps;

  // Clears buffers to preset values
  glClear(GL_COLOR_BUFFER_BIT);

  //Set diameter of pixels
  glPointSize(2);

  // Plot the points
  glBegin(GL_POINTS);
  // Plot the first point
  glVertex2d(x,y);

  // For every step, find an intermediate vertex
  for(int k=0;k<steps;k++)
  {
    x+=xInc;
    y+=yInc;
    glVertex2d(round_value(x), round_value(y));
  }

  glEnd();
  glFlush();
}
void Init()
{
  // Set clear color to white
  glClearColor(1.0,1.0,1.0,0);
  // Set fill color to black
  glColor3f(0.0,0.0,0.0);

  gluOrtho2D(0 , 640 , 0 , 480);
}
void main(int argc, char **argv)
{
  printf("Enter two end points of the line to be drawn:\n");
  printf("\n------------------------------------");
  printf("\nEnter Point1( X1 , Y1):\n");
  scanf("%lf%lf",&X1,&Y1);
  printf("\n------------------------------------");
  printf("\nEnter Point1( X2 , Y2):\n");
  scanf("%lf%lf",&X2,&Y2);
  
  // Initialise GLUT library
  glutInit(&argc,argv);
  // Set the initial display mode
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  // Set the initial window position and size
  glutInitWindowPosition(0,0);
  glutInitWindowSize(640,480);

  // Create the window with title "DDA_Line Drawing Algorithm"
  glutCreateWindow("DDA Line Drawing Algorithm");
  // Initialize drawing colors
  Init();
  // Call the displaying function
  glutDisplayFunc(DDA_Algorithm);

  //Keep displaying until the program is closed
  glutMainLoop();
}
