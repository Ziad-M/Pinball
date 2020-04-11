#pragma once

#include "Drawable.h"

// Represents the ball (the single most important object in a Pinball game!)
class Ball: public Drawable
{
private:
    float radius = BALL_RADIUS;  // Radius of the ball
    Vector2D center;  // The instantaneous center of the ball
    Vector2D velocity;  // The instantaneous velocity of the ball
public:
    explicit Ball(Vector2D center = INITIAL_CENTER, Vector2D velocity = INITIAL_VELOCITY);  // Constructor

    // Accessors
    float getRadius() const;
    Vector2D getCenter() const;
    void setCenter(Vector2D center);
    Vector2D getVelocity() const;
    void setVelocity(Vector2D velocity);
    void move (Vector2D acceleration, float time);  // Simulates the ball's motion under uniform acceleration for a period of time
    void draw (Interface & interface) override;
    bool gameover();
};
