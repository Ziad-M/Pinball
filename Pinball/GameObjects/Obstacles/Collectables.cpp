#include"Collectables.h"
#include<cmath>
using namespace std;

Collectables::Collectables(Vector2D position)
{
	this->position.x= position.x;
	this->position.y = position.y;
}

void Collectables::draw(Interface& interface)
{
	interface.drawCollectables(position);
}

Vector2D Collectables::collideWith(Ball& ball, float collisionTime)
{
	return Vector2D{ 0,0 };
}