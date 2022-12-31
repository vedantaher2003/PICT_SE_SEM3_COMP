#include <GL/glut.h>
GLfloat tr_x = 0, tr_y = 0, tr_z = 0;
GLfloat rx = 0, ry = 0, rz = 0;
GLfloat sx = 1;
void init() {
glClearColor(0, 0, 0, 1);
glEnable(GL_DEPTH_TEST);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glFrustum(-1, 1, -1, 1, 2, 10);
glMatrixMode(GL_MODELVIEW);
}
void Square(GLfloat A[], GLfloat B[], GLfloat C[], GLfloat D[]) {
glBegin(GL_POLYGON);
glVertex3fv(A);
glVertex3fv(B);
glVertex3fv(C);
glVertex3fv(D);
glEnd();
}
void Cube(GLfloat V0[], GLfloat V1[], GLfloat V2[], GLfloat V3[],GLfloat V4[], GLfloat V5[], GLfloat V6[], GLfloat V7[]) {
glColor3f(1, 0, 0);
Square(V0, V1, V2, V3);
glColor3f(0, 1, 0);
Square(V4, V5, V6, V7);
glColor3f(0, 0, 1);
Square(V0, V4, V7, V3);
glColor3f(1, 1, 0);
Square(V1, V5, V6, V2);
glColor3f(1, 0, 1);
Square(V3, V2, V6, V7);
glColor3f(0, 1, 1);
Square(V0, V1, V5, V4);
}
void display() {
GLfloat V[8][3] = {
{-0.5,0.5,0.5},
{0.5,0.5,0.5},
{0.5,-0.5,0.5},
{-0.5,-0.5,0.5},
{-0.5,0.5,-0.5},
{0.5,0.5,-0.5},
{0.5,-0.5,-0.5},
{-0.5,-0.5,-0.5}
};
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
gluLookAt(1, 0, 5, 0, 0, 0, 0, 1, 0);
glTranslatef(tr_x, tr_y, tr_z);
glRotatef(rx, 1.0f, 0.0f, 0.0f);
glRotatef(ry, 0.0f, 1.0f, 0.0f);
glRotatef(rz, 0.0f, 0.0f, 1.0f);
glScalef(sx, sx, sx);
Cube(V[0], V[1],V[2], V[3], V[4], V[5], V[6], V[7]);
glutSwapBuffers();
}
void Key(unsigned char ch, int x, int y) {
switch (ch) {
case 'w' : tr_x = tr_x - 0.5; break;
case 'W': tr_x = tr_x + 0.5; break;
case 'a': tr_y = tr_y - 0.5; break;
case 'A': tr_y = tr_y + 0.5; break;
case 's': tr_z = tr_z - 0.5; break;
case 'S': tr_z = tr_z + 0.5; break;
case 'x': rx = rx - 5; break;
case 'X': rx = rx + 5; break;
case 'y': ry = ry - 5; break;
case 'Y': ry = ry + 5; break;
case 'z': rz = rz - 5; break;
case 'Z': rz = rz + 5; break;
case 'd': sx = sx - 0.1; break;
case 'D': sx = sx + 0.1; break;
}
glutPostRedisplay();
}
int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitWindowPosition(200,100);
glutInitWindowSize(600, 600);
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
glutCreateWindow("Cube");
glutDisplayFunc(display);
init();
glutKeyboardFunc(Key);
glutMainLoop();
}
