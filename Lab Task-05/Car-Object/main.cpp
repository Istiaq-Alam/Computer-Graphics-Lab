#include <GL/glut.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

static float	tx	=  0.0;
static float	ty	=  0.0;

void drawCircle(float cx, float cy, float r)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 100; i++)
    {
        float angle = 2 * 3.1416 * i / 100;
        float x = r * cos(angle);
        float y = r * sin(angle);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Road Land
    glColor3f(0.1, 0, 0.4);

    glBegin(GL_POLYGON);
    glVertex2f(0,8);
    glVertex2f(50,8);
    glVertex2f(50,10);
    glVertex2f(0,10);
    glEnd();


    // Car Body (Red)
    glColor3f(1.0, 0.1, 0.0);

    glPushMatrix();
    glTranslatef(tx,ty,0);
    glBegin(GL_POLYGON);
    glVertex2f(3,11);
    glVertex2f(6,11);
    glVertex2f(9,14);
    glVertex2f(12,14);
    glVertex2f(14,11);
    glVertex2f(31,11);
    glVertex2f(34,14);
    glVertex2f(36,14);
    glVertex2f(36,11);
    glVertex2f(35,11);
    glVertex2f(35,17);
    glVertex2f(24,17);
    glVertex2f(24,21);
    glVertex2f(18,21);
    glVertex2f(14,17);
    glVertex2f(7,17);
    glVertex2f(4,16);
    glVertex2f(3,13);
    glVertex2d(3,11);
    glEnd();


    // Car Window (White)
    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_POLYGON);
    glVertex2f(15,17);
    glVertex2f(23,17);
    glVertex2f(23,20);
    glVertex2f(18,20);
    glEnd();


    // Left Wheel
    glColor3f(0,0,0);
    drawCircle(10, 11, 3);

    glColor3f(1,1,1);
    drawCircle(10, 11, 0.8);

    // Right Wheel
    glColor3f(0,0,0);
    drawCircle(29, 11, 3);

    glColor3f(1,1,1);
    drawCircle(29, 11, 0.8);


    glPopMatrix();
    glFlush();
}

void spe_key(int key, int x, int y)
{

    switch (key)
    {
    case GLUT_KEY_RIGHT:
        tx +=3;
        glutPostRedisplay();
        break;

    case GLUT_KEY_LEFT:
        tx -=3;
        glutPostRedisplay();
        break;

    default:
        break;
    }
}


// Initialize
void init()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,50,0,30);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("2D Car using GLUT");
    init();

    glutDisplayFunc(display);
    glutSpecialFunc(spe_key);
    glutMainLoop();
    return 0;
}
