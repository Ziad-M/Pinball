#pragma once
#include "Obstacle.h"

// Represents a thin horizontally infinite Ground, on which the ball can bounce
class Ground: public Obstacle
{
private:
    float position;  // The vertical position of the Ground
    bool collidedLastFrame;  // Whether or not the last frame was a collision (to prevent flapping)
    GroundType type;

public:
    explicit Ground(GroundType type, float position);
    void draw(Interface & interface) override;
    Vector2D collideWith(Ball & ball, float collisionTime) override;
};



