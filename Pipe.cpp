#include "Pipe.h"
#include "Bird.h"
#include "core/Globals.h"

Pipe::Pipe(float x, float y,string dir) : Actor("images/pipe_"+dir+".png", x, y, 26, 135){
	init_x = x;
	init_y = y;
	this->dir = dir;
	reset();
}

void Pipe::update(){
	if (game.state == Game::waiting){
		active = false;
	}
	if (game.state == Game::playing){
		active = true;
		move(-g_scroll_speed, 0);
		if (xpos < -36){
			reposition();
		}
		collideWithPlayer();
	}
	else if (game.state == Game::reset){
		reset();
	}
}

void Pipe::reposition(){
	srand(seed);
	int newpos = rand() % 75;
	if (dir == "u"){
		ypos = newpos + 100;
	}
	else{
		ypos = newpos - 95;
	}
	xpos=144;
	passed = false;
}

void Pipe::collideWithPlayer(){
	if (game.state==Game::playing&&collidesWithActor(*g_player)){
		shared_ptr<Bird> p = std::static_pointer_cast<Bird>(g_player);
		p->die();
	}
	else if (g_player->xpos > xpos && !passed){
		passed = true;
		g_score += 0.5;
		if (g_score > g_high_score){
			g_high_score = static_cast<int>(g_score);
		}
	}
}

void Pipe::reset(){
	srand(1);
	reposition();
	xpos = init_x;
	passed = false;
}