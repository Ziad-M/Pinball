#include "Magnet.h"
Magnet::Magnet(Vector2D center, float radius)
{
    this->center = center;
    this->radius = radius;
}

float Magnet::getRadius() const
{
    return radius;
}

Vector2D Magnet::getCenter() const
{
    return center;
}

void Magnet::draw (Interface & interface)
{
    interface.drawMagnet(center, radius);
}
Vector2D Magnet::pass(Ball& ball)
{
    return Vector2D{ 0,0 };
}

Vector2D Magnet::collideWith(Ball& ball, float collisionTime)
{
    if (!collidedLastFrame && ((sqrt(pow(this->center.y - ball.getCenter().y, 2) + pow(this->center.x - ball.getCenter().x, 2))) < this->radius + ball.getRadius() + 35))
    {
        collidedLastFrame = true;
        return Vector2D{ ball.getVelocity().x * -2, } / collisionTime;
    }
    else
    {
        collidedLastFrame = false;
        return Vector2D{ 0, 0 };
    }
}

