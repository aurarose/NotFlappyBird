#pragma once
#include <memory>
#include "Level.h"
#include "Actor.h"


class Game
{
public:
	Game(){
		this->state = waiting;
	}
	std::map<int, shared_ptr<Actor>> actors;
	enum state{loading,menu,waiting,playing,paused,death,reset,next_level,game_over};
	state state;
	//state last_state;
	sf::Clock clock;
	shared_ptr<Actor> addActor(shared_ptr<Actor>);

	void cullActor(int);

	void loadLevel(string);
	void nextLevel();

	void update();
	void handleStates();
	void restart();
private:
	vector<shared_ptr<Actor>> actors_add_list;
	vector<int> actors_cull_list;

	int pause_duration;
};

