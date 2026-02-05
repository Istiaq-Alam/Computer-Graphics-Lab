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

    //int x1=-100, y1=60, x2=-90, y2=70;
    int startX = -50;
    int startY = 60;
    int size = 10;

    for (int r = 1; r<=8; r++)
    {
        int x1 = startX;
        int x2 = -40;

        for (int c = 1; c <=8; c++)
        {
            if ((r + c) % 2 == 0)
                glColor3f(1.0f, 1.0f, 1.0f); // white
            else
                glColor3f(0.0f, 0.0f, 0.0f); // black

            glRectf(x1, startY, x2, startY - size);

            x1=x1+size;
            x2=x2+size;
        }

        startY=startY-size;
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
