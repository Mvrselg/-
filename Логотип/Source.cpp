#include <gl\glut.h>
#include <math.h>
#include <Windows.h>
GLfloat angle = 0, angle1 = 0;
GLfloat scal = 1.0, rot1 = 1.0, rot = 1.0;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(100, 1, 1, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void myDisplay()
{
	glPushMatrix(); //��������� VM = 1
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	GLfloat myDiffuse[] = { 0.50754 * rot1, 0.50754, 0.50754, 1 };//����������� ���������� ���������
	glMaterialfv(GL_FRONT, GL_DIFFUSE, myDiffuse);
	GLfloat myShininess[] = { 51.2 };//������� ����������� ���������
	glMaterialfv(GL_FRONT, GL_SHININESS, myShininess);
	GLfloat myAmbient[] = { 0.19225 * rot1, 0.19225, 0.19225, 1 };//����������� �������� ���������
	glMaterialfv(GL_FRONT, GL_SHININESS, myAmbient);
	GLfloat mySpecular[] = { 0.508273 * rot1, 0.508273, 0.508273, 1 };//����������� ����������� ���������
	glMaterialfv(GL_FRONT, GL_SHININESS, mySpecular);
	GLfloat myLightPosition[] = { 1.0, 2.0, 2.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition);
	glEnable(GL_LIGHTING); // ��������� ������� ������������
	glEnable(GL_LIGHT0); // �������� ���� ���������� ��������
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(1, 0, 3, 1, 0, 0, 0, 1, 0);
	glPushMatrix();
	glRotatef(angle1 * rot, 0, 1, 0); // ������� �������� �����
	glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition);
	glPopMatrix();
	glRotatef(angle, 1, 0, 0); // VM=Fwe*R
	glRotatef(angle, 0, 1, 0); // VM=Fwe*R*R
    glRotatef(angle, 0, 0, 1); // VM=Fwe*R*R*R
	glScalef(scal * 1, 1, 1);
	glutSolidTorus(0.05, 0.8, 100, 100);
	glBegin(GL_POLYGON);//����� 1
	glNormal3f(0.577, 0.577, 0.577);
	glVertex3f(-0.05, 0, 0.05);
	glVertex3f(0, 0, 0.05);
	glVertex3f(-0.3, 0.7, 0.05);
	glVertex3f(-0.35, 0.65, 0.05);
	glEnd();
	glBegin(GL_POLYGON);//����� 2
	glNormal3f(0.577, 0.577, 0.577);
	glVertex3f(-0.05, 0.05, 0.05);
	glVertex3f(-0.05, 0, 0.05);
	glVertex3f(0.05, 0.05, 0.05);
	glVertex3f(0.05, 0, 0.05);
	glEnd();
	glBegin(GL_POLYGON);//����� 3
	glNormal3f(0.577, 0.577, 0.577);
	glVertex3f(0.05, 0, 0.05);
	glVertex3f(0, 0, 0.05);
	glVertex3f(0.3, 0.7, 0.05);
	glVertex3f(0.35, 0.65, 0.05);
	glEnd();
	glBegin(GL_POLYGON);//����� 4
	glNormal3f(0.577, 0.577, 0.577);
	glVertex3f(-0.35, -0.45, 0.05);
	glVertex3f(-0.3, -0.4, 0.05);
	glVertex3f(-0.6, 0.4, 0.05);
	glVertex3f(-0.65, 0.31, 0.05);
	glEnd();
	glBegin(GL_POLYGON);//����� 5
	glNormal3f(0.577, 0.577, 0.577);
	glVertex3f(-0.35, -0.45, 0.05);
	glVertex3f(-0.35, -0.4, 0.05);
	glVertex3f(-0.05, -0.1, 0.05);
	glVertex3f(-0.05, -0.15, 0.05);
	glEnd();
	glBegin(GL_POLYGON);//����� 6
	glNormal3f(0.577, 0.577, 0.577);
	glVertex3f(-0.05, -0.15, 0.05);
	glVertex3f(-0.05, -0.1, 0.05);
	glVertex3f(0.05, -0.1, 0.05);
	glVertex3f(0.05, -0.15, 0.05);
	glEnd();
	glBegin(GL_POLYGON);//����� 7
	glNormal3f(0.577, 0.577, 0.577);
	glVertex3f(0.35, -0.45, 0.05);
	glVertex3f(0.35, -0.4, 0.05);
	glVertex3f(0.05, -0.1, 0.05);
	glVertex3f(0.05, -0.15, 0.05);
	glEnd();
	glBegin(GL_POLYGON);//����� 8
	glNormal3f(0.577, 0.577, 0.577);
	glVertex3f(0.35, -0.45, 0.05);
	glVertex3f(0.3, -0.4, 0.05);
	glVertex3f(0.6, 0.45, 0.05);
	glVertex3f(0.65, 0.4, 0.05);
	glEnd();
	glBegin(GL_POLYGON);//�������� 1
	glNormal3f(0.577, 0.577, 0.577);
	glVertex3f(-0.05, 0, -0.05);
	glVertex3f(0, 0, -0.05);
	glVertex3f(-0.3, 0.7, -0.05);
	glVertex3f(-0.35, 0.65, -0.05);
	glEnd();
	glBegin(GL_POLYGON);//�������� 2
	glNormal3f(0.577, 0.577, 0.577);
	glVertex3f(-0.05, 0.05, -0.05);
	glVertex3f(-0.05, 0, -0.05);
	glVertex3f(0.05, 0.05, -0.05);
	glVertex3f(0.05, 0, -0.05);
	glEnd();
	glBegin(GL_POLYGON);//�������� 3
	glNormal3f(0.577, 0.577, 0.577);
	glVertex3f(0.05, 0, -0.05);
	glVertex3f(0, 0, -0.05);
	glVertex3f(0.3, 0.7, -0.05);
	glVertex3f(0.35, 0.65, -0.05);
	glEnd();
	glBegin(GL_POLYGON);//�������� 4
	glNormal3f(0.577, 0.577, 0.577);
	glVertex3f(-0.35, -0.45, -0.05);
	glVertex3f(-0.3, -0.4, -0.05);
	glVertex3f(-0.6, 0.4, -0.05);
	glVertex3f(-0.65, 0.31, -0.05);
	glEnd();
	glBegin(GL_POLYGON);//�������� 5
	glNormal3f(0.577, 0.577, 0.577);
	glVertex3f(-0.35, -0.45, -0.05);
	glVertex3f(-0.35, -0.4, -0.05);
	glVertex3f(-0.05, -0.1, -0.05);
	glVertex3f(-0.05, -0.15, -0.05);
	glEnd();
	glBegin(GL_POLYGON);//�������� 6
	glNormal3f(0.577, 0.577, 0.577);
	glVertex3f(-0.05, -0.15, -0.05);
	glVertex3f(-0.05, -0.1, -0.05);
	glVertex3f(0.05, -0.1, -0.05);
	glVertex3f(0.05, -0.15, -0.05);
	glEnd();
	glBegin(GL_POLYGON);//�������� 7
	glNormal3f(0.577, 0.577, 0.577);
	glVertex3f(0.35, -0.45, -0.05);
	glVertex3f(0.35, -0.4, -0.05);
	glVertex3f(0.05, -0.1, -0.05);
	glVertex3f(0.05, -0.15, -0.05);
	glEnd();
	glBegin(GL_POLYGON);//�������� 8
	glNormal3f(0.577, 0.577, 0.577);
	glVertex3f(0.35, -0.45, -0.05);
	glVertex3f(0.3, -0.4, -0.05);
	glVertex3f(0.6, 0.45, -0.05);
	glVertex3f(0.65, 0.4, -0.05);
	glEnd();
	glBegin(GL_POLYGON);//��������� 1
	glNormal3f(0.577, 0.577, 0.577);
	glVertex3f(-0.35, 0.65, 0.05);
	glVertex3f(-0.35, 0.65, -0.05);
	glVertex3f(-0.05, 0, -0.05);
	glVertex3f(-0.05, 0, 0.05);
	glEnd();
	glBegin(GL_POLYGON);//��������� 2
	glNormal3f(0.577, 0.577, 0.577);
	glVertex3f(-0.3, 0.7, 0.05);
	glVertex3f(-0.3, 0.7, -0.05);
	glVertex3f(-0.35, 0.65, -0.05);
	glVertex3f(-0.35, 0.65, 0.05);
	glEnd();
	glBegin(GL_POLYGON);//��������� 3
	glNormal3f(0.577, 0.577, 0.577);
	glVertex3f(-0.3, 0.7, 0.05);
	glVertex3f(-0.3, 0.7, -0.05);
	glVertex3f(0, 0, -0.05);
	glVertex3f(0, 0, 0.05);
	glEnd();
	glBegin(GL_POLYGON);//��������� 4
	glNormal3f(0.577, 0.577, 0.577);
	glVertex3f(0.35, 0.65, 0.05);
	glVertex3f(0.35, 0.65, -0.05);
	glVertex3f(0.05, 0, -0.05);
	glVertex3f(0.05, 0, 0.05);
	glEnd();
	glBegin(GL_POLYGON);//��������� 5
	glNormal3f(0.577, 0.577, 0.577);
	glVertex3f(0.3, 0.7, 0.05);
	glVertex3f(0.3, 0.7, -0.05);
	glVertex3f(0.35, 0.65, -0.05);
	glVertex3f(0.35, 0.65, 0.05);
	glEnd();
	glBegin(GL_POLYGON);//��������� 6
	glNormal3f(0.577, 0.577, 0.577);
	glVertex3f(0.3, 0.7, 0.05);
	glVertex3f(0.3, 0.7, -0.05);
	glVertex3f(0, 0, -0.05);
	glVertex3f(0, 0, 0.05);
	glEnd();
	glBegin(GL_POLYGON);//��������� 7
	glNormal3f(0.577, 0.577, 0.577);
	glVertex3f(-0.65, 0.31, 0.05);
	glVertex3f(-0.65, 0.31, -0.05);
	glVertex3f(-0.35, -0.45, -0.05);
	glVertex3f(-0.35, -0.45, 0.05);
	glEnd();
	glBegin(GL_POLYGON);//��������� 8
	glNormal3f(0.577, 0.577, 0.577);
	glVertex3f(-0.6, 0.4, 0.05);
	glVertex3f(-0.6, 0.4, -0.05);
	glVertex3f(-0.3, -0.4, -0.05);
	glVertex3f(-0.3, -0.4, 0.05);
	glEnd();
	glBegin(GL_POLYGON);//��������� 8
	glNormal3f(0.577, 0.577, 0.577);
	glVertex3f(-0.65, 0.31, 0.05);
	glVertex3f(-0.65, 0.31, -0.05);
	glVertex3f(-0.6, 0.4, -0.05);
	glVertex3f(-0.6, 0.4, 0.05);
	glEnd();
	glBegin(GL_POLYGON);//��������� 9
	glNormal3f(0.577, 0.577, 0.577);
	glVertex3f(-0.35, -0.45, 0.05);
	glVertex3f(-0.35, -0.45, -0.05);
	glVertex3f(-0.05, -0.1, -0.05);
	glVertex3f(-0.05, -0.1, 0.05);
	glEnd();
	glBegin(GL_POLYGON);//��������� 10
	glNormal3f(0.577, 0.577, 0.577);
	glVertex3f(-0.35, -0.45, 0.05);
	glVertex3f(-0.35, -0.45, -0.05);
	glVertex3f(-0.05, -0.15, 0.05);
	glVertex3f(-0.05, -0.15, -0.05);
	glEnd();
	glBegin(GL_POLYGON);//��������� 11
	glNormal3f(0.577, 0.577, 0.577);
	glVertex3f(-0.05, -0.15, 0.05);
	glVertex3f(-0.05, -0.15, -0.05);
	glVertex3f(0.05, -0.15, -0.05);
	glVertex3f(0.05, -0.15, 0.05);
	glEnd();
	glBegin(GL_POLYGON);//��������� 12
	glNormal3f(0.577, 0.577, 0.577);
	glVertex3f(-0.05, -0.1, 0.05);
	glVertex3f(-0.05, -0.1, -0.05);
	glVertex3f(0.05, -0.15, -0.05);
	glVertex3f(0.05, -0.15, 0.05);
	glEnd();
	glBegin(GL_POLYGON);//��������� 13
	glNormal3f(0.577, 0.577, 0.577);
	glVertex3f(0.35, -0.45, 0.05);
	glVertex3f(0.35, -0.45, -0.05);
	glVertex3f(0.05, -0.1, -0.05);
	glVertex3f(0.05, -0.1, 0.05);
	glEnd();
	glBegin(GL_POLYGON);//��������� 14
	glNormal3f(0.577, 0.577, 0.577);
	glVertex3f(0.35, -0.4, 0.05);
	glVertex3f(0.35, -0.4, -0.05);
	glVertex3f(0.05, -0.15, -0.05);
	glVertex3f(0.05, -0.15, 0.05);
	glEnd();
	glBegin(GL_POLYGON);//��������� 15
	glNormal3f(0.577, 0.577, 0.577);
	glVertex3f(0.35, -0.45, 0.05);
	glVertex3f(0.35, -0.45, -0.05);
	glVertex3f(0.6, 0.45, -0.05);
	glVertex3f(0.6, 0.45, 0.05);
	glEnd();
	glBegin(GL_POLYGON);//��������� 16
	glNormal3f(0.577, 0.577, 0.577);
	glVertex3f(0.3, -0.4, 0.05);
	glVertex3f(0.3, -0.4, -0.05);
	glVertex3f(0.65, 0.4, -0.05);
	glVertex3f(0.65, 0.4, 0.05);
	glEnd();
	glBegin(GL_POLYGON);//��������� 17
	glNormal3f(0.577, 0.577, 0.577);
	glVertex3f(0.6, 0.45, 0.05);
	glVertex3f(0.6, 0.45, -0.05);
	glVertex3f(0.65, 0.4, -0.05);
	glVertex3f(0.65, 0.4, 0.05);
	glEnd();
	glPopMatrix(); // ��������������� VM=Fwe
	glDisable(GL_LIGHTING); //��������� ���������
	glPopMatrix();
	glutSwapBuffers();
	Sleep(20);
}

void myIdle()
{
	angle += 0.9;
	if (angle > 360.0) angle = 0;
	glutPostRedisplay();
	angle1 += 0.1;
	if (angle1 > 360.0) angle1 = 0;
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) { rot = 1 - rot; }
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP) { rot1 *= 0.7; }
}

void keys(unsigned char key, int x, int y)
{
	if (key == 'x')
	{
		scal += 0.2;
	}
	if (key == 'X')
	{
		scal -= 0.2;
	}
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);//���������� ������������� ������ �������
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("my window");
	glutDisplayFunc(myDisplay);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keys);
	glutIdleFunc(myIdle);
	init();
	glutMainLoop();
}