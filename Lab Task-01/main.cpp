/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.
 * The number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#include <GL/glut.h>  // Include GLUT header here
#include <stdlib.h>
#include <math.h>

// Initialization
void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Background color
    glOrtho(-5, 5, -5, 5, -5, 5);  // Set up an orthogonal view
}

// Display function
void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the screen
    glColor3f(1.0f, 1.0f, 0.0f);  // Set color to yellow

    glBegin(GL_QUADS);  // Draw a square
        glVertex3d(2.0, 2.0, 0.0);
        glVertex3d(2.0, -2.0, 0.0);
        glVertex3d(-2.0, -2.0, 0.0);
        glVertex3f(-2.0, 2.0, 0.0);
    glEnd();

    glColor3f(0.0f, 1.0f, 0.0f);  // Set color to green
    glBegin(GL_LINES);  // Draw a line
        glVertex3d(2.0, 2.0, 0.0);
        glVertex3d(-2.0, -2.0, 0.0);
    glEnd();

    glFlush();  // Force execution of OpenGL commands
}

// Main function
int main(int argc, char** argv)
{
    glutInit(&argc, argv);  // Initialize GLUT with command-line arguments
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // Set display mode
    glutInitWindowSize(600, 600);  // Set window size
    glutInitWindowPosition(400, 200);  // Set window position
    glutCreateWindow("Shape");  // Create the window

    init();  // Initialize OpenGL settings
    glutDisplayFunc(myDisplay);  // Register the display function

    glutMainLoop();  // Enter the GLUT event loop
    return 0;
}
