#include "eRoad.h"

eRoad::eRoad() {}
eRoad::~eRoad(){}

float eRoad::getSpeed()
{
	return Speed;
}

void eRoad::Load(int id_texture)
{
	this->id_texture = id_texture;
	this->Speed = 20*ROAD_SPEED;
	this->xLength = VISIBLE_X + VISIBLE_X * 0.1; // 20 units + 10% OF XLENGTH
	this->yLength = VISIBLE_Y ; // 12 units
	this->xValue[0] = -VISIBLE_X - VISIBLE_X * 0.05; // - ( 20 + 5% of VISIBLE_X )
	this->xValue[1] = xValue[0] + xLength - DELAY_UNIT/5;
	this->xValue[2] = xValue[1] + xLength - DELAY_UNIT/5;
	this->yValue = VISIBLE_Y - 1;
}

void eRoad::Draw()
{
	glColor4f(1.0,1.0,1.0,1.0);
	glBindTexture(GL_TEXTURE_2D, id_texture);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glBegin(GL_QUADS);
 	
 		glTexCoord2f(0.0f, 0.0f); glVertex2f ( xValue[0]            , yValue           ); 
 		glTexCoord2f(1.0f, 0.0f); glVertex2f ( xValue[0] + xLength  , yValue           );
 		glTexCoord2f(1.0f, 1.0f); glVertex2f ( xValue[0] + xLength  , yValue - yLength ); 
 		glTexCoord2f(0.0f, 1.0f); glVertex2f ( xValue[0]            , yValue - yLength ); 
 
 		glTexCoord2f(0.0f, 0.0f); glVertex2f ( xValue[1]            , yValue           ); 
 		glTexCoord2f(1.0f, 0.0f); glVertex2f ( xValue[1] + xLength  , yValue           );
 		glTexCoord2f(1.0f, 1.0f); glVertex2f ( xValue[1] + xLength  , yValue - yLength ); 
 		glTexCoord2f(0.0f, 1.0f); glVertex2f ( xValue[1]            , yValue - yLength ); 

 		glTexCoord2f(0.0f, 0.0f); glVertex2f ( xValue[2]            , yValue           ); 
 		glTexCoord2f(1.0f, 0.0f); glVertex2f ( xValue[2] + xLength  , yValue           );
 		glTexCoord2f(1.0f, 1.0f); glVertex2f ( xValue[2] + xLength  , yValue - yLength ); 
 		glTexCoord2f(0.0f, 1.0f); glVertex2f ( xValue[2]            , yValue - yLength ); 

  	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);

  	glDisable(GL_BLEND);
} 

void eRoad::Move()
{	
	if(xValue[0] + xLength > -VISIBLE_X)
	{
		xValue[0]-=Speed;
	}
	else
	{
		xValue[0]=xValue[2] + xLength - DELAY_UNIT;
	}
	if(xValue[1] + xLength > -VISIBLE_X)
	{
		xValue[1]-=Speed;
	}
	else
	{
		xValue[1] = xValue[0] + xLength - DELAY_UNIT/5;
	}
	if(xValue[2] + xLength > -VISIBLE_X)
	{
		xValue[2]-=Speed;
	}
	else
	{
		xValue[2] = xValue[1] + xLength - DELAY_UNIT/5;
	}
}

void eRoad::increaseSpeed()
{
	Speed += ROAD_SPEED;
}

void eRoad::decreaseSpeed()
{
	Speed -= ROAD_SPEED;
}