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
	Road.Init();
	Traffic.CreateCar(true, 2, 0, -2);
}

void cWorld::Keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 27:
			exit(0);
		break;
		case '1':
			Traffic.CreateCar(false, 0, rand()%4, 0);
		break;
		case '2':
			Traffic.CreateCar(false, 1, rand()%4, 0);
		break;
		case '3':
			Traffic.CreateCar(false, 2, rand()%4, 0);
		break;
		case '4':
			Traffic.CreateCar(false, 3, rand()%4, 0);
		break;
	}
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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(0.0,0.0,-5.0);

	Road.draw();

	Traffic.DrawCars();
	
	glutSwapBuffers();

	usleep(10000);
}
