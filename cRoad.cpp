#include "cRoad.h"

cRoad::cRoad(void) 
{
	margin = -20;
	xLeftFront=margin;
	xRightFront=-margin;
	xRightBack=-margin;
	xRightBack=-3*margin;
	y=8.8;
	speed = 0.2;
}
cRoad::~cRoad(void){}

void cRoad::setSpeed(float x)
{
	speed = x;
}

float cRoad::getSpeed()
{
	return speed;
}

void cRoad::Init()
{
	if (!LoadGLTextures())
	{
		printf("Nu a mers!\n");
	}
	glEnable(GL_TEXTURE_2D);
}

int cRoad::LoadGLTextures() // Load Bitmaps And Convert To Textures
{
	/* load an image file directly as a new OpenGL texture */
	texture[0] = SOIL_load_OGL_texture
		(
		"Texture/Road.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);

	if(texture[0] == 0)
		return false;

	// Typical Texture Generation Using Data From The Bitmap
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	return true;
}

void drawOneLine(float x1, float y1, float x2, float y2)
{
	glBegin(GL_LINES);
	glVertex2f (x1,y1);
	glVertex2f (x2,y2);
	glEnd();
}

void cRoad::move()
{
	if(xRightFront>margin)
	{
		xRightFront-=speed;
		xLeftFront -=speed;
	}
	else
	{
		xLeftFront=xRightBack-speed;
		xRightFront = xLeftFront + (-2)*margin;
	}
	if(xRightBack>margin)
	{
		xRightBack-=speed;
		xLeftBack-=speed;
	}
	else
	{
		xLeftBack=xRightFront-speed;
		xRightBack=xLeftBack + (-2)*margin;
	}
}

void cRoad::draw()
{
	glColor4f(1.0,1.0,1.0,1.0);
	glBindTexture(GL_TEXTURE_2D, texture[0]);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glBegin(GL_QUADS);
 	
 		glTexCoord2f(0.0f, 0.0f); glVertex2f (xLeftFront,y); 
 		glTexCoord2f(1.0f, 0.0f); glVertex2f (xRightFront,y);
 		glTexCoord2f(1.0f, 1.0f); glVertex2f (xRightFront,y-12); 
 		glTexCoord2f(0.0f, 1.0f); glVertex2f (xLeftFront,y-12); 

 		glTexCoord2f(0.0f, 0.0f); glVertex2f (xLeftBack,y); 
 		glTexCoord2f(1.0f, 0.0f); glVertex2f (xRightBack,y);
 		glTexCoord2f(1.0f, 1.0f); glVertex2f (xRightBack,y-12); 
 		glTexCoord2f(0.0f, 1.0f); glVertex2f (xLeftBack,y-12); 
 
  	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);

  	glDisable(GL_BLEND);

  	move();
} 
