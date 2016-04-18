#include "cRoad.h"
#include "cCar.h"

class cWorld
{
public:

	cWorld();
	~cWorld();
	
	//Initialize the perspective and window scaling
	bool Init();

	//Input
	void Keyboard(unsigned char c, int x, int y);

	//Showing functions
	void Reshape(int w,int h);
	void Render();

private:
	cCar Car;
	cRoad Road;
};
