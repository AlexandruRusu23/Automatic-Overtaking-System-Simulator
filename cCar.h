#include "Global.h"

class cCar
{
public:
	cCar(void);
	~cCar(void);

	//getters and setters
	int getLane();
	float getxPosition();
	bool getPlayer();
	int getOrientation();
	void setType(int x);
	void setPlayer(bool g);
	void setLane(int lane);
	void setxPosition(float xPos);

	//loading and drawing functions

	void Init();
	int LoadGLTextures();	
	void draw();

private:
	bool player;
	int Lane;
	float xPosition,yPosition;
	int type; 
	// 0 == Porsche.png || 1 == RetroCar.png || 2 == PoliceCar.png || 3 == Mercedes.png
	int orientation; // -1 == left->right || 1 == right -> left
	GLuint texture[1];
};
