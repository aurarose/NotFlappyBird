#pragma once
#include "core/actor.h"
class Bird :
	public Actor
{
public:
	Bird(float x, float y);
	enum state{alive,hit,falling,dead};

	void die();
private:
	float gravity;
	float v_speed;
	float max_speed;
	float flap_height;
	float cur_rotation = 0;
	float max_rotation = 15;
	int jump_timer = 0;
	int jump_delay = 15;
	state state;
	sf::Clock state_timer;

	virtual void update();
	void flap();
	void updateRotation();
	void clampSpeed();
	
	void reset();
	void handleInput();
	
};

