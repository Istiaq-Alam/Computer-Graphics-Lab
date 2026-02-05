/*
 * Flag of Palestine 🇵🇸
 * Drawn using OpenGL (GLUT)
 *
 * Author: Istiak Alam
 */

#include <GL/glut.h>

void init()
{
    glClearColor(1, 1, 1, 1);  // White background

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50, 50, -30, 30, -1, 1);

    glMatrixMode(GL_MODELVIEW);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    /* Black stripe (top) */
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
        glVertex2f(-50, 10);
        glVertex2f( 50, 10);
        glVertex2f( 50, 30);
        glVertex2f(-50, 30);
    glEnd();

    /* White stripe (middle) */
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
        glVertex2f(-50, -10);
        glVertex2f( 50, -10);
        glVertex2f( 50, 10);
        glVertex2f(-50, 10);
    glEnd();

    /* Green stripe (bottom) */
    glColor3f(0, 0.6f, 0);
    glBegin(GL_QUADS);
        glVertex2f(-50, -30);
        glVertex2f( 50, -30);
        glVertex2f( 50, -10);
        glVertex2f(-50, -10);
    glEnd();

    /* Red triangle (left side) */
    glColor3f(0.8f, 0, 0);
    glBegin(GL_TRIANGLES);
        glVertex2f(-50, 30);
        glVertex2f(-50, -30);
        glVertex2f(-10, 0);
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 400);
    glutCreateWindow("Free Palestine 🇵🇸");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
