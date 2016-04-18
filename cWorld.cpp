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
}

void cWorld::Keyboard(unsigned char key, int x, int y)
{
	if(key == 27) 
		exit(0);
	if(key == 'n')
		Car.makeNewCar();
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

	Road.draw();

	Car.moveCars();

	Car.drawCars();

	glutSwapBuffers();

	usleep(10000);
}
