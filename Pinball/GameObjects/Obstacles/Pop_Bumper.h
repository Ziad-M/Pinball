#pragma once
#include "Bumper.h"
class Pop_Bumper final: public Bumper
{
public:
    Pop_Bumper(Vector2D center, float radius);
    // Accessors
   virtual float getRadius() const;
   virtual Vector2D getCenter() const;
   virtual void draw (Interface & interface) override;
   virtual Vector2D collideWith(Ball& ball, float collisionTime) override;
};
