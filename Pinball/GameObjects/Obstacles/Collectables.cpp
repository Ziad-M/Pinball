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
	Vector2D comparingvector = { position.x - BALL_RADIUS, position.y - BALL_RADIUS };
	if ((ball.getCenter().x >= comparingvector.x && ball.getCenter().x <= comparingvector.x + (145 + 2 * BALL_RADIUS)) && (ball.getCenter().y >= comparingvector.y && ball.getCenter().y <= comparingvector.y + (23 + 2 * BALL_RADIUS)))
	{
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
