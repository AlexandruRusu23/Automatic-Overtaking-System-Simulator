# Traffic-Simulator #

# An OpenGL C++ project which simulate a daily traffic. #

  - 4 lanes
  - Add a car by tapping '1' '2' '3' or '4' key. Number representing the lane you want the car to be loaded
  - Every car has implemented an AI to avoid collision with other cars, also maintain and adjust the speed to keep a reasonable distance from the car in front
  - After a tour (cross entire displayed road) the car will be respawned to remake the tour
  - There is player's car which has implemented an automatic overtaking system
  - Player's car can be controled with 'W', 'A', 'S', 'D' keys:
      - 'W': resume preset speed
      - 'A': move on the left lane
      - 'S': keep the speed of the car in front
      - 'D': move on the right lane
  - System informations interface mapped with GLUT 2D texture:
      - Messages about AOS system (which lanes are free, player's driving mode, etc)

### Requirments ###

```
sudo apt-get install freeglut3 freeglut3-dev
sudo apt-get install libsoil-dev
```

### Usage ###

```
make
./exe
```
### Have fun! ###
