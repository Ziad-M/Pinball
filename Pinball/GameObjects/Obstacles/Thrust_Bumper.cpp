#include "Thrust_Bumper.h"
Thrust_Bumper::Thrust_Bumper(Vector2D center, float radius)
{
    this->center = center;
    this->radius = radius;
}

float Thrust_Bumper::getRadius() const
{
    return radius;
}

Vector2D Thrust_Bumper::getCenter() const
{
    return center;
}


void Thrust_Bumper::draw (Interface & interface)
{
    interface.drawThrust_Bumper(center, radius);
}

Vector2D Thrust_Bumper::collideWith(Ball& ball, float collisionTime)
{
    if (!collidedLastFrame && (sqrt(pow(this->center.y - ball.getCenter().y, 2) + pow(this->center.x - ball.getCenter().x, 2))) < this->radius + ball.getRadius())
    {
        ball.setscore(25);
        collidedLastFrame = true;
        return Vector2D{ ball.getVelocity().x * -4, ball.getVelocity().y * -4 } / collisionTime;
    }
    else
    {
        collidedLastFrame = false;
        return Vector2D{ 0, 0 };
    }
}
Vector2D Thrust_Bumper::pass(Ball& ball)
{
    return Vector2D{ 0,0 };
}