#include "SpeedBoosters.h"

SpeedBoosters::SpeedBoosters(Vector2D center, float radius)
{
	this->center = center;
	this->radius = radius;
}

void SpeedBoosters::draw(Interface& interface)
{
	interface.drawSpeedBoosters(center, radius);
}

Vector2D SpeedBoosters::collideWith(Ball& ball, float collisionTime)
{
    if (!collidedLastFrame && (((sqrt(pow(this->center.y - ball.getCenter().y, 2) + pow(this->center.x - ball.getCenter().x, 2))) < this->radius + ball.getRadius()) || ((sqrt(pow(this->center.y - ball.getCenter().y, 2) + pow(this->center.x +radius*3 - ball.getCenter().x, 2))) < this->radius + ball.getRadius())|| ((sqrt(pow(this->center.y - ball.getCenter().y, 2) + pow(this->center.x+radius*6 - ball.getCenter().x, 2))) < this->radius + ball.getRadius())))
    {
        ball.setscore(25);
        collidedLastFrame = true;
        return Vector2D{ ball.getVelocity().x * 2,ball.getVelocity().y * 2 } / collisionTime;
    }
    else
    {
        collidedLastFrame = false;
        return Vector2D{ 0, 0 };
    }
}

Vector2D SpeedBoosters::pass(Ball& ball)
{
	return Vector2D{ 0,0 };
}