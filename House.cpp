#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
typedef GLfloat point[3];
point v[] = { { -0.5, 0.3, -0.5 }, { -0.5, -0.5, -0.5 }, { 0.5, -0.5, -0.5 }, { 0.5, 0.3, -0.5 }, { -0.5, 0.3, 0.5 }, { -0.5, -0.5, 0.5 }, { 0.5, -0.5, 0.5 }, { 0.5, 0.3, 0.5 } };
point z[] = { { -0.5, -0.3, 0.3 }, { -0.5, -0.5, 0.3 }, { -0.3, -0.5, 0.3 }, { -0.3, -0.3, 0.3 }, { -0.5, -0.3, -0.3 }, { -0.5, -0.5, -0.3 }, { -0.3, -0.5, -0.3 }, { -0.3, -0.3, -0.3 } };
point h[] = { { 0, 0.6, 0.0 }, { -0.5, 0.3, -0.5 }, { 0.5, 0.3, -0.5 }, { -0.5, 0.3, 0.5 }, { 0.5, 0.3, 0.5 } };
point f[] = { { 0.0, 0.35, 0.0 }, { 0.0, 0.25, 0.0 }, { 0.025, 0.25, -0.025 }, { -0.025, 0.25, -0.025 }, { -0.025, 0.25, 0.025 }, { 0.025, 0.25, 0.025 } };
point fb[] = { { 0.025, 0.25, -0.025 }, { 0.025, 0.25, 0.025 }, { 0.2, 0.25, 0.05 }, { 0.2, 0.25, -0.05 }, { -0.025, 0.25, -0.025 }, { -0.025, 0.25, 0.025 }, { -0.2, 0.25, 0.05 }, { -0.2, 0.25, -0.05 }, { 0.025, 0.25, -0.025 }, { -0.025, 0.25, -0.025 }, { -0.05, 0.25, -0.2 }, { 0.05, 0.25, -0.2 }, { -0.025, 0.25, 0.025 }, { 0.025, 0.25, 0.025 }, { 0.05, 0.25, 0.2 }, { -0.05, 0.25, 0.2 } };
point sft[] = { { -0.5, -0.3, 0.3 }, { -0.3, -0.3, 0.3 }, { -0.3, -0.3, 0.25 }, { -0.5, -0.3, 0.25 }, { -0.5, -0.25, 0.3 }, { -0.3, -0.25, 0.3 }, { -0.3, -0.25, 0.25 }, { -0.5, -0.25, 0.25 } };
point srt[] = { { -0.5, -0.3, -0.3 }, { -0.3, -0.3, -0.3 }, { -0.3, -0.3, -0.25 }, { -0.5, -0.3, -0.25 }, { -0.5, -0.25, -0.3 }, { -0.3, -0.25, -0.3 }, { -0.3, -0.25, -0.25 }, { -0.5, -0.25, -0.25 } };
point sbk[] = { { -0.5, -0.3, 0.3 }, { -0.5, -0.2, 0.3 }, { -0.45, -0.2, 0.3 }, { -0.45, -0.3, 0.3 }, { -0.5, -0.3, -0.3 }, { -0.5, -0.2, -0.3 }, { -0.45, -0.2, -0.3 }, { -0.45, -0.3, -0.3 } };
point t[] = { { 0.4, -0.1, -0.2 }, { 0.4, 0.1, -0.2 }, { 0.4, 0.1, 0.2 }, { 0.4, -0.1, 0.2 } };
point ts[] = { { 0.4, 0.05, -0.05 }, { 0.4, 0.0, -0.05 }, { 0.4, 0.0, 0.05 }, { 0.4, 0.05, 0.05 }, { 0.5, 0.0, -0.05 }, { 0.5, -0.05, -0.05 }, { 0.5, -0.05, 0.05 }, { 0.5, 0.0, 0.05 } };;
point hfrt[] = { { -0.5, 0.3, 0.5 }, { 0.5, 0.3, 0.5 }, { 0.5, 0.25, 0.65 }, { -0.5, 0.25, 0.65 } };

void sofa1();
void house(point, point, point, point, point, point, point, point);
void htop(point, point, point, point, point);
void fan(point, point, point, point, point, point);
void fblade(point, point, point, point, point, point, point, point, point, point, point, point, point, point, point, point);
void grass();
void tv(point, point, point, point);
void tvs(point, point, point, point, point, point, point, point);
void compound();
void rainwater();
void sump();
void table();
void teapot();
void tree();
void window();
void housefront(point, point, point, point);

int lightflag = 0;
int housepolygon = 1;
int orthoflag = 0;
float sofa_d = 0.0;
float sofa_w = 0.0;
float sofa_a = 0.0;
float sofa_s = 0.0;
int mouseflag = 0;
float fanspeed = 1.0;
int back = 0;
int flag = 0;
int translate_sofa_flag = 0;
float dy_c = 0.0;
float dy_s = 1.0;
GLfloat angle = 0;
GLfloat theta[] = { 0.0, 0.0, 0.0 };
GLint axis = 1;
GLdouble viewer[] = { 0.0, 0.0, 2.0 };

void mouse(int btn, int state, int x, int y)
{
	if (mouseflag)
	{
		if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)axis = 0;
		if (btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)axis = 1;
		if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)axis = 2;
		theta[axis] += 2.0;
		if (theta[axis] > 360.0)
			theta[axis] -= 360.0;
	}
	glutPostRedisplay();
}

void spin()
{
	angle = angle + fanspeed;
	if (angle >= 360)
	{
		angle = 0;
	}
	glutPostRedisplay();
}

void sofa1()
{
	glColor3f(0.96, 0.64, 0.38);
	glPushMatrix();
	glTranslated(-0.4 + sofa_s, -0.425, 0 + sofa_d);		//bottom
	glScaled(2, 1.5, 6);
	glutSolidCube(0.1);
	glPopMatrix();

	glColor3f(0.93, 0.84, 0.72);
	glPushMatrix();
	glTranslated(-0.4 + sofa_s, -0.3125, -0.25 + sofa_d);		//back
	glScaled(2, 0.75, 1);
	glutSolidCube(0.1);
	glPopMatrix();

	glColor3f(0.93, 0.84, 0.72);
	glPushMatrix();
	glTranslated(-0.4 + sofa_s, -0.3125, 0.25 + sofa_d);		//front
	glScaled(2, 0.75, 1);
	glutSolidCube(0.1);
	glPopMatrix();

	glColor3f(0.87, 0.72, 0.53);
	glPushMatrix();
	glTranslated(-0.475 + sofa_s, -0.275, 0 + sofa_d);			//rest
	glScaled(0.5, 1.5, 4);
	glutSolidCube(0.1);
	glPopMatrix();
}
void myreshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
	{
		if (orthoflag)
			glOrtho(-1.0, 1.0, -1.0*((GLfloat)h / (GLfloat)w), 1.0*((GLfloat)h / (GLfloat)w), -20.0, 20.0);
		else
			glFrustum(-1.0, 1.0, -1.0*(GLfloat)h / (GLfloat)w, 1.0*(GLfloat)h / (GLfloat)w, 1.0, 10.0);
	}
	else
	{
		if (orthoflag)
			glOrtho(-1.0*((GLfloat)w / (GLfloat)h), 1.0*((GLfloat)w / (GLfloat)h), -1.0, 1.0, -20.0, 20.0);
		else
			glFrustum(-1.0*(GLfloat)w / (GLfloat)h, 1.0*(GLfloat)w / (GLfloat)h, -1.0, 1.0, 1.0, 10.0);
	}
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}

void display()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
	GLfloat mat_diffuse[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat lightintensity[] = { 1, 1, 1, 1.0 };
	GLfloat lightposition[] = { 2.0, 2.0, 2.0, 1.0 };
	GLfloat lightposition2[] = { -2.0, -2.0, -2.0, 1.0 };
	glClearColor(0.5, 0.5, 0.5, 0.0);
	switch (back)
	{
	case 1:     glClearColor(1.0, 0.0, 0.0, 0.0);
		break;
	case 2:     glClearColor(0.0, 0.0, 1.0, 0.0);
		break;
	case 3:    glClearColor(0.0, 1.0, 0.0, 0.0);
		break;
	case 4:    glClearColor(0.0, 0.0, 0.0, 0.0);
		break;
	}

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glLightfv(GL_LIGHT0, GL_POSITION, lightposition);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightintensity);
	glLightfv(GL_LIGHT0, GL_SPECULAR, mat_specular);
	glLightfv(GL_LIGHT1, GL_POSITION, lightposition2);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightintensity);
	glLightfv(GL_LIGHT1, GL_SPECULAR, mat_specular);

	if (lightflag)   glEnable(GL_LIGHTING);
	else glDisable(GL_LIGHTING);
	
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	
	if (orthoflag)
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-1, 1, -1, 1, -20, 20);
		glMatrixMode(GL_MODELVIEW);
	}
	else
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 10.0);
		glMatrixMode(GL_MODELVIEW);
	}

	glLoadIdentity();
	gluLookAt(viewer[0], viewer[1], viewer[2], 0, 0, 0, 0, 1, 0);
	glRotatef(theta[0], 1, 0, 0);
	glRotatef(theta[1], 0, 1, 0);
	glRotatef(theta[2], 0, 0, 1);

	house(v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7]);
	htop(h[0], h[1], h[2], h[3], h[4]);
	tv(t[0], t[1], t[2], t[3]);
	tvs(ts[0], ts[1], ts[2], ts[3], ts[4], ts[5], ts[6], ts[7]);
	grass();
	sofa1();
	rainwater();
	sump();
	table();
	teapot();
	tree();
	compound();
	window();
	housefront(hfrt[0], hfrt[1], hfrt[2], hfrt[3]);
	fan(f[0], f[1], f[2], f[3], f[4], f[5]);
	fblade(fb[0], fb[1], fb[2], fb[3], fb[4], fb[5], fb[6], fb[7], fb[8], fb[9], fb[10], fb[11], fb[12], fb[13], fb[14], fb[15]);

	glEnable(GL_DEPTH_TEST);
	glutSwapBuffers();
}

void backMenu(int value)
{
	switch (value)
	{	
		case 1:back = 1;
		break;
		case 2:back = 2;
		break;
		case 3:back = 3;
		break;
		case 4:back = 4;
		break;
	}
	glutPostRedisplay();
}

void rainwater()
{
	glColor3f(0.69,0.77,0.87);
	glBegin(GL_POLYGON);
	glVertex3f(-0.5, 0.3, 0.5);
	glVertex3f(-0.55, 0.3, 0.5);		//left bottom
	glVertex3f(-0.55, 0.275, -0.55);
	glVertex3f(-0.5, 0.275, -0.55);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-0.5, 0.275, -0.55);
	glVertex3f(-0.5, 0.277, -0.5);		//back bottom
	glVertex3f(0.55, 0.262, -0.55);
	glVertex3f(0.55, 0.260, -0.5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(0.55, 0.262, -0.55);		//right bottom
	glVertex3f(0.5, 0.261, -0.55);
	glVertex3f(0.5, 0.251, 0.4);
	glVertex3f(0.55, 0.252, 0.4);
	glEnd();
	
	glColor3f(0.44,0.50,0.56);
	glBegin(GL_POLYGON);
	glVertex3f(-0.55, 0.3, 0.5);
	glVertex3f(-0.55, 0.325, 0.5);		//left top
	glVertex3f(-0.55, 0.295, -0.55);
	glVertex3f(-0.55, 0.275, -0.55);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-0.55, 0.295, -0.55);
	glVertex3f(-0.55, 0.275, -0.55);	//back top
	glVertex3f(0.55, 0.260, -0.55);
	glVertex3f(0.55, 0.285, -0.55);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(0.55, 0.262, -0.55);
	glVertex3f(0.55, 0.282, -0.55);		//right top
	glVertex3f(0.55, 0.272, 0.4);
	glVertex3f(0.55, 0.252, 0.4);
	glEnd();

	glColor3f(0.47, 0.53, 0.60);
	glBegin(GL_POLYGON);
	glVertex3f(0.55, 0.252, 0.4);
	glVertex3f(0.5, 0.251, 0.4);			//back
	glVertex3f(0.5, -0.7, 0.4);
	glVertex3f(0.55, -0.7, 0.4);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(0.55, 0.250, 0.45);				//front
	glVertex3f(0.5, 0.250, 0.45);
	glVertex3f(0.5, -0.7, 0.45);
	glVertex3f(0.55, -0.7, 0.45);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(0.5, 0.251, 0.4);
	glVertex3f(0.5, 0.250, 0.45);				//left
	glVertex3f(0.5, -0.7, 0.45);
	glVertex3f(0.5, -0.7, 0.4);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(0.55, 0.251, 0.4);				//right
	glVertex3f(0.55, 0.250, 0.45);
	glVertex3f(0.55, -0.7, 0.45);
	glVertex3f(0.55, -0.7, 0.4);
	glEnd();

	glPushMatrix();
	glTranslated(0.6, -0.675, 0.425);						//left wall
	glScaled(2, 1, 1);
	glutSolidCube(0.05);
	glPopMatrix();

}

void window()
{
	if (housepolygon)
	{
		glColor3f(0.5, 0.55, 0.5);
		glBegin(GL_POLYGON);
		glVertex3f(0.25, -0.1, 0.505);
		glVertex3f(0.4, -0.1, 0.505);
		glVertex3f(0.4, 0.05, 0.505);
		glVertex3f(0.25, 0.05, 0.505);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(-0.25, -0.1, 0.505);
		glVertex3f(-0.4, -0.1, 0.505);
		glVertex3f(-0.4, 0.05, 0.505);
		glVertex3f(-0.25, 0.05, 0.505);
		glEnd();
	}
	else
	{
		glColor3f(0.5, 0.55, 0.5);
		glBegin(GL_LINE_LOOP);
		glVertex3f(0.25, -0.1, 0.505);
		glVertex3f(0.4, -0.1, 0.505);
		glVertex3f(0.4, 0.05, 0.505);
		glVertex3f(0.25, 0.05, 0.505);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glVertex3f(-0.25, -0.1, 0.505);
		glVertex3f(-0.4, -0.1, 0.505);
		glVertex3f(-0.4, 0.05, 0.505);
		glVertex3f(-0.25, 0.05, 0.505);
		glEnd();
	}
}

void housefront(point a, point b, point c, point d)
{
	glColor3f(0.5,0,0);
	glBegin(GL_POLYGON);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
	glVertex3fv(d);
	glEnd();
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex3f(0.5, 0.25, 0.65);
	glVertex3f(0.5, -0.5, 0.65);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(-0.5, 0.25, 0.65);
	glVertex3f(-0.5, -0.5, 0.65);
	glEnd();
}

void table()
{
	glColor3f(0.80, 0.72, 0.62);
	glPushMatrix();
	glTranslated(0.375, -0.325, -0.375);
	glScaled(2.5, 0.5, 2.5);
	glutSolidCube(0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.475, -0.425, -0.475);
	glScaled(0.5, 1.5, 0.5);
	glutSolidCube(0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.475, -0.425, -0.275);
	glScaled(0.5, 1.5, 0.5);
	glutSolidCube(0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.275, -0.425, -0.275);
	glScaled(0.5, 1.5, 0.5);
	glutSolidCube(0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.275, -0.425, -0.475);
	glScaled(0.5, 1.5, 0.5);
	glutSolidCube(0.1);
	glPopMatrix();
}

void teapot()
{
	glColor3f(0.55, 0.27, 0.07);
	glPushMatrix();
	glTranslated(0.35, -0.275, -0.35);
	glScaled(0.5, 0.5, 0.5);
	glutSolidTeapot(0.1);
	glPopMatrix();
}

void sump()
{
	glColor3f(0.37,0.62,0.63);
	glPushMatrix();
	glTranslated(0.7, -0.6, 0.5);
	glScaled(2, 3, 2);
	glutSolidCube(0.1);
	glPopMatrix();
}

void tree()
{
	glColor3f(0.80, 0.52, 0.25);
	glPushMatrix();
	glTranslated(-0.75, -0.35, 0.8);
	glScaled(0.5, 2.5, 0.5);
	glutSolidCube(0.1);
	glPopMatrix();

	glColor3f(0, 0.39, 0);
	glPushMatrix();
	glTranslated(-0.75, -0.3, 0.8);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(0.1, 0.25, 500, 500);
	glPopMatrix();

	glColor3f(0.24, 0.7, 0.44);
	glPushMatrix();
	glTranslated(-0.75, -0.25, 0.8);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(0.1, 0.25, 500, 500);
	glPopMatrix();

	glColor3f(0.20, 0.80, 0.20);
	glPushMatrix();
	glTranslated(-0.75, -0.2, 0.8);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(0.1, 0.25, 500, 500);
	glPopMatrix();
}
void compound()
{
	glColor3f(1, 0.89, 0.71);
	glPushMatrix();
	glTranslated(-0.975, -0.4 + dy_c, 0.0);						//left wall
	glScaled(0.5, 2 * dy_s, 20);
	glutSolidCube(0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.975, -0.4 + dy_c, 0.0);						//right wall
	glScaled(1, 2 * dy_s, 20);
	glutSolidCube(0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.0, -0.4 + dy_c, -0.975);						//back wall
	glScaled(20, 2 * dy_s, 0.5);
	glutSolidCube(0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.25, -0.4 + dy_c, 0.975);						//front wall
	glScaled(15, 2 * dy_s, 0.5);
	glutSolidCube(0.1);
	glPopMatrix();

	glColor3f(0.55, 0.47, 0.4);
	glBegin(GL_POLYGON);
	glVertex3f(0.5, -0.5, 0.975);
	glVertex3f(0.5, -0.3, 0.975);
	glVertex3f(1.0, -0.3, 0.975);
	glVertex3f(1.0, -0.5, 0.975);
	glEnd();
}

void keys(unsigned char key, int x, int y)
{
	if (key == 'x') viewer[0] -= 0.5;
	if (key == 'X') viewer[0] += 0.5;
	if (key == 'y') viewer[1] -= 0.5;
	if (key == 'Y') viewer[1] += 0.5;
	if (key == 'z') viewer[2] -= 0.5;
	if (key == 'Z') viewer[2] += 0.5;

	if (translate_sofa_flag)
	{
		if (key == 'd') sofa_d += 0.1;
		if (key == 'a') sofa_d -= 0.1;
		if (key == 'w') sofa_s += 0.1;
		if (key == 's') sofa_s -= 0.1;
	}
	glutPostRedisplay();
}

void tv(point a, point b, point c, point d)
{
	glColor3f(0.19, 0.31, 0.31);
	glBegin(GL_POLYGON);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
	glVertex3fv(d);
	glEnd();

}

void tvs(point a, point b, point c, point d, point a1, point b1, point c1, point d1)
{
	glColor3f(0.75, 0.75, 0.75);
	glBegin(GL_LINES);
	glVertex3fv(a);
	glVertex3fv(a1);
	glEnd();
	glBegin(GL_LINES);
	glVertex3fv(b);
	glVertex3fv(b1);
	glEnd();
	glBegin(GL_LINES);
	glVertex3fv(c);
	glVertex3fv(c1);
	glEnd();
	glBegin(GL_LINES);
	glVertex3fv(d);
	glVertex3fv(d1);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3fv(a);
	glVertex3fv(a1);
	glVertex3fv(b1);
	glVertex3fv(b);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3fv(a);
	glVertex3fv(a1);
	glVertex3fv(d1);
	glVertex3fv(d);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3fv(b);
	glVertex3fv(b1);
	glVertex3fv(c1);
	glVertex3fv(c);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3fv(c);
	glVertex3fv(c1);
	glVertex3fv(d1);
	glVertex3fv(d);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3fv(a1);
	glVertex3fv(b1);
	glVertex3fv(c1);
	glVertex3fv(d1);
	glEnd();
}

void house(point a, point b, point c, point d, point e, point f, point g, point h)
{
	if (housepolygon)
	{
		glColor3f(1, 0.98, 0.8);
		glBegin(GL_POLYGON);
		glVertex3fv(a);
		glVertex3fv(e);
		glVertex3fv(f);			//left
		glVertex3fv(b);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3fv(d);
		glVertex3fv(h);			//right
		glVertex3fv(g);
		glVertex3fv(c);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3fv(a);
		glVertex3fv(b);			//back
		glVertex3fv(c);
		glVertex3fv(d);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3fv(e);
		glVertex3fv(h);
		glVertex3fv(g);
		glVertex3fv(f);
		glEnd();
		glColor3f(1, 0.5, 0.31);
		glBegin(GL_POLYGON);
		glVertex3f(-0.15, -0.1, 0.51);
		glVertex3f(-0.15, -0.5, 0.51);
		glVertex3f(0.15, -0.5, 0.51);
		glVertex3f(0.15, -0.1, 0.51);
		glEnd();
	}
	else
	{
		glBegin(GL_LINE_LOOP);
		glVertex3fv(b);
		glVertex3fv(f);
		glVertex3fv(g);
		glVertex3fv(c);
		glEnd();
		glBegin(GL_LINES);
		glVertex3fv(e);
		glVertex3fv(f);
		glVertex3fv(h);
		glVertex3fv(g);
		glVertex3fv(d);
		glVertex3fv(c);
		glVertex3fv(a);
		glVertex3fv(b);
		glEnd();
		glColor3f(1, 0.5, 0.31);
		glBegin(GL_LINE_LOOP);
		glVertex3f(-0.15, -0.1, 0.5);
		glVertex3f(-0.15, -0.5, 0.5);
		glVertex3f(0.15, -0.5, 0.5);
		glVertex3f(0.15, -0.1, 0.5);
		glEnd();
	}
	glColor3f(0.96, 0.87, 0.70);
	glBegin(GL_POLYGON);
	glVertex3f(-0.5, -0.49, -0.5);
	glVertex3f(-0.5, -0.49, 0.5);
	glVertex3f(0.5, -0.49, 0.5);				//bottom
	glVertex3f(0.5, -0.49, -0.5);
	glEnd();
}

void grass()
{
	glColor3f(0.13, 0.55, 0.13);
	glBegin(GL_POLYGON);
	glVertex3f(-1.0, -0.5, -1.0);
	glVertex3f(-1.0, -0.5, 1.0);
	glVertex3f(1.0, -0.5, 1.0);
	glVertex3f(1.0, -0.5, -1.0);
	glEnd();
}

void fan(point a, point b, point c, point d, point e, point f)
{
	glColor3f(0.72, 0.53, 0.04);
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex3fv(a);
	glVertex3fv(b);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3fv(c);
	glVertex3fv(d);
	glVertex3fv(e);
	glVertex3fv(f);
	glEnd();
}

void fblade(point a, point b, point c, point d, point a1, point b1, point c1, point d1, point a2, point b2, point c2, point d2, point a3, point b3, point c3, point d3)
{
	glColor3f(0.72, 0.53, 0.04);
	if (flag)
		glRotatef(angle, 0, 1, 0);
	glBegin(GL_POLYGON);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
	glVertex3fv(d);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3fv(a1);
	glVertex3fv(b1);
	glVertex3fv(c1);
	glVertex3fv(d1);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3fv(a2);
	glVertex3fv(b2);
	glVertex3fv(c2);
	glVertex3fv(d2);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3fv(a3);
	glVertex3fv(b3);
	glVertex3fv(c3);
	glVertex3fv(d3);
	glEnd();
}

void htop(point a, point b, point c, point d, point e)
{
	if (housepolygon)
	{
		glColor3f(0.70, 0.13, 0.13);
		glBegin(GL_POLYGON);
		glVertex3fv(a);
		glVertex3fv(b);			//back
		glVertex3fv(c);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3fv(a);
		glVertex3fv(b);			//left
		glVertex3fv(d);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3fv(a);
		glVertex3fv(d);			//front
		glVertex3fv(e);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3fv(a);
		glVertex3fv(c);			//right
		glVertex3fv(e);
		glEnd();
	}
	else
	{
		glColor3f(0.70, 0.13, 0.13);
		glBegin(GL_LINES);
		glVertex3fv(a);
		glVertex3fv(b);
		glEnd();
		glBegin(GL_LINES);
		glVertex3fv(a);
		glVertex3fv(c);
		glEnd();
		glBegin(GL_LINES);
		glVertex3fv(a);
		glVertex3fv(d);
		glEnd();
		glBegin(GL_LINES);
		glVertex3fv(a);
		glVertex3fv(e);
		glEnd();
	}
}

void main_menu(int choice)
{
	switch (choice)
	{
	case 1:exit(0);
		break;
	case 9:housepolygon = 1;
		orthoflag = 0;
		sofa_d = 0.0;
		sofa_w = 0.0;
		sofa_a = 0.0;
		sofa_s = 0.0;				//mouse menu
		mouseflag = 0;
		fanspeed = 1.0;
		back = 0;
		flag = 0;
		translate_sofa_flag = 0;
		dy_c = 0.0;
		dy_s = 1.0;
		angle = 0;
		axis = 1;
		orthoflag = 0;
		viewer[0] = 0.0;
		viewer[1] = 0.0;
		viewer[2] = 2.0;
		theta[0] = 0.0;
		theta[1] = 0.0;
		theta[2] = 0.0;
		glutPostRedisplay();
		break;
	}

}

void rotateMenu(int choice)
{
	switch (choice)
	{
	case 1:flag = 1;
		break;
	case 2:flag = 0;
		break;						//rotate menu
	case 3:fanspeed += 2;
		break;
	case 4:fanspeed -= 2;
		break;
	}
	glutPostRedisplay();
}

void rotateHouse(int choice)
{
	switch (choice)
	{
	case 1:mouseflag = 1;
		break;						//Rotate House
	case 2:mouseflag = 0;
		break;
	default:exit(0);
	}
	glutPostRedisplay();
}

void translatesofa(int choice)
{
	switch (choice)
	{
	case 1:translate_sofa_flag = 1;
		break;
	case 2:translate_sofa_flag = 0;			//Translate Sofa
		break;
	default:exit(0);
	}
	glutPostRedisplay();
}

void scalecompoundheight(int choice)
{
	switch (choice)
	{
	case 1:dy_s = 1.0;
		dy_c = 0.0;
		break;
	case 2:dy_s = 1.5;
		dy_c = 0.05;				//Scale Compound Wall
		break;
	case 3:dy_s = 2.0;
		dy_c = 0.1;
		break;
	case 4:dy_s = 2.5;
		dy_c = 0.15;
		break;
	default:exit(0);
	}
	glutPostRedisplay();
}

void viewtypefunc(int choice)
{
	switch (choice)
	{
	case 1:orthoflag = 1;
		break;
	case 2:orthoflag = 0;			//View Menu
		break;
	default:exit(0);
	}
	glutPostRedisplay();
}

void housewallfunc(int choice)
{
	switch (choice)
	{
	case 1:housepolygon = 0;
		break;
	case 2:housepolygon = 1;		//House walls
		break;
	default:exit(0);
	}
	glutPostRedisplay();
}

void lightsfunc(int choice)
{
	switch (choice)
	{
	case 1:lightflag = 1;
		break;
	case 2:lightflag = 0;			//Lights Func
		break;
	default:exit(0);
	}
	glutPostRedisplay();
}

void keyboard2(unsigned char c, int x, int y)
{
	switch (c)
	{
	case 13:
		glutDisplayFunc(display);
		glutMouseFunc(mouse);
		glutIdleFunc(spin);
		glutReshapeFunc(myreshape);
		glutKeyboardFunc(keys);
		break;
	}
	glutPostRedisplay();
}
	
void strokeString(float x, float y, float sx, float sy, char *string, int width)
{
	char *c;
	glLineWidth(width);
	glPushMatrix();
	glTranslatef(x, y, 0);
	glScalef(sx, sy, 0);
	for (c = string; *c != '\0'; c++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
	glPopMatrix();
}

void first()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.75, 0.75, 0.75);
	strokeString(50, 850, 0.15, 0.15, "BANGALORE INSTITUTE OF TECHNOLOGY", 2);
	strokeString(100, 750, 0.3, 0.3, "DEPARTMENT OF COMPUTER SCIENCE", 4);
	strokeString(300, 670, 0.3, 0.3, "AND ENGINEERING", 4);
	strokeString(200, 500, 0.3, 0.3, "COMPUTER GRAPHICS PAKAGE ON", 2);
	glColor3f(0, 0.5, 0.5);
	strokeString(360, 420, 0.4, 0.4, "3D HOUSE", 6);
	glColor3f(0.54, 0, 0);
	strokeString(50, 50, 0.17, 0.17, "Press (Enter) to display the house", 2);
	strokeString(650, 200, 0.15, 0.15, "By:", 2);
	strokeString(650, 60, 0.15, 0.15, "Under the guidance of.", 2);
	glColor3f(0.74,0.72,0.42);
	strokeString(650, 160, 0.18, 0.18, "Girish Kumar.N", 2);
	strokeString(650, 30, 0.2, 0.2, "Girija.J (Associate Professor)", 2);
	strokeString(650, 120, 0.18, 0.18, "1BI13CS057", 2);
	glutSwapBuffers();
}		
//similarly we set translate_sofa flag
void initfirst()
{
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 1000, 0, 1000, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
	int c_smenu, rotatefan, mouserotate, sofatranslate, scalecompound, viewtype, housewall, lightsonoff;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("3D HOUSE");
	initfirst();
	glutDisplayFunc(first);
	glutKeyboardFunc(keyboard2);
	
	housewall = glutCreateMenu(housewallfunc);
	glutAddMenuEntry("Use LineLoop ", 1);
	glutAddMenuEntry("Use Polygon ", 2);

	lightsonoff = glutCreateMenu(lightsfunc);
	glutAddMenuEntry("On ", 1);
	glutAddMenuEntry("Off ", 2);

	viewtype = glutCreateMenu(viewtypefunc);
	glutAddMenuEntry("Orthographic View ", 1);
	glutAddMenuEntry("Perspective View ", 2);

	sofatranslate = glutCreateMenu(translatesofa);
	glutAddMenuEntry("On (Use keys w,a,s,d) ", 1);
	glutAddMenuEntry("Off ", 2);

	scalecompound = glutCreateMenu(scalecompoundheight);
	glutAddMenuEntry("x1 ", 1);
	glutAddMenuEntry("x1.5", 2);
	glutAddMenuEntry("x2.0", 3);
	glutAddMenuEntry("x2.5", 4);

	mouserotate = glutCreateMenu(rotateHouse);
	glutAddMenuEntry("Mouse On ", 1);
	glutAddMenuEntry("Mouse Off ", 2);

	rotatefan = glutCreateMenu(rotateMenu);
	glutAddMenuEntry("On ", 1);
	glutAddMenuEntry("Off ", 2);
	glutAddMenuEntry("Increase speed ", 3);
	glutAddMenuEntry("Decrease speed ", 4);

	c_smenu = glutCreateMenu(backMenu);
	glutAddMenuEntry("Red ", 1);
	glutAddMenuEntry("Blue ", 2);
	glutAddMenuEntry("Grean ", 3);
	glutAddMenuEntry("Black ", 4);

	glutCreateMenu(main_menu);
	glutAddMenuEntry("Exit", 1);
	glutAddSubMenu("Rotation of fan", rotatefan);
	glutAddSubMenu("Change Color", c_smenu);
	glutAddSubMenu("House Rotation", mouserotate);
	glutAddSubMenu("Translate Sofa", sofatranslate);
	glutAddSubMenu("Scale the height of compound wall", scalecompound);
	glutAddSubMenu("Lighting", lightsonoff);
	glutAddSubMenu("View", viewtype);
	glutAddSubMenu("House Walls", housewall);
	glutAddMenuEntry("Default Mode", 9);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}
