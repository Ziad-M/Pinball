#include "Ground.h"
#include <cmath>
using namespace std;

Ground::Ground(GroundType type, float position): type(type), position(position), collidedLastFrame(false) {}

void Ground::draw(Interface & interface)
{
    interface.drawGround(position);
}

Vector2D Ground::collideWith(Ball & ball, float collisionTime)
{
    if (!collidedLastFrame && abs(position - ball.getCenter().y) < ball.getRadius())
    {
        if ((ball.getCenter().x > (GAME_WIDTH / 2.0f + (FLIPPER_LENGTH + FLIPPERS_DISTANCE / 2.0f))) ||  (ball.getCenter().x < (GAME_WIDTH / 2.0f - (FLIPPER_LENGTH + FLIPPERS_DISTANCE / 2.0f))))
        {
            collidedLastFrame = true;
            return Vector2D{ 0, ball.getVelocity().y * -2 } / collisionTime;
        }
        else
        {
            collidedLastFrame = false;
            return Vector2D{ 0, 0 };
        }
    }
    else
    {
        collidedLastFrame = false;
        return Vector2D {0, 0};
    }
}
Vector2D Ground::pass(Ball& ball)
{
    return Vector2D{ 0,0 };
}