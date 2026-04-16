/*
 * GLUT Object-Controlling Demo
 *
 * Lab-05 ;
 * 16 April, 2026
 *
 */

#include <GL/glut.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
//#include<stdarg.h>

static GLfloat spin = 0.0;
static float	tx	=  0.0;
static float	ty	=  0.0;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();

    glRotatef(spin, 0.0, 0.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);

    glTranslatef(tx,ty,0);

    glRectf(-25.0, -25.0, 25.0, 25.0);
    glPopMatrix();

    glFlush();
}

void spinDisplay_left(void)
{
    spin = spin + 1;

    glutPostRedisplay();
}

void spinDisplay_right(void)
{
    spin = spin - 1;

    glutPostRedisplay();
}


void init(void)
{
    glClearColor (1.0, 0.0, 0.0, 0.0);
    glOrtho(-100.0, 100.0, -100.0,100.0, -1.0, 1.0);
}


void my_keyboard(unsigned char key, int x, int y)
{

    switch (key)
    {

    case 'l':
        spinDisplay_left();
        break;

    case 'r':
        spinDisplay_right();
        break;

    case 's':
        glutIdleFunc(NULL);
        break;

    default:
        break;
    }
}

void spe_key(int key, int x, int y)
{

    switch (key)
    {

    case GLUT_KEY_UP:
        ty +=5;
        //PlaySound("Horn Honk-SoundBible.com-1162546405.wav", NULL, SND_ASYNC|SND_FILENAME);
        glutPostRedisplay();
        break;



    case GLUT_KEY_DOWN:

        //PlaySound("Horn Honk-SoundBible.com-1162546405.wav", NULL, SND_ASYNC|SND_FILENAME);
        ty -=5;


        glutPostRedisplay();
        break;

    case GLUT_KEY_RIGHT:
        //PlaySound("Horn Honk-SoundBible.com-1162546405.wav", NULL, SND_ASYNC|SND_FILENAME);
        tx +=5;
        glutPostRedisplay();
        break;



    case GLUT_KEY_LEFT:
        //PlaySound("Horn Honk-SoundBible.com-1162546405.wav", NULL, SND_ASYNC|SND_FILENAME);
        tx -=5;
        glutPostRedisplay();
        break;



    default:
        break;
    }
}


void my_mouse(int button, int state, int x, int y)
{
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay_left);
        break;
    case GLUT_MIDDLE_BUTTON:
    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay_right);

        break;
    default:
        break;
    }
}

int main(int argc, char** argv)
{
    //PlaySound("Horn Honk-SoundBible.com-1162546405.wav", NULL, SND_ASYNC|SND_FILENAME);
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (800, 800);
    glutInitWindowPosition (550, 100);
    glutCreateWindow ("Object-Control");
    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(my_keyboard);
    glutSpecialFunc(spe_key);
    glutMouseFunc(my_mouse);
    glutMainLoop();
    return 0;
}
