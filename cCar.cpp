#include "cCar.h"

cCar::cCar(){}
cCar::~cCar(){}

int cCar::getLane()
{
	return Lane;
}

void cCar::setOnlyLane(int lane)
{
	Lane = lane;
}

float cCar::getxPosition()
{
	return xPosition;
}

float cCar::getyPosition()
{
	return yPosition;
}

float cCar::getyPosByLane(int lane)
{	
	float y;
	switch (lane)
	{
		case 0:
			y=8.4;
			return y;
		break;
		case 1:
			y=5.5;
			return y;
		break;
		case 2:
			y=2.4;
			return y;
		break;
		case 3:
			y=-0.3;
			return y;
		break;
	}
}

int cCar::getType()
{
	return type;
}

int cCar::getOrientation()
{
	return orientation;
}

float cCar::getSpeed()
{
	return speed;
}

void cCar::setByLane(int lane)
{
	Lane=lane;
	switch (lane)
	{
		case 0:
			yPosition=8.4;
			orientation = 1;
			speed = 0.3;
		break;
		case 1:
			yPosition=5.5;
			orientation = 1;
			speed = 0.3;
		break;
		case 2:
			yPosition=2.4;
			orientation = -1;
			speed = 0.1;
		break;
		case 3:
			yPosition=-0.3;
			orientation = -1;
			speed = 0.1;
		break;
	}
}

void cCar::setxPosition(float xPos)
{
	xPosition = xPos;
}

void cCar::setyPosition(float yPos)
{
	yPosition = yPos;
}

void cCar::setType(int x)
{
	type = x;
}

void cCar::setSpeed(float x)
{
	speed = x;
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
		case 3:
			if(orientation == 1)
				texture[0] = SOIL_load_OGL_texture("Texture/revMercedes.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y );
			else
				texture[0] = SOIL_load_OGL_texture("Texture/Mercedes.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y );
	}

	if(texture[0] == 0)
		return false;

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
    	glTexCoord2f(1.0f, 1.0f); glVertex2f(xPosition    , yPosition     );
 		glTexCoord2f(0.0f, 1.0f); glVertex2f(xPosition - 5, yPosition     );
		glTexCoord2f(0.0f, 0.0f); glVertex2f(xPosition - 5, yPosition - 2.5 );
		glTexCoord2f(1.0f, 0.0f); glVertex2f(xPosition    , yPosition - 2.5 );
	glEnd();

	glBindTexture(GL_TEXTURE_2D,0);

	glDisable(GL_BLEND);

}
