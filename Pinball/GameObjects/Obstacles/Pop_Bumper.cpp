#include "Pop_Bumper.h"
Pop_Bumper::Pop_Bumper(Vector2D center, float radius)
{
    this->center = center;
    this->radius = radius;
}

float Pop_Bumper::getRadius() const
{
    return radius;
}

Vector2D Pop_Bumper::getCenter() const
{
    return center;
}


void Pop_Bumper::draw (Interface & interface)
{
    interface.drawPop_Bumper(center, radius);
}

Vector2D Pop_Bumper::collideWith(Ball& ball, float collisionTime)
{
    return Vector2D{ 0,0 };
}