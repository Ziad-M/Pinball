#include "Obstacle.h"

class Gates : public Obstacle
{
private:
	Vector2D Position;
public:
	Gates(Vector2D Position);   
	void draw(Interface& interface) override;
	virtual Vector2D collideWith(Ball& ball, float collisionTime) override;
};
