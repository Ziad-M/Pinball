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
    return Vector2D{ 0,0 };
}