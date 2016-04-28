#include "Global.h"

class cRoad
{
public:
	cRoad(void);
	~cRoad(void);

	void Init();
	int LoadGLTextures();

	void move();
	void draw();

private:
	float xLeftFront,xRightFront,xLeftBack,xRightBack,y;
	GLuint texture[1];
};