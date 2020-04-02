#include "Switches.h"
#include<cmath>
using namespace std;

Switches::Switches(Vector2D Po )
{
	this->Po=Po;
	
}

void Switches::draw (Interface & interface)
{
	interface.drawswitches(Po);
}

Vector2D Switches::collideWith(Ball& ball, float collisionTime)
{
	return Vector2D{ 0,0 };
	//Phase II
}
