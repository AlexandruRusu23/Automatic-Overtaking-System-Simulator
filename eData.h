#pragma once

#include "eTexture.h"

//number of images to be loaded as texture with SOIL
#define TEXTURE_NUMBERS 10

//index of every image in Textures array
#define IMG_PORSCHE 0
#define IMG_RETRO 1
#define IMG_POLICE 2
#define IMG_MERCEDES 3
#define IMG_ROAD 4
#define IMG_NEW_BUTTON 5

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