#include "BullsEye.h"
BullsEye::BullsEye(Vector2D center, float radius, float gravity)
{
    this->center = center;
    this->radius = radius;
    this->gravity = gravity;
}

float BullsEye::getRadius() const
{
    return radius;
}

Vector2D BullsEye::getCenter() const
{
    return center;
}


void BullsEye::draw (Interface & interface)
{
    interface.drawVibranium_Bumper(center, radius);
}

Vector2D BullsEye::collideWith(Ball& ball, float collisionTime)
{
    if (!collidedLastFrame && (sqrt(pow(this->center.y - ball.getCenter().y, 2) + pow(this->center.x - ball.getCenter().x, 2))) < this->radius + ball.getRadius())
    {
        ball.setscore((25*5/radius));
        collidedLastFrame = true;
        return Vector2D{ ball.getVelocity().x * -1,ball.getVelocity().y * -1 + gravity } / collisionTime;
    }
    else
    {
        collidedLastFrame = false;
        return Vector2D{ 0, 0 };
    }
}
Vector2D BullsEye::pass(Ball& ball)
{
    return Vector2D{ 0,0 };
}