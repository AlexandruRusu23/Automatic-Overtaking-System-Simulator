all:
	
	g++ -o exe main.cpp eData.cpp eGame.cpp eRoad.cpp eTexture.cpp eCar.cpp eVehicle.cpp ePlayer.cpp eMessage.cpp -lGL -lGLU -lglut -lSOIL
