all:
	g++ -o exe AOSmain.cpp cWorld.cpp cRoad.cpp cCar.cpp -lGL -lGLU -lglut -lSOIL
