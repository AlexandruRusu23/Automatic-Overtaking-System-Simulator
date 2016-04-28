#include "cCar.h"

class cTraffic
{
public:
	cTraffic();
	~cTraffic();

	void Init(bool player, int type, int lane, float xPos);

	void CreateCar(bool player, int lane,int type, float xPos);

	void DrawCars();

	void MoveCars();

	void VerifyLimit();

private:
	vector<cCar> Car;
};