#include "Ball.h"

Ball::Ball(Vector2D center, Vector2D velocity): center(center), velocity(velocity) {}

float Ball::getRadius() const
{
    return radius;
}

Vector2D Ball::getCenter() const
{
    return center;
}

void Ball::setCenter(Vector2D center)
{
    this->center = center;
}

Vector2D Ball::getVelocity() const
{
    return velocity;
}

void Ball::setVelocity(Vector2D velocity)
{
    this->velocity = velocity;
}

void Ball::move(Vector2D acceleration, float time)
{
    // Kinematic equations for planar motion of a particle
    velocity += acceleration * time;
    center += velocity * time - acceleration * time * time * 0.5;
}

void Ball::teleport(Vector2D center)
{   
    this->center += center;
}

void Ball::draw (Interface & interface)
{
    interface.drawBall(center, radius, score, gover);
}


int Ball::getscore() const
{
    return score;
}
void Ball::setscore(int score)
{
    if(!gover) this->score += score;
}

bool Ball::getstatus()
{
    return gover;
}
void Ball::setstatus()
{
    if (center.y > (GAME_HEIGHT - 50))
        gover = true;
    else
        gover = false;
}