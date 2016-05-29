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

	if(!aux)
	{
		printf("Nu am reusit pe %d\n", img);
		return false;
	}

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
	aux = LoadImage(IMG_CHANGE_PLAYER_BUTTON, new string("Texture/Buttons/change.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_TIR, new string("Texture/Cars/TIR.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_PLUS_BUTTON, new string("Texture/Buttons/plus.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_MINUS_BUTTON, new string("Texture/Buttons/minus.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_PLAYER_INFO, new string("Texture/Messages/playerinfo.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_CRUISE_BUTTON_ON, new string("Texture/Buttons/cruise_mode_on.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_CRUISE_BUTTON_OFF, new string("Texture/Buttons/cruise_mode_off.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_PANEL, new string("Texture/Messages/panou.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_AOS_INFO, new string("Texture/Messages/aosinfo.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_NOTHING_TEXT, new string("Texture/Messages/nothing.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_BOTH_LANES_TEXT, new string("Texture/Messages/bothlanes.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_RIGHT_LANE_TEXT, new string("Texture/Messages/rightlane.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_LEFT_LANE_TEXT, new string("Texture/Messages/leftlane.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_STATE_INFO, new string("Texture/Messages/state.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_CRUISING_TEXT, new string("Texture/Messages/cruising.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_OVERTAKING_TEXT, new string("Texture/Messages/overtaking.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_SPEEDING_TEXT, new string("Texture/Messages/speeding.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_KMH, new string("Texture/Messages/kmh.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_PLAY_BUTTON, new string("Texture/Buttons/play.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_PAUSE_BUTTON, new string("Texture/Buttons/pause.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_AOS_ON, new string("Texture/Buttons/AOS_ON.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_AOS_OFF, new string("Texture/Buttons/AOS_OFF.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_ARROW_LEFT, new string("Texture/Buttons/arrow_left.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_ARROW_RIGHT, new string("Texture/Buttons/arrow_right.png"));
	if(!aux) return false;

	aux = LoadImage(IMG_0, new string("Texture/Alphabet/0.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_1, new string("Texture/Alphabet/1.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_2, new string("Texture/Alphabet/2.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_3, new string("Texture/Alphabet/3.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_4, new string("Texture/Alphabet/4.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_5, new string("Texture/Alphabet/5.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_6, new string("Texture/Alphabet/6.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_7, new string("Texture/Alphabet/7.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_8, new string("Texture/Alphabet/8.png"));
	if(!aux) return false;
	aux = LoadImage(IMG_9, new string("Texture/Alphabet/9.png"));
	if(!aux) return false;

	return true;
}