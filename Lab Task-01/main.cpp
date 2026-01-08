/*
 * Lab Task-01
 * Creating a House using quad line
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

#include <GL/glut.h>  // GLUT header
#include <stdlib.h>
#include <math.h>
#include <cmath>


// Setup and Projection
void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // White background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10, 10, -10, 10, -1, 1); // Its just like margine or padding
    glMatrixMode(GL_MODELVIEW);
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // House Base (Rectangle)
    glColor3f(1.0f, 0.8f, 0.0f); // Light orange
    glBegin(GL_QUADS);
        glVertex2f(-5.0f, -3.0f);
        glVertex2f( 5.0f, -3.0f);
        glVertex2f( 5.0f,  3.0f);
        glVertex2f(-5.0f,  3.0f);
    glEnd();

    // Roof (Triangle)
    glColor3f(0.8f, 0.0f, 0.0f); // Dark red
    glBegin(GL_TRIANGLES);
        glVertex2f(-6.0f,  3.0f);
        glVertex2f( 6.0f,  3.0f);
        glVertex2f( 0.0f,  7.0f);
    glEnd();

    // Door (Rectangle)
    glColor3f(0.3f, 0.2f, 0.1f); // Brown
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -3.0f);
        glVertex2f( 1.0f, -3.0f);
        glVertex2f( 1.0f,  0.0f);
        glVertex2f(-1.0f,  0.0f);
    glEnd();

    // Window 1 (Left)
    glColor3f(0.0f, 0.6f, 1.0f); // Light blue
    glBegin(GL_QUADS);
        glVertex2f(-4.0f,  0.5f);
        glVertex2f(-2.0f,  0.5f);
        glVertex2f(-2.0f,  2.0f);
        glVertex2f(-4.0f,  2.0f);
    glEnd();

    // Window 2 (Right)
    glBegin(GL_QUADS);
        glVertex2f( 2.0f,  0.5f);
        glVertex2f( 4.0f,  0.5f);
        glVertex2f( 4.0f,  2.0f);
        glVertex2f( 2.0f,  2.0f);
    glEnd();

    glFlush();
}

// Main
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 900);
    glutCreateWindow("House - Computer Graphics Lab-01");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
