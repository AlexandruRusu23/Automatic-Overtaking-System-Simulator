#include "Global.h"

class cCar
{
public:
	cCar(void);
	~cCar(void);

	int getLane();
	float getxPosition();
	void setType(int x);
	void setPlayer(bool g);

	void setPosition(int Lane, float xPosition);

	void Init();
	int LoadGLTextures();	
	void draw();

	void move();

private:
	bool player;
	int Lane;
	float xPosition,yPosition;
	int type; 
	// 0 == Porsche.png || 1 == RetroCar.png || 2 == PoliceCar.png
	int orientation; // 0 == left->right || 1 == right -> left
	GLuint texture[1];
};
