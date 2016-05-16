#include "eData.h"

eData::eData() {}
eData::~eData(){}

int eData::GetID(int img)
{
	return Textures[img].GetID();
}

bool eData::LoadImage(int img, string *filename)
{
	int aux;

	aux = Textures[img].Load(filename);

	if(!aux) return false;

	return true;
}

bool eData::Load()
{
	int aux;

	aux = LoadImage(IMG_PORSCHE, new string("Texture/Cars/Porsche.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_RETRO, new string("Texture/Cars/RetroCar.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_POLICE, new string("Texture/Cars/PoliceCar.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_MERCEDES, new string("Texture/Cars/Mercedes.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_ROAD, new string("Texture/Road.png"));
	if(!aux) return false;

	return true;
}