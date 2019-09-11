//#include<stdafx.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<string.h>
#include<stdio.h>


int _tmain(int argc, char* argv[])
{
	return 0;
}



GLfloat z = 250.0, z1 = 270.0;

int menu = 0, w = 0, helpscreen = 0, menu1 = 0;
char skey[20] = { "Press (v) to Start" };
char game[170] = { "             GRAPHICAL IMPLEMENTATION OF AN ELEVATOR" };
char strt[25] = { "  6     SIMULATE" };
char help[25] = { "  7     CONTROLS" };
char ext[15] = { " Esc   QUIT" };
char subm[20] = { "PROJECT BY" };
char guid[30] = { "UNDER GUIDANCE OF" };
char name3[50] = { "Mrs. MAMATHA JAJUR S " };
char lec[70] = { "Lecturer,Dept. of CSE" };
char name1[17] = { "SANJEET CHANDA" };
char reg1[20] = { "(1RN16CS090)" };
char name2[20] = { "PARVES KHAISAR" };
char reg2[20] = { "(1RN16CS065)" };
char coll[70] = { "RNS INSTITUTE OF TECHNOLOGY" };
char coll1[50] = { "CHANNASANDRA,BENGALURU" };
char opt[10] = { "OPTIONS" };
char cntrl[20] = { "CONTROLS" };
char cntrl1[50] = { "1 -- To move to the 1st floor" };
char cntrl2[50] = { "2 -- To move to the 2nd floor" };
char cntrl3[50] = { "0 -- To move to the Ground floor" };
char cntrl4[50] = { "S -- Side View of the Elevator" };
char cntrl5[50] = { "x -- Rotation along X-axis" };
char cntrl6[50] = { "y -- Rotation along Y-axis" };
char cntrl7[50] = { "z -- Rotation along Z-axis" };
char cntrl8[50] = { "c -- Close the door of the Elevator" };
char cntrl9[50] = { "o -- Open the door of the Elevator" };


char bck[25] = { "Press (b) to go back" };
#define ESCAPE 27

GLint Xsize = 1024;                                              /* size of the window */
GLint Ysize = 728;
int floor = 0, delay = 10;

GLfloat xangle = 0.0, yangle = 0.0, zangle = 0.0;                     /* axis angles */
GLfloat xt = 0.0, yt = 0.0;
GLfloat eyt = 0.0;
GLfloat ext0 = 0.0, ext1 = 0.0, ext2 = 0.0, ext3 = 0.0, ext4 = 0.0, ext5 = 0.0;

GLUquadricObj *t;                                             /* declaring quadric object for cylinder */

void myInit(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);                            /* clear the background to black */
	glLineWidth(1.0);                                         /* line thickness */
	t = gluNewQuadric();                                        /* initialize the quadric object for rope */
	gluQuadricDrawStyle(t, GLU_FILL);
	glOrtho(-290.0, 290.0, -380.0, 380.0, 300.0, -300.0);
}

/* function to open the lift doors at ground floor by using delay */

void timer4(int value)
{
	if (ext0 == -67.0 && ext1 == 67) { return; }

	ext0 -= 1.0;
	ext1 += 1.0;
	glutPostRedisplay();
	glutTimerFunc(delay, timer4, value);
}

/* function to close the lift doors at ground floor by using delay */

void timer5(int value)
{
	if (ext0 == 0 && ext1 == 0) { return; }

	ext0 += 1.0;
	ext1 -= 1.0;
	glutPostRedisplay();
	glutTimerFunc(delay, timer5, value);
}

/* function to open the lift doors at first floor by using delay */

void timer6(int value)
{
	if (ext2 == -68.0 && ext3 == 68) { return; }

	ext2 -= 1.0;
	ext3 += 1.0;
	glutPostRedisplay();
	glutTimerFunc(delay, timer6, value);
}

/* function to close the lift doors at first floor by using delay */

void timer7(int value)
{
	if (ext2 == 0 && ext3 == 0) { return; }

	ext2 += 1.0;
	ext3 -= 1.0;
	glutPostRedisplay();
	glutTimerFunc(delay, timer7, value);
}

/* function to open the lift doors at second floor by using delay */

void timer8(int value)
{
	if (ext4 == -68.0 && ext5 == 68) { return; }

	ext4 -= 1.0;
	ext5 += 1.0;
	glutPostRedisplay();
	glutTimerFunc(delay, timer8, value);
}

/* function to close the lift doors at second floor by using delay */

void timer9(int value)
{
	if (ext4 == 0 && ext5 == 0) { return; }

	ext4 += 1.0;
	ext5 -= 1.0;
	glutPostRedisplay();
	glutTimerFunc(delay, timer9, value);
}

/* function to move the lift to first floor from ground floor */

void timer(int value)
{
	if (eyt == 240)
	{
		floor = 1;
		glutTimerFunc(delay, timer6, value);
		return;
	}

	eyt += 1.0;
	glutPostRedisplay();
	glutTimerFunc(delay, timer, value);    /* introducing delay */
}

/* function to move the lift to first floor from second floor */

void timer1(int value)
{
	if (eyt == 240)
	{
		floor = 1;
		glutTimerFunc(delay, timer6, value);
		return;
	}

	eyt -= 1.0;
	glutPostRedisplay();
	glutTimerFunc(delay, timer1, value);   /* introducing delay */
}

/* function to move the lift to second floor */

void timer2(int value) {

	if (eyt == 480)
	{
		floor = 2;
		glutTimerFunc(delay, timer8, value);
		return;
	}

	eyt += 1.0;
	glutPostRedisplay();
	glutTimerFunc(delay, timer2, value);   /* introducing delay */
}

/* function to move the lift to ground floor */

void timer3(int value) {

	if (eyt == 0)
	{
		floor = 0;
		glutTimerFunc(delay, timer4, value);
		return;
	}

	eyt -= 1.0;
	glutPostRedisplay();
	glutTimerFunc(delay, timer3, value);   /* introducing delay */
}

/* the following function draws the main body of the elevator */

void ele_draw()
{
	glPushMatrix();
	//	glColor3f(1.0,1.0,1.0);
	glTranslatef(0.0, -160.0, -125.0);
	glTranslatef(0.0, eyt, 0.0);
	glRotatef(-90.0, 280.0, 0.0, 0.0);
	gluCylinder(t, 1.5, 1.5, 600.0, 10.0, 10.0);   /* draw the rope of the lift */
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, eyt, 0.0);

	glColor3f(0.0, 1.0, 0.0);

	glBegin(GL_QUADS);                             //back face of ele body
	glVertex3f(-69.0, -360.0, -198.0);
	glVertex3f(69.0, -360.0, -198.0);
	glVertex3f(69.0, -160.0, -198.0);
	glVertex3f(-69.0, -160.0, -198.0);
	glEnd();

	glBegin(GL_QUADS);                          //left face
	glVertex3f(-69.0, -360.0, -50.0);
	glVertex3f(-69.0, -360.0, -198.0);
	glVertex3f(-69.0, -160.0, -198.0);
	glVertex3f(-69.0, -160.0, -50.0);
	glEnd();

	glBegin(GL_QUADS);							//right face
	glVertex3f(69.0, -360.0, -50.0);
	glVertex3f(69.0, -360.0, -198.0);
	glVertex3f(69.0, -160.0, -198.0);
	glVertex3f(69.0, -160.0, -50.0);
	glEnd();

	glBegin(GL_QUADS);							//lower face
	glVertex3f(-69.0, -360.0, -50.0);
	glVertex3f(69.0, -360.0, -50.0);
	glVertex3f(69.0, -360.0, -198.0);
	glVertex3f(-69.0, -360.0, -198.0);
	glEnd();

	glBegin(GL_QUADS);							//upper face
	glVertex3f(-69.0, -160.0, -50.0);
	glVertex3f(69.0, -160.0, -50.0);
	glVertex3f(69.0, -160.0, -198.0);
	glVertex3f(-69.0, -160.0, -198.0);
	glEnd();

	glPopMatrix();
}

/* the following six functions draw the elevator doors at all the levels */

void lift_doors0()
{
	glPushMatrix();
	glTranslatef(ext0, 0.0, 0.0);

	glColor3f(0.9, 0.9, 0.8);

	glBegin(GL_QUADS);
	//   glColor3f(0.6,1.0,0.0);
	glVertex3f(-70.0, -355.0, -50.0);
	//    glColor3f(1.0,0.0,0.0);
	glVertex3f(-3.0, -355.0, -50.0);
	//  glColor3f(1.0,0.0,0.0);  
	glVertex3f(-3.0, -165.0, -50.0);
	// glColor3f(1.0,1.0,0.0);
	glVertex3f(-70.0, -165.0, -50.0);
	glEnd();

	glPopMatrix();
}

void lift_doors1()
{
	glPushMatrix();
	glTranslatef(ext1, 0.0, 0.0);

	glColor3f(0.9, 0.9, 0.8);

	glBegin(GL_QUADS);
	//	  glColor3f(1.0,0.0,0.0);
	glVertex3f(3.0, -355.0, -50.0);
	//	  glColor3f(1.0,1.0,0.0);
	glVertex3f(70.0, -355.0, -50.0);
	//      glColor3f(1.0,1.0,0.0);  
	glVertex3f(70.0, -165.0, -50.0);
	//       glColor3f(1.0,0.0,0.0);
	glVertex3f(3.0, -165.0, -50.0);
	glEnd();

	glPopMatrix();
}

void lift_doors2()
{
	glPushMatrix();
	glTranslatef(ext2, 0.0, 0.0);

	glColor3f(0.9, 0.9, 0.8);

	glBegin(GL_QUADS);
	//    glColor3f(1.0,1.0,0.0);
	glVertex3f(-70.0, -115.0, -50.0);
	//    glColor3f(1.0,0.0,0.0);
	glVertex3f(-3.0, -115.0, -50.0);
	//   glColor3f(1.0,0.0,0.0);  
	glVertex3f(-3.0, 75.0, -50.0);
	//   glColor3f(1.0,1.0,0.0);
	glVertex3f(-70.0, 75.0, -50.0);
	glEnd();

	glPopMatrix();
}

void lift_doors3()
{
	glPushMatrix();
	glTranslatef(ext3, 0.0, 0.0);

	glColor3f(0.9, 0.9, 0.8);

	glBegin(GL_QUADS);
	//	  glColor3f(1.0,0.0,0.0);
	glVertex3f(3.0, -115.0, -50.0);
	//	  glColor3f(1.0,1.0,0.0);
	glVertex3f(70.0, -115.0, -50.0);
	//    glColor3f(1.0,1.0,0.0);  
	glVertex3f(70.0, 75.0, -50.0);
	//   glColor3f(1.0,0.0,0.0);
	glVertex3f(3.0, 75.0, -50.0);
	glEnd();

	glPopMatrix();
}

void lift_doors4()
{
	glPushMatrix();
	glTranslatef(ext4, 0.0, 0.0);

	glColor3f(0.9, 0.9, 0.8);

	glBegin(GL_QUADS);
	//    glColor3f(1.0,1.0,0.0);
	glVertex3f(-70.0, 125.0, -50.0);
	//    glColor3f(1.0,0.0,0.0);
	glVertex3f(-3.0, 125.0, -50.0);
	//    glColor3f(1.0,0.0,0.0);  
	glVertex3f(-3.0, 315.0, -50.0);
	//    glColor3f(1.0,1.0,0.0);
	glVertex3f(-70.0, 315.0, -50.0);
	glEnd();

	glPopMatrix();
}

void lift_doors5()
{
	glPushMatrix();
	glTranslatef(ext5, 0.0, 0.0);

	glColor3f(0.9, 0.9, 0.8);

	glBegin(GL_QUADS);
	//	  glColor3f(1.0,0.0,0.0);
	glVertex3f(3.0, 125.0, -50.0);
	//	  glColor3f(1.0,1.0,0.0);
	glVertex3f(70.0, 125.0, -50.0);
	//     glColor3f(1.0,1.0,0.0);  
	glVertex3f(70.0, 315.0, -50.0);
	//     glColor3f(1.0,0.0,0.0);
	glVertex3f(3.0, 315.0, -50.0);
	glEnd();

	glPopMatrix();
}





void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	if (menu == 0)
	{
		glClearColor(0.1, 0.1, 0.3, 0.0);

		glColor3f(1.0, 0.5, 0.5);
		glRasterPos2f(-150.0, 280.0);
		for (w = 0; w < sizeof(game); w++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, game[w]);

		glColor3f(0.2, 0.9, 0.8);
		glRasterPos2f(-30.0, -220.0);
		for (w = 0; w < sizeof(skey); w++)

			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, skey[w]);


		glColor3f(0.3, 1.0, 0.5);
		glRasterPos2f(-27.0, 40.0);
		for (w = 0; w < sizeof(subm); w++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, subm[w]);

		glColor3f(1.0, 1.0, 0.0);
		glRasterPos2f(-190.0, 0.0);
		for (w = 0; w < sizeof(name2); w++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, name2[w]);
		glColor3f(1.0, 1.0, 0.0);
		glRasterPos2f(-185.0, -30.0);
		for (w = 0; w < sizeof(reg2); w++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, reg2[w]);

		glColor3f(1.0, 1.0, 0.0);
		glRasterPos2f(165.0, 0.0);
		for (w = 0; w < sizeof(name1); w++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, name1[w]);
		glColor3f(1.0, 1.0, 0.0);
		glRasterPos2f(165.0, -30.0);
		for (w = 0; w < sizeof(reg1); w++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, reg1[w]);

		glColor3f(1.0, 0.0, 1.0);
		glRasterPos2f(-25.0, -90.0);
		for (w = 0; w < sizeof(guid); w++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, guid[w]);

		glColor3f(1.0, 1.0, 0.0);
		glRasterPos2f(-27.0, -120.0);
		for (w = 0; w < sizeof(name3); w++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, name3[w]);
		glColor3f(1.0, 1.0, 0.0);
		glRasterPos2f(-35.0, -150.0);
		for (w = 0; w < sizeof(lec); w++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, lec[w]);


		glColor3f(1.0, 0.0, 0.0);
		glRasterPos2f(z, -275.0);
		for (w = 0; w < sizeof(coll); w++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, coll[w]);
		glColor3f(1.0, 0.0, 0.0);
		glRasterPos2f(z1, -300.0);
		for (w = 0; w < sizeof(coll1); w++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, coll1[w]);

		if (menu1 == 1)
		{
			glClear(GL_COLOR_BUFFER_BIT);

			glColor3f(0.5, 0.8, 0.0);
			glRasterPos2f(-20.0, 300.0);
			for (w = 0; w < sizeof(opt); w++)
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, opt[w]);


			glColor3f(1.0, 1.0, 0.0);
			glRasterPos2f(-35.0, 40.0);
			for (w = 0; w < sizeof(strt); w++)
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, strt[w]);


			glColor3f(1.0, 1.0, 0.0);
			glRasterPos2f(-35.0, -10.0);
			for (w = 0; w < sizeof(help); w++)
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, help[w]);

			glColor3f(1.0, 1.0, 0.0);
			glRasterPos2f(-35.0, -60.0);
			for (w = 0; w < sizeof(ext); w++)
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ext[w]);


			glColor3f(0.0, 1.0, 1.0);
			glRasterPos2f(140.0, -330.0);
			for (w = 0; w < sizeof(bck); w++)
				glutBitmapCharacter(GLUT_BITMAP_9_BY_15, bck[w]);


			if (helpscreen == 1)
			{
				glClear(GL_COLOR_BUFFER_BIT);
				glColor3f(1.0, 0.0, 0.0);
				glRasterPos2f(-60.0, 320.0);
				for (w = 0; w < sizeof(cntrl); w++)
					glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, cntrl[w]);
				glColor3f(0.0, 1.0, 1.0);
				glRasterPos2f(-100.0, 200.0);
				for (w = 0; w < sizeof(cntrl1); w++)
					glutBitmapCharacter(GLUT_BITMAP_9_BY_15, cntrl1[w]);
				glColor3f(0.0, 1.0, 1.0);
				glRasterPos2f(-100.0, 150.0);
				for (w = 0; w < sizeof(cntrl2); w++)
					glutBitmapCharacter(GLUT_BITMAP_9_BY_15, cntrl2[w]);
				glColor3f(0.0, 1.0, 1.0);
				glRasterPos2f(-100.0, 100.0);
				for (w = 0; w < sizeof(cntrl3); w++)
					glutBitmapCharacter(GLUT_BITMAP_9_BY_15, cntrl3[w]);

				glColor3f(1.0, 0.0, 1.0);
				glRasterPos2f(-100.0, 50.0);
				for (w = 0; w < sizeof(cntrl4); w++)
					glutBitmapCharacter(GLUT_BITMAP_9_BY_15, cntrl4[w]);
				glColor3f(1.0, 0.0, 1.0);
				glRasterPos2f(-100.0, 0.0);
				for (w = 0; w < sizeof(cntrl5); w++)
					glutBitmapCharacter(GLUT_BITMAP_9_BY_15, cntrl5[w]);
				glColor3f(1.0, 0.0, 1.0);
				glRasterPos2f(-100.0, -50.0);
				for (w = 0; w < sizeof(cntrl6); w++)
					glutBitmapCharacter(GLUT_BITMAP_9_BY_15, cntrl6[w]);
				glColor3f(1.0, 0.0, 1.0);
				glRasterPos2f(-100.0, -100.0);
				for (w = 0; w < sizeof(cntrl7); w++)
					glutBitmapCharacter(GLUT_BITMAP_9_BY_15, cntrl7[w]);
				glColor3f(1.0, 0.0, 1.0);
				glRasterPos2f(-100.0, -150.0);
				for (w = 0; w < sizeof(cntrl8); w++)
					glutBitmapCharacter(GLUT_BITMAP_9_BY_15, cntrl8[w]);
				glColor3f(1.0, 0.0, 1.0);
				glRasterPos2f(-100.0, -200.0);
				for (w = 0; w < sizeof(cntrl9); w++)
					glutBitmapCharacter(GLUT_BITMAP_9_BY_15, cntrl9[w]);


				glColor3f(0.0, 1.0, 0.0);
				glRasterPos2f(140.0, -330.0);
				for (w = 0; w < sizeof(bck); w++)
					glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, bck[w]);

				glFlush();
			}

			glFlush();
		}
		glFlush();
	}

	else
	{
		GLfloat i, j;
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glPushMatrix();
		glRotatef(xangle, 1.0, 0.0, 0.0);
		glRotatef(yangle, 0.0, 1.0, 0.0);
		glRotatef(zangle, 0.0, 0.0, 1.0);
		glTranslatef(xt, yt, 0.0);

		/* back wall where lift is located */
		glColor3f(1.0, 0.0, 1.0);
		glPushMatrix();

		glBegin(GL_QUADS);
		glVertex3f(-70.0, -360.0, -200.0);
		glVertex3f(70.0, -360.0, -200.0);
		glVertex3f(70.0, 360.0, -200.0);
		glVertex3f(-70.0, 360.0, -200.0);
		glEnd();

		glPopMatrix();

		/* right wall where lift is located */
		glColor3f(1.0, 0.0, 0.0);
		glPushMatrix();

		glBegin(GL_QUADS);
		glVertex3f(70.0, -360.0, -50.0);
		glVertex3f(70.0, -360.0, -200.0);
		glVertex3f(70.0, 360.0, -200.0);
		glVertex3f(70.0, 360.0, -50.0);
		glEnd();

		glPopMatrix();

		/* left wall where lift is located */
		glColor3f(1.0, 0.0, 0.0);
		glPushMatrix();

		glBegin(GL_QUADS);
		glVertex3f(-70.0, -360.0, -50.0);
		glVertex3f(-70.0, -360.0, -200.0);
		glVertex3f(-70.0, 360.0, -200.0);
		glVertex3f(-70.0, 360.0, -50.0);
		glEnd();

		glPopMatrix();

		/* floor where lift is located only at ground floor */
		glPushMatrix();
		glBegin(GL_QUADS);
		glVertex3f(-70.0, -360.0, -50.0);
		glVertex3f(70.0, -360.0, -50.0);
		glVertex3f(70.0, -360.0, -200.0);
		glVertex3f(-70.0, -360.0, -200.0);
		glEnd();

		glPopMatrix();


		/* upper portion */
		glColor3f(0.0, 1.0, 0.0);
		glPushMatrix();

		glBegin(GL_QUADS);
		glVertex3f(-270.0, 360.0, 0.0);
		glVertex3f(270.0, 360.0, 0.0);
		glVertex3f(270.0, 360.0, -50.0);
		glVertex3f(-270.0, 360.0, -50.0);
		glEnd();

		glPopMatrix();

		/* left portion */
		glColor3f(0.0, 1.0, 0.0);
		glPushMatrix();

		glBegin(GL_QUADS);
		glVertex3f(-270.0, -360.0, 0.0);
		glVertex3f(-270.0, -360.0, -50.0);
		glVertex3f(-270.0, 360.0, -50.0);
		glVertex3f(-270.0, 360.0, 0.0);
		glEnd();

		glPopMatrix();

		/* right portion */
		glColor3f(0.0, 1.0, 0.0);
		glPushMatrix();

		glBegin(GL_QUADS);
		glVertex3f(270.0, -360.0, 0.0);
		glVertex3f(270.0, -360.0, -50.0);
		glVertex3f(270.0, 360.0, -50.0);
		glVertex3f(270.0, 360.0, 0.0);
		glEnd();
		glPopMatrix();

		/* left back wall */
		glColor3f(1.0, 1.0, 0.0);
		glPushMatrix();

		glBegin(GL_QUADS);
		glVertex3f(-270.0, -360.0, -50.0);
		glVertex3f(-70.0, -360.0, -50.0);
		glVertex3f(-70.0, 360.0, -50.0);
		glVertex3f(-270.0, 360.0, -50.0);
		glEnd();
		glPopMatrix();

		/* right back wall */
		glColor3f(1.0, 1.0, 0.0);
		glPushMatrix();

		glBegin(GL_QUADS);
		glVertex3f(70.0, -360.0, -50.0);
		glVertex3f(270.0, -360.0, -50.0);
		glVertex3f(270.0, 360.0, -50.0);
		glVertex3f(70.0, 360.0, -50.0);
		glEnd();

		glPopMatrix();

		/* draw elevator */
		ele_draw();

		/*tiles in front of elevator doors */
		glColor3f(0.0, 0.0, 1.0);      //FOR BLUE TILES
		glPushMatrix();
		for (i = -70; i < 70; i = i + 70)
		{
			for (j = -360; j < 360; j = j + 200)
			{
				if (j == 40) j = -120;
				if (j == 280) j = 120;

				glBegin(GL_QUADS);
				glVertex3f(i, j, 0.0);
				glVertex3f(i + 35, j, 0.0);
				glVertex3f(i + 35, j, -50.0);
				glVertex3f(i, j, -50.0);
				glEnd();
			}
		}
		glPopMatrix();

		glColor3f(0.0, 1.0, 0.0);			//FOR GREEN TILES
		glPushMatrix();
		for (i = -35; i < 70; i = i + 70)
		{
			for (j = -360; j < 360; j = j + 200)
			{
				if (j == 40) j = -120;
				if (j == 280) j = 120;

				glBegin(GL_QUADS);
				glVertex3f(i, j, 0.0);
				glVertex3f(i + 35, j, 0.0);
				glVertex3f(i + 35, j, -50.0);
				glVertex3f(i, j, -50.0);
				glEnd();
			}
		}
		glPopMatrix();
		/* tiles end */

		/* line loop for all till the above */

		/* back wall where lift is located */
		glColor3f(1.0, 0.0, 1.0);
		glBegin(GL_LINE_LOOP);
		glVertex3f(-70.0, -360.0, -200.0);
		glVertex3f(70.0, -360.0, -200.0);
		glVertex3f(70.0, 360.0, -200.0);
		glVertex3f(-70.0, 360.0, -200.0);
		glEnd();


		/* right wall where lift is located */
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_LINE_LOOP);
		glVertex3f(70.0, -360.0, -50.0);
		glVertex3f(70.0, -360.0, -200.0);
		glVertex3f(70.0, 360.0, -200.0);
		glVertex3f(70.0, 360.0, -50.0);
		glEnd();

		/* left wall where lift is located */
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_LINE_LOOP);
		glVertex3f(-70.0, -360.0, -50.0);
		glVertex3f(-70.0, -360.0, -200.0);
		glVertex3f(-70.0, 360.0, -200.0);
		glVertex3f(-70.0, 360.0, -50.0);
		glEnd();

		/* upper portion */
		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_LINE_LOOP);
		glVertex3f(-270.0, 360.0, 0.0);
		glVertex3f(270.0, 360.0, 0.0);
		glVertex3f(270.0, 360.0, -50.0);
		glVertex3f(-270.0, 360.0, -50.0);
		glEnd();

		/* left portion */
		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_LINE_LOOP);
		glVertex3f(-270.0, -360.0, 0.0);
		glVertex3f(-270.0, -360.0, -50.0);
		glVertex3f(-270.0, 360.0, -50.0);
		glVertex3f(-270.0, 360.0, 0.0);
		glEnd();

		/* right portion */
		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_LINE_LOOP);
		glVertex3f(270.0, -360.0, 0.0);
		glVertex3f(270.0, -360.0, -50.0);
		glVertex3f(270.0, 360.0, -50.0);
		glVertex3f(270.0, 360.0, 0.0);
		glEnd();

		/* left back wall */
		glColor3f(1.0, 1.0, 0.0);
		glBegin(GL_LINE_LOOP);
		glVertex3f(-270.0, -360.0, -50.0);
		glVertex3f(-70.0, -360.0, -50.0);
		glVertex3f(-70.0, 360.0, -50.0);
		glVertex3f(-270.0, 360.0, -50.0);
		glEnd();

		/* right back wall */
		glColor3f(1.0, 1.0, 0.0);
		glBegin(GL_LINE_LOOP);
		glVertex3f(70.0, -360.0, -50.0);
		glVertex3f(270.0, -360.0, -50.0);
		glVertex3f(270.0, 360.0, -50.0);
		glVertex3f(70.0, 360.0, -50.0);
		glEnd();

		/* floor where lift is located */
		glBegin(GL_LINE_LOOP);
		glVertex3f(-70.0, -360.0, -50.0);
		glVertex3f(70.0, -360.0, -50.0);
		glVertex3f(70.0, -360.0, -200.0);
		glVertex3f(-70.0, -360.0, -200.0);
		glEnd();

		/* tiles in front of elevator door */
		glColor3f(0.0, 0.0, 1.0);
		for (i = -70; i < 70; i = i + 70)
		{
			for (j = -360; j < 340; j = j + 200)
			{
				if (j == 40) j = -120;
				if (j == 280) j = 120;

				glBegin(GL_LINE_LOOP);
				glVertex3f(i, j, 0.0);
				glVertex3f(i + 35, j, 0.0);
				glVertex3f(i + 35, j, -50.0);
				glVertex3f(i, j, -50.0);
				glEnd();
			}
		}

		glColor3f(0.0, 1.0, 0.0);
		for (i = -35; i < 70; i = i + 70)
		{
			for (j = -360; j < 340; j = j + 200)
			{
				if (j == 40) j = -120;
				if (j == 280) j = 120;

				glBegin(GL_LINE_LOOP);
				glVertex3f(i, j, 0.0);
				glVertex3f(i + 35, j, 0.0);
				glVertex3f(i + 35, j, -50.0);
				glVertex3f(i, j, -50.0);
				glEnd();
			}
		}
		/* tiles end */

		/* line loop ends */

		/* lift doors */

		lift_doors0();
		lift_doors1();
		lift_doors2();
		lift_doors3();
		lift_doors4();
		lift_doors5();

		/* lift door ends */

		/* draw the bricks on the left part of front wall */
		glColor3f(0.7, 0.7, 0.7);

		for (j = -360; j < 320; j = j + 200)
		{
			if (j == -160 || j == -140) j = -120;
			if (j == 80 || j == 100)j = 120;


			glBegin(GL_QUADS);
			glVertex3f(-270, j, 0.0);
			glVertex3f(-70.0, j, 0.0);
			glVertex3f(-70.0, j + 200.0, 0.0);
			glVertex3f(-270.0, j + 200.0, 0.0);
			glEnd();

		}

		/* side bricks between the front wall and the elevator */
		glColor3f(0.0, 0.0, 1.0);
		for (i = -70; i < 80; i = i + 140)
		{
			for (j = -360; j < 340; j = j + 40)
			{
				if (j == -160 || j == -140) j = -120;
				if (j == 80 || j == 100) j = 120;

				glBegin(GL_QUADS);
				glVertex3f(i, j, 0.0);
				glVertex3f(i, j, -50.0);
				glVertex3f(i, j + 20.0, -50.0);
				glVertex3f(i, j + 20.0, 0.0);
				glEnd();
			}
		}

		glColor3f(0.0, 1.0, 1.0);
		for (i = -70; i < 80; i = i + 140)
		{
			for (j = -340; j < 340; j = j + 40)
			{
				if (j == -160 || j == -140) j = -100;
				if (j == 80 || j == 100) j = 140;

				glBegin(GL_QUADS);
				glVertex3f(i, j, 0.0);
				glVertex3f(i, j, -50.0);
				glVertex3f(i, j + 20.0, -50.0);
				glVertex3f(i, j + 20.0, 0.0);
				glEnd();
			}
		}
		/* ends */

		/* line loop for left side of front wall */

		glColor3f(1.0, 1.0, 1.0);
		for (i = -270; i < -70; i = i + 100)
		{
			for (j = -360; j < 340; j = j + 40)
			{
				if (j == -160 || j == -140) j = -120;
				if (j == 80 || j == 100) j = 120;

				glBegin(GL_LINE_LOOP);
				glVertex3f(i, j, 0.0);
				glVertex3f(i + 50.0, j, 0.0);
				glVertex3f(i + 50.0, j + 20.0, 0.0);
				glVertex3f(i, j + 20.0, 0.0);
				glEnd();
			}
		}

		for (i = -245; i < -70; i = i + 100)
		{
			for (j = -340; j < 340; j = j + 40)
			{
				if (j == -160 || j == -140) j = -100;
				if (j == 80 || j == 100) j = 140;

				glBegin(GL_LINE_LOOP);
				glVertex3f(i, j, 0.0);
				glVertex3f(i + 50.0, j, 0.0);
				glVertex3f(i + 50.0, j + 20.0, 0.0);
				glVertex3f(i, j + 20.0, 0.0);
				glEnd();
			}
		}

		for (i = -220; i < -70; i = i + 100)
		{
			for (j = -360; j < 340; j = j + 40)
			{
				if (j == -160 || j == -140) j = -120;
				if (j == 80 || j == 100) j = 120;

				glBegin(GL_LINE_LOOP);
				glVertex3f(i, j, 0.0);
				glVertex3f(i + 50.0, j, 0.0);
				glVertex3f(i + 50.0, j + 20.0, 0.0);
				glVertex3f(i, j + 20.0, 0.0);
				glEnd();
			}
		}

		for (i = -195; i < -70; i = i + 100)
		{
			for (j = -340; j < 340; j = j + 40)
			{
				if (j == -160 || j == -140) j = -100;
				if (j == 80 || j == 100) j = 140;
				if (i < -95.0)
				{
					glBegin(GL_LINE_LOOP);
					glVertex3f(i, j, 0.0);
					glVertex3f(i + 50.0, j, 0.0);
					glVertex3f(i + 50.0, j + 20.0, 0.0);
					glVertex3f(i, j + 20.0, 0.0);
					glEnd();
				}
				else
				{
					glBegin(GL_LINE_LOOP);
					glVertex3f(i, j, 0.0);
					glVertex3f(i + 25.0, j, 0.0);
					glVertex3f(i + 25.0, j + 20.0, 0.0);
					glVertex3f(i, j + 20.0, 0.0);
					glEnd();
				}
			}
		}

		for (j = -340; j < 340; j = j + 40)
		{
			if (j == -160 || j == -140) j = -100;
			if (j == 80 || j == 100) j = 140;

			glBegin(GL_LINE_LOOP);
			glVertex3f(-270.0, j, 0.0);
			glVertex3f(-245.0, j, 0.0);
			glVertex3f(-245.0, j + 20.0, 0.0);
			glVertex3f(-270.0, j + 20.0, 0.0);
			glEnd();
		}

		/* LINE LOOP ENDS */

		/* side bricks line loop */
		glColor3f(1.0, 1.0, 1.0);
		for (i = -70; i < 80; i = i + 140)
		{
			for (j = -360; j < 340; j = j + 40)
			{
				if (j == -160 || j == -140) j = -120;
				if (j == 80 || j == 100) j = 120;

				glBegin(GL_LINE_LOOP);
				glVertex3f(i, j, 0.0);
				glVertex3f(i, j, -50.0);
				glVertex3f(i, j + 20.0, -50.0);
				glVertex3f(i, j + 20.0, 0.0);
				glEnd();
			}
		}

		glColor3f(1.0, 1.0, 1.0);
		for (i = -70; i < 80; i = i + 140)
		{
			for (j = -340; j < 340; j = j + 40)
			{
				if (j == -160 || j == -140) j = -100;
				if (j == 80 || j == 100) j = 140;

				glBegin(GL_LINE_LOOP);
				glVertex3f(i, j, 0.0);
				glVertex3f(i, j, -50.0);
				glVertex3f(i, j + 20.0, -50.0);
				glVertex3f(i, j + 20.0, 0.0);
				glEnd();
			}
		}
		/* side bricks line loop ends */

		/* right front wall */
		glColor3f(0.7, 0.7, 0.7);
		for (j = -360; j < 320; j = j + 200)
		{
			if (j == -160 || j == -140) j = -120;
			if (j == 80 || j == 100) j = 120;

			glBegin(GL_QUADS);
			glVertex3f(70, j, 0.0);
			glVertex3f(270.0, j, 0.0);
			glVertex3f(270.0, j + 200.0, 0.0);
			glVertex3f(70, j + 200.0, 0.0);
			glEnd();
		}

		/* line loop for front right wall */
		glColor3f(1.0, 1.0, 1.0);
		for (i = 70; i < 270; i = i + 100)
		{
			for (j = -360; j < 340; j = j + 40)
			{
				if (j == -160 || j == -140) j = -120;
				if (j == 80 || j == 100) j = 120;

				glBegin(GL_LINE_LOOP);
				glVertex3f(i, j, 0.0);
				glVertex3f(i + 50.0, j, 0.0);
				glVertex3f(i + 50.0, j + 20.0, 0.0);
				glVertex3f(i, j + 20.0, 0.0);
				glEnd();
			}
		}

		for (i = 95; i < 270; i = i + 100)
		{
			for (j = -340; j < 340; j = j + 40)
			{
				if (j == -160 || j == -140) j = -100;
				if (j == 80 || j == 100) j = 140;

				glBegin(GL_LINE_LOOP);
				glVertex3f(i, j, 0.0);
				glVertex3f(i + 50.0, j, 0.0);
				glVertex3f(i + 50.0, j + 20.0, 0.0);
				glVertex3f(i, j + 20.0, 0.0);
				glEnd();
			}
		}

		for (i = 120; i < 270; i = i + 100)
		{
			for (j = -360; j < 340; j = j + 40)
			{
				if (j == -160 || j == -140) j = -120;
				if (j == 80 || j == 100) j = 120;

				glBegin(GL_LINE_LOOP);
				glVertex3f(i, j, 0.0);
				glVertex3f(i + 50.0, j, 0.0);
				glVertex3f(i + 50.0, j + 20.0, 0.0);
				glVertex3f(i, j + 20.0, 0.0);
				glEnd();
			}
		}

		for (i = 145; i < 270; i = i + 100)
		{
			for (j = -340; j < 340; j = j + 40)
			{
				if (j == -160 || j == -140) j = -100;
				if (j == 80 || j == 100) j = 140;
				if (i < 245.0)
				{
					glBegin(GL_LINE_LOOP);
					glVertex3f(i, j, 0.0);
					glVertex3f(i + 50.0, j, 0.0);
					glVertex3f(i + 50.0, j + 20.0, 0.0);
					glVertex3f(i, j + 20.0, 0.0);
					glEnd();
				}
				else
				{
					glBegin(GL_LINE_LOOP);
					glVertex3f(i, j, 0.0);
					glVertex3f(i + 25.0, j, 0.0);
					glVertex3f(i + 25.0, j + 20.0, 0.0);
					glVertex3f(i, j + 20.0, 0.0);
					glEnd();
				}
			}
		}

		for (j = -340; j < 340; j = j + 40)
		{
			if (j == -160 || j == -140) j = -100;
			if (j == 80 || j == 100) j = 140;

			glBegin(GL_LINE_LOOP);
			glVertex3f(70.0, j, 0.0);
			glVertex3f(95.0, j, 0.0);
			glVertex3f(95.0, j + 20.0, 0.0);
			glVertex3f(70.0, j + 20.0, 0.0);
			glEnd();
		}

		/* line loop for front right wall ends */

		/* blocks between floors */
		for (j = -160; j < 360; j = j + 240)
		{
			glColor3f(1.0, 0.0, 0.1);
			glBegin(GL_QUADS);
			glVertex3f(-270.0, j, 0.0);
			glVertex3f(270.0, j, 0.0);
			glVertex3f(270.0, j + 40, 0.0);
			glVertex3f(-270.0, j + 40, 0.0);
			glEnd();

			glColor3f(1.0, 1.0, 1.0);
			glBegin(GL_LINE_LOOP);
			glVertex3f(-270.0, j, 0.0);
			glVertex3f(270.0, j, 0.0);
			glVertex3f(270.0, j + 40, 0.0);
			glVertex3f(-270.0, j + 40, 0.0);
			glEnd();
		}


		//blocks between floor ends
		glPopMatrix();

		glFlush();
	}

	glutPostRedisplay();
}

void NormalKey(GLubyte key, GLint x, GLint y)
{
	if (key == 'v')
		menu1 = 1;
	if (key == '6')
		menu = 1;
	if (key == '7')
		helpscreen = 1;
	if (key == 'b' && menu1 == 1)
	{
		menu = 0;
		menu1 = 0;
	}
	if (key == 'b' && helpscreen == 1)
	{
		menu1 = 1;
		helpscreen = 0;
	}
	switch (key)
	{
	case ESCAPE:
		printf("escape pressed. exit.\n");
		//glutDestroyWindow(window);	/* Kill our window */
		exit(0); 			/* Very dirty exit */
		break;				/* Do we need this??? */

	case 's':
		glRotatef(90.0, 0.0, 1.0, 0.0);
		glutPostRedisplay();
		break;

	case 'X':
		xangle += 5.0;
		glutPostRedisplay();
		break;

	case 'x':
		xangle -= 5.0;
		glutPostRedisplay();
		break;

	case 'Y':
		yangle += 5.0;
		glutPostRedisplay();
		break;

	case 'y':
		yangle -= 5.0;
		glutPostRedisplay();
		break;

	case 'Z':
		zangle += 5.0;
		glutPostRedisplay();
		break;

	case 'z':
		zangle -= 5.0;
		glutPostRedisplay();
		break;

	case 'a':                          /* Move to right */
		xt += 0.2;
		glutPostRedisplay();
		break;

	case 'A':
		xt -= 0.2;                      /* Move to left */
		glutPostRedisplay();
		break;

	case 'g':                          /* Move up */
		yt += 0.2;
		glutPostRedisplay();
		break;

	case 'G':
		yt -= 0.2;                      /* Move down */
		glutPostRedisplay();
		break;

	case '1':
		glClear(GL_COLOR_BUFFER_BIT);
		if (floor == 0)
			glutTimerFunc(delay, timer, 1);

		else if (floor == 2)
			glutTimerFunc(delay, timer1, 1);
		break;

	case '2':
		glClear(GL_COLOR_BUFFER_BIT);
		glutTimerFunc(delay, timer2, 1);
		break;

	case '0':
		glClear(GL_COLOR_BUFFER_BIT);
		glutTimerFunc(delay, timer3, 1);
		break;

	case 'o':
		if (floor == 0)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			glutTimerFunc(delay, timer4, 1);
		}
		else if (floor == 1)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			glutTimerFunc(delay, timer6, 1);
		}
		else if (floor == 2)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			glutTimerFunc(delay, timer8, 1);
		}
		break;

	case 'c':
		if (floor == 0)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			glutTimerFunc(delay, timer5, 1);
		}
		else if (floor == 1)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			glutTimerFunc(delay, timer7, 1);
		}
		else if (floor == 2)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			glutTimerFunc(delay, timer9, 1);
		}
		break;

	case 'f':
		glEnable(GL_DEPTH_TEST);
		glutPostRedisplay();
		break;

	case 'F':
		glDisable(GL_DEPTH_TEST);
		glutPostRedisplay();
		break;

	default: break;
	}
}



void move()
{
	if (menu == 0)
	{
		z -= 0.5;
		z1 -= 0.5;
		if (z == -300.0)
		{
			z = 250.0;
			z1 = 270.0;
		}
	}
}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);// | GLUT_DEPTH);
	glutInitWindowSize(Xsize, Ysize);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("elevator");
	myInit();
	glutIdleFunc(move);
	glutDisplayFunc(display);
	glutKeyboardFunc(NormalKey);
	//glutTimerFunc(1000/n,myTimer,1000);
//    glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}