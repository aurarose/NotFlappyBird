#include "Game.h"
#include "Globals.h"

shared_ptr<Actor> Game::addActor(shared_ptr<Actor> actor){
	this->actors_add_list.push_back(actor);
	return actor;
}

void Game::cullActor(int id){
	this->actors_cull_list.push_back(id);
}

void Game::loadLevel(string path){
	Level level(path);
	this->actors = level.getActors();
	this->state = waiting;
	this->clock.restart();
}

void Game::update(){
	if (state==playing)
		seed++;
	handleStates();
	for (auto it = this->actors.begin(); it != actors.end(); it++){
		(it->second)->update();
		(it->second)->draw();
	}
	auto it = this->actors_add_list.begin();
	while (it != actors_add_list.end()){
		actors[(*it)->id] = *it;
		it = actors_add_list.erase(it);
	}
	auto cull = actors_cull_list.begin();
	while (cull != actors_cull_list.end()){
		auto pos = actors.find(*cull);
		actors.erase(pos);
		cull = actors_cull_list.erase(cull);
	}

	actors_add_list.erase(actors_add_list.begin(), actors_add_list.end());
}

void Game::restart(){
	state = reset;
	g_score = 0;
	seed = 1;
}

void Game::handleStates(){
	if (state == death){
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && clock.getElapsedTime()>sf::seconds(1)){
			restart();
			clock.restart();
		}
	}
	else if(state == waiting){
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)&&clock.getElapsedTime()>sf::seconds(1))
			state = playing;
	}
	else if (state == reset){
		state = waiting;
	}
}
