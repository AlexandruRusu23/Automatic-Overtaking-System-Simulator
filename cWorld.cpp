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

	Car.setPlayer(true);
	Car.setType(0);
	Car.setPosition(2,-2.0);
	Car.Init();

	Car1.setType(1);
	Car1.setPosition(0,-8.0);
	Car1.Init();

	Car2.setType(2);
	Car2.setPosition(1,5.0);
	Car2.Init();

	Car3.setType(1);
	Car3.setPosition(3,5.0);
	Car3.Init();
}

void cWorld::Keyboard(unsigned char key, int x, int y)
{
	int lane = Car.getLane();
	float xPos = Car.getxPosition();
	switch(key)
	{
		case 27:
			exit(0);
		break;
		case 'd': //move the car on the lane above
			if(lane<3)
			{
				lane++;
				Car.setPosition(lane,xPos);
			}
		break;
		case 'u': //move the car on the lane below
			if(lane>0)
			{
				lane--;
				Car.setPosition(lane,xPos);
			}
		break;
		case 'n':
			//make a new car
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

	Car.draw();
	Car1.draw();
	Car2.draw();
	Car3.draw();

	glutSwapBuffers();

	usleep(10000);
}
