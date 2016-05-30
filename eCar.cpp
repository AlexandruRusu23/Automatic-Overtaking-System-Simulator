#include "eCar.h"

eCar::eCar() {}
eCar::~eCar(){}

int eCar::getLane()
{
	return Lane;
}

void eCar::setxValue(float xValue)
{
	this->xValue = xValue;
}

float eCar::getxValue()
{
	return xValue;
}

float eCar::getSpeed()
{
	return Speed;
}

void eCar::Init() {}

void eCar::Draw() {}