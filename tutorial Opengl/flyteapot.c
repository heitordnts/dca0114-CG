#include <GL/gl.h>
#include <GL/glut.h>

double xd, yd, zd;           // current teapot position (initialized in main)
double ex, ey, ez;           // current teapot position (initialized in main)

void display () {

    /* clear window */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* future matrix manipulations should affect the modelview matrix */
    glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
    //gluLookAt(ex,ey,ez,0.0,0.0,0.0,0.0,1.0,0.0);
    //gluLookAt(0.0,0.0,0.0,ex,ey,ez,0.0,1.0,0.0);
    //gluLookAt(0.0,0.0,0.0,0.0,0.0,0.0,ex,ey,ez);

    /* draw scene */
    glPushMatrix();
    glTranslatef(xd,yd,zd);
    glutWireTeapot(.5);
    glPopMatrix();

    /* flush drawing routines to the window */
    glFlush();
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
			xd+=0.1;
			break;
		case 'd':
			zd += .1;
			break;
		case 's':
			xd-=0.1;
			break;
		case 'a':
			zd -= .1;
			break;
		case 'q':
			yd-=0.1;
			break;
		case 'e':
			yd += .1;
			break;
		case 'W':
			ex+=0.1;
			break;
		case 'D':
			ez += .1;
			break;
		case 'S':
			ex-=0.1;
			break;
		case 'A':
			ez -= .1;
			break;
		case 'Q':
			ey-=0.1;
			break;
		case 'E':
			ey += .1;
			break;
		default:
			break;
	}
	printf("%lf\n",xd);
	glutPostRedisplay();
}

int main ( int argc, char * argv[] ) {

    /* initialize GLUT, using any commandline parameters passed to the 
       program */
    glutInit(&argc,argv);

    /* setup the size, position, and display mode for new windows */
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);

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
    gluLookAt(1.0,0.0,0.0,
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
