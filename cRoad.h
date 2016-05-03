#include "Global.h"

class cRoad
{
public:
	cRoad(void);
	~cRoad(void);

	void Init();
	int LoadGLTextures();

	void setSpeed(float x);
	float getSpeed();

	void move();
	void draw();

private:
	float margin, luggage;
	float xLeftFront,xRightFront,xLeftBack,xRightBack,y;
	float speed;
	GLuint texture[1];
};