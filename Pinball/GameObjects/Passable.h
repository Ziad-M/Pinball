#pragma once

#include "Ball.h"

class Passable
{
public:
    virtual Vector2D pass(Ball& ball) = 0;
};
