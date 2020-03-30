#pragma once
#include "Bumper.h"
class Thrust_Bumper final: public Bumper
{
public:
    Thrust_Bumper(Vector2D center, float radius);
    // Accessors
   virtual float getRadius() const;
   virtual Vector2D getCenter() const;
   virtual void draw (Interface & interface) override;
   virtual Vector2D collideWith(Ball& ball, float collisionTime) override;
};
