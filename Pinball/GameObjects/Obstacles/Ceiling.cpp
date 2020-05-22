#include "Ceiling.h"
#include <cmath>
using namespace std;

Ceiling::Ceiling(float position): position(position), collidedLastFrame(false) {}

void Ceiling::draw(Interface & interface)
{
    interface.drawCeiling(position);
}

Vector2D Ceiling::collideWith(Ball & ball, float collisionTime)
{
    if(!collidedLastFrame && abs(position - ball.getCenter().y) < ball.getRadius())
    {
        collidedLastFrame = true;
        return Vector2D {0, ball.getVelocity().y * -2} / collisionTime;
    }
    else
    {
        collidedLastFrame = false;
        return Vector2D {0, 0};
    }
}
Vector2D Ceiling::pass(Ball& ball)
{
    return Vector2D{ 0,0 };
}
