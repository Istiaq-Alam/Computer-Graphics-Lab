/*
 * Neutral Face Emoji Drawing 😑
 *
 * Written by Istiak Alam
 *
 */

#include <GL/glut.h>  // GLUT header
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979323846
//float p=-2.3;

// Draw filled circle
void DrawCircle(float cx, float cy, float rx, float ry, int segments)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(12, 12); // center point
    for (int i = 0; i <= segments; i++)
    {
        float theta = 2.0f * PI * i / segments;
        float x = rx * cos(theta);
        float y = ry * sin(theta);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}

// Draw circle outline
void DrawCircleOutline(float cx, float cy, float r, int segments)
{
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < segments; i++)
    {
        float theta = 2.0f * PI * i / segments;
        glVertex2f(cx + r * cos(theta), cy + r * sin(theta));
    }
    glEnd();
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50, 50, -50, 50, -1, 1);

    glMatrixMode(GL_MODELVIEW);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    /* Face (filled) */
    glColor3f(1.0f, 0.85f, 0.0f);          // Emoji yellow
    DrawCircle(0, 0, 25, 25, 100);

    /* Face outline */
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(3);
    DrawCircleOutline(0, 0, 25, 100);


    glColor3f(0.0f, 0.0f, 0.0f);

    // Left eye
    glRectf(-16.0f, 6.5f, -6.0f, 4.5f);

    // Right eye
    glRectf(6.0f, 6.5f, 16.0f, 4.5f);

    // Mouth
    glRectf(-10.0f, -6.0f, 10.0f, -8.0f);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (800, 800);
	glutInitWindowPosition (500, 100);
	glutCreateWindow ("Emoji 😑");
	init();
    glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
