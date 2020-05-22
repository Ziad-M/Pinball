#include "Vibranium_Bumper.h"
Vibranium_Bumper::Vibranium_Bumper(Vector2D center, float radius)
{
    this->center = center;
    this->radius = radius;
}

float Vibranium_Bumper::getRadius() const
{
    return radius;
}

Vector2D Vibranium_Bumper::getCenter() const
{
    return center;
}


void Vibranium_Bumper::draw (Interface & interface)
{
    interface.drawVibranium_Bumper(center, radius);
}

Vector2D Vibranium_Bumper::collideWith(Ball& ball, float collisionTime)
{
    if (!collidedLastFrame && (sqrt(pow(this->center.y - ball.getCenter().y, 2) + pow(this->center.x - ball.getCenter().x, 2))) < this->radius + ball.getRadius())
    {
        collidedLastFrame = true;
        return Vector2D{ ball.getVelocity().x * -1,ball.getVelocity().y * -1 } / collisionTime;
    }
    else
    {
        collidedLastFrame = false;
        return Vector2D{ 0, 0 };
    }
}
Vector2D Vibranium_Bumper::pass(Ball& ball)
{
    return Vector2D{ 0,0 };
}