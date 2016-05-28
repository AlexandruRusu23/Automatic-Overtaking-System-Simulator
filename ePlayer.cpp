#include "ePlayer.h"

ePlayer::ePlayer() {}
ePlayer::~ePlayer(){}
void ePlayer::increaseSpeed() {}
void ePlayer::decreaseSpeed() {}

void ePlayer::Init(int id_texture)
{
	this->id_texture = id_texture;
	this->Lane = LANE_3;
	this->xValue = -5;
	this->yValue = yValueByLane(Lane);
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
	}
}

void ePlayer::Draw()
{
	glBindTexture(GL_TEXTURE_2D, id_texture);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPushMatrix();
	glLoadIdentity();

	glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex2f(xValue             , yValue             );
		glTexCoord2f(0.0f, 1.0f); glVertex2f(xValue - CAR_LENGTH, yValue             );
		glTexCoord2f(0.0f, 0.0f); glVertex2f(xValue - CAR_LENGTH, yValue - CAR_WIDTH );
		glTexCoord2f(1.0f, 0.0f); glVertex2f(xValue             , yValue - CAR_WIDTH );
	glEnd();

	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D,0);

	glDisable(GL_BLEND);
}

void ePlayer::MoveToLane(int Lane, int direction)
{
	float yAux;
	if(Lane >= LANE_1 && Lane <= LANE_4)
	{
		if(Lane == LANE_1 || Lane == LANE_4)
		{
			if(this->Lane == Lane)
			{
				if(yValue != yValueByLane(Lane))
				{
					yAux = yValueByLane(Lane);
				}
				else
				direction = 43538;
			}
			else
			{
				yAux = yValueByLane(Lane);
			}
		}
		else
		{
			yAux = yValueByLane(Lane);
		}
		if(direction == GO_TO_LEFT)
		{
			if(yValue < yAux)
			{
				yValue += CHANGE_UNIT;
			}
			else
			{
				this->Lane = Lane;
				yValue = yAux;
			}
		}
		if(direction == GO_TO_RIGHT)
		{
			if(yValue > yAux)
			{
				yValue -= CHANGE_UNIT;
			}
			else
			{
				this->Lane = Lane;
				yValue = yAux;
			}
		}
	}
}
