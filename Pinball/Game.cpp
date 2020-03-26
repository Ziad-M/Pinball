
#include "Game.h"

#define GRAVITY 400.0f

Game::Game(): leftFlipper(LEFT, Vector2D { GAME_WIDTH / 2.0f - (FLIPPER_LENGTH + FLIPPERS_DISTANCE / 2.0f), GAME_HEIGHT - 50.0f}, FLIPPER_LENGTH, 5.00f, FLIPPER_MAJOR_RADIUS, FLIPPER_MINOR_RADIUS),
              rightFlipper(RIGHT, Vector2D { GAME_WIDTH / 2.0f + (FLIPPER_LENGTH + FLIPPERS_DISTANCE / 2.0f), GAME_HEIGHT - 50.0f}, FLIPPER_LENGTH, 5.00f, FLIPPER_MAJOR_RADIUS, FLIPPER_MINOR_RADIUS),
              leftWall(1), rightWall(GAME_WIDTH), Ceiling(1), Lground(Left, GAME_HEIGHT -50), Rground(Right, GAME_HEIGHT - 50) // This line should be removed
{
    mObstCount = 0;
    mObstList = new Obstacle * [MAX_OBSTACLES];
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
    
    if (left)
        leftFlipper.flip(LUp);
    else
        leftFlipper.flip(LDown);
    if (right)
        rightFlipper.flip(RUp);
    else
        rightFlipper.flip(RDown);
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
    interface.display();
}

bool Game::exited()
{
    return exit;
}

void Game::AddObstacle(Obstacle* pObst) {
    if (mObstCount < MAX_OBSTACLES) {
        mObstList[mObstCount++] = pObst;
    }
}

/* Loads the circuit from the file */
void Game::Load(ifstream& file) {
    string compType;
    file >> Game_Width >> Game_Height;
    /*while (file >> compType, compType != "-1") {
        if (file.eof()) {
            break;
        }

        if (compType == "CONNECTION") {
            file >> compData.Label;
            file >> compData.GfxInfo.x1 >> compData.GfxInfo.y1 >> compData.GfxInfo.x2 >> compData.GfxInfo.y2;
            pAct = new AddConnection(this, &compData);
        }
        else {
            file >> compData.Label;
            file >> compData.GfxInfo.x1 >> compData.GfxInfo.y1;

            if (compType == "AND")
                pAct = new AddGate(this, ADD_GATE_AND, &compData);
            else if (compType == "OR")
                pAct = new AddGate(this, ADD_GATE_OR, &compData);
            else if (compType == "NOT")
                pAct = new AddGate(this, ADD_GATE_NOT, &compData);
            else if (compType == "NAND")
                pAct = new AddGate(this, ADD_GATE_NAND, &compData);
            else if (compType == "NOR")
                pAct = new AddGate(this, ADD_GATE_NOR, &compData);
            else if (compType == "XOR")
                pAct = new AddGate(this, ADD_GATE_XOR, &compData);
            else if (compType == "XNOR")
                pAct = new AddGate(this, ADD_GATE_XNOR, &compData);
            else if (compType == "AND3")
                pAct = new AddGate(this, ADD_GATE_AND3, &compData);
            else if (compType == "NOR3")
                pAct = new AddGate(this, ADD_GATE_NOR3, &compData);
            else if (compType == "XOR3")
                pAct = new AddGate(this, ADD_GATE_XOR3, &compData);
            else if (compType == "BUFFER")
                pAct = new AddGate(this, ADD_GATE_BUFFER, &compData);
            else if (compType == "SWITCH")
                pAct = new AddGate(this, ADD_SWITCH, &compData);
            else if (compType == "LED")
                pAct = new AddGate(this, ADD_LED, &compData);*/
 }
double Game::getGame_Width()
{
    return Game_Width;
}   