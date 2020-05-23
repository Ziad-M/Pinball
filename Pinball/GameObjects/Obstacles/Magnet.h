#pragma once
#include "Bumper.h"
#include <cmath>
class Magnet final: public Bumper
{
private:
    bool collidedLastFrame = false;  // Whether or not the last frame was a collision (to prevent flapping)
public:
    Magnet(Vector2D center, float radius);
    // Accessors
   virtual float getRadius() const;
   virtual Vector2D getCenter() const;
   virtual void draw (Interface & interface) override;
   Vector2D collideWith(Ball& ball, float collisionTime) override;
   Vector2D pass(Ball& ball) override;
};
