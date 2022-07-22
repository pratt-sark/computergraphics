//Translation of an object

#include <iostream>

//header file containing OPENGL intitialisation functions
#include "header.h" 

using namespace std;

int n; //number of sides of a polygon
double tx,ty; //translation values for x-axis and y-axis

//Structure of a point
struct PointStructure
{
    //x - abscissa, y-ordinate
    float x, y; 
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

//Translate all points in array 'points' by tx and ty
void translate()
{
    for(int i=0;i<n;i++)
    { 
        points[i].x = tx + points[i].x;
        points[i].y = ty + points[i].y;
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
        glVertex2f(points[i].x, points[i].y);
        cout<<points[i].x<<" "<<points[i].y<<endl;
    }
    glEnd(); //end redering
}

void myDisplay()
{
    //draw the polygon with given points
    drawPolygon();

    //translate as: x' = x + tx and y' = y + ty
    translate();

    //draw the translated polygon with now reflected points
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
        float a, b;
        cin>>a>>b;
        points[i].x = a;
        points[i].y = b;
    }

    cout<<"Enter translation value along x-axis and y-axis:\n";
    cin>>tx>>ty;

    // Initialize GLUT
    initializeGLUT(&argc, argv, myDisplay);

    return 0;
}