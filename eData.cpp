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
	aux = LoadImage(IMG_NEW_BUTTON, new string("Texture/Messages/new_button.png"));
	if(!aux) return false;

	aux = LoadImage(IMG_AOS_INFO, new string("Texture/Messages/aosinfo.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_PLAYER_STATE, new string("Texture/Messages/state.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_BOTH_LANES_SHOW, new string("Texture/Messages/bothlanes.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_RIGHT_LANE_SHOW, new string("Texture/Messages/rightlane.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_LEFT_LANE_SHOW, new string("Texture/Messages/leftlane.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_CRUISING_SHOW, new string("Texture/Messages/cruising.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_SPEEDING_SHOW, new string("Texture/Messages/speeding.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_OVERTAKING_SHOW, new string("Texture/Messages/overtaking.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_NOTHING_SHOW, new string("Texture/Messages/nothing.png"));
	if(!aux) return false;

	return true;
}