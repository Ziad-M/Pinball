#pragma once
#include "Bumper.h"
#include <cmath>
class ScoreMultipler :  public Bumper
{
private:
	bool collidedLastFrame = false;
public:
	ScoreMultipler(Vector2D center, float radius);
	virtual float getRadius() const;
	virtual Vector2D getCenter() const;
	virtual void draw(Interface& interface) override;
	Vector2D collideWith(Ball& ball, float collisionTime) override;
	Vector2D pass(Ball& ball)override;
};
