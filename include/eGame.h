#pragma once

#include "eData.h"
#include "eRoad.h"
#include "eVehicle.h"
#include "ePlayer.h"
#include "eMessage.h"

#define KM_H_110 0.36
#define KM_H_18 0.07

#define LOOK_FRONT 1
#define LOOK_BEHIND 2
#define LOOK_MIDDLE 3

#define FRONT_LIMIT 4
#define BEHIND_LIMIT 4
#define MIDDLE_LIMIT 1
#define FPS 60

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

	bool checkFreeArea(int lane, int direction, int limit);

	void AOS();
	void CRUISE();

	//draw and move all objects
	void Render();

	void Update();

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
	eMessage newMercedes, newRetro, newPolice, newPorsche, newTir;
	eMessage changePlayer, speedUpPlayer, speedDownPlayer;
	eMessage cruiseButton, aosButton, panel;
	eMessage aosInfo, stateInfo, aosInfoText, stateInfoText;
	eMessage blinker;

	eMessage numar1,numar2,numar3;
	eMessage kilometru;

	eMessage playerInfo;
	eMessage playButton;

	eMessage plusButton, minusButton;
	eMessage cifra1, cifra2;
	eMessage meters;

	bool gameRunning;

	int AddCarState,carChoice;
	int changePlayerSkin;
	int showPlayerInfo;
	float windowWidth,windowHeight;
	int fpsclock;
	int blinkRatio;
	int increaseSpeedRatio, decreaseSpeedRatio;

	float laneSpeed[4];

	int laneToChange;
	float cruiseDistance;
	float cruiseSpeed;

	bool cruiseModeReduce, cruiseModeAdapt, cruiseModeReturn;

	bool PlayerOvertake, PlayerCruising;

	bool checkFreeSpawnSpace(int lane, float xPos);
	void drawUIButtons();
};