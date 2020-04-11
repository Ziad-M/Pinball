#include"Score.h"
using namespace std;

Score::Score(Vector2D position)
{
	this->position.x= position.x;
	this->position.y = position.y;
}

void Score::draw(Interface& interface)
{
	interface.drawScore(position,gover);
}

bool Score::getstatus()
{
	return gover;
}
void Score::setstatus(bool status)
{
	this->gover = status;
}