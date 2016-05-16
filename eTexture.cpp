#include "eTexture.h"

eTexture::eTexture() {}
eTexture::~eTexture(){}

int eTexture::GetID()
{
	return id;
}

bool eTexture::Load(string *filename)
{
	//SOIL request a char* input, not string object 
	//so we parse the string and write into a char *
	char * writable = new char[filename->size() + 1];
	copy(filename->begin(), filename->end(), writable);
	writable[filename->size()] = '\0';

	id = SOIL_load_OGL_texture(writable, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);

	delete[] writable;

	if(id == 0)
	{
		return false;
	}

	glBindTexture(GL_TEXTURE_2D, id);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glEnable(GL_TEXTURE_2D);

	return true;
}