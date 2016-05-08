#include "cTraffic.h"

cTraffic::cTraffic() 
{
	srand(time(NULL));
	activatePlayer = true;
	moveLeft = false;
	moveRight = false;
	setTrafficSpeed = false;
	setInitialSpeed = false;
	moveBack = false;
}
cTraffic::~cTraffic(){}

void cTraffic::Init()
{
	if (!LoadGLTextures())
	{
		printf("Nu a mers!\n");
	}
}

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
			if(abs(newCar.getxPosition() - (*it).getxPosition() ) < 12)
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
	newCar.setByLane(lane);
	newCar.setxPosition(xPos);
	newCar.Init();

	if(lane <2)
	{
		if(Road.getSpeed() <= 0.21 )
		{
			newCar.setSpeed(0.3);
		}
	}
	else
	{
		if(Road.getSpeed() <= 0.21 )
		{
			newCar.setSpeed(0);
		}
	}

	if(VerifySpawn(newCar) == true && setInitialSpeed == false && setTrafficSpeed == false )
		Car.push_back(newCar);
	else
	{
		printf("Can't load the car! %d %d\n",setInitialSpeed, setTrafficSpeed);
	}
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
						if( abs( (*it).getxPosition() - (*jt).getxPosition() ) < 12 )
						{
							if( abs( (*it).getxPosition() - (*jt).getxPosition() ) < 8 )
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
					(*it).setxPosition(24);
				}
			}
			else // lanes 3 and 4
			{
				if((*it).getxPosition()<24 || (*it).getxPosition()>-24 )
				{
					(*it).setxPosition((*it).getxPosition()-(*it).getSpeed() );
				}
				if((*it).getxPosition() < -24)
					(*it).setxPosition(24);
				else
					if((*it).getxPosition() > 24)
						(*it).setxPosition(-24);
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
 //BETA FUNCTION - depasire prin stanga, cu tot cu revenire pentru banda 2
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
				if(Player.getxPosition() < (*it).getxPosition() && abs( Player.getxPosition() - (*it).getxPosition()) <= 16)
				{
					if(Road.getSpeed() > 0.299 )
						movePlayer = 3;
				}
			}
		}
	}
	
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
			moveBack = false;
		break;
		case 4:	
			//setInitialSpeed
			setInitialSpeed = true;
			setTrafficSpeed = false;
			moveBack = false;
		break;
		case 5:
			setInitialSpeed = false;
			setTrafficSpeed = false;
			moveBack = true;
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

	if(moveBack == true )
	{
		MoveBackPlayer();
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
					if( (*it).getSpeed() > 0 && (*it).getSpeed() < 0.007 )
						(*it).setSpeed(0);
					if( (*it).getSpeed() >= 0.007 )
						(*it).setSpeed( (*it).getSpeed() - 0.002 );
				}
				else
				{
					if( (*it).getSpeed() > 0.3 && (*it).getSpeed() < 0.307 )
						(*it).setSpeed(0.3);
					if( (*it).getSpeed() >= 0.307 )
						(*it).setSpeed( (*it).getSpeed() - 0.002 );
				}
			}
		}
		if(Road.getSpeed() >= 0.2 && Road.getSpeed() <= 0.201)
		{
			setTrafficSpeed = false;
		}
		if(Road.getSpeed() > 0.201 && Road.getSpeed()<0.205 )
		{
			Road.setSpeed(0.2);
		}
		if(Road.getSpeed()>= 0.205 )
		{
			Road.setSpeed(Road.getSpeed() - 0.001);
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
					if( (*it).getSpeed() < 0.2 && (*it).getSpeed() > 0.193 )
						(*it).setSpeed(0.2);
					if( (*it).getSpeed() <= 0.193 )
						(*it).setSpeed( (*it).getSpeed() + 0.002 );
				}
				else
				{
					if( (*it).getSpeed() < 0.4 && (*it).getSpeed() > 0.393 )
						(*it).setSpeed(0.4);
					if( (*it).getSpeed() <= 0.393 )
						(*it).setSpeed( (*it).getSpeed() + 0.002 );
				}
			}
		}

		if(Road.getSpeed() >= 0.3)
		{
			setInitialSpeed = false;
		}
		if(Road.getSpeed() < 0.3 && Road.getSpeed() > 0.295 )
		{
			Road.setSpeed(0.3);	
		}
		if(Road.getSpeed()<= 0.295 )
		{
			Road.setSpeed(Road.getSpeed() + 0.001);
		}
	}
}
// beta version of move back player
void cTraffic::MoveBackPlayer()
{
	if(moveBack == true)
	{
		movePlayer= 0;
		for(vector<cCar>::iterator it = Car.begin(); it!= Car.end(); it ++ )
		{
			if( (*it).getType()!=0)
			{
				(*it).setxPosition((*it).getxPosition() + 0.05);
			}
		}
		moveBack = false;
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
			Player.setOnlyLane(lane);
			float yToAchieve = Player.getyPosByLane(lane);

			if(abs(yToAchieve - Player.getyPosition() ) <0.1 )
			{
				Player.setyPosition ( yToAchieve );
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
			Player.setOnlyLane(lane);
			float yToAchieve = Player.getyPosByLane(lane);

			if(abs(yToAchieve - Player.getyPosition() ) < 0.1 )
			{
				Player.setyPosition ( yToAchieve );
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

int cTraffic::LoadGLTextures()
{
	texture[0] = SOIL_load_OGL_texture("Texture/Messages/state.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	texture[1] = SOIL_load_OGL_texture("Texture/Messages/aosinfo.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	texture[2] = SOIL_load_OGL_texture("Texture/Messages/speeding.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	texture[3] = SOIL_load_OGL_texture("Texture/Messages/cruising.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	texture[4] = SOIL_load_OGL_texture("Texture/Messages/overtaking.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	texture[5] = SOIL_load_OGL_texture("Texture/Messages/bothlanes.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	texture[6] = SOIL_load_OGL_texture("Texture/Messages/leftlane.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	texture[7] = SOIL_load_OGL_texture("Texture/Messages/rightlane.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	texture[8] = SOIL_load_OGL_texture("Texture/Messages/nothing.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	return true;
}

void cTraffic::drawMessage(int i, float xLeft, float xRight, float yTop, float yBottom)
{
	glBindTexture(GL_TEXTURE_2D, texture[i]);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glBegin(GL_QUADS);
		
		glTexCoord2f(1.0f, 1.0f); glVertex2f (xRight, yTop);
		glTexCoord2f(0.0f, 1.0f); glVertex2f (xLeft, yTop);
		glTexCoord2f(0.0f, 0.0f); glVertex2f (xLeft, yBottom);
		glTexCoord2f(1.0f, 0.0f); glVertex2f (xRight, yBottom);		

	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);

  	glDisable(GL_BLEND);
}

void cTraffic::DisplayAOS()
{
	glEnable(GL_TEXTURE_2D);
	glColor4f(1.0,1.0,1.0,1.0);

	drawMessage(0, -19.5, -14.5, -3.5, -4.5);

	drawMessage(1, -19.5, -14.5, -5.0, -6.0);

	if(Player.getyPosition() > 3)
	{
		drawMessage(4, -14.5, -8.0, -3.5, -4.5);
	}
	else
	{
		if(Road.getSpeed() > 0.25)
		{
			drawMessage(2, -14.5, -9.0, -3.5, -4.5);
			//drawMessage(8, -14.3, -4.7, -5.0, -6.0);
		}
		else
		{
			drawMessage(3, -14.5, -9.0, -3.5, -4.5);
		}
	}

	if(bothAOS == true)
	{
		drawMessage(5, -14.3, -2.7, -5.0, -6.0);
	}
	else
	{
		if(leftAOS == true)
		{
			drawMessage(6, -14.3, -3.7, -5.0, -6.0);
		}
		else
		{
			if(rightAOS == true)
			{
				drawMessage(7, -14.3, -3.7, -5.0, -6.0);
			}
			else
			{
				drawMessage(8, -14.3, -4.7, -5.0, -6.0);
			}
		}
	}
}
