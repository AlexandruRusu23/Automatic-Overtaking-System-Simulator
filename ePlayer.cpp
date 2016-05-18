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

	if(changeLane == GO_TO_LEFT)
	{
		if(yValue < yValueByLane(Lane))
			changeLane = RETURN_TO_LEFT;
	}
	if(changeLane == GO_TO_RIGHT)
	{
		if(yValue > yValueByLane(Lane))
			changeLane = RETURN_TO_RIGHT;
	}
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
		case GO_TO_LEFT:
			if(Lane > LANE_1)
				MoveToLane(Lane - 1);
			else
				changeLane = 0;
		break;
		case GO_TO_RIGHT:
			if(Lane < LANE_4)
				MoveToLane(Lane + 1);
			else
				changeLane = 0;
		break;
		case RETURN_TO_LEFT:
			if(Lane > LANE_1)
				MoveToLane(Lane);
			else
			{
				if(Lane == LANE_1)
					MoveToLane(Lane);
				else
					changeLane = 0;
			}
		break;
		case RETURN_TO_RIGHT:
			if(Lane < LANE_4)
				MoveToLane(Lane);
			else
			{
				if(Lane == LANE_4)
					MoveToLane(Lane);
				else
					changeLane = 0;
			}
		break;
	}
}

void ePlayer::MoveToLane(int lane)
{
	float yAux = yValueByLane(lane);

	if(changeLane == GO_TO_LEFT || changeLane == RETURN_TO_LEFT)
	{
		if(yValue < yAux)
		{
			yValue += CHANGE_UNIT;
		}
		else
		{
			Lane = lane;
			yValue = yAux;
			changeLane = 0;
		}
	}
	if(changeLane == GO_TO_RIGHT || changeLane == RETURN_TO_RIGHT)
	{
		if(yValue > yAux)
		{
			yValue -= CHANGE_UNIT;
		}
		else
		{
			Lane = lane;
			yValue = yAux;
			changeLane = 0;
		}
	}
}
