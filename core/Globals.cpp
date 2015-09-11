#include <memory>
#include "Game.h"
#include "Actor.h"
#include "../Bird.h"
#include "Globals.h"

// Engine variables
ResourceManager resources;
sf::RenderWindow window(sf::VideoMode(144*2, 256*2), "Flappy Bird");
sf::View view;

Game game;
int g_cur_id = 0;

int g_ground_height = 200;
float g_score = 0;
int g_high_score = 0;
float g_scroll_speed = 1.2;

int seed = 1;

shared_ptr<Actor> g_player;

