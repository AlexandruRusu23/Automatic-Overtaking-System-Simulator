#include "Global.h"

class cCar
{
public:
	cCar(void);
	~cCar(void);

	//getters and setters
	int getLane();
	void setOnlyLane(int lane);
	float getxPosition();
	float getyPosition();
	float getyPosByLane(int lane);
	int getType();
	int getOrientation();
	float getSpeed();

	void setType(int x);
	void setByLane(int lane);
	void setxPosition(float xPos);
	void setyPosition(float yPos);
	void setSpeed(float x);

	//loading and drawing functions

	void Init();
	int LoadGLTextures();	
	void draw();

protected:
	int Lane;
	float xPosition,yPosition;
	float speed;
	int type; 
	// 0 == Porsche.png || 1 == RetroCar.png || 2 == PoliceCar.png || 3 == Mercedes.png
	int orientation; // -1 == left->right || 1 == right -> left
	GLuint texture[1];
};
