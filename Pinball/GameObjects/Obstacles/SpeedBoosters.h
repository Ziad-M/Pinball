#include"Obstacle.h"

class SpeedBoosters : public Obstacle
{
private:
	Vector2D center;
	float radius;
	bool collidedLastFrame = false;  // Whether or not the last frame was a collision (to prevent flapping)
public:
	SpeedBoosters(Vector2D center, float radius);
	void draw(Interface& interface) override;
	virtual Vector2D collideWith(Ball& ball, float collisionTime) override;
	virtual Vector2D pass(Ball& ball)override;
};