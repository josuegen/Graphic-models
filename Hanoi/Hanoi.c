#include <windows.h>
#include <GL/glut.h>


#include <stdlib.h>


static int giro = 0;
GLfloat altura = 1.3;
GLfloat s1=0;
GLfloat horizontal=0;
GLfloat s2=1;
GLfloat i;
GLfloat altura2 = 0.8;
GLfloat altura3 = 0.4;
GLUquadricObj *cilindro;

void init(void)
{
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_FLAT);
}


void display(void)
{
     cilindro = gluNewQuadric();
     gluQuadricDrawStyle(cilindro,GLU_LINE);

     const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

	glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);

 glPushMatrix();

	gluLookAt(0,-1.75,6,   0,0,0,   0,1,0);
	glRotated(90,0,-1,0);

    glTranslatef(-1.0, -5.0, 3.0);
	glRotatef((GLfloat) giro, 0.0,0.0,1.0);
	glTranslatef(1.0, 0.0, 0.0);

    glPushMatrix();
	glScalef(2.0, 0.4, 2.0);
    glutWireCube(1.0);
	glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 0.2, 0.0);
    glRotated(90,-1,0,0);
    gluCylinder(cilindro,.1,.1,2,10,10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 0.0, -3.0);
	glScalef(2.0, 0.4, 2.0);
	glutWireCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.2, -3.0);
    glRotated(90,-1,0,0);
	gluCylinder(cilindro,.1,.1,2,10,10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 0.0, -6.0);
	glScalef(2.0, 0.4, 2.0);
	glutWireCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.2, -6.0);
    glRotated(90,-1,0,0);
	gluCylinder(cilindro,.1,.1,2,10,10);
    glPopMatrix();

    glPushMatrix();        //TOROIDE rojo
    glTranslatef(0.0f,altura3, -0.0f);
    glRotatef(90.0, 1.0f, 0.0f, 0.0f);
    glColor3d(1.0,0.0,0.0);
    glutWireTorus(0.2,1.5,8,8);
    glPopMatrix();


	glPushMatrix();        //TOROIDE verde
    glTranslatef(0.0f,altura2, -0.0f);
    glRotatef(90.0, 1.0f, 0.0f, 0.0f);
    glColor3d(0.0,1.0,0.0);
    glutWireTorus(0.2,1.1,8,8);
    glPopMatrix();

    glPushMatrix();        //TOROIDE azul
    glTranslatef(0.0f,altura,-horizontal);
    glRotatef(90.0, 1.0f, 0.0f, 0.0f);
    glColor3d(0.0,0.0,1.0);
    glutWireTorus(0.2,0.6,8,8);
    glPopMatrix();

 glPopMatrix();
	glutSwapBuffers();
	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0,0,(GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0,(GLfloat)w/(GLfloat)h,1.0,20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0,0.0,-5.0);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key){
		case 's':
		   giro = (giro +90) %360;
		   glutPostRedisplay();
			break;

		case 'S':
		   giro = (giro -90) %360;
		   glutPostRedisplay();
			break;

		case '27':
		   exit(0);
		 default:
			break;
	}
}

static void idle(void)
{

   if(altura<6){
      altura += .1;
      if(altura>3.1){
         horizontal +=.25;
      }
   }

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
    	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(idle);
	glutMainLoop();
	return 0;
}
