#pragma once

#include "eCar.h"

class eVehicle : public eCar
{
public:
	eVehicle();
	~eVehicle();

	void setChangeSpeed(int type, int lane);
	int getChangeSpeed();

	//data initialization
	void Init(int Lane, float xValue, int speed_units, int id_texture);

	//draw and move function
	void Draw();

	bool notInRange(int lane, float xPos);

	void Move();

	//Speed changing functions
	void increaseSpeed();
	void decreaseSpeed();

	void CalcRealSpeed(float road_speed);

private:
	int realSpeed;
};