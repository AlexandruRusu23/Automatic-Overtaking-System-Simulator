#include "cRoad.h"

cRoad::cRoad(void) {}
cRoad::~cRoad(void){}

void drawOneLine(float x1, float y1, float x2, float y2, float z1, float z2)
{ 	glBegin(GL_LINES);
    glVertex3f (x1,y1,z2);
    glVertex3f (x2,y2,z2);
    glEnd();
}

void cRoad::draw()
{
	glPushMatrix();
    glBegin(GL_QUADS);
	glColor3f(0.4, 0.4, 0.4);
 	
 		glVertex3f (-38.0,6.5,-11.0); 
 		glVertex3f (38.0,6.5,-11.0);
 		glVertex3f (38.0,-4.5,-11.0); 
 		glVertex3f (-38.0,-4.5,-11.0); 
 	
 	glEnd();

	glBegin(GL_LINES);
 	glColor3f(0.97, 0.97, 1.0);

    glEnable (GL_LINE_STIPPLE);
    glLineStipple (10, 0xAAAA);  
    drawOneLine(-38.0, 1.0, 38.0, 1.0,-11.0,-11.0);
    drawOneLine(-38.0, 0.8, 38.0, 0.8,-11.0,-11.0); 

	glEnable (GL_LINE_STIPPLE);
    glLineStipple (10, 0xAAAA); 
	drawOneLine(-38.0, 3.7, 38.0, 3.7,-11.0,-11.0);

	glEnable (GL_LINE_STIPPLE);
    glLineStipple (10, 0xAAAA); 
   	drawOneLine(-38.0, -1.8, 38.0, -1.7,-11.0,-11.0);
   
  	glEnd();

  	glFlush();
 	glPopMatrix();
} 