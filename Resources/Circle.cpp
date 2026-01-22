/*
 * GLUT Circle Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include <GL/glut.h>  // Include GLUT header here
#include <stdlib.h>
#include <math.h>


//float p=-2.3;
void DrawCircle(float cx, float cy, float rx,float ry, int num_segments)
{
	glBegin(GL_TRIANGLE_FAN);
	for(int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

		float x = rx * cosf(theta);         //calculate the x component
		float y = ry * sinf(theta);         //calculate the y component

		glVertex2f(x + cx, y + cy);         //output vertex

	}
	glEnd();
}
void init(void)
{
	glClearColor (0.0, 0.6, 0.2, 0.0);      // green color
	 glOrtho(-500.0, 500.0, -500.0, 500.0, -1.0, 1.0);
}

void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();

	glColor3f(0.7, 0.2, 0.3);

    DrawCircle(0,0,200,200,100);
    glPopMatrix();

	glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (800, 800);
	glutInitWindowPosition (500, 100);
	glutCreateWindow ("Circle");
	init();
    glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}


// THETA = Q_start + (Q_end - Q_start) * (i/N)
//       = 0 + (2pie - 0) * (i/N)
//       = 2pie * (i/N)


