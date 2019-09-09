#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>


double ex=30,ey=30,ez=30;

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


void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		

    //gluLookAt(ex,ey,ez,0.0,0.0,0.0,0.0,1.0,0.0);
	glPushMatrix();
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
    	gluLookAt(ex,ey,ez,0.0,0.0,0.0,0.0,1.0,0.0);
		flat_plane();
	glPopMatrix();

	glFlush();
}

void reshape(int width, int height){
	glViewport(0,0,width,height);
}

void mouse(int button,int state,int x, int y){
	printf("x = %d\ny = %d\n",x,y);
	printf("ex = %f\ney = %f\nez = %f\n",ex,ey,ez);
	ex+=1;
	ey+=1;
	ez+=1;
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100,40);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	
	glutCreateWindow("nav");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);

	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	gluPerspective(45.0, 1.0, 0.5, 300.0);

	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(30.0,30.0,30.0,0.0,0.0,0.0,0.0,1.0,0.0);

	glutMainLoop();
	return 0;
}
