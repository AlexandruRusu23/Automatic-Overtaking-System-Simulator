#pragma once

#include "Global.h"

#define CAR_LENGTH 4
#define CAR_WIDTH 2

#define LANE_1 0
#define LANE_2 1
#define LANE_3 2
#define LANE_4 3

#define Y_L1 8.6
#define Y_L2 6.25
#define Y_L3 3.65
#define Y_L4 1.3

#define SPEED_SCALE 0.05
#define SPEED_UNIT 0.0005

class eCar
{
public:
	eCar();
	~eCar();

	int getLane();
	float getxValue();

	void Init(int laneAux);

	virtual void Draw() = 0;
	virtual void Move() = 0;
	virtual void SetLowSpeed() = 0;
	virtual void SetMediumSpeed() = 0;
	virtual void SetHighSpeed() = 0;

protected:
	int Lane;
	float xValue, yValue;
	float Speed;
	GLuint id_texture;
};