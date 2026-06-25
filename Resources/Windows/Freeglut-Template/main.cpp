#include <GL/glut.h>
#include <cmath>

// Window size
const int WIDTH = 600;
const int HEIGHT = 600;

void drawHeart(float centerX, float centerY, float size)
{
    glColor3f(1.0f, 0.0f, 0.0f); // red

    glBegin(GL_POLYGON);
    for (float t = 0; t < 2 * M_PI; t += 0.02f)
    {
        float x = 16 * pow(sin(t), 3);
        float y = 13 * cos(t) - 5 * cos(2 * t)
                - 2 * cos(3 * t) - cos(4 * t);

        // scale + translate
        glVertex2f(centerX + (x / 20.0f) * size,
                   centerY + (y / 20.0f) * size);
    }
    glEnd();
}

// Function to draw a heart shape
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glBegin(GL_POLYGON);

    // Draw heart using parametric equation
    for (float t = 0; t < 2 * M_PI; t += 0.01f) {
        float x = 16 * pow(sin(t), 3);
        float y = 13 * cos(t) - 5 * cos(2 * t) - 2 * cos(3 * t) - cos(4 * t);
        glVertex2f(x / 20.0f, y / 20.0f); // Scale down
    }

    glEnd();
    glFlush();
}

// Initialization
void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // White background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.5, 1.5, -1.5, 1.5); // Set coordinate system
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Heart Shape - OpenGL/GLUT");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
