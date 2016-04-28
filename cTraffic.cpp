#include "cTraffic.h"

cTraffic::cTraffic() 
{
	srand(time(NULL));
}
cTraffic::~cTraffic(){}

void cTraffic::Init(bool player, int type, int lane, float xPos)
{
	cCar newCar;
	newCar.setPlayer(player);
	newCar.setType(type);
	newCar.setLane(lane);
	newCar.setxPosition(xPos);
	newCar.Init();

	Car.push_back(newCar);
}

void cTraffic::CreateCar(bool player, int lane,int type, float xPos)
{
	Init(player, type, lane, xPos);
}

void cTraffic::VerifyLimit()
{
	for(vector<cCar>::iterator it=Car.begin(); it!=Car.end(); it++)
	{
		for(vector<cCar>::iterator jt=Car.begin(); jt!=Car.end(); jt++)
		{
			if((*it).getLane() == (*jt).getLane())
			{	
				if( (*it).getxPosition() * (*it).getOrientation() > (*jt).getxPosition() * (*jt).getOrientation() )
				{
					if( abs( (*it).getxPosition() - (*jt).getxPosition() ) < 10 )
					{
						(*it).setxPosition( (*it).getxPosition()+0.02 * (*it).getOrientation() );
					}
				}
			}
		}
	}
}

void cTraffic::MoveCars()
{
	for(vector<cCar>::iterator it=Car.begin(); it!=Car.end();it++)
	{
		if((*it).getPlayer() == false )
		{
			if((*it).getLane()<2)
			{
				if((*it).getxPosition()>-18)
				{
					(*it).setxPosition((*it).getxPosition()-0.15);
				}
				else
				{
					(*it).setxPosition(18);
				}
			}
			else
			{
				if((*it).getxPosition()<18)
				{
					(*it).setxPosition((*it).getxPosition()+0.05);
				}
				else
				{
					(*it).setxPosition(-18);
				}
			}
		}
	}
}

void cTraffic::DrawCars()
{
	for(vector<cCar>::iterator it=Car.begin(); it!=Car.end();it++)
	{
		(*it).draw();
	}

	MoveCars();
	VerifyLimit();
}