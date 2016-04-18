#include <GL/freeglut.h>
#include <GL/glut.h>
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <cmath>
#include <unistd.h>
#include <vector>
#include <cstdio>
using namespace std;

#define PERSPECTIVE_SIZE 90
#define SCREEN_WIDTH	800
#define SCREEN_HEIGHT	600

#define ROAD_LIMIT 100
#define ROAD_EDGE 40

#define SPAWN_LIMIT 8
#define COLLISION_LIMIT 6
#define SPEED_UP_LIMIT 6
#define BRAKE_UNIT 0.01;
#define SPEED_UP_UNIT 0.05;