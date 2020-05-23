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
Vector2D Pop_Bumper::pass(Ball& ball)
{
    return Vector2D{ 0,0 };
}

Vector2D Pop_Bumper::collideWith(Ball& ball, float collisionTime)
{
    if (!collidedLastFrame && ((sqrt(pow(this->center.y - ball.getCenter().y, 2) + pow(this->center.x - ball.getCenter().x, 2))) < this->radius + ball.getRadius()))
    {
        ball.setscore(25) ;
        collidedLastFrame = true;
        return Vector2D{ ball.getVelocity().x * -2,ball.getVelocity().y * -2 } / collisionTime;
    }
    else
    {
        collidedLastFrame = false;
        return Vector2D{ 0, 0 };
    }
}

