#include "ScoreMultipler.h"
#include<cmath>
using namespace std;

ScoreMultipler::ScoreMultipler(Vector2D Position)
{
	this->Position = Position;
}

void ScoreMultipler::draw (Interface & interface)
{
	interface.drawScoreMultipler(Position);
}

Vector2D ScoreMultipler::collideWith(Ball& ball, float collisionTime)
{
	return Vector2D{ 0,0 };
	//Phase II
}
