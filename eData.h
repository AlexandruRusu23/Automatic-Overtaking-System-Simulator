#pragma once

#include "eTexture.h"

//number of images to be loaded as texture with SOIL
#define TEXTURE_NUMBERS 20

//index of every image in Textures array
#define IMG_PORSCHE 0
#define IMG_RETRO 1
#define IMG_POLICE 2
#define IMG_MERCEDES 3
#define IMG_ROAD 4
#define IMG_NEW_BUTTON 5
#define IMG_AOS_INFO 6
#define IMG_PLAYER_STATE 7
#define IMG_BOTH_LANES_SHOW 8
#define IMG_RIGHT_LANE_SHOW 9
#define IMG_LEFT_LANE_SHOW 10
#define IMG_CRUISING_SHOW 11
#define IMG_SPEEDING_SHOW 12
#define IMG_OVERTAKING_SHOW 13
#define IMG_NOTHING_SHOW 14

class eData
{
public:
	eData();
	~eData();

	// get texture id
	int GetID(int img);

	// load entire texture in app stack
	bool Load();

private:
	eTexture Textures[TEXTURE_NUMBERS];
	bool LoadImage(int img, string *filename);
};