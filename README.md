# Traffic-Simulator #

### An OpenGL C++ project which simulate a daily traffic. ###

  - 4 lanes.
  - Add a car by tapping 'n' key.
  - Every car has implemented an AI to avoid collision with other cars, maintain and adjust the speed. 
  - Every new car inserted is respawned randomly on one of the lanes.
  - After a tour (cross entire displayed road) the car will be respawned random with same method as inserted method.

### How to run the game ###

  - Game runs only on Linux
  - Install freeglut and SOIL
        - sudo apt-get install freeglut3 freeglut3-dev
        - sudo apt-get install libsoil-dev
  - Change in directory named "Traffic-Simulator"
  - Type command "make"
  - Type command "./exe"
  - Have fun!
