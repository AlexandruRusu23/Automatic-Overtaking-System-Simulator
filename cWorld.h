#include "cTraffic.h"
#include <string>

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
	void Render();

private:
	cTraffic Traffic;
	string *str;
};
