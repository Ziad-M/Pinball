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
	//Phase II
}
