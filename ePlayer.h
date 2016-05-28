#pragma once

#include "eCar.h"

class ePlayer : public eCar
{
public:
	ePlayer();
	~ePlayer();

	void Init(int id_texture);

	//draw and move functions
	void Draw();

	//lane changing
	void MoveToLane(int Lane, int direction);
	
private:
	int moveTo;

	float yValueByLane(int l);

	void increaseSpeed();
	void decreaseSpeed();
};