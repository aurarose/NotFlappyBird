#include "Ground.h"
#include "core/Globals.h"

Ground::Ground() : Actor("images/ground.png", 0, g_ground_height, 154, 56){

}

void Ground::update(){
	if (xpos < -6){
		reset();
	}
	if (game.state == Game::playing|| game.state==Game::waiting){
		move(-g_scroll_speed, 0);
		
	}
}

void Ground::reset(){
	xpos = 0;
}