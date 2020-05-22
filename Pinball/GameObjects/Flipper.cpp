#include "Flipper.h"

Flipper::Flipper(FlipperType type, Vector2D center, float length, float angle, float majorRadius, float minorRadius):
    type(type), center(center), length(length), angle(angle), majorRadius(majorRadius), minorRadius(minorRadius) {}

Vector2D Flipper::collideWith(Ball & ball, float collisionTime)
{
    /*if (!collidedLastFrame && (sqrt(pow(this->center.y - ball.getCenter().y, 2) + pow(this->center.x - ball.getCenter().x, 2))) < this->radius + ball.getRadius())
    {
        collidedLastFrame = true;
        return Vector2D{ ball.getVelocity().x * -2,ball.getVelocity().y * -2 } / collisionTime;
    }
    else
    {*/
        collidedLastFrame = false;
        return Vector2D{ 0, 0 };
    
}

void Flipper::draw(Interface & interface)
{
    interface.drawFlipper(type, center, length, angle, majorRadius, minorRadius);
}
void Flipper::flip(MovingDirection direction)
{
    if (direction == LUp && angle > -30)
        angle-=5;
    else if (direction == LDown && angle < 30)
        angle+=5;
    if (direction == RUp && angle < 30)
        angle+=5;
    else if (direction == RDown && angle > -30)
        angle-=5;
}