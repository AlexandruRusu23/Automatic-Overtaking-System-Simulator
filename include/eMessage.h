#pragma once

#include "Global.h"

class eMessage
{
public:
	eMessage();
	~eMessage();

	void InitButton(float x, float y, float w, float h, int id_texture);

	bool insideButton(float x, float y);

	void drawButton();
	void drawInfo();

private:
	float xButton, yButton, widthButton, heightButton;
	int button_texture;
};