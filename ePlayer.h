#pragma once

#include "eCar.h"

#define CHANGE_UNIT 0.025

class ePlayer : public eCar
{
public:
	ePlayer();
	~ePlayer();

	void Init(int id_texture);

	void setChangeLane(int val);

	//draw and move functions
	void Draw();

private:
	int changeLane;

	float yValueByLane(int l);

	void Move();

	//changing lane functions
	void ChangeToLeftLane();
	void ChangeToRightLane();

	void SetLowSpeed();
	void SetMediumSpeed();
	void SetHighSpeed();
};