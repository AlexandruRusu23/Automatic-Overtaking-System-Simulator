#include "cRoad.h"
#include "cPlayer.h"

class cTraffic
{
public:
	cTraffic();
	~cTraffic();

	void Init();

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

	int LoadGLTextures();
	void AOS();
	void drawMessage(int i, float xLeft, float xRight, float yTop, float yBottom);
	void DisplayAOS();

	void MovePlayerLeft(int lane);
	void MovePlayerRight(int lane);
	void MoveBackPlayer();
	void SetTrafficSpeedPlayer();
	void SetInitialSpeedPlayer();
	void DecreaseSpeedPlayer();

private:
	cRoad Road;
	vector<cCar> Car;
	cPlayer Player;
	bool activatePlayer;
	int movePlayer;
	bool moveLeft, moveRight, moveBack, setInitialSpeed, setTrafficSpeed;
	bool leftAOS, rightAOS, bothAOS;
	int texture[30];
};
