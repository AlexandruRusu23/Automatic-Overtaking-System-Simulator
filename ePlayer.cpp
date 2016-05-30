#include "ePlayer.h"

ePlayer::ePlayer() {}
ePlayer::~ePlayer(){}
void ePlayer::increaseSpeed() {}
void ePlayer::decreaseSpeed() {}

void ePlayer::setID(int id_texture)
{
	this->id_texture = id_texture;
}

int ePlayer::getLength()
{
	return Length;
}

void ePlayer::setLength(int Length)
{
	this->Length = Length;
}

float ePlayer::getyValue()
{
	return yValue;
}

void ePlayer::setBlinker(int value)
{
	this->blinkerSwitch = value;
}

void ePlayer::Init(int id_texture)
{
	this->id_texture = id_texture;
	this->Lane = LANE_3;
	this->xValue = -5;
	this->yValue = yValueByLane(Lane);
	this->Length = CAR_LENGTH;
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
	glRotatef(maneuverAngle,0.0,0.0,1.0);

		glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex2f(xValue         , yValue             );
			glTexCoord2f(0.0f, 1.0f); glVertex2f(xValue - Length, yValue             );
			glTexCoord2f(0.0f, 0.0f); glVertex2f(xValue - Length, yValue - CAR_WIDTH );
			glTexCoord2f(1.0f, 0.0f); glVertex2f(xValue         , yValue - CAR_WIDTH );
		glEnd();

	glBindTexture(GL_TEXTURE_2D,0);

		if (blinkerSwitch != 0) {
			
			float lrbx, lrby, lfbx, lfby, rrbx, rrby, rfbx, rfby;

			if(Length == CAR_LENGTH)
			{
				lrbx = xValue - 3.85, lrby = yValue - 1.55;
				lfbx = xValue - 0.3, lfby = yValue - 1.55;
				rrbx = xValue - 3.65, rrby = yValue - 0.45;
				rfbx = xValue - 0.5, rfby = yValue - 0.4;
			}
			else
			{
				lrbx = xValue - 6.85, lrby = yValue - 1.55;
				lfbx = xValue - 0.3, lfby = yValue - 1.55;
				rrbx = xValue - 6.65, rrby = yValue - 0.45;
				rfbx = xValue - 0.5, rfby = yValue - 0.4;
			}
			if (blinkerStage < 50) {
				glColor3f(1.0,1.0,0.0);
				if (blinkerSwitch == 1) {
					glBegin(GL_QUADS);
						glVertex2f(lrbx,lrby);
						glVertex2f(lrbx + 0.15,lrby - 0.15);
						glVertex2f(lrbx + 0.2,lrby - 0.1);
						glVertex2f(lrbx + 0.05,lrby + 0.1);
					glEnd();
					glBegin(GL_QUADS);
						glVertex2f(lfbx,lfby);
						glVertex2f(lfbx - 0.15,lfby - 0.15);
						glVertex2f(lfbx - 0.2,lfby - 0.1);
						glVertex2f(lfbx - 0.05,lfby + 0.1);
					glEnd();
				}
				if (blinkerSwitch == -1) {
					glBegin(GL_QUADS);
						glVertex2f(rrbx,rrby);
						glVertex2f(rrbx - 0.15,rrby - 0.15);
						glVertex2f(rrbx - 0.2,rrby - 0.1);
						glVertex2f(rrbx - 0.05,rrby + 0.1);
					glEnd();
					glBegin(GL_QUADS);
						glVertex2f(rfbx,rfby);
						glVertex2f(rfbx + 0.15,rfby - 0.15);
						glVertex2f(rfbx + 0.2,rfby - 0.1);
						glVertex2f(rfbx + 0.05,rfby + 0.1);
					glEnd();
				}
			}
			blinkerStage++;
			if (blinkerStage == 100) blinkerStage = 0;	
		}

	glPopMatrix();

	glColor4f(1.0,1.0,1.0,1.0);

	glDisable(GL_BLEND);

	if(yValue == yValueByLane(Lane)) 
	{
		maneuverAngle = 0.0;
		leftManeuverStage = 0;
		rightManeuverStage = 0;
	}
}

bool ePlayer::insideArea(float x, float y)
{
	if(xValue >= x && x >= xValue - Length && yValue >= y && y >= yValue - CAR_WIDTH )
		return true;
	return false;
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

	if(direction == GO_TO_RIGHT)
	{
		if (rightManeuverStage == 0)
			rightManeuverStage = 1;
		if (rightManeuverStage == 1) 
		{
			if (maneuverAngle > -4.0) maneuverAngle -= 0.06;
			if (maneuverAngle <= -4.0) rightManeuverStage = -1;
		}
		if (rightManeuverStage == -1) 
		{
			if (maneuverAngle < 0.0) maneuverAngle += 0.09;
			if (maneuverAngle >= 0.0) maneuverAngle = 0.0;
		}
	}
	if(direction == GO_TO_LEFT)
	{
		if (leftManeuverStage == 0) 
			leftManeuverStage = 1;
		if (leftManeuverStage == 1) 
		{
			if (maneuverAngle < 4.0) maneuverAngle += 0.06;
			if (maneuverAngle >= 4.0) leftManeuverStage = -1;
		}
		if (leftManeuverStage == -1) 
		{
			if (maneuverAngle > 0.0) maneuverAngle -= 0.09;
			if (maneuverAngle <= 0.0) maneuverAngle = 0.0;
		}
	}

}