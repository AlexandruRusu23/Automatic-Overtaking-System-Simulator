#include "cTraffic.h"

cTraffic::cTraffic() 
{
	srand(time(NULL));
	activatePlayer = true;
	moveLeft = false;
	moveRight = false;
	Brake = false;
	Accelerate = false;
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

	if(VerifySpawn(newCar) == true && Accelerate == false && Brake == false )
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

void cTraffic::AOS()
{
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
			//brake
			Brake = true;
			Accelerate = false;
		break;
		case 4:	
			//accelerate
			Accelerate = true;
			Brake = false;
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

	if(Brake == true )
	{
		BrakePlayer(Player.getLane());
	}

	if(Accelerate == true )
	{
		AcceleratePlayer(Player.getLane());
	}
}

void cTraffic::BrakePlayer(int lane)
{
	if(Brake == true )
	{
		for(vector<cCar>::iterator it=Car.begin(); it!=Car.end(); it++)
		{
			if((*it).getType()!= 0 )
			{
				if((*it).getLane() >=2 )
				{
					if( (*it).getSpeed() >= 0 && (*it).getSpeed() < 0.005 )
						(*it).setSpeed(0);
					if( (*it).getSpeed() >= 0.005 )
						(*it).setSpeed( (*it).getSpeed() - 0.001 );
				}
				else
				{
					if( (*it).getSpeed() >= 0.2 && (*it).getSpeed() < 0.205 )
						(*it).setSpeed(0.2);
					if( (*it).getSpeed() >= 0.205 )
						(*it).setSpeed( (*it).getSpeed() - 0.001 );
				}
			}
		}
		if(Road.getSpeed() >= 0.1 && Road.getSpeed()<0.105 )
		{
			Brake = false;
			movePlayer = 0;
			Road.setSpeed(0.1);
		}
		if(Road.getSpeed()>= 0.105 )
		{
			Road.setSpeed(Road.getSpeed() - 0.001);
		}		
	}
}

void cTraffic::AcceleratePlayer(int lane)
{
	if(Accelerate == true )
	{
		for(vector<cCar>::iterator it=Car.begin(); it!=Car.end(); it++)
		{
			if((*it).getType()!= 0 )
			{
				if((*it).getLane() >=2 )
				{
					if( (*it).getSpeed() <= 0.1 && (*it).getSpeed() > 0.095 )
						(*it).setSpeed(0.1);
					if( (*it).getSpeed() <= 0.095 )
						(*it).setSpeed( (*it).getSpeed() + 0.001 );
				}
				else
				{
					if( (*it).getSpeed() <= 0.3 && (*it).getSpeed() > 0.295 )
						(*it).setSpeed(0.3);
					if( (*it).getSpeed() <= 0.295 )
						(*it).setSpeed( (*it).getSpeed() + 0.001 );
				}
			}
		}

		if(Road.getSpeed() <= 0.2 && Road.getSpeed() > 0.195 )
		{
			Accelerate = false;
			movePlayer = 0;
			Road.setSpeed(0.2);	
		}
		if(Road.getSpeed()<= 0.195 )
		{
			Road.setSpeed(Road.getSpeed() + 0.001);
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
		if(lane > -1)
		{
			float yToAchieve = Player.getyPosByLane(lane);

			if(abs(yToAchieve - Player.getyPosition() ) <0.1 )
			{
				Player.setyPosition ( yToAchieve );
				Player.setLane(lane);
				moveLeft = false;
				movePlayer = 0;
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
		if(lane < 4)
		{
			float yToAchieve = Player.getyPosByLane(lane);

			if(abs(yToAchieve - Player.getyPosition() ) < 0.1 )
			{
				Player.setyPosition ( yToAchieve );
				Player.setLane(lane);
				moveRight = false;
				movePlayer = 0;
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