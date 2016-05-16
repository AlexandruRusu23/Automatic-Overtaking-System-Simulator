#pragma once

#include "Global.h"

class eTexture
{
public:
	eTexture();
	~eTexture();

	//get texture id
	int GetID();

	//load image as texture with SOIL
	bool Load(string *filename);

private:
	//texture id
	GLuint id;
};