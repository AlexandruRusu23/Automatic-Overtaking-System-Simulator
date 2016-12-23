#include "eMessage.h"

eMessage::eMessage() {}
eMessage::~eMessage(){}

void eMessage::InitButton(float x, float y, float w, float h, int id_texture)
{
	xButton = x;
	yButton = y;
	widthButton = w;
	heightButton = h;
	button_texture = id_texture;
}

bool eMessage::insideButton(float x, float y)
{
	if(xButton <= x && x <= xButton + widthButton && yButton >= y && y >= yButton - heightButton )
		return true;
	return false;
}

void eMessage::drawButton()
{
	glColor4f(1.0,1.0,1.0,1.0);
	glBindTexture(GL_TEXTURE_2D, button_texture);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glBegin(GL_QUADS);
 	
 		glTexCoord2f(0.0f, 1.0f); glVertex2f ( xButton               , yButton                ); 
 		glTexCoord2f(1.0f, 1.0f); glVertex2f ( xButton + widthButton , yButton                );
 		glTexCoord2f(1.0f, 0.0f); glVertex2f ( xButton + widthButton , yButton - heightButton ); 
 		glTexCoord2f(0.0f, 0.0f); glVertex2f ( xButton               , yButton - heightButton ); 

  	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);

  	glDisable(GL_BLEND);
}

void eMessage::drawInfo()
{

}