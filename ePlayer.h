#pragma once

#include "eCar.h"

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
	float maneuverAngle,leftManeuverStage,rightManeuverStage;

	float yValueByLane(int l);

	void Move();

	//lane changing
	void MoveToLane(int lane);
	
	void SetLowSpeed();
	void SetMediumSpeed();
	void SetHighSpeed();
};