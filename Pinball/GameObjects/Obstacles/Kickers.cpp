#include "Kickers.h"
#include<cmath>
using namespace std;

Kickers::Kickers(Vector2D center, KickerType type)
{
	this->center = center;
	this->type = type;
	
}

void Kickers::draw (Interface & interface)
{
	interface.drawKicker(center, type);
}

Vector2D Kickers::collideWith(Ball& ball, float collisionTime)
{
	ball.setscore(25);
	return Vector2D{ 0,0 };
}
Vector2D Kickers::pass(Ball& ball)
{
	return Vector2D{ 0,0 };
}