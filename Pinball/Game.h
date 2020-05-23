#pragma once
#include <chrono>
#include <string>
#include <fstream>
#include<iostream>
#include "Interface.h"
#include "Defs.h"
#include "GameObjects/Ball.h"
#include "GameObjects/Flipper.h"
#include "GameObjects/Obstacles/Wall.h"
#include "GameObjects/Obstacles/Ceiling.h"
#include "GameObjects/Obstacles/Ground.h"
#include "GameObjects/Obstacles/Thrust_Bumper.h"
#include "GameObjects/Obstacles/Pop_Bumper.h"
#include "GameObjects/Obstacles/Vibranium_Bumper.h"
#include "GameObjects/Obstacles/Kickers.h"
#include "GameObjects/Obstacles/Collectables.h"
#include "GameObjects/Obstacles/Gates.h"
#include "GameObjects/Obstacles/Switches.h"
#include "GameObjects/Obstacles/SpeedBoosters.h"
#include "GameObjects/Obstacles/ScoreMultipler.h"
#include "GameObjects/Obstacles/Magnet.h"
#include "GameObjects/Obstacles/BullsEye.h"


using namespace std::chrono;
using namespace std;

// Represents a game, keeps track of everything relevant to the game and delegates the tasks to their proper objects
class Game
{
private:
    high_resolution_clock::time_point lastFrame;  // Time point of the last rendered frame
    Interface interface;  // An object representing the game interface
    bool exit, left, right;  // Flags about the user's current controls
    Ball ball; Vector2D ballpos, ballvel;
    float Gravity;
    Flipper leftFlipper, rightFlipper;  // The right and left flippers
    Wall leftWall, rightWall; Ceiling Ceiling; Ground Lground, Rground;
    int mObstCount;				// Actual number of Obstacles
    Obstacle** mObstList;		// List of all Obstacles
    ifstream mRead;
    Collectables CIE202;
public:
    Game();
    void readInterfaceInput();
    void simulate();
    void updateInterfaceOutput();
    void Load(ifstream& file);
    bool exited();
    ~Game();
};
