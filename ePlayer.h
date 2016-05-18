#pragma once

#include "eCar.h"

#define GO_TO_LEFT 1
#define GO_TO_RIGHT 2
#define RETURN_TO_LEFT 3
#define RETURN_TO_RIGHT 4

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

	//lane changing
	void MoveToLane(int lane);
	
	void SetLowSpeed();
	void SetMediumSpeed();
	void SetHighSpeed();
};