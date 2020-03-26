#pragma once
#include <chrono>
#include <string>
#include <fstream>
#include<iostream>
#include "Interface.h"
#include "Defs.h"
#include "GameObjects/Ball.h"
#include "GameObjects/Obstacles/Wall.h"
#include "GameObjects/Obstacles/Ceiling.h"
#include "GameObjects/Obstacles/Ground.h"
#include "GameObjects/Flipper.h"
using namespace std::chrono;
using namespace std;

// Represents a game, keeps track of everything relevant to the game and delegates the tasks to their proper objects
class Game
{
private:
    high_resolution_clock::time_point lastFrame;  // Time point of the last rendered frame
    Interface interface;  // An object representing the game interface
    bool exit, left, right;  // Flags about the user's current controls
    Ball ball;  // The ball (obviously :D)
    Flipper leftFlipper, rightFlipper;  // The right and left flippers
    Wall leftWall, rightWall;  // This line should be replaced by an array of obstacles
    Ceiling Ceiling;
    Ground Lground, Rground;
    int mObstCount;				// Actual number of components
    Obstacle** mObstList;		// List of all components
    float Game_Width, Game_Height;
    ifstream mRead;
public:
    Game();
    void readInterfaceInput();
    void simulate();
    void updateInterfaceOutput();
    void AddObstacle(Obstacle* pObst);
    void Load(ifstream& file);
    bool exited();
    double getGame_Width();
    double getGame_Height();

};
