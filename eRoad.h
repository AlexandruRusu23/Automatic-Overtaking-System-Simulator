#pragma once

#include "Global.h"

#define ROAD_SPEED 0.01

#define DELAY_UNIT 0.5

class eRoad
{
public:
	eRoad();
	~eRoad();

	float getSpeed();

	//calculate road coords and dimension
	void Load(int id_texture);

	//draw and move the road
	void Draw();

	void Move();

	//speed changing functions
	void increaseSpeed();
	void decreaseSpeed();  

private:
	float Speed;
	float xValue[4], yValue, xLength, yLength;

	int id_texture;
};