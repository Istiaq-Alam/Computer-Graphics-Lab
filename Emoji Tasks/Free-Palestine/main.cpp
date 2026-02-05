/*
 * Flag Emoji of Palestine 🇵🇸
 * Drawn using OpenGL (GLUT)
 *
 * Author: Istiak Alam
 */

#include <GL/glut.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to draw wavy rectangle stripe
void DrawWavyStripe(float xStart, float xEnd, float yStart, float yEnd, float waveAmplitude, float waveFrequency)
{
    int segments = 100; // more segments = smoother curve
    glBegin(GL_QUADS);
    for (int i = 0; i < segments; i++)
    {
        float t1 = (float)i / segments;
        float t2 = (float)(i + 1) / segments;

        float x1 = xStart + t1 * (xEnd - xStart);
        float x2 = xStart + t2 * (xEnd - xStart);

        // Apply simple sine wave for top and bottom edges
        float yTop1 = yEnd + waveAmplitude * sin(waveFrequency * x1 * PI);
        float yTop2 = yEnd + waveAmplitude * sin(waveFrequency * x2 * PI);

        float yBot1 = yStart + waveAmplitude * sin(waveFrequency * x1 * PI);
        float yBot2 = yStart + waveAmplitude * sin(waveFrequency * x2 * PI);

        glVertex2f(x1, yBot1);
        glVertex2f(x2, yBot2);
        glVertex2f(x2, yTop2);
        glVertex2f(x1, yTop1);
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Draw the flag stripes
    float waveAmplitude = 0.03f;  // How curved the stripes are
    float waveFrequency = 2.0f;   // Number of waves

    // Top stripe (Black)
    glColor3f(0.0f, 0.0f, 0.0f);
    DrawWavyStripe(-0.5f, 1.0f, 0.17f, 0.5f, waveAmplitude, waveFrequency);

    // Middle stripe (White)
    glColor3f(1.0f, 1.0f, 1.0f);
    DrawWavyStripe(-0.5f, 1.0f, -0.17f, 0.17f, waveAmplitude, waveFrequency);

    // Bottom stripe (Green)
    glColor3f(0.0f, 0.6f, 0.0f);
    DrawWavyStripe(-0.5f, 1.0f, -0.5f, -0.17f, waveAmplitude, waveFrequency);

    // Left red triangle
    glColor3f(0.8f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5f, 0.5f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.5f, -0.5f);
    glEnd();

    glFlush();
}

void init()
{
    glClearColor(1, 1, 1, 1); // white background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.5, 1.5, -1.5, 1.5, -2, 2);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(600, 200);
    glutCreateWindow("Free-Palestine");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
