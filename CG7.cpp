#include<GL/glut.h>
#include<cmath>
#define GLUT_DISABLE_ATEXIT_HACK

float x_position = 0.0;
float y_position = 0.0;
int flag = 1;
void init() {
	glClearColor(0, 0, 0, 1);//takes 4 params- r,g,b and alpha(0 = obj is transparent;1 = opaque)
	glMatrixMode(GL_PROJECTION);//projecting object on screen
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);//orthogonal view for window(set left,right,top,bottom vals)
}
void animation() {
	glutPostRedisplay();//erase previous, draw new
	switch (flag) {
	case 1:
		if (x_position < 250) {
			x_position += 0.05;
			y_position = 100.0 * sin(2.2*x_position *(6.284/360.0));
		}
		else {
			flag = -1;
		}
		break;
	case -1:
		if (x_position > 0) {
			x_position -= 0.05;
			y_position = 100.0 * sin(2.2*x_position *(6.284/360.0));
		}
		else {
		flag = 1;
		}
		break;
}
}
void circle(){
	glClear(GL_COLOR_BUFFER_BIT);//clear disp window
	glLoadIdentity();
	glTranslatef(x_position,y_position,0);
	glTranslatef(0,250,0);
	int i;
	int triangleAmount = 20; //# of triangles used to draw circle
	float radius = 10.0;
	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * 3.142;
	
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x_position, y_position); // center of circle
		for(i = 0; i <= triangleAmount;i++) { 
			glVertex2f(
		            x_position + (radius * cos(i *  twicePi / triangleAmount)), 
			    y_position + (radius * sin(i * twicePi / triangleAmount))
			);
		}
		
	glEnd();
	glFlush();
}
void reshape(int w, int h) {
	glViewport(0, 0, w, h);//use whole window
	glMatrixMode(GL_PROJECTION);//projection
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);//position of window
	glutInitWindowSize(500, 500);//set height and width of window
	glutCreateWindow("Window 1");//create window
	init();
	glutDisplayFunc(circle);//send graphics to disp window
	glutReshapeFunc(reshape);//setting viewport
	glutIdleFunc(animation);
	glutMainLoop();//displays everything and wait
	return 0;
}

