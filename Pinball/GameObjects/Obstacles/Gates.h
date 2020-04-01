#include "Obstacle.h"

class Gates : public Obstacle
{
private:

public:
	Gates();   //Add Parameters if you need
	void draw(Interface& interface) override;
	virtual Vector2D collideWith(Ball& ball, float collisionTime) override;
};
