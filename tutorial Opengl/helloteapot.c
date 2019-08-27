#include <GL/gl.h>
#include <GL/glut.h>

void display(){//must have a void return and no parameters
	glClear(GL_COLOR_BUFFER_BIT); 
	//SCENE ----

	//glutSolidTeapot(.2);
	glutWireTeapot(.5);

	// ---------
	glFlush();

}

int main(int argc, char **argv){
	glutInit(&argc, argv);

	glutInitWindowSize(300,300);
	glutInitWindowPosition(100,100);
	glutInitDisplayMode(GLUT_RGB);

	glutCreateWindow("hello, teapot");
	glutDisplayFunc(display);

	glutMainLoop();

	return 0;
}
