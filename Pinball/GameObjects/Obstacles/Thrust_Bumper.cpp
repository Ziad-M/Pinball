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
    return Vector2D{ 0,0 };
}