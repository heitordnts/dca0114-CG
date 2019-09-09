#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

double xd, yd, zd;           // current teapot position (initialized in main)
double ex, ey, ez;           // current teapot position (initialized in main)

double INC = 0.2;
double ANG = 1,ANGZ=1;

double ix,iy,iz;

void dir(){
	double mod = sqrt(xd*xd + yd*yd + zd*zd);
	if (mod == 0) return;

	ix = -xd/mod;
	iy = -yd/mod;
	iz = -zd/mod;

	printf("ix=%lf\niy=%lf\niz=%lf\nmod=%lf\n", ix,iy,iz,mod);

}


void flat_plane(){
	glBegin(GL_LINES);
	for(int i=-10;i<= 10;i++){
	glVertex3d(i,0,-10);
	glVertex3d(i,0.0,10.0);
	}
	glEnd();	

	glBegin(GL_LINES);
	for(int i=-10;i<= 10;i++){
	glVertex3d(-10,0,i);
	glVertex3d(10,0.0,i);
	}
	glEnd();	
}

void init(void) 
{
   GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat mat_shininess[] = { 50.0 };
   GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_SMOOTH);

   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_DEPTH_TEST);
}

void display () {

    /* clear window */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* future matrix manipulations should affect the modelview matrix */
    glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
    //gluLookAt(ex,ey,ez,0.0,0.0,0.0,0.0,1.0,0.0);
    //gluLookAt(0.0,0.0,0.0,ex,ey,ez,0.0,1.0,0.0);
    //gluLookAt(0.0,0.0,0.0,0.0,0.0,0.0,ex,ey,ez);
	glColor3f (0.0, 0.0, 1.0);
	

    glPushMatrix();

    /* draw scene */
	//glRotatef(ex,0.0,1.0,0.0);
	//glRotatef(ez,1.0,0.0,0.0);
	//glTranslatef(xd,yd,zd);
    gluLookAt(xd,yd,zd
				,0,0,0,
				0,1,0);
	//glTranslatef(0,0,0);

	flat_plane();
/*
    glPushMatrix();
		glTranslatef(0,-0.05,0);
		glScalef(1,0.01,1);
		glutSolidCube(5.0);
    glPopMatrix();
*/

	glColor3f(0,1,0);

    glPushMatrix();
		glTranslatef(0.5,0,0);
		glScalef(1,0.05,0.05);
		glutSolidCube(1.0);
		//glutWireCube(1.0);
    glPopMatrix();

    glPushMatrix();
		glTranslatef(0,0.5,0);
		glScalef(0.05,1,0.05);
		glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
		glTranslatef(0,0,0.5);
		glScalef(0.05,0.05,1);
		glutSolidCube(1.0);
    glPopMatrix();
/*
	glColor3f (1.0, 0.0, 1.0);
    glPushMatrix();
		//glRotatef(ex,0.0,1.0,0.0);
		glutSolidTeapot(.5);
    glPopMatrix();
*/

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
	dir();
	switch (key) {
		case 'w':
			zd+=iz;
			yd+=iy;
			xd+=ix;
			break;
		case 's':
			zd-=iz;
			yd-=iy;
			xd-=ix;
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
	printf("%f\n", xd);
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
	init();
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
    gluPerspective(45.0,1.0,0.5,300.0);

    /* define the viewing transformation */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0,0.0,10.0,
				0.0,0.0,0.0,
				0.0,1.0,0.0);

    /* initialize state variables (teapot position) */
    xd = 0;
    yd = 0;
    zd = 20;

    ex = 0;
    ey = 0;
    ez = 5;

    ix = 0;
    iy = 0;
    iz = 5;

    /* tell GLUT to wait for events */
    glutMainLoop();
}
