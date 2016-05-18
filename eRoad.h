#pragma once

#include "Global.h"

#define ROAD_SLOW_SPEED 0.1
#define ROAD_MEDIUM_SPEED 0.15
#define ROAD_HIGH_SPEED 0.2

#define UNIT 0.0005 //unit for add or reduce to change road speed

class eRoad
{
public:
	eRoad();
	~eRoad();

	void setSetValue(int val);

	//calculate road coords and dimension
	void Load(int id_texture);

	//draw and move the road
	void Draw();

private:
	float speed;
	float xValue[4], yValue, xLength, yLength;

	int id_texture;
	int SetValue; 

	void Move();

	//speed changing functions
	void SetSlowSpeed();
	void SetMediumSpeed(); 
	void SetHighSpeed(); 
};