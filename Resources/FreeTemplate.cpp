#include <GL/glut.h>   // Works for both GLUT and FreeGLUT
#include <stdlib.h>
#include <math.h>

// Function to render graphics
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Drawing starts here
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);   // Red
        glVertex2f(-0.5f, -0.5f);

        glColor3f(0.0f, 1.0f, 0.0f);   // Green
        glVertex2f(0.5f, -0.5f);

        glColor3f(0.0f, 0.0f, 1.0f);   // Blue
        glVertex2f(0.0f, 0.5f);
    glEnd();
    // Drawing ends here

    glFlush();   // Render now
}

// Initialization function
void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Background color (black)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1); // 2D coordinate system
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL FreeGLUT Template");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
