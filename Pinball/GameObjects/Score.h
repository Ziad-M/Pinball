#pragma once
#include "Drawable.h"


class Score: public Drawable
{
private:
	Vector2D position;
	double score = 0;
	bool gover = false;
public:
	Score(Vector2D position);
	void draw(Interface& interface) override;
	void setstatus(bool status);
	bool getstatus();
};

