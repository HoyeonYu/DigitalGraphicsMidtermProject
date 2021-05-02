#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include "gl/glut.h"
#include "Mesh.h"
#define PI 3.14159265
using namespace std;

void init();
void display();
void resize(int w, int h);
void mouseButton(int button, int state, int x, int y);
void mouseDrag(int x, int y);
void keyboard(unsigned char key, int x, int y);
void dirKeyboard(int key, int x, int y);
double radian(double angle);

Mesh meshCat, meshDeer, meshLove;
GLfloat mouseX, mouseY, scaleTotal = 1, scaleX = 1, scaleY = 1, scaleXZ = 1, scaleYZ = 1;
int angleTotal = 0, anglePart = 0, angleMesh = 0, angleStick = 0;
int vecTotalX = 0, vecTotalY = 0, vecTotalZ = 0;
int vecLeftY = 0, vecCenterX = 0, vecRightZ = 0;
int vecMesh = 0, vecStick = 0;
int posTotalX = 0, posTotalY = 0, posTotalZ = 0;
int posLeftX = 0, posCenterY = 0, posRightZ = 0;
int posCenterPartX = 0, posCenterPartZ = 0;
int posLeftDir = 1, posCenterDir = 1, posRightDir = 1, posCenterPartDir = 1;
bool isAngleStickIncrease = false;

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Midterm Project");
	init();
	meshCat.LoadMesh("cat.obj");
	meshDeer.LoadMesh("deer.obj");
	meshLove.LoadMesh("love.obj");
	glutReshapeFunc(resize);
	glutMouseFunc(mouseButton);
	//glutMotionFunc(mouseDrag);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(dirKeyboard);
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}

void init() {
	glClearColor(0, 0, 0, 0);
	glEnable(GL_DEPTH_TEST);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glRotatef(angleTotal, vecTotalX, vecTotalY, vecTotalZ);
	glTranslatef(posTotalX, posTotalY, posTotalZ);
	glScalef(scaleTotal, scaleTotal, scaleTotal);

	glPushMatrix();	// 1

	glRotatef(angleMesh, 0, vecMesh, 0);
	glTranslatef(-40, -10, 0);
	meshCat.RenderMesh(VECTOR3D(0, 1, 0),  0.04);

	glTranslatef(0, 20, 0);
	glRotatef(angleMesh, vecMesh, 0, 0);
	glTranslatef(0, -5, 0);
	meshLove.RenderMesh(VECTOR3D(1, 0, 0), 0.1);

	glTranslatef(0, 5, 0);
	glRotatef(-angleMesh, vecMesh, 0, 0);
	glTranslatef(0, -20, 0);
	glTranslatef(80, 0, 0);
	glRotatef(180, 0, 1, 0);
	meshDeer.RenderMesh(VECTOR3D(0, 0, 1), 0.02);
	glPopMatrix();	// 1

	{
		// Red: x(-), Magenta: x(+) // Green: y(-), Yellow: y(+)// Blue: z(-), Cyan: z(+) //
		glBegin(GL_LINES);
		glColor3f(1, 0, 0);
		glVertex3f(-40, 0, 0);
		glVertex3f(0, 0, 0);
		glColor3f(1, 0, 1);
		glVertex3f(0, 0, 0);
		glVertex3f(40, 0, 0);

		glColor3f(0, 1, 0);
		glVertex3f(0, -40, 0);
		glVertex3f(0, 0, 0);
		glColor3f(1, 1, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 40, 0);

		glColor3f(0, 0, 1);
		glVertex3f(0, 0, -40);
		glVertex3f(0, 0, 0);
		glColor3f(0, 1, 1);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 40);
		glEnd();
		// Red: x(-), Magenta: x(+) // Green: y(-), Yellow: y(+)// Blue: z(-), Cyan: z(+) //
	}

	glPushMatrix();	// 1-1 연
	glPushMatrix();	// 1-2 호
	glPushMatrix();	// 1-3 유

	glPopMatrix();	// 1-3 유
	{	// 유 - ㅇ
		glTranslatef(posLeftX, 0, 0);
		glPushMatrix();	// 1-3 유
		glPushMatrix();	// 1-3 유

		{
			glColor3f(1, 0, 1);
			glTranslatef(-24, 4, 0);
			glTranslatef(0.5, 2, 0);
			glRotatef(angleStick, 0, 0, vecStick);
			glTranslatef(0.5, 2, 0);
			glPushMatrix();	// 1-3 유

			glRotatef(30, 0, 0, 1);
			glScalef(1, 4, 1);
			glutSolidCube(1.0);

			glPopMatrix();	// 1-3 유

			glTranslatef(-1, 1.5, 0);
			glRotatef(angleStick, 0, 0, vecStick);
			glRotatef(20, 0, 0, 1);
			glTranslatef(0, 1.5, 0);
			glScalef(1, 3, 1);

			glColor3f(1, 1, 0);
			glutSolidCube(1.0);
			glColor3f(0, 0, 0);
			glutWireCube(1.0);
		}

		glPopMatrix();	// 1-3 유

		{
			glColor3f(1, 0, 1);
			glTranslatef(-18, 4, 0);
			glTranslatef(0.5, 2, 0);
			glRotatef(-angleStick, 0, 0, vecStick);
			glTranslatef(0.5, 2, 0);
			glPushMatrix();	// 1-3 유

			glRotatef(-30, 0, 0, 1);
			glScalef(1, 4, 1);
			glutSolidCube(1.0);

			glPopMatrix();	// 1-3 유

			glTranslatef(1, 1.5, 0);
			glRotatef(-angleStick, 0, 0, vecStick);
			glRotatef(-20, 0, 0, 1);
			glTranslatef(0, 1.5, 0);
			glScalef(1, 3, 1);

			glColor3f(1, 1, 0);
			glutSolidCube(1.0);
			glColor3f(0, 0, 0);
			glutWireCube(1.0);
		}




		glPopMatrix();	// 1-3 유


		glTranslatef(-20, 4, 0);
		glColor3f(1, 1, 1);
		glutSolidSphere(4, 30, 30);
		glColor3f(0, 0, 0);
		glutWireSphere(4, 30, 30);
	}

	{	// 유 - ㅠ - ㅡ
		glTranslatef(0, -5.5, 0);
		glRotatef(anglePart, 0, vecLeftY, 0);
		glScalef(15, 2, 2);
		glScalef(scaleX, 1, 1);
		glColor3f(1, 1, 1);
		glutSolidCube(1.0);
		glColor3f(0, 0, 0);
		glutWireCube(1.0);
	}

	glScalef((1.0 / 15), (1.0 / 2), (1.0 / 2));

	{	// 유 - ㅠ - |
		glTranslatef(-2.5, -4.5, 0);
		glScalef(2, 7, 2);
		glColor3f(1, 1, 1);
		glutSolidCube(1.0);
		glColor3f(0, 0, 0);
		glutWireCube(1.0);
	}

	{	// 유 - ㅠ - |
		glTranslatef(2.5, 0, 0);
		glColor3f(1, 1, 1);
		glutSolidCube(1.0);
		glColor3f(0, 0, 0);
		glutWireCube(1.0);
	}

	glPopMatrix();	// 1-2 호
	{	// 호 - ㅎ - ㅇ
		glTranslatef(0, posCenterY, 0);
		glTranslatef(0, -1, 0);
		glScalef(1, scaleY, 1);
		glColor3f(1, 1, 1);
		glutSolidCone(3.5, 5, 30, 30);
		glColor3f(0, 0, 0);
		glutWireCone(3.5, 5, 30, 30);
	}

	glScalef(1, 1.0 / scaleY, 1);

	glPushMatrix();	// 1-2-1 ㅎ

	glScalef(1, scaleY, 1);
		{	// 호 - ㅎ - -
			glColor3f(1, 1, 1);
			glTranslatef(-0.3, 7, 0);
			glScalef(4.5, 1.5, 2);
			glutSolidTetrahedron();
			glColor3f(0, 0, 0);
			glutWireTetrahedron();
		}

		glScalef(1 / 4.5, 1 / 1.5, 1.0 / 2);

		{	// 호 - ㅎ - ㅡ
			glTranslatef(0, -2, 0);
			glScalef(10, 1.5, 2);
			glColor3f(1, 1, 1);
			glutSolidCube(1.0);
			glColor3f(0, 0, 0);
			glutWireCube(1.0);
		}
	
		glPopMatrix();	// 1-2-1 ㅎ 
		{	// 호 - ㅗ - | 
			glTranslatef(posCenterPartX, 0, posCenterPartZ);
			glTranslatef(0, -5.5 * scaleY, 0);
			glScalef(2, 3.5, 2);
			glRotatef(anglePart, vecCenterX, 0, 0);
			glColor3f(1, 1, 1);
			glutSolidCube(1.0);
			glColor3f(0, 0, 0);
			glutWireCube(1.0);
		}

		glScalef(1.0 / 2, 1 / 3.5, 1.0 / 2);

		{	// 호 - ㅗ - ㅡ
			glTranslatef(0, - 2, 0);
			glScalef(14, 2, 2);
			glColor3f(1, 1, 1);
			glutSolidCube(1.0);
			glColor3f(0, 0, 0);
			glutWireCube(1.0);
		}

	glPopMatrix();	// 1-1
	glPushMatrix();	// 1-1-1

	{	// 연 - ㅇ
		glTranslatef(0, 0, posRightZ);
		glTranslatef(18, 2.5, 0);
		glColor3f(1, 1, 1);
		glutSolidTorus(1, 2.5, 30, 30);
		glColor3f(0, 0, 0);
		glutWireTorus(1, 2.5, 30, 30);
	}

	glPushMatrix();	// 1-1-1

	{	// 연 - ㅕ - -
		glTranslatef(4.5, 1.5 * scaleYZ, 0);
		glScalef(4, 2, 1.5);
		glScalef(1, scaleYZ, scaleYZ);
		glColor3f(1, 1, 1);
		glutSolidCube(1.0);
		glColor3f(0, 0, 0);
		glutWireCube(1.0);
	}

	{	// 연 - ㅕ - -
		glTranslatef(0, -1.5, 0);
		glScalef(1, 1, 1);
		glColor3f(1, 1, 1);
		glutSolidCube(1.0);
		glColor3f(0, 0, 0);
		glutWireCube(1.0);
	}

	glScalef(1.0 / 4, 1.0 / 2, 1.0 / 1.5);

	{	// 연 - ㅕ - |
		glTranslatef(2, 0.5, 0);
		glScalef(2, 11, 2);
		glScalef(1, scaleYZ, scaleYZ);
		glColor3f(1, 1, 1);
		glutSolidCube(1.0);
		glColor3f(0, 0, 0);
		glutWireCube(1.0);
	}

	glPopMatrix();	// 1-1-1
	{	// 연 - ㄴ - |
		glTranslatef(0, -9.5, 0);
		glScalef(2, 5, 2);
		glScalef(scaleXZ, 1, scaleXZ);
		glRotatef(anglePart, 0, 0, vecRightZ);
		glColor3f(1, 1, 1);
		glutSolidCube(1.0);
		glColor3f(0, 0, 0);
		glutWireCube(1.0);
	}

	glScalef(1.0 / 2, 1.0 / 5, 1.0 / 2);

	{	// 연 - ㄴ - -
		glTranslatef(4, -1.5, 0);
		glScalef(8, 2, 2);
		glColor3f(1, 1, 1);
		glutSolidCube(1.0);
		glColor3f(0, 0, 0);
		glutWireCube(1.0);
	}

	
	glPopMatrix();	// 1-1-1

	glFlush();
	glutSwapBuffers();
}

void resize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-60, 60, -60, 60, -60, 60);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void mouseButton(int button, int state, int x, int y) {
	angleTotal = 0;
	vecTotalX = vecTotalY = vecTotalZ = 0;
	posTotalX = posTotalY = posTotalZ = 0;
	scaleTotal = 1;

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		scaleTotal *= 1.2;
		scaleX = scaleY = scaleXZ = scaleYZ *= 1.6;
		glutPostRedisplay();
	}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		scaleTotal *= (1 / 1.2);
		scaleX = scaleY = scaleXZ = scaleYZ *= (1 / 1.6);
		glutPostRedisplay();
	}

}

void mouseDrag(int x, int y) {
	mouseX = x;
	mouseY = y;

	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	angleTotal = 0;
	vecTotalX = vecTotalY = vecTotalZ = 0;
	posTotalX = posTotalY = posTotalZ = 0;
	scaleTotal = 1;

	if (key == 'a') {
		angleTotal = 5;
		anglePart += 5;
		vecTotalX = 1;
		vecLeftY = 1;
		vecCenterX = 1;
		vecRightZ = 1;
	}

	if (key == 'A') {
		angleTotal = 5;
		anglePart -= 5;
		vecTotalX = -1;
		vecLeftY = 1;
		vecCenterX = 1;
		vecRightZ = 1;
	}

	if (key == 's') {
		angleTotal = 5;
		anglePart += 5;
		vecTotalY = 1;
		vecLeftY = 1;
		vecCenterX = 1;
		vecRightZ = 1;
	}

	if (key == 'S') {
		angleTotal = 5;
		anglePart -= 5;
		vecTotalY = -1;
		vecLeftY = 1;
		vecCenterX = 1;
		vecRightZ = 1;
	}

	if (key == 'd') {
		angleTotal = 5;
		anglePart += 5;
		vecTotalZ = 1;
		vecLeftY = 1;
		vecCenterX = 1;
		vecRightZ = 1;
	}

	if (key == 'D') {
		angleTotal = 5;
		anglePart -= 5;
		vecTotalZ = -1;
		vecLeftY = 1;
		vecCenterX = 1;
		vecRightZ = 1;
	}
	
	glutPostRedisplay();
}

void dirKeyboard(int key, int x, int y) {
	angleTotal = 0;
	vecTotalX = vecTotalY = vecTotalZ = 0;
	posTotalX = posTotalY = posTotalZ = 0;
	scaleTotal = 1;

	if (key == GLUT_KEY_LEFT) {
		posTotalX = -1;
		posTotalY = -1;

		posLeftX = 5 * posLeftDir;
		posLeftDir *= -1;

		posCenterY = 10 * posCenterDir;
		posCenterDir *= -1;

		posRightZ = 15 * posRightDir;
		posRightDir *= -1;

		posCenterPartX = 10 * posCenterPartDir;
		posCenterPartZ = 10 * posCenterPartDir;
		posCenterPartDir *= -1;
	}

	if (key == GLUT_KEY_RIGHT) {
		posTotalX = 1;
		posTotalY = 1;

		posLeftX = 5 * posLeftDir;
		posLeftDir *= -1;

		posCenterY = 10 * posCenterDir;
		posCenterDir *= -1;

		posRightZ = 15 * posRightDir;
		posRightDir *= -1;

		posCenterPartX = 10 * posCenterPartDir;
		posCenterPartZ = 10 * posCenterPartDir;
		posCenterPartDir *= -1;
	}

	if (key == GLUT_KEY_UP) {
		angleMesh += 5;

		if (isAngleStickIncrease) {
			angleStick += 5;

			if (angleStick > 20) {
				isAngleStickIncrease = false;
			}
		}

		else {
			angleStick -= 5;

			if (angleStick < -20) {
				isAngleStickIncrease = true;
			}
		}

		vecMesh = 1;
		vecStick = 1;
	}

	if (key == GLUT_KEY_DOWN) {
		angleMesh -= 5;

		if (isAngleStickIncrease) {
			angleStick += 5;

			if (angleStick > 20) {
				isAngleStickIncrease = false;
			}
		}

		else {
			angleStick -= 5;

			if (angleStick < -20) {
				isAngleStickIncrease = true;
			}
		}
		vecMesh = 1;
		vecStick = 1;
	}

	if (key == GLUT_KEY_HOME) {
		anglePart = angleMesh = angleStick = 0;
		posLeftX = posCenterY = posRightZ = 0;
		posCenterPartX = posCenterPartZ = 0;
		scaleX = scaleY = scaleXZ = scaleYZ = 1; 
		posLeftDir = posCenterDir = posRightDir = posCenterPartDir = 1;
		vecMesh = vecStick = 0;
	}

	glutPostRedisplay();
}

double radian(double angle) {
	return (180 / PI) * angle;
}