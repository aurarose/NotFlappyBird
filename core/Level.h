#pragma once
#include <memory>
#include "Actor.h"

#include <fstream>
#include <iostream>

class Level
{
public:
	Level(string path){ 
		this->loadFromFile(path); 
	}
	std::map<int, shared_ptr<Actor>> getActors(){
		return this->actors;
	}
	void addActor(Actor){

	}

	void loadFromFile(string);
private:
	std::map<int, shared_ptr<Actor>> actors;
	int cur_id = 0;
};

