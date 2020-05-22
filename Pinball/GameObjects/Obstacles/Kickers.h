#include "Obstacle.h"

class Kickers : public Obstacle
{
private:
	KickerType type = rigt;
	Vector2D center;
public:
	Kickers(Vector2D center, KickerType);
	void draw(Interface& interface) override;
	virtual Vector2D collideWith(Ball& ball, float collisionTime) override;
	virtual Vector2D pass(Ball& ball)override;
};
