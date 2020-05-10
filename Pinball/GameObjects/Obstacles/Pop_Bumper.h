#pragma once
#include "Bumper.h"
#include <cmath>
class Pop_Bumper final: public Bumper
{
private:
    bool collidedLastFrame = false;  // Whether or not the last frame was a collision (to prevent flapping)
public:
    Pop_Bumper(Vector2D center, float radius);
    // Accessors
   virtual float getRadius() const;
   virtual Vector2D getCenter() const;
   virtual void draw (Interface & interface) override;
   Vector2D collideWith(Ball& ball, float collisionTime) override;
};
