#include<fstream>
#include <istream>
#include <iostream>
#include <string>
#include "Game.h"
#define GRAVITY 400.0f
using namespace std;

Game::Game(): leftFlipper(LEFT, Vector2D { GAME_WIDTH / 2.0f - (FLIPPER_LENGTH + FLIPPERS_DISTANCE / 2.0f), GAME_HEIGHT - 50.0f}, FLIPPER_LENGTH, 5.00f, FLIPPER_MAJOR_RADIUS, FLIPPER_MINOR_RADIUS),
              rightFlipper(RIGHT, Vector2D { GAME_WIDTH / 2.0f + (FLIPPER_LENGTH + FLIPPERS_DISTANCE / 2.0f), GAME_HEIGHT - 50.0f}, FLIPPER_LENGTH, 5.00f, FLIPPER_MAJOR_RADIUS, FLIPPER_MINOR_RADIUS),
              leftWall(1), rightWall(GAME_WIDTH), Ceiling(1), Lground(Left, GAME_HEIGHT -50), Rground(Right, GAME_HEIGHT - 50)
{
    mObstCount = 0;
    mObstList = new Obstacle* [MAX_OBSTACLES];
    for (int i = 0; i < MAX_OBSTACLES; i++) mObstList[i] = NULL;
    mRead.open("Config.txt");
    Load(mRead);
    lastFrame = high_resolution_clock::now();
    exit = left = right = false;
}

void Game::readInterfaceInput()
{
    interface.getControls(exit, left, right);
}

void Game::simulate()
{
    // Measuring time elapsed in-between frames
    high_resolution_clock::time_point thisFrame = high_resolution_clock::now();
    duration<float> timeSpan = duration_cast<duration<float>>(thisFrame - lastFrame);
    lastFrame = thisFrame;
    float deltaTime = timeSpan.count();  // Delta time in seconds
    Vector2D resultantAcceleration = {0, GRAVITY};  // Starting with gravity as the first acceleration contributer
    resultantAcceleration += leftWall.collideWith(ball, deltaTime);
    resultantAcceleration += rightWall.collideWith(ball, deltaTime);
    resultantAcceleration += Ceiling.collideWith(ball, deltaTime);
    resultantAcceleration += Lground.collideWith(ball, deltaTime);
    resultantAcceleration += Rground.collideWith(ball, deltaTime);
    ball.move(resultantAcceleration, deltaTime);
    
    if (left) leftFlipper.flip(LUp);
    else leftFlipper.flip(LDown);
    if (right) rightFlipper.flip(RUp);
    else rightFlipper.flip(RDown);
}

void Game::updateInterfaceOutput()
{
    interface.clear();
    leftFlipper.draw(interface);
    rightFlipper.draw(interface);
    // The following two lines be replaced with a loop over collidable obstacles
    leftWall.draw(interface);
    rightWall.draw(interface);
    Ceiling.draw(interface);
    Lground.draw(interface);
    Rground.draw(interface);
    ball.draw(interface);
    for (int i = 0; i < mObstCount; i++) mObstList[i]->draw(interface);
    interface.display(); 
}

bool Game::exited()
{
    return exit;
}

 void Game::AddObstacle(Obstacle* pObst) {
    if (Game::mObstCount < MAX_OBSTACLES) {
        mObstList[mObstCount++] = pObst;
    }
}



void Game::Load(ifstream& file) {
	string ObstType;

	while (!file.eof()) {
        file >> ballpos.x >> ballpos.y;
        file >> ballvel.x >> ballvel.y;
        file >> Gravity;
        int num; file >> num;
        for (int i = 0; i < num; i++)
        {
            float x_coordinate, y_coordinate, property1, property2; int property3 =-1;
                file >> ObstType;
                if (ObstType == "POP_BUMPER")
                {
                    file >> (x_coordinate); file >> (y_coordinate); file >> (property1); mObstList[i] = new Pop_Bumper(Vector2D{ x_coordinate,y_coordinate }, property1);
                }
                else if (ObstType == "THRUST_BUMPER")
                {
                    file >> (x_coordinate); file >> (y_coordinate); file >> (property1); mObstList[i] = new Thrust_Bumper(Vector2D{ x_coordinate,y_coordinate }, property1);
                }
                else if (ObstType == "VIBRANIUM_BUMPER")
                {
                    file >> (x_coordinate); file >> (y_coordinate); file >> (property1); mObstList[i] = new Vibranium_Bumper(Vector2D{ x_coordinate,y_coordinate }, property1);
                }
                else if (ObstType == "KICKERS")
                {
                    file >> (x_coordinate); file >> (y_coordinate); file >> (property1); mObstList[i] = new Kickers(Vector2D{ x_coordinate,y_coordinate }, (KickerType)property3);
                }
                mObstCount++;        
        }
        break;
	}
}