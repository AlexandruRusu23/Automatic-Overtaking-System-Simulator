#pragma once

#include "eData.h"
#include "eRoad.h"
#include "eVehicle.h"
#include "ePlayer.h"

#define AddCarButtonX 16.5
#define AddCarButtonY -7.5
#define CarType1X 7
#define CarType1Y -4
#define CarType2X 12
#define CarType2Y -4
#define CarType3X 17
#define CarType3Y -4

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
	void MouseMotion(int x,int y);

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

	int state_vehicle_speed;

	int AddCarState,carChoice;
	float AddButtonWidth,AddButtonHeight,CarTypeWidth,CarTypeHeight;
	int windowWidth,windowHeight;

	bool checkFreeSpace(int lane, float xPos);
	void drawUIButtons();
};