#pragma once

#include "eCar.h"

class eVehicle : public eCar
{
public:
	eVehicle();
	~eVehicle();

	void setChangeSpeed(int val);
	int getChangeSpeed();

	//data initialization
	void Init(int lane, float xPos, int id_texture);

	//draw and move function
	void Draw();

	bool notInRange(int lane, float xPos);

private:
	int changeSpeed;

	void Move();

	//Speed changing functions
	void SetLowSpeed();
	void SetMediumSpeed();
	void SetHighSpeed();
};