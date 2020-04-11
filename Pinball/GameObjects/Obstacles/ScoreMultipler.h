#include "Obstacle.h"

class ScoreMultipler : public Obstacle
{
private:
	Vector2D Position;
public:
	ScoreMultipler(Vector2D Position);
	void draw(Interface& interface) override;
	virtual Vector2D collideWith(Ball& ball, float collisionTime) override;
};
