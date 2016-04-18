#include "Global.h"

struct data
{
	float xPosition,yPosition,zPosition; // Car position
	float xColor,yColor,zColor; // Car color
	int Lane; // car lane
	float Speed; // car speed
	float prefferedSpeed;
	int Orientation; // 1 = right-> left | -1 = left -> right
	int pressureFromBehind;
};

class cCar
{
public:
	cCar(void);
	~cCar(void);

	void makeNewCar();

	bool cDetector(data *newCar);

	void draw(data carToDraw);

	//draw all cars
	void drawCars();

	//detect next car for specified car 	
	vector<data>::iterator detectNextCar(vector<data>::iterator cCar);

	//detect last car for specified lane
	vector<data>::iterator detectLastCar(int cLane);

	//Car motion
	void move(vector<data>::iterator carToMove);

	//All Cars motion
	void moveCars();

private:
	vector<data> Car;
	int numberCar[4]; // number of cars per lane
};
