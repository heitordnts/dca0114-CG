#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

static int year = 0, day = 0, inc = 1;
static int a=0,b=0,c=0;
void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f (1.0, 1.0, 1.0);

   glPushMatrix();
	   glutWireSphere(1.0, 200, 50);   /* draw sun */
	   glRotatef ((GLfloat) year, 0.0, 1.0, 0.0);
	   glTranslatef ((GLfloat) a,(GLfloat)  b, (GLfloat) c);
	   glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
	   glutWireSphere(0.2, 100, 50);    /* draw smaller planet */
   glPopMatrix();

   glutSwapBuffers();
   
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt (5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void spin(){
	year = (year - inc ) % 360;	
	glutPostRedisplay();
}
void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
      case 'd':
         day = (day + 10) % 360;
         glutPostRedisplay();
         break;
      case 'D':
         day = (day - 10) % 360;
         glutPostRedisplay();
         break;
      case 'y':
		 inc = -1;
	     glutIdleFunc(spin);
         break;
      case 'Y':
		 inc = 1;
	     glutIdleFunc(spin);
         glutPostRedisplay();
         break;
      case 'z':
		 a+=inc;
	     glutIdleFunc(spin);
         glutPostRedisplay();
         break;
      case 'x':
		 b+=inc;
	     glutIdleFunc(spin);
         glutPostRedisplay();
         break;
      case 'c':
		 c+=inc;
	     glutIdleFunc(spin);
         glutPostRedisplay();
         break;
      default:
         break;
   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}
