#include <GL/glut.h>
#include<stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<math.h>
#include <iostream>

// turtle run from object

GLfloat angle1 = 160.0;
GLfloat angle2 = 200.0;
GLfloat angle3 = 200.0;
float m = 0;
float mount = 0;
float mm = 500;
float flag = 0;
float flag2 = 500;
double F = 0;
float b2_speed = 5;
int counter = 0;
#define PI 3.1416
void circle(GLdouble rad);


//done
float xr = 0, yr = 0;
float ar = 0, sr = 0;
void specialkey(int key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_UP: //when the UP key pressed
		if (yr < 380) {
			if((xr <= 200 && xr>= -400) && (yr == 15)){
			
			}else{
						yr = yr + 15;
			glutPostRedisplay();
			}



		}else{
		
		
		}
		break;
	case GLUT_KEY_DOWN: //when the DOWN key pressed
		if (yr > -150) {
			yr = yr - 15;
			glutPostRedisplay();
		}

		break;
	case GLUT_KEY_LEFT:  //when the LEFT key pressed
		if(xr>-420){
				xr = xr - 15;
		glutPostRedisplay();
		}

		break;
	case GLUT_KEY_RIGHT: //when the RIGHT key pressed
		
		if(xr<250){
		xr = xr + 15;
		glutPostRedisplay();
		}

		break;
	}
}


//done
int i;
void circle(GLdouble rad)
{
	GLint points = 50;
	GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
	GLdouble theta = 0.0;
	glBegin(GL_POLYGON);
	{
		for (i = 0; i <= 50; i++, theta += delTheta)
		{
			glVertex2f(rad * cos(theta), rad * sin(theta));
		}
	}
	glEnd();
}


//done
void Turtle()   // the filled one
{
	//-----------Head------------//
	glPushMatrix();
	glColor3f(0, .5, 0);
	glScalef(.5, .7, .5);
	glTranslatef(110 + 350 + xr, 245 + yr, 1);
	circle(20);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0, 0, 0);
	glScalef(.5, .7, .5);
	glTranslatef(110 + 350 + xr, 245 + yr, 1);
	circle(5);
	glPopMatrix();
	glutPostRedisplay();

	//-----------Leg1-----------//
	glPushMatrix();
	glColor3f(0, .7, 0);
	glScalef(.5, .7, .5);
	glTranslatef(230 + 350, 110, 1);
	glBegin(GL_POLYGON);
	glVertex3f(-80 + xr, 90 + yr, 1);
	glVertex3f(-85 + xr, 70 + yr, 1);
	glVertex3f(-45 + xr, 70 + yr, 1);
	glVertex3f(-50 + xr, 90 + yr, 1);
	glutPostRedisplay();
	glEnd();
	glPopMatrix();
	//-----------LEg2-----------//
	glPushMatrix();
	glColor3f(0, .7, 0);
	glScalef(.5, .7, .5);
	glTranslatef(650, 110, 1);
	glBegin(GL_POLYGON);
	glVertex3f(-80 + xr, 90 + yr, 1);
	glVertex3f(-85 + xr, 70 + yr, 1);
	glVertex3f(-45 + xr, 70 + yr, 1);
	glVertex3f(-50 + xr, 90 + yr, 1);
	glutPostRedisplay();
	glEnd();
	glPopMatrix();
	//-----------Body-----------------//
	glPushMatrix();
	float radius = 70;
	float twoPI = 2 * PI;
	glColor3f(0, .5, 0);
	glScalef(.5, 0.7, .5);
	glTranslatef(200 + 350 + xr, 200 + yr, 1);
	glRotatef(-90, 0, 0, 1);
	glBegin(GL_TRIANGLE_FAN);

	for (float i = PI; i <= twoPI; i += 0.001)
	{
		glVertex2f((sin(i) * radius), (cos(i) * radius));
	}

	glutPostRedisplay();
	glEnd();
	glPopMatrix();

}

//done
void myInit(void)
{
	gluOrtho2D(0.0, 450.0, 0.0, 480.0);
}

//done
void sceenario()
{

	//Road------------------//
	glColor3f(.7, 0.7, 0.7);
	glTranslatef(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2i(0, 20);
	glVertex2i(700, 20);
	glVertex2i(700, 460);
	glVertex2i(0, 460);
	glEnd();

	//-----------Border road--------//
	glColor3f(0.2, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex2i(0, 165);
	glVertex2i(700, 165);
	glVertex2i(700, 160);
	glVertex2i(0, 160);
	glEnd();

	//-----------Border road2--------//
	glColor3f(0.2, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex2i(0, 330);
	glVertex2i(700, 330);
	glVertex2i(700, 325);
	glVertex2i(0, 325);
	glEnd();

}


void move()
{
	if (flag == 0)
	{
		ar = ar + 1;
		sr = sr + 1;
	}
	else if (flag == 1)
	{
		ar = ar + 1;
		sr = sr - 1;
	}
	else if (flag == 2)
	{
		ar = ar - 1;
		sr = sr + 1;
	}
	else if (flag == 3)
	{
		ar = ar - 1;
		sr = sr - 1;
	}
	glutPostRedisplay();
	
	
}










void starting(int a ,int b ,int c,int d)
{
	//sinboard//
	glColor3f(.2, 0.3, 0.7);
	glPushMatrix();
	glBegin(GL_POLYGON);
	glVertex2i(a, d);
	glVertex2i(c, d);
	glVertex2i(c, b);
	glVertex2i(a, b);
	glEnd();
	glPopMatrix();
}


void drowLol()
{
	starting(0,0,450,20);//down straite line
	starting(0,460,450,480);//up straite line
	starting(130,355,320,370);
	starting(130,200,320,215);
	starting(0,270,10,480);//شمال فوق
	starting(0,0,10,160);//شمال تحت
	starting(440,480,450,0);//يمين
	starting(120,200,130,370);





}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	sceenario();
	drowLol();
	glutSpecialFunc(specialkey);
	Turtle();
	
	glEnd();
	glFlush();
	glutPostRedisplay();
	glutSwapBuffers();
	
}



int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(750, 600);
	glutCreateWindow("The Survivor Turtle Game");
	glutDisplayFunc(display);
	myInit();
	glutMainLoop();
	glutSpecialFunc(specialkey);
	glutMainLoop();


	return 0;
}
