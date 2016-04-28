#include "cRoad.h"

cRoad::cRoad(void) 
{
	xLeftFront=-16;
	xRightFront=16;
	xRightBack=16;
	xRightBack=48;
	y=5.8;
}
cRoad::~cRoad(void){}

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
	if(xRightFront>-16)
	{
		xRightFront-=0.05;
		xLeftFront -=0.05;
	}
	else
	{
		xLeftFront=xRightBack-0.05;
		xRightFront = xLeftFront + 32;
	}
	if(xRightBack>-16)
	{
		xRightBack-=0.05;
		xLeftBack-=0.05;
	}
	else
	{
		xLeftBack=xRightFront-0.05;
		xRightBack=xLeftBack + 32;
	}
}

void cRoad::draw()
{
	glBindTexture(GL_TEXTURE_2D, texture[0]);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glBegin(GL_QUADS);
 	
 		glTexCoord2f(0.0f, 0.0f); glVertex2f (xLeftFront,y); 
 		glTexCoord2f(1.0f, 0.0f); glVertex2f (xRightFront,y);
 		glTexCoord2f(1.0f, 1.0f); glVertex2f (xRightFront,y-10); 
 		glTexCoord2f(0.0f, 1.0f); glVertex2f (xLeftFront,y-10); 

 		glTexCoord2f(0.0f, 0.0f); glVertex2f (xLeftBack,y); 
 		glTexCoord2f(1.0f, 0.0f); glVertex2f (xRightBack,y);
 		glTexCoord2f(1.0f, 1.0f); glVertex2f (xRightBack,y-10); 
 		glTexCoord2f(0.0f, 1.0f); glVertex2f (xLeftBack,y-10); 
 
  	glEnd();

  	glDisable(GL_BLEND);

  	move();
} 