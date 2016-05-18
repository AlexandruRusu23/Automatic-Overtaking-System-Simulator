#include "eGame.h"

eGame::eGame() {}
eGame::~eGame(){}

void eGame::Init()
{
	//setting the view area using glOrtho
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-VISIBLE_X, VISIBLE_X, -VISIBLE_Y, VISIBLE_Y, -1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);

	//initialize objects data and texture
	Data.Load();
	Road.Load(Data.GetID(IMG_ROAD));
	Player.Init(Data.GetID(IMG_PORSCHE));

	state_vehicle_speed = LOW_SPEED;
}

void eGame::Keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 27:
			exit(0);
		break;
		case '1':
			if(state_vehicle_speed == HIGH_SPEED)
				newVehicle.setChangeSpeed(HIGH_SPEED);
			if(state_vehicle_speed == MEDIUM_SPEED)
				newVehicle.setChangeSpeed(MEDIUM_SPEED);
			if(state_vehicle_speed == LOW_SPEED)
				newVehicle.setChangeSpeed(LOW_SPEED);
			newVehicle.Init(LANE_1, VISIBLE_X, Data.GetID(IMG_MERCEDES));
			if(checkFreeSpace(LANE_1, VISIBLE_X))
				Vehicle.push_back(newVehicle);
		break;
		case '2':
			if(state_vehicle_speed == HIGH_SPEED)
				newVehicle.setChangeSpeed(HIGH_SPEED);
			if(state_vehicle_speed == MEDIUM_SPEED)
				newVehicle.setChangeSpeed(MEDIUM_SPEED);
			if(state_vehicle_speed == LOW_SPEED)
				newVehicle.setChangeSpeed(LOW_SPEED);
			newVehicle.Init(LANE_2, VISIBLE_X, Data.GetID(IMG_RETRO));
			if(checkFreeSpace(LANE_2, VISIBLE_X))
				Vehicle.push_back(newVehicle);
		break;
		case '3':
			if(state_vehicle_speed == HIGH_SPEED)
				newVehicle.setChangeSpeed(HIGH_SPEED);
			if(state_vehicle_speed == MEDIUM_SPEED)
				newVehicle.setChangeSpeed(MEDIUM_SPEED);
			if(state_vehicle_speed == LOW_SPEED)
				newVehicle.setChangeSpeed(LOW_SPEED);
			newVehicle.Init(LANE_3, -VISIBLE_X, Data.GetID(IMG_POLICE));
			if(checkFreeSpace(LANE_3, -VISIBLE_X))
				Vehicle.push_back(newVehicle);
		break;
		case '4':
			if(state_vehicle_speed == HIGH_SPEED)
				newVehicle.setChangeSpeed(HIGH_SPEED);
			if(state_vehicle_speed == MEDIUM_SPEED)
				newVehicle.setChangeSpeed(MEDIUM_SPEED);
			if(state_vehicle_speed == LOW_SPEED)
				newVehicle.setChangeSpeed(LOW_SPEED);
			newVehicle.Init(LANE_4, -VISIBLE_X, Data.GetID(IMG_MERCEDES));
			if(checkFreeSpace(LANE_4, -VISIBLE_X))
				Vehicle.push_back(newVehicle);
		break;
		case 'o':
			Road.setSetValue(3);
		break;
		case 'k':
			Road.setSetValue(2);
		break;
		case 'm':
			Road.setSetValue(1);
		break;
		case 'w':
			for(vector <eVehicle>::iterator it=Vehicle.begin(); it!= Vehicle.end(); it++)
			{
				(*it).setChangeSpeed(HIGH_SPEED);
			}
			state_vehicle_speed = HIGH_SPEED;
		break;
		case 's':
			for(vector <eVehicle>::iterator it=Vehicle.begin(); it!= Vehicle.end(); it++)
			{
				(*it).setChangeSpeed(MEDIUM_SPEED);
			}		
			state_vehicle_speed = MEDIUM_SPEED;
		break;
		case 'x':
			for(vector <eVehicle>::iterator it=Vehicle.begin(); it!= Vehicle.end(); it++)
			{
				(*it).setChangeSpeed(LOW_SPEED);
			}		
			state_vehicle_speed = LOW_SPEED;
		break;
		case 'a':
			Player.setChangeLane(GO_TO_LEFT);
		break;
		case 'd':
			Player.setChangeLane(GO_TO_RIGHT);
		break;
	}
}

void eGame::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	Road.Draw();

	Player.Draw();

	for(vector <eVehicle>::iterator it=Vehicle.begin(); it!= Vehicle.end(); it++)
	{
		(*it).Draw();
	}

	glutSwapBuffers();

	usleep(10000);
}

bool eGame::checkFreeSpace(int lane, float xPos)
{
	if(Player.getLane() == lane)
	{
		if(abs (Player.getxValue() - xPos) < 11 )
			return false;
	}
	for(vector<eVehicle>::iterator it=Vehicle.begin(); it!=Vehicle.end(); it++)
	{
		if((*it).getLane() == lane)
		{
			if(abs( (*it).getxValue() - xPos) < 11 )
			{
				return false;
			}
		}
	}
	return true;
}