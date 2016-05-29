#pragma once

#include "eCar.h"

class ePlayer : public eCar
{
public:
	ePlayer();
	~ePlayer();

	void setID(int id_texture);
	void setLength(int Length);
	int getLength();
	float getyValue();

	void Init(int id_texture);

	//draw and move functions
	void Draw();

	//lane changing
	void MoveToLane(int Lane, int direction);
	
	bool insideArea(float x, float y);

	void setBlinker(int value);

private:
	int moveTo;	

	float maneuverAngle,leftManeuverStage,rightManeuverStage;
	unsigned char blinkerStage;
	char blinkerSwitch;

	float yValueByLane(int l);

	void increaseSpeed();
	void decreaseSpeed();
};