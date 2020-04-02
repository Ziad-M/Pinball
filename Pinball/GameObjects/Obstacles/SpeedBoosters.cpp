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
	return Vector2D{ 0,0 };
}