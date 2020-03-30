#pragma once
#include "Obstacle.h"
class Bumper: public Obstacle
{
protected:
    float radius = BALL_RADIUS;  // Radius of the Bumper
    Vector2D center;  // The instantaneous center of the Bumper
public:
    // Accessors
   virtual float getRadius() const = 0;
   virtual Vector2D getCenter() const = 0;
};
