
#include "Obstacle.h"

class Switches : public Obstacle
{
private:
	Vector2D Po;
public:
	Switches(Vector2D Po);
	void draw(Interface& interface) override;
	virtual Vector2D collideWith(Ball& ball, float collisionTime) override;
	virtual Vector2D pass(Ball& ball)override;
};