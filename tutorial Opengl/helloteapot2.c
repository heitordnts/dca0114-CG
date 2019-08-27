#include <GL/gl.h>
#include <GL/glut.h>

void display(){//must have a void return and no parameters
	glClear(GL_COLOR_BUFFER_BIT); 
	//SCENE ----

	glutSolidTeapot(.5);
	//glutWireTeapot(.5);

	// ---------
	glFlush();

}

void reshape(int width, int height){
	//glViewport(0,0,width,height);
}

int main(int argc, char **argv){
	glutInit(&argc, argv);

	glutInitWindowSize(300,300);
	glutInitWindowPosition(100,100);
	glutInitDisplayMode(GLUT_RGB);

	glutCreateWindow("hello, teapot");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	//glViewport(0,0,100,100);
	glutMainLoop();

	return 0;
}
