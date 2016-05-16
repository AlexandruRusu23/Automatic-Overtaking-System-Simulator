#include "eRoad.h"

eRoad::eRoad() {}
eRoad::~eRoad(){}

void eRoad::setSetValue(int val)
{
	SetValue = val;
}

void eRoad::Load(int id_texture)
{
	this->id_texture = id_texture;
	SetValue = 0;
	speed = HIGH_SPEED; // high speed
	xLength = VISIBLE_X + VISIBLE_X * 0.1; // 20 units + 10% OF XLENGTH
	yLength = VISIBLE_Y ; // 12 units
	xValue[0] = -VISIBLE_X - VISIBLE_X * 0.05; // - ( 20 + 5% of VISIBLE_X )
	xValue[1] = xValue[0] + xLength;
	xValue[2] = xValue[1] + xLength;
	yValue = VISIBLE_Y - 1;
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

  	Move();
} 

void eRoad::Move()
{
	switch (SetValue)
	{
		case 1:
			SetSlowSpeed();
		break;
		case 2:
			SetMediumSpeed();
		break;
		case 3:
			SetHighSpeed();
		break;
	}
	
	if(xValue[0] + xLength > -VISIBLE_X)
	{
		xValue[0]-=speed;
	}
	else
	{
		xValue[0]=xValue[2] + xLength - 0.5;
	}
	if(xValue[1] + xLength > -VISIBLE_X)
	{
		xValue[1]-=speed;
	}
	else
	{
		xValue[1] = xValue[0] + xLength - 0.5;
	}
	if(xValue[2] + xLength > -VISIBLE_X)
	{
		xValue[2]-=speed;
	}
	else
	{
		xValue[2] = xValue[1] + xLength - 0.5;
	}
}

void eRoad::SetSlowSpeed()
{
	if(SetValue == 1)
	{
		if(speed > SLOW_SPEED)
		{
			speed -= UNIT;
		}
		else
		{
			speed = SLOW_SPEED;
			SetValue = 0;
		}
	}
}

void eRoad::SetMediumSpeed()
{
	if(SetValue == 2)
	{
		if(speed < MEDIUM_SPEED)
		{
			speed += UNIT;
		}
		else
		{
			if(speed > MEDIUM_SPEED)
			{
				speed -= UNIT;
			}
		}
		if(speed > MEDIUM_SPEED - epsilon && speed < MEDIUM_SPEED + epsilon)
		{
			speed == MEDIUM_SPEED;
			SetValue = 0;
		}
	}
}

void eRoad::SetHighSpeed()
{
	if(SetValue == 3)
	{
		if(speed < HIGH_SPEED)
		{
			speed += UNIT;
		}
		else
		{
			speed = HIGH_SPEED;
			SetValue = 0;
		}
	}
}