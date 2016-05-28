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

	AddCarState = 0;
	laneToChange = -1;
	PlayerOvertake = true;
	PlayerCruising = false;
}

void eGame::Keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 27:
			exit(0);
		break;
		case '1':
			newVehicle.Init(LANE_1, VISIBLE_X, 15, Data.GetID(IMG_MERCEDES));
			if(checkFreeSpawnSpace(LANE_1, VISIBLE_X))
				Vehicle.push_back(newVehicle);
		break;
		case '2':
			newVehicle.Init(LANE_2, VISIBLE_X, 15, Data.GetID(IMG_RETRO));
			if(checkFreeSpawnSpace(LANE_2, VISIBLE_X))
				Vehicle.push_back(newVehicle);
		break;
		case '3':
			newVehicle.Init(LANE_3, -VISIBLE_X, 5, Data.GetID(IMG_POLICE));
			if(checkFreeSpawnSpace(LANE_3, -VISIBLE_X))
				Vehicle.push_back(newVehicle);
		break;
		case '4':
			newVehicle.Init(LANE_4, -VISIBLE_X, 5, Data.GetID(IMG_MERCEDES));
			if(checkFreeSpawnSpace(LANE_4, -VISIBLE_X))
				Vehicle.push_back(newVehicle);
		break;

		case 'o':
			Road.increaseSpeed();
		break;
		case 'k':
			Road.decreaseSpeed();
		break;

		case '9':
			if(PlayerOvertake == true)
				PlayerOvertake = false;
			else
				PlayerOvertake = true;
		break;

		case 'q':
			for(vector <eVehicle>::iterator it=Vehicle.begin(); it!= Vehicle.end(); it++)
			{
				if((*it).getLane() == LANE_1)
					(*it).increaseSpeed( (*it).getLane() );
			}
		break;
		case 'a':
			for(vector <eVehicle>::iterator it=Vehicle.begin(); it!= Vehicle.end(); it++)
			{
				if((*it).getLane() == LANE_1)
					(*it).decreaseSpeed( (*it).getLane() );
			}		
		break;
		
		case 'w':
			for(vector <eVehicle>::iterator it=Vehicle.begin(); it!= Vehicle.end(); it++)
			{
				if((*it).getLane() == LANE_2)
					(*it).increaseSpeed( (*it).getLane() );
			}
		break;
		case 's':
			for(vector <eVehicle>::iterator it=Vehicle.begin(); it!= Vehicle.end(); it++)
			{
				if((*it).getLane() == LANE_2)
					(*it).decreaseSpeed( (*it).getLane() );
			}		
		break;
		case 'e':
			for(vector <eVehicle>::iterator it=Vehicle.begin(); it!= Vehicle.end(); it++)
			{
				if((*it).getLane() == LANE_3)
					(*it).increaseSpeed( (*it).getLane() );
			}
		break;
		case 'd':
			for(vector <eVehicle>::iterator it=Vehicle.begin(); it!= Vehicle.end(); it++)
			{
				if((*it).getLane() == LANE_3)
					(*it).decreaseSpeed( (*it).getLane() );
			}		
		break;
		case 'r':
			for(vector <eVehicle>::iterator it=Vehicle.begin(); it!= Vehicle.end(); it++)
			{
				if((*it).getLane() == LANE_4)
					(*it).increaseSpeed( (*it).getLane() );
			}
		break;
		case 'f':
			for(vector <eVehicle>::iterator it=Vehicle.begin(); it!= Vehicle.end(); it++)
			{
				if((*it).getLane() == LANE_4)
					(*it).decreaseSpeed( (*it).getLane() );
			}		
		break;

		case 'z':
			if(Player.getLane() == LANE_1)
				Player.MoveToLane(Player.getLane(), GO_TO_LEFT);
			else	
				Player.MoveToLane(Player.getLane()-1, GO_TO_LEFT);
		break;
		case 'c':
			if(Player.getLane() == LANE_4)
				Player.MoveToLane(Player.getLane(), GO_TO_RIGHT);
			else
				Player.MoveToLane(Player.getLane()+1, GO_TO_RIGHT);
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

		if(y <= (Y_L1 + 1) && y >= (Y_L1 - 1))
		{	
			newVehicle.Init(LANE_1, x, 15, Data.GetID(carChoice));
			if(checkFreeSpawnSpace(LANE_1, x ))
				Vehicle.push_back(newVehicle);
		}
		if(y <= (Y_L2 + 1) && y >= (Y_L2 - 1))
		{	
			newVehicle.Init(LANE_2, x, 15, Data.GetID(carChoice));
			if(checkFreeSpawnSpace(LANE_2, x ))
				Vehicle.push_back(newVehicle);
		}
		if(y <= (Y_L3 + 1) && y >= (Y_L3 - 1))
		{	
			newVehicle.Init(LANE_3, x, 5, Data.GetID(carChoice));
			if(checkFreeSpawnSpace(LANE_3, x ))
				Vehicle.push_back(newVehicle);
		}
		if(y <= (Y_L4 + 1) && y >= (Y_L4 - 1))
		{	
			newVehicle.Init(LANE_4, x, 5, Data.GetID(carChoice));
			if(checkFreeSpawnSpace(LANE_4, x ))
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

	if ( (x < 8 || y > -2) && AddCarState == 1)
		AddCarState = 0;
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

	if (clock() - fpsclock < 1000000 / FPS) { //60 fps
		return;
	}
	fpsclock = clock();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	Road.Draw();

	Player.Draw();

	for(vector <eVehicle>::iterator it=Vehicle.begin(); it!= Vehicle.end(); it++)
	{
		(*it).Draw();
	}
	
	drawUIButtons();

	Update();
	
	glutSwapBuffers();
}

void eGame::Update()
{
	Road.Move();

	for(vector<eVehicle>::iterator it=Vehicle.begin(); it!=Vehicle.end(); it++)
	{
		(*it).Move();
		(*it).CalcRealSpeed(Road.getSpeed());
	}

	if(PlayerOvertake == true)
		AOS();
	if(PlayerCruising == true)
		CRUISE();
}

void eGame::Reshape(int w,int h)
{
	windowWidth = w;
	windowHeight = h;
	glViewport(0,0,w,h);
}

bool eGame::checkFreeSpawnSpace(int lane, float xPos)
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

bool eGame::checkFreeArea(int lane, int direction, int limit)
{
	for(vector<eVehicle>::iterator it=Vehicle.begin(); it!=Vehicle.end(); it++)
	{
		if((*it).getLane() == lane)
		{
			if(direction == LOOK_FRONT)
			{
				if(Player.getxValue() < (*it).getxValue())
					if(abs(Player.getxValue() - ((*it).getxValue() - CAR_LENGTH)) < limit )
						return false;
			}
			if(direction == LOOK_BEHIND)
			{
				if(Player.getxValue() > (*it).getxValue())
					if(abs((Player.getxValue() - CAR_LENGTH) - (*it).getxValue()) < limit )
						return false;	
			}
			if(direction == LOOK_MIDDLE)
			{
				if( Player.getxValue() + limit > ((*it).getxValue() - CAR_LENGTH))
				{
					if((Player.getxValue() - CAR_LENGTH) - limit < (*it).getxValue())
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

//AOS AI 
void eGame::AOS()
{
	if(!checkFreeArea(Player.getLane(), LOOK_FRONT, 6*FRONT_LIMIT)) // AOS detect a car in front of player
	{
		if(!checkFreeArea(Player.getLane(), LOOK_FRONT, 5*FRONT_LIMIT)) // AOS start to verify free spaces for overtaking
		{
			switch (Player.getLane())
			{
				case LANE_4:

					if(!checkFreeArea(Player.getLane(), LOOK_FRONT, 4*FRONT_LIMIT))
					{
						// start semnalizare
						if (!checkFreeArea(Player.getLane(), LOOK_FRONT, 2*FRONT_LIMIT))
						{
							if(checkFreeArea(Player.getLane()-1, LOOK_FRONT, 2*FRONT_LIMIT) && checkFreeArea(Player.getLane()-1, LOOK_MIDDLE, MIDDLE_LIMIT))
							{
								if(laneToChange == -1)
									laneToChange = Player.getLane()-1;
								if(laneToChange != -1)
								{
									if(Player.getLane() > laneToChange)
										Player.MoveToLane(laneToChange, GO_TO_LEFT);
									else
									{
										laneToChange = -1;
										// stop semnalizare
									}
								}
							}
							else
							{
								// stop semnalizare 
								// nu pot depasi
								PlayerOvertake = false;
								PlayerCruising = true;
							}
						}
					}

				break;

				case LANE_3:
						
						//start semnalizare dreapta
						if(!checkFreeArea(Player.getLane(), LOOK_FRONT, 4*FRONT_LIMIT))
						{
							if (!checkFreeArea(Player.getLane(), LOOK_FRONT, 2*FRONT_LIMIT))
							{
								if(checkFreeArea(Player.getLane()+1, LOOK_FRONT, 2*FRONT_LIMIT) && checkFreeArea(Player.getLane()+1, LOOK_MIDDLE, MIDDLE_LIMIT))
								{
									if(laneToChange == -1)
										laneToChange = Player.getLane() + 1;
									if(laneToChange != -1)
									{
										if(Player.getLane() < laneToChange)
											Player.MoveToLane(laneToChange, GO_TO_RIGHT);
										else
										{
											laneToChange = -1;
											// stop semnalizare
										}
									}
								}
								else
								{
									// start semnalizare stanga 
									if(checkFreeArea(Player.getLane()-1, LOOK_FRONT, 2*FRONT_LIMIT) && checkFreeArea(Player.getLane()-1, LOOK_MIDDLE, MIDDLE_LIMIT))
									{
										if(laneToChange == -1)
											laneToChange = Player.getLane()-1;
										if(laneToChange != -1)
										{
											if(Player.getLane() > laneToChange)
												Player.MoveToLane(laneToChange, GO_TO_LEFT);
											else
											{
												laneToChange = -1;
												// stop semnalizare
											}
										}
									}
									else
									{
										// stop semnalizare 
										// nu pot depasi
										PlayerOvertake = false;
										PlayerCruising = true;
									}
								}
							}
						}

				break;

				case LANE_2:

					if(checkFreeArea(Player.getLane() + 1, LOOK_FRONT, 2*FRONT_LIMIT) && checkFreeArea(Player.getLane() + 1, LOOK_MIDDLE, MIDDLE_LIMIT))
					{
						if(laneToChange == -1)
							laneToChange = Player.getLane() + 1;
						if(laneToChange != -1)
						{
							if(Player.getLane() < laneToChange)
								Player.MoveToLane(laneToChange, GO_TO_RIGHT);
							else
								laneToChange = -1;
						}
					}
					else
					{
						PlayerOvertake = false;
						PlayerCruising = true;
					}

				break;	
			}
		}
	}
	else
	{
		if(Player.getLane() == LANE_2)
		{
			if(checkFreeArea(Player.getLane() + 1, LOOK_FRONT, FRONT_LIMIT) && checkFreeArea(Player.getLane() + 1, LOOK_MIDDLE, MIDDLE_LIMIT))
			{
				if(laneToChange == -1)
					laneToChange = Player.getLane() + 1;
				if(laneToChange != -1)
				{
					if(Player.getLane() < laneToChange)
						Player.MoveToLane(laneToChange, GO_TO_RIGHT);
					else
						laneToChange = -1;
				}
			}
			else
			{
				PlayerOvertake = false;
				PlayerCruising = true;
			}			
		}
	}
}

void eGame::CRUISE()
{

}
