#include "Gates.h"
#include<cmath>
using namespace std;

Gates::Gates(Vector2D Position)   
{
	this->Position = Position;
}

void Gates::draw (Interface & interface)
{
	interface.drawgates(Position);
}
Vector2D Gates::collideWith(Ball& ball, float collisionTime)
{
    if (!collidedLastFrame && ((abs(Position.x - ball.getCenter().x) < ball.getRadius()) || (abs(Position.x + 30.0f - ball.getCenter().x) < ball.getRadius())) && (ball.getCenter().y > Position.y && ball.getCenter().y < Position.y + 100))
    {
        collidedLastFrame = true;
        return Vector2D{ ball.getVelocity().x * -2, 0 } / collisionTime;
    }
    return Vector2D{ 0,0 };
}
Vector2D Gates::pass(Ball& ball)
{
    if (!collidedLastFrame && Position.y - ball.getCenter().y < ball.getRadius() && ball.getCenter().x < Position.x + 30.0f && ball.getCenter().x > Position.x)
    {
        ball.setscore(ball.getscore() * 2);
        collidedLastFrame = true;
        return Vector2D{ 0, 100.0f };
    }
    else
    {
        collidedLastFrame = false;
        return Vector2D{ 0, 0 };
    }
}
