//Scaling with respect to a point

#include <iostream>
#include <cmath>

//header file containing OPENGL intitialisation functions
#include "header.h" 

using namespace std;

int n; //number of sides of a polygon
double xf,yf; //P(rx,ry) is the point of scaling
double sx,sy; //scaling factors along x- axis and y-axis

//Structure of a point
struct PointStructure
{
    //x - abscissa, y-ordinate
    double x, y; 
} typedef Point;

Point *points;// array of points

//Function to draw a pixel
void draw_pixel(int x, int y)
{
    glPointSize(2); //size of pixel
    glBegin(GL_POINTS); //mention that we are rendering points
    glVertex2i(x, y); //render a pixel
    glEnd(); //stop rendering
}

//Translate all points in array 'points' by tx = rx and ty = ry
//k=0 for x' = x - rx and y' = y - ry
//k=1 for x' = x + rx and y' = y + ry
void translate(int k)
{
    for(int i=0;i<n;i++)
    {
        if(k==0)
        {
            points[i].x = points[i].x -xf;
            points[i].y = points[i].y -yf;
        }
        else
        {
            points[i].x = xf + points[i].x;
            points[i].y = yf + points[i].y;
        }
    }
}

//Scale points with respect to origin
void scale()
{
    for(int i=0;i<n;i++)
    {
        points[i].x =  points[i].x * sx;
        points[i].y =  points[i].y * sy;
    }
}

//Draw a polygon with given points in 'points' array
void drawPolygon()
{
    glPointSize(2); //set pixel width
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //set polygon mode
    glBegin(GL_POLYGON); //mention that we are rendering polygons
    int i;
    for (i=0;i<n;i++)
    {
        glVertex2f(round(points[i].x), round(points[i].y));
        cout<<points[i].x<<" "<<points[i].y<<endl;
    }
    glEnd(); //end rendering
}

void myDisplay()
{
    //draw the point of scaling
    draw_pixel(xf,yf);

    //draw the polygon with given points
    drawPolygon();

    //translate as: x' = x - rx and y' = y - ry
    translate(0);

    //scale with respect to origin
    scale();

    //translate as: x' = x + rx and y' = y + ry
    translate(1);

    //draw the reflected polygon with now scaled points
    drawPolygon();
    glFlush();
}

//Execution starts here
int main(int argc, char **argv)
{
    cout<<"\nEnter number of sides of the polygon:\n";
    cin>>n;

    points = (Point *)calloc(n, sizeof(Point));
    cout<<"\nEnter "<<n<<" points(x,y):\n";
    for (int i = 0; i < n; i++)
    {
        double a, b;
        cin>>a>>b;
        points[i].x = a;
        points[i].y = b;
    }

    cout<<"Enter the pivot point for scaling:\n";
    cin>>xf>>yf;

    cout<<"Enter scaling in x-direction and y-direction:\n";
    cin>>sx>>sy;    

    // Initialize GLUT
    initializeGLUT(&argc, argv, myDisplay);

    return 0;
}