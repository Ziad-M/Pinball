#pragma once
#include "Bumper.h"
class Vibranium_Bumper final: public Bumper
{
private:
    bool collidedLastFrame = false;  // Whether or not the last frame was a collision (to prevent flapping)
public:
	Vibranium_Bumper(Vector2D center, float radius);
	// Accessors
   virtual float getRadius() const;
   virtual Vector2D getCenter() const;
   virtual void draw (Interface & interface) override;
   virtual Vector2D collideWith(Ball& ball, float collisionTime) override;
   virtual Vector2D pass(Ball& ball)override;
};
