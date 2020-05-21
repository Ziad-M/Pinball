#include<fstream>
#include <istream>
#include <iostream>
#include <string>
#include "Game.h"
using namespace std;

Game::Game(): leftFlipper(LEFT, Vector2D { GAME_WIDTH / 2.0f - (FLIPPER_LENGTH + FLIPPERS_DISTANCE / 2.0f), GAME_HEIGHT - 50.0f}, FLIPPER_LENGTH, 5.00f, FLIPPER_MAJOR_RADIUS, FLIPPER_MINOR_RADIUS),
              rightFlipper(RIGHT, Vector2D { GAME_WIDTH / 2.0f + (FLIPPER_LENGTH + FLIPPERS_DISTANCE / 2.0f), GAME_HEIGHT - 50.0f}, FLIPPER_LENGTH, 5.00f, FLIPPER_MAJOR_RADIUS, FLIPPER_MINOR_RADIUS),
    leftWall(1), rightWall(GAME_WIDTH), Ceiling(35), Lground(Left, GAME_HEIGHT - 50), Rground(Right, GAME_HEIGHT - 50), CIE202(Vector2D{ (GAME_WIDTH/2 - 75), (GAME_HEIGHT/2 - 75)}), lscore(Vector2D{0,0}) 
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
    Vector2D resultantAcceleration = {0, Gravity};  // Starting with gravity as the first acceleration contributer
    resultantAcceleration += leftWall.collideWith(ball, deltaTime);
    resultantAcceleration += rightWall.collideWith(ball, deltaTime);
    resultantAcceleration += Ceiling.collideWith(ball, deltaTime);
    resultantAcceleration += Lground.collideWith(ball, deltaTime);
    resultantAcceleration += Rground.collideWith(ball, deltaTime);
    for (int i = 0; i < mObstCount; i++) resultantAcceleration += mObstList[i]->collideWith(ball, deltaTime);
    ball.move(resultantAcceleration, deltaTime);
    Vector2D resultantCenter = { 0, 0 };
    for (int i = 0; i < mObstCount; i++) resultantCenter += mObstList[i]->pass(ball);
    ball.teleport(resultantAcceleration);
    lscore.setstatus(ball.gameover());
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
    leftWall.draw(interface);
    rightWall.draw(interface);
    Ceiling.draw(interface);
    Lground.draw(interface);
    Rground.draw(interface);
    ball.draw(interface);
    lscore.draw(interface);
    for (int i = 0; i < mObstCount; i++) mObstList[i]->draw(interface);
    CIE202.draw(interface);
    interface.display(); 
}

bool Game::exited()
{
    return exit;
}



void Game::Load(ifstream& file) {
	string ObstType;

	while (!file.eof()) {
        file >> ballpos.x >> ballpos.y; ballpos.y += 35; ball.setCenter(ballpos);
        file >> ballvel.x >> ballvel.y; ball.setVelocity(ballvel);
        file >> Gravity;
        int num; file >> num;
        for (int i = 0; i < num; i++)
        {
            float x_coordinate, y_coordinate, property1, property2; int property3 =-1;
                file >> ObstType;
                if (ObstType == "POP_BUMPER")
                {
                    file >> (x_coordinate); file >> (y_coordinate); file >> (property1); mObstList[i] = new Pop_Bumper(Vector2D{ x_coordinate,y_coordinate + 35 }, property1);
                }
                else if (ObstType == "THRUST_BUMPER")
                {
                    file >> (x_coordinate); file >> (   y_coordinate); file >> (property1); mObstList[i] = new Thrust_Bumper(Vector2D{ x_coordinate,y_coordinate + 35 }, property1);
                }
                else if (ObstType == "VIBRANIUM_BUMPER")
                {
                    file >> (x_coordinate); file >> (y_coordinate); file >> (property1); mObstList[i] = new Vibranium_Bumper(Vector2D{ x_coordinate,y_coordinate + 35 }, property1);
                }
                else if (ObstType == "KICKERS")
                {
                    file >> (x_coordinate); file >> (y_coordinate); file >> (property3); mObstList[i] = new Kickers(Vector2D{ x_coordinate,y_coordinate + 35 }, (KickerType)property3); 
                }
                else if (ObstType == "GATES")
                {
                    file >> (x_coordinate); file >> (y_coordinate); mObstList[i] = new Gates(Vector2D{ x_coordinate,y_coordinate + 35 });
                }
                else if (ObstType == "SPEEDBOOSTERS")
                {
                    file >> (x_coordinate); file >> (y_coordinate), file >> (property1); mObstList[i] = new SpeedBoosters(Vector2D{ x_coordinate,y_coordinate + 35 }, property1);
                }
                else if (ObstType == "SWITCHES")
                {
                    file >> (x_coordinate); file >> (y_coordinate); mObstList[i] = new Switches(Vector2D{ x_coordinate,y_coordinate + 35 });
                }
                else if (ObstType == "SCORE_MULTIPLIER")
                {
                    file >> (x_coordinate); file >> (y_coordinate); mObstList[i] = new ScoreMultipler(Vector2D{ x_coordinate,y_coordinate + 35 });
                }
                mObstCount++;        
        }
        break;
	}
}

Game::~Game()
{
    delete [] mObstList;
}