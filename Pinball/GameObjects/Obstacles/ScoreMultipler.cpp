#include "ScoreMultipler.h"

ScoreMultipler::ScoreMultipler(Vector2D center, float radius)
{
	this->center = center;
	this->radius = radius;
}

float ScoreMultipler::getRadius() const
{
	return radius;
}

Vector2D ScoreMultipler::getCenter() const
{
	return center;
}


void ScoreMultipler::draw (Interface & interface)
{
	interface.drawScoreMultipler(center, radius);
}

Vector2D ScoreMultipler::collideWith(Ball& ball, float collisionTime)
{
    if (!collidedLastFrame && ((sqrt(pow(this->center.y - ball.getCenter().y, 2) + pow(this->center.x - ball.getCenter().x, 2))) < this->radius + ball.getRadius()))
    {
        ball.setscore(ball.getscore() * 2);
        collidedLastFrame = true;
        return Vector2D{ ball.getVelocity().x * -2,ball.getVelocity().y * -2 } / collisionTime;
    }
    else
    {
        collidedLastFrame = false;
        return Vector2D{ 0, 0 };
    }
}
Vector2D ScoreMultipler::pass(Ball& ball)
{
	return Vector2D{ 0,0 };
}