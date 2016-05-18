#pragma once

#include "eData.h"
#include "eRoad.h"
#include "eVehicle.h"
#include "ePlayer.h"

class eGame
{
public:
	eGame();
	~eGame();

	//init for every object's data and texture
	void Init();

	//keyboard input behavior
	void Keyboard(unsigned char key, int x, int y);

	//draw and move all objects
	void Render();

private:
	// Game can see and control all other objects
	eData Data;
	eRoad Road;
	vector <eVehicle> Vehicle;
	eVehicle newVehicle;
	ePlayer Player;

	int state_vehicle_speed;

	bool checkFreeSpace(int lane, float xPos);
};