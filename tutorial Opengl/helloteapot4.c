#include <GL/gl.h>
#include <GL/glut.h>

void display(){//must have a void return and no parameters
	glClear(GL_COLOR_BUFFER_BIT); 


	glMatrixMode(GL_MODELVIEW);

	//SCENE ----

	//glutSolidTeapot(.5);
	glutWireTeapot(.5);

	// ---------
	glFlush();

}

void reshape(int width, int height){
	glViewport(0,0,width,height);
}

int main(int argc, char **argv){
	glutInit(&argc, argv);

	glutInitWindowSize(300,300);
	glutInitWindowPosition(100,100);
	glutInitDisplayMode(GLUT_RGB);

	glutCreateWindow("hello, teapot");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-2.0,2.0,-2.0,2.0,-2.0,2.0);
	glFrustum(-1.0,1.0,-1.0,1.0,0.5,3.0);
	//gluPerspective(100.0,1.0,0.0,100.0);

	glMatrixMode(GL_MODELVIEW);
	////glLoadIdentity();
	gluLookAt(1.0,1.0,1.0,/*eye*/
			  0.0,1.0,0.0,/*center*/
			  0.0,1.0,0.0);/*v up*/

	glutMainLoop();

	return 0;
}
