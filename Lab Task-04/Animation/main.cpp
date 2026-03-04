/*
* GLUT Shapes Demo
*
* Written by Nigel Stewart November 2003
*
* This program is test harness for the sphere, cone * and torus shapes in GLUT.
*
* Spinning wireframe and smooth shaded shapes are * displayed until the ESC or q key is pressed. The
* number of geometry stacks and slices can be adjusted * using the + and - keys.
*/

#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
float p=0.0;
void display(void)
{
//PlaySound("Horn Honk-SoundBible.com-1162546405.wav", NULL, SND_ASYNC|SND_FILENAME);
    if(p<=+125.0)
    {
        p=p+0.01 ;  //speed
    }
    else
        p=0; //p er value reset

    glutPostRedisplay();
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);

    //glTranslatef(tx,ty,0);
    //glRectf(-25.0, -25.0, 25.0, 25.0);
    //glRectf(p-25.0, -25.0, p+25.0, 25.0);

    glBegin(GL_QUADS);
    glVertex2f(p-25,-25);
    glVertex2f(p+25,-25);
    glVertex2f(p+25,25);
    glVertex2f(p-25,25);
    glEnd();
    glPopMatrix();
    glFlush();
}
void init(void)
{
    glClearColor (1.0, 0.0, 0.0, 0.0);
    glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (600, 600);
    glutInitWindowPosition (650, 100);
    glutCreateWindow ("moving_object");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


