#pragma once

#include "Global.h"

#define CAR_LENGTH 4
#define TIR_LENGTH 7
#define CAR_WIDTH 2

#define LANE_1 0
#define LANE_2 1
#define LANE_3 2
#define LANE_4 3

#define Y_L1 8.6
#define Y_L2 6.25
#define Y_L3 3.65
#define Y_L4 1.3

#define SPEED_STEP 0.01

#define CHANGE_UNIT 0.05

#define GO_TO_LEFT 1
#define GO_TO_RIGHT 2
#define RETURN_TO_LEFT 3
#define RETURN_TO_RIGHT 4
#define BRAKE 5

class eCar
{
public:
	eCar();
	~eCar();

	int getLane();
	float getxValue();
	float getSpeed();

	void Init();

	virtual void Draw() = 0;
	virtual void increaseSpeed() = 0;
	virtual void decreaseSpeed() = 0;

protected:
	int Lane;
	float xValue, yValue;
	float Speed;
	int Length;
	GLuint id_texture;
};