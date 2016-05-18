#include "eVehicle.h"

eVehicle::eVehicle() 
{
	changeSpeed = 0;
}
eVehicle::~eVehicle(){}

void eVehicle::setChangeSpeed(int val) { changeSpeed = val; }
int eVehicle::getChangeSpeed() { return changeSpeed; }

void eVehicle::Init(int lane,float xPos, int id_texture)
{
	this->id_texture = id_texture;
	Lane = lane;
	xValue = xPos;
	switch(Lane)
	{
		case LANE_1:
			yValue = Y_L1;
			switch (changeSpeed)
			{
				case HIGH_SPEED:
					Speed = 4*SPEED_SCALE;
				break;
				case MEDIUM_SPEED:
					Speed = 5*SPEED_SCALE;
				break;
				case LOW_SPEED:
					Speed = 6*SPEED_SCALE;
				break;
			}
			if(xPos < -50)
				xValue = VISIBLE_X - epsilon;
		break;
		case LANE_2:
			yValue = Y_L2;
			switch (changeSpeed)
			{
				case HIGH_SPEED:
					Speed = 4*SPEED_SCALE;
				break;
				case MEDIUM_SPEED:
					Speed = 5*SPEED_SCALE;
				break;
				case LOW_SPEED:
					Speed = 6*SPEED_SCALE;
				break;
			}
			if(xPos < -50)
				xValue = VISIBLE_X - epsilon;
		break;
		case LANE_3:
			yValue = Y_L3;
			switch (changeSpeed)
			{
				case HIGH_SPEED:
					Speed = SPEED_SCALE;
				break;
				case MEDIUM_SPEED:
					Speed = 0;
				break;
				case LOW_SPEED:
					Speed = -SPEED_SCALE;
				break;
			}
			if(xPos < -50)
				xValue = -VISIBLE_X + epsilon;
		break;
		case LANE_4:
			yValue = Y_L4;
			switch (changeSpeed)
			{
				case HIGH_SPEED:
					Speed = SPEED_SCALE;
				break;
				case MEDIUM_SPEED:
					Speed = 0;
				break;
				case LOW_SPEED:
					Speed = -SPEED_SCALE;
				break;
			}
			if(xPos < -50)
				xValue = -VISIBLE_X + epsilon;
		break;
	}
	changeSpeed = 0;
}

void eVehicle::Draw()
{
	glBindTexture(GL_TEXTURE_2D, id_texture);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	if(Lane > LANE_2)
	{
		glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex2f(xValue             , yValue             );
			glTexCoord2f(0.0f, 1.0f); glVertex2f(xValue - CAR_LENGTH, yValue             );
			glTexCoord2f(0.0f, 0.0f); glVertex2f(xValue - CAR_LENGTH, yValue - CAR_WIDTH );
			glTexCoord2f(1.0f, 0.0f); glVertex2f(xValue             , yValue - CAR_WIDTH );
		glEnd();
	}
	else
	{
		glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex2f(xValue             , yValue             );
			glTexCoord2f(0.0f, 1.0f); glVertex2f(xValue + CAR_LENGTH, yValue             );
			glTexCoord2f(0.0f, 0.0f); glVertex2f(xValue + CAR_LENGTH, yValue - CAR_WIDTH );
			glTexCoord2f(1.0f, 0.0f); glVertex2f(xValue             , yValue - CAR_WIDTH );
		glEnd();	
	}
	glBindTexture(GL_TEXTURE_2D,0);

	glDisable(GL_BLEND);

	Move();
}

void eVehicle::Move()
{
	if(Lane > LANE_2)
	{
		if(xValue > -(VISIBLE_X + 4*CAR_LENGTH) || xValue - CAR_LENGTH < VISIBLE_X + 4*CAR_LENGTH )
		{
			xValue += Speed;
		}
		if(xValue < -(VISIBLE_X + 4*CAR_LENGTH))
			xValue = (VISIBLE_X + CAR_LENGTH) + 4*CAR_LENGTH;
		if(xValue - CAR_LENGTH > VISIBLE_X + 4*CAR_LENGTH)
			xValue = -(VISIBLE_X + 4*CAR_LENGTH);
	}
	else
	{
		if(xValue > -(VISIBLE_X + 4*CAR_LENGTH) )
		{
			xValue -= Speed;
		}
		else
		{
			xValue = VISIBLE_X + 4*CAR_LENGTH;
		}
	}

	switch (changeSpeed)
	{
		case LOW_SPEED:
			SetLowSpeed();
		break;
		case MEDIUM_SPEED:
			SetMediumSpeed();
		break;
		case HIGH_SPEED:
			SetHighSpeed();
		break;
	}
}

void eVehicle::SetLowSpeed()
{
	if(changeSpeed == LOW_SPEED)
	{
		if(Lane > LANE_2)
		{
			if(Speed > -SPEED_SCALE)
			{
				Speed -= SPEED_UNIT;
			}
			else
			{
				Speed = -SPEED_SCALE;
				changeSpeed = 0;
			}
		}
		else
		{
			if(Speed < 6*SPEED_SCALE)
			{
				Speed += SPEED_UNIT;
			}
			else
			{
				Speed = 6*SPEED_SCALE;
				changeSpeed = 0;
			}
		}
	}
}

void eVehicle::SetMediumSpeed()
{
	if(changeSpeed == MEDIUM_SPEED)
	{
		if(Lane > LANE_2)
		{
			if(Speed > 0)
			{
				Speed -= SPEED_UNIT;
			}
			else
			{
				if(Speed < 0)
				{
					Speed += SPEED_UNIT;
				}
			}
			if(Speed > -epsilon && Speed < epsilon)
			{				
				Speed = 0;
				changeSpeed = 0;
			}
		}
		else
		{
			if(Speed > 5*SPEED_SCALE)
			{
				Speed -= SPEED_UNIT;
			}
			else
			{
				if(Speed < 5*SPEED_SCALE)
				{
					Speed += SPEED_UNIT;
				}
			}
			if(Speed > 5*SPEED_SCALE - epsilon && Speed < 5*SPEED_SCALE + epsilon)
			{
				Speed = 5*SPEED_SCALE;
				changeSpeed = 0;
			}
		}
	}
}

void eVehicle::SetHighSpeed()
{
	if(changeSpeed == HIGH_SPEED)
	{
		if(Lane > LANE_2)
		{
			if(Speed < SPEED_SCALE)
			{
				Speed += SPEED_UNIT;
			}
			else
			{
				Speed = SPEED_SCALE;
				changeSpeed = 0;			
			}
		}
		else
		{
			if(Speed > 4*SPEED_SCALE)
			{
				Speed -= SPEED_UNIT;
			}
			else
			{
				Speed = 4*SPEED_SCALE;
				changeSpeed = 0;
			}
		}
	}
}
