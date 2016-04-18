#include "cCar.h"

cCar::cCar() 
{
	srand(time(NULL));
}
cCar::~cCar(){}

vector<data>::iterator cCar::detectNextCar(vector<data>::iterator cCar)
{
	vector<data>::iterator minim=cCar;

	int minDist=ROAD_LIMIT;

	for(vector<data>::iterator it=Car.begin(); it!=Car.end(); it++ )
	{
		if(minim!=it)
		{
			if(cCar->Lane == it -> Lane )
			{
				if( it -> xPosition * it -> Orientation < cCar -> xPosition * cCar -> Orientation 
					&&  abs(it -> xPosition - cCar -> xPosition) < minDist )
				{
					minim=it;
					minDist= abs(it -> xPosition - cCar -> xPosition); 
				}
			}
		}
	}
	return minim;
}

vector<data>::iterator cCar::detectLastCar(int cLane)
{
	vector<data>::iterator minim=Car.begin();

	for(vector<data>::iterator it=Car.begin(); it!=Car.end(); it++ )
	{
		if(minim != it)
		{
			if(cLane == it -> Lane )
			{
				if( it -> xPosition * it->Orientation > minim -> xPosition * minim -> Orientation )
				{
					minim=it;
				}
			}
		}
	}
	return minim;
}

bool cCar::cDetector(data *newCar)
{
	int xRange;

	if(numberCar[newCar->Lane]==0)
	{
		newCar -> xPosition = rand()%60 + ROAD_EDGE;
		newCar -> xPosition*= newCar->Orientation;
		return true;
	}
	else
	{
		if(numberCar[newCar->Lane] == 1)
		{
			for(vector<data>::iterator it = Car.begin(); it != Car.end(); it++)
			{
				if(it -> Lane == newCar -> Lane)
				{
					while(abs(newCar -> xPosition - it -> xPosition) < 2*SPAWN_LIMIT)
					{
						newCar -> xPosition = rand()%60 + ROAD_EDGE;
						newCar -> xPosition*= newCar->Orientation;
					}	
					return true;
				}
			}						
		}
		else
		{
			vector<data>::iterator lastCar = detectLastCar(newCar->Lane);
			
			if(lastCar->xPosition*lastCar->Orientation > ROAD_EDGE ) // verify if last car is inside spawn area
			{
				if(abs( newCar -> Orientation*ROAD_LIMIT - lastCar -> xPosition) > 2*SPAWN_LIMIT) // verify if new car fit between ROAD_LIMIT and lastCar
				{
					newCar->xPosition= lastCar -> xPosition + newCar -> Orientation*SPAWN_LIMIT;
					return true;
				}
				else  
				{
					for(int i=2; i<=numberCar[newCar->Lane];i++)
					{
						vector<data>::iterator nextCar = detectNextCar(lastCar);

						if(lastCar -> xPosition != nextCar -> xPosition)
						{	
							if(nextCar -> xPosition* nextCar -> Orientation > ROAD_EDGE) // verify if nextCar is inside spawn area
							{
								if(abs( nextCar->xPosition - lastCar -> xPosition) > 2*SPAWN_LIMIT) // verify if newCar fit between nextCar and lastCar
								{
									newCar->xPosition= lastCar -> xPosition - newCar -> Orientation*SPAWN_LIMIT;
									return true;
								}
							}
							else
							{
								newCar->xPosition= lastCar -> xPosition - newCar -> Orientation*SPAWN_LIMIT;
								return true;
							}
						}
						lastCar=nextCar;
					}
				}
			}
			else
			{
				newCar->xPosition=rand()%60+ROAD_EDGE;
				newCar->xPosition*=newCar->Orientation;
				return true;
			}
		}
	}
	return false;
}

void cCar::makeNewCar()
{
	data newCar;

	newCar.Lane=rand()%4;
	newCar.Speed=(float)(rand()%20+5)/100;
	newCar.prefferedSpeed = newCar.Speed;
	newCar.Orientation=(newCar.Lane == 0 || newCar.Lane == 1 ) ? 1 : -1; 

	newCar.xPosition=rand()%60 + ROAD_EDGE;
	newCar.xPosition*=newCar.Orientation;

	switch (newCar.Lane)
	{
		case 0:
			newCar.yPosition=6.1;
			break;
		case 1:
			newCar.yPosition=3.35;
			break;
		case 2:
			newCar.yPosition=0.5;
			break;
		case 3:
			newCar.yPosition=-2.17;
			break;
	}

	newCar.zPosition=-11.0;

	newCar.xColor=(float)(rand()%10)/10;
	newCar.yColor=(float)(rand()%10)/10;
	newCar.zColor=(float)(rand()%10)/10;
	newCar.pressureFromBehind = 0;

	if(cDetector(&newCar) == false ) 
	{
		printf("Can't load this car %d \n",newCar.Lane);
	}
	else
	{
		Car.push_back(newCar);
		numberCar[newCar.Lane]++;
	}
}

void cCar::draw(data carToDraw)
{
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(carToDraw.xPosition, carToDraw.yPosition, carToDraw.zPosition);
 	glColor3f(carToDraw.xColor,carToDraw.yColor,carToDraw.zColor);

	glBegin(GL_QUADS);
    	glVertex3f(carToDraw.xPosition, carToDraw.yPosition, carToDraw.zPosition);
 		glVertex3f(carToDraw.xPosition-8, carToDraw.yPosition, carToDraw.zPosition);
		glVertex3f(carToDraw.xPosition-8, carToDraw.yPosition-4, carToDraw.zPosition);
		glVertex3f(carToDraw.xPosition, carToDraw.yPosition-4, carToDraw.zPosition);
	glEnd();
 	
 	glPopMatrix();
}

void cCar::drawCars()
{
	for(vector<data>::iterator it=Car.begin(); it!=Car.end(); it++)
	{
		draw((*it));
	}
}

void cCar::move(vector<data>::iterator carToMove)
{
	for (vector<data>::iterator it = Car.begin(); it != Car.end(); it++) 
	{
		if (carToMove -> xPosition * it -> Orientation > it -> xPosition * it -> Orientation && carToMove -> Lane == it -> Lane)
			if ( abs(carToMove -> xPosition - it -> xPosition) <= 7.5 && (carToMove -> Speed > it -> Speed) ) 
			{
				if (abs(carToMove -> xPosition - it -> xPosition) < 5.5) 
					carToMove -> Speed = 0; //precaution for avoiding collisions due to erroneus spawning
				else 
					carToMove -> Speed = it -> Speed;
				it -> pressureFromBehind = 1;
			} //blocked cars slow down and blockers feel pressure

			else carToMove -> Speed = carToMove -> prefferedSpeed; // if no longer blocked, car resumes it's previous speed
	}

	if (carToMove -> pressureFromBehind == 1)
	{
		if (rand()%10  == 0) 
		{
			carToMove -> Speed += 0.01;
			carToMove -> prefferedSpeed = carToMove -> Speed;
			carToMove -> pressureFromBehind = 0;
		} //small chance for blockers to increase speed due to pressure
	}

	carToMove -> xPosition-= carToMove -> Orientation*carToMove -> Speed;

	if (carToMove -> Orientation == 1)
	{
		if (carToMove -> xPosition < -ROAD_EDGE)
		{
			numberCar[carToMove->Lane]--;
			Car.erase(carToMove);
			makeNewCar();
		}
	}
	else
	{
		if (carToMove -> xPosition > ROAD_EDGE)
		{
			numberCar[carToMove->Lane]--;
			Car.erase(carToMove);
			makeNewCar();
		}	
	}

}

void cCar::moveCars()
{
	for(vector<data>::iterator it=Car.begin(); it!= Car.end(); it++)
	{
		move(it);
	}
}
