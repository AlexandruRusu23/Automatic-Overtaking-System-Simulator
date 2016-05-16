#include "ePlayer.h"

ePlayer::ePlayer() 
{
	changeLane = 0;
}
ePlayer::~ePlayer(){}
void ePlayer::SetLowSpeed() {}
void ePlayer::SetMediumSpeed() {}
void ePlayer::SetHighSpeed() {}

void ePlayer::Init(int id_texture)
{
	this->id_texture = id_texture;
	Lane = LANE_3;
	xValue = -5;
	yValue = yValueByLane(Lane);
}

void ePlayer::setChangeLane(int val)
{
	changeLane = val;
}

float ePlayer::yValueByLane(int l)
{
	switch(l)
	{
		case LANE_1:
			return Y_L1;
		break;
		case LANE_2:
			return Y_L2;
		break;
		case LANE_3:
			return Y_L3;
		break;
		case LANE_4:
			return Y_L4;
		break;
		default:
			return -100;
		break;
	}
}

void ePlayer::Draw()
{
	glBindTexture(GL_TEXTURE_2D, id_texture);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex2f(xValue             , yValue             );
		glTexCoord2f(0.0f, 1.0f); glVertex2f(xValue - CAR_LENGTH, yValue             );
		glTexCoord2f(0.0f, 0.0f); glVertex2f(xValue - CAR_LENGTH, yValue - CAR_WIDTH );
		glTexCoord2f(1.0f, 0.0f); glVertex2f(xValue             , yValue - CAR_WIDTH );
	glEnd();

	glBindTexture(GL_TEXTURE_2D,0);

	glDisable(GL_BLEND);

	Move();
}

void ePlayer::Move()
{
	switch(changeLane)
	{
		case 1:
			ChangeToLeftLane();
		break;
		case 2:
			ChangeToRightLane();
		break;
	}
}

void ePlayer::ChangeToLeftLane()
{
	if(changeLane == 1)
	{
		float yAux = yValueByLane(Lane - 1);
		if(yAux >= -20)
		{
			if(yValue < yAux)
			{
				yValue += CHANGE_UNIT;
			}
			else
			{
				changeLane = 0;
				yValue = yAux;
				Lane = Lane - 1;
			}
		}
	}
}

void ePlayer::ChangeToRightLane()
{
	if(changeLane == 2)
	{
		float yAux = yValueByLane(Lane + 1);
		if(yAux >= -20)
		{
			if(yValue > yAux)
			{
				yValue -= CHANGE_UNIT;
			}
			else
			{
				changeLane = 0;
				yValue = yAux;
				Lane = Lane + 1;
			}
		}
	}
}
