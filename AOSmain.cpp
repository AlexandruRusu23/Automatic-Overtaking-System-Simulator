#include "cWorld.h"

cWorld World;

void AppRender()
{
	World.Render();
}

void AppKeyboard(unsigned char key, int x, int y)
{
	World.Keyboard(key, x, y);
}

int main(int argc, char** argv)
{
	int res_x,res_y,pos_x,pos_y;
 
	glutInit(&argc, argv);

	//Make centered window
	res_x = glutGet(GLUT_SCREEN_WIDTH);
	res_y = glutGet(GLUT_SCREEN_HEIGHT);
	pos_x = (res_x>>1)-(SCREEN_WIDTH>>1);
	pos_y = (res_y>>1)-(SCREEN_HEIGHT>>1);

	//Setting the window
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(pos_x,pos_y);
	glutInitWindowSize(SCREEN_WIDTH,SCREEN_HEIGHT);
	glutCreateWindow("AOS Simulator");
	
	//Get a full screen window
	//glutFullScreen();

	//Calling functions
	glutDisplayFunc(AppRender);			
	glutKeyboardFunc(AppKeyboard);		

	//Simulator initialization
	World.Init();

	glutIdleFunc(AppRender); 

	//Application loop
	glutMainLoop();	
}
