#include"Collectables.h"
#include<cmath>
#include "../../Interface.h"
using namespace std;

Collectables::Collectables(Vector2D position)
{
	this->position.x= position.x;
	this->position.y = position.y;
}

void Collectables::draw(Interface& interface)
{
	if (mode == true)

		interface.drawCollectables(position);

	else

	   interface.drawlightenedcollectables(position);

}

Vector2D Collectables::collideWith(Ball& ball, float collisionTime)
{
	if (((sqrt(pow(this->position.y - ball.getCenter().y, 2) + pow(this->position.x - ball.getCenter().x, 2))) < ball.getRadius() + 15) || ((sqrt(pow(this->position.y - ball.getCenter().y, 2) + pow(this->position.x + 15 * 3 - ball.getCenter().x, 2))) < ball.getRadius() + 15) || ((sqrt(pow(this->position.y - ball.getCenter().y, 2) + pow(this->position.x + 15 * 6 - ball.getCenter().x, 2))) < ball.getRadius() + 15))
	{
		ball.setscore(25);
		mode = false;
	}

	else
	{
		mode = true;
	}

	return Vector2D { 0,0 };

}

Vector2D Collectables::pass(Ball& ball)
{
	return Vector2D{ 0,0 };
}
