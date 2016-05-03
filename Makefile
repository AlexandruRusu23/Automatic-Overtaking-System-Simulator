all:
	g++ -o exe AOSmain.cpp cWorld.cpp cRoad.cpp cCar.cpp cTraffic.cpp cPlayer.cpp -lGL -lGLU -lglut -lSOIL
