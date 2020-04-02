#include"Obstacle.h"

class SpeedBoosters : public Obstacle
{
private:
	Vector2D center;
	float radius;
public:
	SpeedBoosters(Vector2D center, float radius);
	void draw(Interface& interface) override;
	virtual Vector2D collideWith(Ball& ball, float collisionTime) override;
};