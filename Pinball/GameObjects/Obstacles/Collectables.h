#pragma once
#include "Obstacle.h"



class Collectables: public Obstacle
{
private:
	Vector2D position;
	bool mode = true;
public:
	Collectables(Vector2D position);
	void draw(Interface& interface) override;
	virtual Vector2D collideWith(Ball& ball, float collisionTime) override;
	virtual Vector2D pass(Ball& ball)override;
};

