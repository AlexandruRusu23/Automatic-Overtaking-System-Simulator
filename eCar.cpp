#include "eCar.h"

eCar::eCar() {}
eCar::~eCar(){}

int eCar::getLane()
{
	return Lane;
}

float eCar::getxValue()
{
	return xValue;
}

void eCar::Init(int laneAux)
{
	Lane = laneAux;
	switch(Lane)
	{
		case LANE_1:
			yValue = Y_L1;
		break;
		case LANE_2:
			yValue = Y_L2;
		break;
		case LANE_3:
			yValue = Y_L3;
		break;
		case LANE_4:
			yValue = Y_L4;
		break;
	}
}

void eCar::Draw() {}

void eCar::Move() {}