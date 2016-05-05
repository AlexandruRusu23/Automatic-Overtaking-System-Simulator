#include "cTraffic.h"

cTraffic::cTraffic() 
{
	srand(time(NULL));
	activatePlayer = true;
	moveLeft = false;
	moveRight = false;
	setTrafficSpeed = false;
	setInitialSpeed = false;
}
cTraffic::~cTraffic(){}

void cTraffic::LoadRoad()
{
	Road.Init();
}

void cTraffic::DrawRoad()
{
	Road.draw();
}

int cTraffic::getMovePlayer()
{
	return movePlayer;
}

void cTraffic::setMovePlayer(int active)
{
	movePlayer = active;
}

bool cTraffic::VerifySpawn(cCar newCar)
{
	for(vector<cCar>::iterator it=Car.begin(); it!=Car.end(); it++)
	{
		if(newCar.getLane() == (*it).getLane() )
		{
			if(abs(newCar.getxPosition() - (*it).getxPosition() ) < 10)
			{
				return false;
			}
		}
	}
	return true;
}

void cTraffic::InitCar(int type, int lane, float xPos)
{
	cCar newCar;
	newCar.setType(type);
	newCar.setLane(lane);
	newCar.setxPosition(xPos);
	newCar.Init();

	if(lane <2)
	{
		if(Road.getSpeed() <= 0.11 )
		{
			newCar.setSpeed(0.2);
		}
	}
	else
	{
		if(Road.getSpeed() <= 0.11 )
		{
			newCar.setSpeed(0);
		}
	}

	if(VerifySpawn(newCar) == true && setInitialSpeed == false && setTrafficSpeed == false )
		Car.push_back(newCar);
	else
		printf("Can't load the car!\n");
}

void cTraffic::CreateCar(int lane,int type, float xPos)
{
	InitCar(type, lane, xPos);
}

void cTraffic::LoadPlayer()
{	
	if(activatePlayer == true)
	{
		Player.Init();
		Car.push_back(Player);
		activatePlayer = false; 
	}
}

void cTraffic::VerifyLimit()
{
	for(vector<cCar>::iterator it=Car.begin(); it!=Car.end(); it++)
	{
		for(vector<cCar>::iterator jt=Car.begin(); jt!=Car.end(); jt++)
		{
			if((*it).getType() != 0 && (*jt).getType() != 0)
			{
				if((*it).getLane() == (*jt).getLane())
				{	
					if( (*it).getxPosition() * (*it).getOrientation() > (*jt).getxPosition() * (*jt).getOrientation() )
					{
						if( abs( (*it).getxPosition() - (*jt).getxPosition() ) < 11 )
						{
							if( abs( (*it).getxPosition() - (*jt).getxPosition() ) < 7 )
							{
								(*it).setxPosition( (*it).getxPosition()+0.02 * (*it).getOrientation() );	
							}
							else
							{
								(*it).setxPosition( (*it).getxPosition()+0.01 * (*it).getOrientation() );
							}
						}
					}
				}
			}
		}
	}
}

void cTraffic::MoveCars()
{
	VerifyLimit();
	for(vector<cCar>::iterator it=Car.begin(); it!=Car.end();it++)
	{
		if((*it).getType() != 0)
		{
			if((*it).getLane()<2)
			{
				if((*it).getxPosition()>-22)
				{
					(*it).setxPosition((*it).getxPosition()-(*it).getSpeed() );
				}
				else
				{
					(*it).setxPosition(22);
				}
			}
			else // lanes 3 and 4
			{
				if((*it).getxPosition()<22 || (*it).getxPosition()>-22 )
				{
					(*it).setxPosition((*it).getxPosition()-(*it).getSpeed() );
				}
				if((*it).getxPosition() < -22)
					(*it).setxPosition(22);
				else
					if((*it).getxPosition() > 22)
						(*it).setxPosition(-22);
			}
		}
	}
}

void cTraffic::DrawCars()
{
	for(vector<cCar>::iterator it=Car.begin(); it!=Car.end();it++)
	{
		if((*it).getType() !=0)
		{
			(*it).draw();
		}
	}

	MoveCars();
}

void cTraffic::rendertext(string *message) 
{
	for (int i=0;i<message->size();i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,(int)((*message)[i]));
}

void cTraffic::DisplayPlayerState() 
{
	glColor3f(0.0,0.5,1.0);
	glRasterPos2f(-16.5,-5.5);
	rendertext(new string("State: "));

	if ( Player.getyPosition() > 0.5 ) 
	{
		glColor3f(1.0,0.0,0.0);
		glRasterPos2f(-14.0,-5.5);
		rendertext(new string("Overtaking"));
	}
	else
	{
		if( Player.getyPosition() > 0.5 )
		{
			glColor3f(1.0,0.0,0.0);
			glRasterPos2f(-14.0,-5.5);
			rendertext(new string("Overtaking"));
		}
		else {
			if (Road.getSpeed() < 0.15) {
				glColor3f(0.5,1.0,0.0);
				glRasterPos2f(-14.0,-5.5);
				rendertext(new string("Cruising"));
			}
			else {
				glColor3f(1.0,1.0,0.0);
				glRasterPos2f(-14.0,-5.5);
				rendertext(new string("Speeding"));
			}
		}
	}

	if( leftAOS == true && rightAOS == true )
		bothAOS = true;

	glColor3f(0.0,0.5,1.0);
	glRasterPos2f(-16.5,-6.5);
	rendertext(new string("AOS Info: "));

	if( bothAOS == true )
	{
		glColor3f(0.0,0.5,1.0);
		glRasterPos2f(-12.5,-6.5);
		rendertext(new string("BOTH lanes are free"));
	}
	else
	{
		if( leftAOS == true )
		{
			glColor3f(0.0,0.5,1.0);
			glRasterPos2f(-12.5,-6.5);
			rendertext(new string("Only LEFT lane is free"));
		}
		else
		{
			if( rightAOS == true )
			{
				glColor3f(0.0,0.5,1.0);
				glRasterPos2f(-12.5,-6.5);
				rendertext(new string("Only RIGHT lane is free"));
			}
			else
			{
				glColor3f(0.0,0.5,1.0);
				glRasterPos2f(-12.5,-6.5);
				rendertext(new string("Nothing to show"));
			}
		}
	}
}

void cTraffic::AOS()
{
 //depasire prin stanga, cu tot cu revenire pentru banda 2
/*	for(vector<cCar>::iterator it=Car.begin(); it!=Car.end(); it++)
	{
		if((*it).getType()!=0)
		{
			if(Player.getLane() == (*it).getLane() && Player.getLane() >= 2 )
			{
				if(Player.getxPosition() < (*it).getxPosition() && abs( Player.getxPosition() - (*it).getxPosition()) <= 10 )
				{
					movePlayer = 1;
				}
			}
			if(Player.getLane() < 2 )
			{
				if((*it).getLane() == Player.getLane() + 1)
				{
					if(Player.getxPosition() > (*it).getxPosition() && abs( Player.getxPosition() - (*it).getxPosition()) >= 2 )
					{
						movePlayer = 2;
					}
				}
			}
		}
	}
*/
	for(vector<cCar>::iterator it=Car.begin(); it!=Car.end(); it++)
	{
		if((*it).getType()!=0)
		{
			if(Player.getLane() == (*it).getLane())
			{
				if(Player.getxPosition() < (*it).getxPosition() && abs( Player.getxPosition() - (*it).getxPosition()) <= 9)
				{
					if(Road.getSpeed() > 0.199 )
						movePlayer = 3;
				}
			}
		}
	}

	if(Road.getSpeed() < 0.15 )
	{	
		if( Player.getLane() < 1)
		{
			leftAOS = false;
		}
		else
		{
			leftAOS = true;
		}
		if( Player.getLane() > 2 )
		{
			rightAOS = false;
		}
		else
		{
			rightAOS = true;
		}
		
		for(vector<cCar>::iterator it=Car.begin(); it!= Car.end(); it++ )
		{
			if( (*it).getType() != 0 )
			{
				if( Player.getLane() - 1 == (*it).getLane() )
				{
					if(Player.getxPosition() - 4 < (*it).getxPosition() && abs(Player.getxPosition() - (*it).getxPosition()) <=14 )
					{	
						leftAOS = false;
					}
				}
				if( Player.getLane() + 1 == (*it).getLane() )
				{
					if(Player.getxPosition() -4 < (*it).getxPosition() && abs(Player.getxPosition() - (*it).getxPosition()) <=14 )
					{
						rightAOS = false;
					}
				}
			}
		}

		if( leftAOS == true && rightAOS == true )
		{
			bothAOS = true;
		}
		else
		{
			bothAOS = false;
		}
	}
	else
	{
		leftAOS = false;
		rightAOS = false;
		bothAOS = false;
	}

	switch(movePlayer)
	{
		case 1:
			moveLeft=true;
			moveRight=false;
		break;
		case 2:
			moveRight = true;
			moveLeft = false;
		break;
		case 3:
			//setTrafficSpeed
			setTrafficSpeed = true;
			setInitialSpeed = false;
		break;
		case 4:	
			//setInitialSpeed
			setInitialSpeed = true;
			setTrafficSpeed = false;
		break;
	}

	if(	moveLeft == true )
	{
		if(Player.getyPosition() < Player.getyPosByLane(Player.getLane()) )
		{
			MovePlayerLeft(Player.getLane() );
		}
		else
		{
			MovePlayerLeft(Player.getLane() - 1 );
		}
	}

	if( moveRight == true )
	{
		if(Player.getyPosition() > Player.getyPosByLane(Player.getLane()) )
		{
			MovePlayerRight(Player.getLane() );
		}
		else
		{
			MovePlayerRight(Player.getLane() + 1);
		}
	}

	if(setTrafficSpeed == true )
	{
		SetTrafficSpeedPlayer();
	}

	if(setInitialSpeed == true )
	{
		SetInitialSpeedPlayer();
	}
}

void cTraffic::SetTrafficSpeedPlayer() // make player to move as fast as the traffic
{
	if(setTrafficSpeed == true )
	{
		movePlayer = 0;
		for(vector<cCar>::iterator it=Car.begin(); it!=Car.end(); it++)
		{
			if((*it).getType()!= 0 )
			{
				if((*it).getLane() >=2 )
				{
					if( (*it).getSpeed() >= 0 && (*it).getSpeed() < 0.005 )
						(*it).setSpeed(0);
					if( (*it).getSpeed() >= 0.005 )
						(*it).setSpeed( (*it).getSpeed() - 0.0015 );
				}
				else
				{
					if( (*it).getSpeed() >= 0.2 && (*it).getSpeed() < 0.205 )
						(*it).setSpeed(0.2);
					if( (*it).getSpeed() >= 0.205 )
						(*it).setSpeed( (*it).getSpeed() - 0.0015 );
				}
			}
		}
		if(Road.getSpeed() >= 0.1 && Road.getSpeed()<0.105 )
		{
			setTrafficSpeed = false;
			Road.setSpeed(0.1);
		}
		if(Road.getSpeed()>= 0.105 )
		{
			Road.setSpeed(Road.getSpeed() - 0.0015);
		}		
	}
}

void cTraffic::SetInitialSpeedPlayer()
{
	if(setInitialSpeed == true )
	{
		movePlayer = 0;
		for(vector<cCar>::iterator it=Car.begin(); it!=Car.end(); it++)
		{
			if((*it).getType()!= 0 )
			{
				if((*it).getLane() >=2 )
				{
					if( (*it).getSpeed() <= 0.1 && (*it).getSpeed() > 0.095 )
						(*it).setSpeed(0.1);
					if( (*it).getSpeed() <= 0.095 )
						(*it).setSpeed( (*it).getSpeed() + 0.0015 );
				}
				else
				{
					if( (*it).getSpeed() <= 0.3 && (*it).getSpeed() > 0.295 )
						(*it).setSpeed(0.3);
					if( (*it).getSpeed() <= 0.295 )
						(*it).setSpeed( (*it).getSpeed() + 0.0015 );
				}
			}
		}

		if(Road.getSpeed() <= 0.2 && Road.getSpeed() > 0.195 )
		{
			setInitialSpeed = false;
			Road.setSpeed(0.2);	
		}
		if(Road.getSpeed()<= 0.195 )
		{
			Road.setSpeed(Road.getSpeed() + 0.0015);
		}
	}
}

void cTraffic::DrawPlayer()
{
	Player.draw();
	AOS();
}

void cTraffic::MovePlayerLeft(int lane)
{
	if(moveLeft == true )
	{
		movePlayer = 0;
		if(lane > -1)
		{
			float yToAchieve = Player.getyPosByLane(lane);

			if(abs(yToAchieve - Player.getyPosition() ) <0.1 )
			{
				Player.setyPosition ( yToAchieve );
				Player.setLane(lane);
				moveLeft = false;
			}
			else
			{
				if(abs(yToAchieve - Player.getyPosition()) >=0.1 )
				{
					Player.setyPosition(Player.getyPosition() + 0.03);
				}
			}
		}
	}
}

void cTraffic::MovePlayerRight(int lane)
{
	if(moveRight == true )
	{
		movePlayer = 0;
		if(lane < 4)
		{
			float yToAchieve = Player.getyPosByLane(lane);

			if(abs(yToAchieve - Player.getyPosition() ) < 0.1 )
			{
				Player.setyPosition ( yToAchieve );
				Player.setLane(lane);
				moveRight = false;
			}
			else
			{
				if(abs(yToAchieve - Player.getyPosition()) >=0.1 )
				{
					Player.setyPosition(Player.getyPosition() - 0.03);
				}
			}
		}
	}
}
