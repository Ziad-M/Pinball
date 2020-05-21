#include "Obstacle.h"

class Gates : public Obstacle
{
private:
	Vector2D Position;
	bool collidedLastFrame = false;  // Whether or not the last frame was a collision (to prevent flapping)
public:
	Gates(Vector2D Position);   
	void draw(Interface& interface) override;
	virtual Vector2D collideWith(Ball& ball, float collisionTime) override;
	virtual Vector2D pass(Ball& ball);
};
