/*
 * GLUT Shapes Demo
 *
 * Written by Istiak Alam
 *
 */

#include <GL/glut.h>  // Include GLUT header here
#include <stdlib.h>
#include <math.h>

// Initialization
void init()
{
    glClearColor(0.0f, 0.8f, 1.0f, 0.0f); // Background color
    glOrtho(-100, 100, -100, 100, -1, 1);  // Set up an orthogonal view
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    int x1=-100, y1=60, x2=-90, y2=70;

    for(int i=1; i<=8; i++){
    glColor3f(1.0f, 1.0f, 1.0f); // white
    glRectf(x1, y1, x2, y2);
    x1=x1+10;
    x2=x2+10;
    }

    glFlush();
}

// Main function
int main(int argc, char** argv)
{
    glutInit(&argc, argv);  // Initialize GLUT with command-line arguments
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // Set display mode
    glutInitWindowSize(600, 600);  // Set window size
    glutInitWindowPosition(650, 200);  // Set window position
    glutCreateWindow("Chess");  // Create the window

    init();  // Initialize OpenGL settings
    glutDisplayFunc(display);  // Register the display function

    glutMainLoop();  // Enter the GLUT event loop
    return 0;
}
