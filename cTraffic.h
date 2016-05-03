#include "cRoad.h"
#include "cPlayer.h"

class cTraffic
{
public:
	cTraffic();
	~cTraffic();

	int getMovePlayer();
	void setMovePlayer(int active);

	bool VerifySpawn(cCar newCar);

	void InitCar(int type, int lane, float xPos);

	void CreateCar(int lane,int type, float xPos);

	void LoadRoad();
	void LoadPlayer();

	void DrawRoad();
	void DrawCars();
	void DrawPlayer();

	void MoveCars();

	void VerifyLimit();

	void AOS();

	void MovePlayerLeft(int lane);
	void MovePlayerRight(int lane);
	void BrakePlayer(int lane);
	void AcceleratePlayer(int lane);

private:
	cRoad Road;
	vector<cCar> Car;
	cPlayer Player;
	bool activatePlayer;
	int movePlayer;
	bool moveLeft, moveRight, Accelerate, Brake;
};