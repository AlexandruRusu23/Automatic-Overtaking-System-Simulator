#include "cCar.h"

cCar::cCar() 
{
	xPosition=-2.0;
	yPosition=0.4;
}
cCar::~cCar(){}

int cCar::getLane()
{
	return Lane;
}

float cCar::getxPosition()
{
	return xPosition;
}

void cCar::setPosition(int l, float xPos)
{
	xPosition=xPos;
	Lane=l;
	switch (l)
	{
		case 0:
			yPosition=5.65;
			orientation = 1;
		break;
		case 1:
			yPosition=3.2;
			orientation = 1;
		break;
		case 2:
			yPosition=0.4;
			orientation = 0;
		break;
		case 3:
			yPosition=-2.05;
			orientation = 0;
		break;
	}
}

void cCar::setType(int x)
{
	type = x;
}

void cCar::setPlayer(bool g)
{
	player = g;
}

void cCar::Init()
{
	if (!LoadGLTextures())
	{
		printf("Nu a mers!\n");
	}
	glEnable(GL_TEXTURE_2D);
}

int cCar::LoadGLTextures()
{
	/* load an image file directly as a new OpenGL texture */
	switch(type)
	{
		case 0 :
			if(orientation == 1)
				texture[0] = SOIL_load_OGL_texture("Texture/revPorsche.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y );
			else
				texture[0] = SOIL_load_OGL_texture("Texture/Porsche.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y );
		break;
		case 1 :
			if(orientation == 1)
				texture[0] = SOIL_load_OGL_texture("Texture/revRetroCar.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y );
			else
				texture[0] = SOIL_load_OGL_texture("Texture/RetroCar.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y );
		break;
		case 2 :
			if(orientation == 1)
				texture[0] = SOIL_load_OGL_texture("Texture/revPoliceCar.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y );
			else
				texture[0] = SOIL_load_OGL_texture("Texture/PoliceCar.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y );
		break;
	}

	if(texture[0] == 0)
		return false;

	// Typical Texture Generation Using Data From The Bitmap
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	return true;
}

void cCar::draw()
{
	glBindTexture(GL_TEXTURE_2D, texture[0]);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glBegin(GL_QUADS);
    	glTexCoord2f(0.0f, 1.0f); glVertex2f(xPosition,yPosition);
 		glTexCoord2f(0.0f, 0.0f); glVertex2f(xPosition,yPosition-2);
		glTexCoord2f(1.0f, 0.0f); glVertex2f(xPosition + 4,yPosition-2);
		glTexCoord2f(1.0f, 1.0f); glVertex2f(xPosition + 4,yPosition);
	glEnd();

	move();

	glDisable(GL_BLEND);
}

void cCar::move()
{
	if(Lane <= 1)
	{
		if(xPosition>-18)
			xPosition-=0.15;
		else
			xPosition=18;
	}
	else
	{
		if(player == false)
		{
			if(xPosition < 18 )
				xPosition+=0.05;
			else
				xPosition=-18;
		}
	}
}