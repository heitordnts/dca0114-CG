#include <GL/gl.h>
#include <GL/glut.h>

double xd, yd, zd;           // current teapot position (initialized in main)
double ex, ey, ez;           // current teapot position (initialized in main)

double INC = 0.1;
double ANG = 1,ANGZ=1;
void display () {

    /* clear window */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* future matrix manipulations should affect the modelview matrix */
    glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
    //gluLookAt(ex,ey,ez,0.0,0.0,0.0,0.0,1.0,0.0);
    //gluLookAt(0.0,0.0,0.0,ex,ey,ez,0.0,1.0,0.0);
    //gluLookAt(0.0,0.0,0.0,0.0,0.0,0.0,ex,ey,ez);

	glColor3f (1.0, 1.0, 1.0);
	
    glPushMatrix();

	glRotatef(ex,0.0,1.0,0.0);
	glRotatef(ez,1.0,0.0,0.0);
	glTranslatef(xd,yd,zd);
    /* draw scene */
    glPushMatrix();
		glTranslatef(0,-1,0);
		glScalef(1,0.01,1);
		glutWireCube(5.0);
    glPopMatrix();

    glPushMatrix();
		glTranslatef(0.5,0,0);
		glScalef(1,0.05,0.05);
		glutWireCube(1.0);
    glPopMatrix();

    glPushMatrix();
		glTranslatef(0,0.5,0);
		glScalef(0.05,1,0.05);
		glutWireCube(1.0);
    glPopMatrix();

    glPushMatrix();
		glTranslatef(0,0,0.5);
		glScalef(0.05,0.05,1);
		glutWireCube(1.0);
    glPopMatrix();

	glColor3f (1.0, 0.0, 1.0);
    glPushMatrix();
		//glRotatef(ex,0.0,1.0,0.0);
		glutSolidTeapot(.5);
    glPopMatrix();

    glPopMatrix();
    /* flush drawing routines to the window */
    glFlush();
	glutSwapBuffers();
}

void animate () {

    /* update state variables */
    xd += .001;
    yd += .001;
    zd -= .001;

    /* refresh screen */
    glutPostRedisplay();
}

void reshape ( int width, int height ) {

    /* define the viewport transformation */
    glViewport(0,0,width,height);

}
void keyboard (unsigned char key, int x, int y)
{
	switch (key) {
		case 'w':
			zd+=INC;
			break;
		case 's':
			zd-=INC;
			break;
		case 'a':
			xd +=INC;
			break;
		case 'd':
			xd -=INC;
			break;
		case 'q':
			yd-=INC;
			break;
		case 'e':
			yd +=INC;
			break;
		case 'j':
			ex+=ANG;
			break;
		case 'l':
			ex-= ANG;
			break;

		case 'k':
			ez +=ANGZ;
			break;
		case 'i':
			ez -=ANGZ;
			break;
		case 'Q':
			ey-=INC;
			break;
		case 'E':
			ey += INC;
			break;
		default:
			break;
	}
	glutPostRedisplay();
}

int main ( int argc, char * argv[] ) {

    /* initialize GLUT, using any commandline parameters passed to the 
       program */
    glutInit(&argc,argv);

    /* setup the size, position, and display mode for new windows */
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    /* create and set up a window */
    glutCreateWindow("flying teapot");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

    //glutIdleFunc(animate);

    /* depth-buffering */
    glEnable(GL_DEPTH_TEST);

    /* define the projection transformation */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	//glOrtho(-2.0,2.0,-2.0,2.0,-2.0,2.0);
    //glFrustum(-1.0,1.0,-1.0,1.0,.5,3.0);
    gluPerspective(70.0,1.0,0.5,300.0);

    /* define the viewing transformation */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0,0.0,3.0,
				0.0,0.0,0.0,
				0.0,1.0,0.0);

    /* initialize state variables (teapot position) */
    xd = 0;
    yd = 0;
    zd = 0;

    ex = 0;
    ey = 0;
    ez = 5;

    /* tell GLUT to wait for events */
    glutMainLoop();
}
