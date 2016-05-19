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
	newCarButton.InitButton(15.5, -5.5, 4, 4, Data.GetID(IMG_NEW_BUTTON));
	newMercedes.InitButton(7.2, -1.8, 4, 3, Data.GetID(IMG_MERCEDES));
	newRetro.InitButton(11.4, -1.8, 4, 3, Data.GetID(IMG_RETRO));
	newPolice.InitButton(15.8, -1.8, 4, 3, Data.GetID(IMG_POLICE));

	state_vehicle_speed = LOW_SPEED;

	AddCarState = 0;
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

void eGame::Mouse(int button,int state,float x,float y)
{
	if (state == 1) return;
	y = windowHeight - y;
	x = (float)(x / ((float)windowWidth/(VISIBLE_X * 2))) - 20;
	y = (float)(y / ((float)windowHeight/(VISIBLE_Y * 2))) - 10;

	if (newCarButton.insideButton(x,y)) //AddCar button pressed
	{
		AddCarState = 1;
		return;
	}

	if (AddCarState == 1)
	{
		if (newRetro.insideButton(x,y))
		{
			carChoice = IMG_RETRO;
			AddCarState = 2;
			return;
		}
		if (newPolice.insideButton(x,y))
		{
			carChoice = IMG_POLICE;
			AddCarState = 2;
			return;
		}
		if (newMercedes.insideButton(x,y))
		{
			carChoice = IMG_MERCEDES;
			AddCarState = 2;
			return;
		}
		return;
	} 	
	
	if (AddCarState == 2)
	{
		AddCarState = 0;

		if(state_vehicle_speed == HIGH_SPEED)
			newVehicle.setChangeSpeed(HIGH_SPEED);
		if(state_vehicle_speed == MEDIUM_SPEED)
			newVehicle.setChangeSpeed(MEDIUM_SPEED);
		if(state_vehicle_speed == LOW_SPEED)
			newVehicle.setChangeSpeed(LOW_SPEED);
		if(y <= (Y_L1 +0.8) && y >= (Y_L1 -0.8))
		{	
			newVehicle.Init(LANE_1, x , Data.GetID(carChoice));
			if(checkFreeSpace(LANE_1, x ))
				Vehicle.push_back(newVehicle);
		}
		if(y <= (Y_L2 + 1) && y >= (Y_L2 - 1))
		{	
			newVehicle.Init(LANE_2, x , Data.GetID(carChoice));
			if(checkFreeSpace(LANE_2, x ))
				Vehicle.push_back(newVehicle);
		}
		if(y <= (Y_L3 + 1) && y >= (Y_L3 - 1))
		{	
			newVehicle.Init(LANE_3, x , Data.GetID(carChoice));
			if(checkFreeSpace(LANE_3, x ))
				Vehicle.push_back(newVehicle);
		}
		if(y <= (Y_L4 + 1) && y >= (Y_L4 - 1))
		{	
			newVehicle.Init(LANE_4, x , Data.GetID(carChoice));
			if(checkFreeSpace(LANE_4, x ))
				Vehicle.push_back(newVehicle);
		}
		return;
	}
}

void eGame::MouseMotion(float x,float y)
{
	y = windowHeight - y;
	x = (float)(x / ((float)windowWidth/(VISIBLE_X * 2))) - 20;
	y = (float)(y / ((float)windowHeight/(VISIBLE_Y * 2))) - 10;

	if (newCarButton.insideButton(x,y)) //AddCar button pressed
	{
		if (AddCarState == 0) 
			AddCarState = 1;
		return;
	}
}

void eGame::drawUIButtons()
{
	//Render AddCar button
	newCarButton.drawButton();

	//Show car type options
	if (AddCarState == 1)
	{
		newMercedes.drawButton();
		newPolice.drawButton();
		newRetro.drawButton();
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
	
	drawUIButtons();
	
	glutSwapBuffers();

	usleep(10000);
}

void eGame::Reshape(int w,int h)
{
	windowWidth = w;
	windowHeight = h;
	glViewport(0,0,w,h);
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

bool eGame::checkPlayerCollision(int lane, int direction)
{
	for(vector<eVehicle>::iterator it=Vehicle.begin(); it!=Vehicle.end(); it++)
	{
		if((*it).getLane() == lane)
		{
			if(direction == LOOK_FRONT)
			{
				if(Player.getxValue() < (*it).getxValue())
					if(abs(Player.getxValue() - (*it).getxValue()) < FRONT_LIMIT )
						return false;
			}
			if(direction == LOOK_BEHIND)
			{
				if(Player.getxValue() > (*it).getxValue())
					if(abs(Player.getxValue() - (*it).getxValue()) < BEHIND_LIMIT )
						return false;	
			}
			if(direction == LOOK_MIDDLE)
			{
				if(Player.getxValue() + MIDDLE_LIMIT > (*it).getxValue())
				{
					if(Player.getxValue() - (MIDDLE_LIMIT + CAR_LENGTH) < (*it).getxValue())
						return false;
				}
			}
		}
	}
	return true;
}

/*
--------------------------------------
behind  |       middle       | front
--------------------------------------
  behind    | **PLAYER** |   front 
-------------------------------------- 
behind  |     middle         | front

*/

void eGame::vehicleScanner(int lane, int direction) //if there is a car inside the area mentioned return false
{
	
}

//AOS function (in Game because Player interacts will all objects)
void eGame::AOS()
{

}