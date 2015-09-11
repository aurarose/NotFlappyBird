#include "ResourceManager.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <memory>

#pragma once

using actor_ptr = shared_ptr<Actor>;

extern ResourceManager resources;
extern Game game;

extern sf::RenderWindow window;
extern sf::View view;

extern int g_cur_id;

extern int g_ground_height;
extern float g_score;
extern int g_high_score;
extern float g_scroll_speed;

extern int seed;

extern shared_ptr<Actor> g_player;

extern int g_generatHeight();