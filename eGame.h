#pragma once

#include "eData.h"
#include "eRoad.h"
#include "eVehicle.h"
#include "ePlayer.h"
#include "eMessage.h"

#define LOOK_FRONT 1
#define LOOK_BEHIND 2
#define LOOK_MIDDLE 3

#define FRONT_LIMIT 4
#define BEHIND_LIMIT 4
#define MIDDLE_LIMIT 0.5

class eGame
{
public:
	eGame();
	~eGame();

	//init for every object's data and texture
	void Init();

	//keyboard input behavior
	void Keyboard(unsigned char key, int x, int y);

	//mouse input behavior
	void Mouse(int button,int state,float x,float y);
	void MouseMotion(float x,float y);

	bool checkNotPlayerCollision(int lane, int direction, int limit);

	void AOS();

	//draw and move all objects
	void Render();

	//get window size
	void Reshape(int w,int h);

private:
	// Game can see and control all other objects
	eData Data;
	eRoad Road;

	vector <eVehicle> Vehicle;
	eVehicle newVehicle;

	ePlayer Player;
	eMessage newCarButton;
	eMessage newMercedes, newRetro, newPolice;

	int state_vehicle_speed;

	int AddCarState,carChoice;
	float windowWidth,windowHeight;

	bool checkFreeSpace(int lane, float xPos);
	void drawUIButtons();
};