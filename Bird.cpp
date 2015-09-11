#include "Bird.h"
#include "core/Globals.h"
#include <iostream>

Bird::Bird(float x, float y) : Actor("images/bird.png", x, y, 17, 19){
	reset();
}

void Bird::update(){
	if (game.state == Game::reset) reset();
	else if (game.state == Game::waiting) return;
	if (jump_timer > 0) jump_timer--;
	if (ypos < 185)
		move(0, -v_speed);
	if (game.state == Game::playing){
		handleInput();
		if (ypos >= 185)
			die();
	}
	
		v_speed -= gravity;
	clampSpeed();
	updateRotation();
}

void Bird::handleInput(){
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && jump_timer<1){
		flap();
		jump_timer = jump_delay;
	}
}

void Bird::flap(){
	v_speed = flap_height;
	resources.playSound("sounds/flap.wav");
}

void Bird::updateRotation(){
	if (ypos>185)
		cur_rotation = -90;
	else if (v_speed > 0 && cur_rotation < max_rotation){
		cur_rotation += 3;	
	}
	else if (v_speed<0&&cur_rotation > -max_rotation){
		cur_rotation -= 2;
	}
	sprite.setRotation(-cur_rotation);
}

void Bird::clampSpeed(){
	if (v_speed > 0 && v_speed > max_speed)
		v_speed = max_speed;
	else if (v_speed < 0 && v_speed < -1*max_speed)
		v_speed = -1*max_speed;
}

void Bird::die(){
	resources.playSound("sounds/impact.wav");

	game.clock.restart();
	game.state = Game::death;
	
	state = falling;
	v_speed = flap_height;
	image_speed = 0;
}

void Bird::reset(){
	moveTo(50,50);
	state_timer.restart();
	state = alive;
	image_speed = 15;
	gravity = 0.2; // 0.2;
	v_speed = 0;
	cur_rotation = 0;
	flap_height = 3;  // 3
	max_speed = 3.33;
}

