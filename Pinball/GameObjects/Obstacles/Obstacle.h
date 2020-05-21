#pragma once

#include "../Drawable.h"
#include "../Collidable.h"
#include "../Passable.h"

// An abstract class representing an obstacle
class Obstacle: public Drawable, public Collidable, public Passable
{

};
