#pragma once

#include "eTexture.h"

//number of images to be loaded as texture with SOIL
#define TEXTURE_NUMBERS 50

//index of every image in Textures array
#define IMG_PORSCHE 0
#define IMG_RETRO 1
#define IMG_POLICE 2
#define IMG_MERCEDES 3
#define IMG_ROAD 4
#define IMG_NEW_BUTTON 5
#define IMG_CHANGE_PLAYER_BUTTON 6
#define IMG_TIR 7
#define IMG_PLUS_BUTTON 8
#define IMG_MINUS_BUTTON 9
#define IMG_PLAYER_INFO 10
#define IMG_CRUISE_BUTTON_ON 11
#define IMG_CRUISE_BUTTON_OFF 12
#define IMG_PANEL 13
#define IMG_AOS_INFO 14
#define IMG_NOTHING_TEXT 15
#define IMG_BOTH_LANES_TEXT 16
#define IMG_LEFT_LANE_TEXT 17
#define IMG_RIGHT_LANE_TEXT 18
#define IMG_STATE_INFO 19
#define IMG_SPEEDING_TEXT 20
#define IMG_CRUISING_TEXT 21
#define IMG_OVERTAKING_TEXT 22
#define IMG_KMH 23
#define IMG_PLAY_BUTTON 24
#define IMG_PAUSE_BUTTON 25
#define IMG_AOS_ON 26
#define IMG_AOS_OFF 27
#define IMG_ARROW_LEFT 28
#define IMG_ARROW_RIGHT 29

#define IMG_0 30
#define IMG_1 31
#define IMG_2 32
#define IMG_3 33
#define IMG_4 34
#define IMG_5 35
#define IMG_6 36
#define IMG_7 37
#define IMG_8 38
#define IMG_9 39 

#define IMG_METERS 40

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