#pragma once
#include "Obstacle.h"

// Represents a thin horizontally infinite Ceiling, on which the ball can bounce
class Ceiling: public Obstacle
{
private:
    float position;  // The vertical position of the Ceiling
    bool collidedLastFrame;  // Whether or not the last frame was a collision (to prevent flapping)

public:
    explicit Ceiling(float position);
    void draw(Interface & interface) override;
    Vector2D collideWith(Ball & ball, float collisionTime) override;
    virtual Vector2D pass(Ball& ball)override;
};



