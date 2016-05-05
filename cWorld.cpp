#include "cWorld.h"

cWorld::cWorld(void) {}
cWorld::~cWorld(void){}

bool cWorld::Init()
{
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(PERSPECTIVE_SIZE,(float)SCREEN_WIDTH/(float)SCREEN_HEIGHT,1.0,5000.0);
	glMatrixMode(GL_MODELVIEW);
	Traffic.LoadRoad();
	Traffic.LoadPlayer();
}

void cWorld::Keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 27:
			exit(0);
		break;
		case '1':
			Traffic.CreateCar(0, rand()%3 + 1, 10); // lane , type, xPosition
		break;
		case '2':
			Traffic.CreateCar(1, rand()%3 + 1, 10);
		break;
		case '3':
			Traffic.CreateCar(2, rand()%3 + 1, 10);
		break;
		case '4':
			Traffic.CreateCar(3, rand()%3 + 1, 10);
		break;
		case 'a':
			Traffic.setMovePlayer(1);
			//Move Player on left lane
		break;
		case 'd':
			Traffic.setMovePlayer(2);
			//Move Player on right lane
		break;
		case 's':
			Traffic.setMovePlayer(3);
			//increase Player speed
		break;
		case 'w':
			Traffic.setMovePlayer(4);
			//decrease Player speed
		break;
	}
}

void cWorld::enclosetextarea() {

	
	glColor3f(1.0,1.0,1.0);
	glLineWidth(3.0);
	glPolygonMode(GL_FRONT,GL_LINE);
	glBegin(GL_POLYGON);

		glVertex2f(-17.0,-4.5);
		glVertex2f(-17.0,-8.4);			
		glVertex2f(17.0,-8.4);
		glVertex2f(17.0,-4.5);
			
	glEnd();

	/*glRasterPos2f(-0.6,4.85);
	for (int i=0;i<message->size();i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,(int)((*message)[i]));
*/
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
}

void cWorld::Reshape(int w, int h)
{
    glViewport (0, 0, w, h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective (PERSPECTIVE_SIZE, (float) w / (float) h, 1.0, 5000.0);
    glMatrixMode (GL_MODELVIEW);
}

void cWorld::Render()
{
	str = new string("SAL");

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(0.0,0.0,-5.0);

	Traffic.DrawRoad();

	enclosetextarea();

	Traffic.DrawCars();

	Traffic.DrawPlayer();

	Traffic.DisplayPlayerState();
	
	glutSwapBuffers();

	usleep(10000);
}
