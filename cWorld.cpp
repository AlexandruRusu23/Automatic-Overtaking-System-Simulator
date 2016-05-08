#include "cWorld.h"

cWorld::cWorld(void) {}
cWorld::~cWorld(void){}

bool cWorld::Init()
{
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-20, 20, -10.0, 10.0, -1.0, 100.0);

	glMatrixMode(GL_MODELVIEW);

	Traffic.Init();
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
			Traffic.CreateCar(0, rand()%3 + 1, 20); // lane , type, xPosition
		break;
		case '2':
			Traffic.CreateCar(1, rand()%3 + 1, 20);
		break;
		case '3':
			Traffic.CreateCar(2, rand()%3 + 1, 20);
		break;
		case '4':
			Traffic.CreateCar(3, rand()%3 + 1, 20);
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
			//Player will get initial speed
		break;
		case 'w':
			Traffic.setMovePlayer(4);
			//Player will get Traffic's speed
		break;
		case 'k':
			Traffic.setMovePlayer(5);
			//Player will go back ( not sure how much ) -- beta version
		break;
	}
}

void cWorld::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	Traffic.DrawRoad();

	Traffic.DrawCars();

	Traffic.DrawPlayer();

	Traffic.DisplayAOS();
	
	glutSwapBuffers();

	usleep(10000);
}
