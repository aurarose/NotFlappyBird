#pragma once
#include "core\Actor.h"
class Pipe :
	public Actor
{
public:
	Pipe(float x, float y,string dir);
	float init_x;
	float init_y;
	string dir;
	bool passed;

	void update();
	void reposition();
	void reset();

	void collideWithPlayer();
};

