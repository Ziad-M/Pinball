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
    return Vector2D{ 0,0 };
}
Vector2D Gates::pass(Ball& ball)
{
    if (!collidedLastFrame && Position.y - ball.getCenter().y < ball.getRadius() && ball.getCenter().x < Position.x + 30.0f && ball.getCenter().x > Position.x)
    {
        collidedLastFrame = true;
        return Vector2D{ 0, 30.0 };
    }
    else
    {
        collidedLastFrame = false;
        return Vector2D{ 0, 0 };
    }
}
