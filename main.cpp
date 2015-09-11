#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>

#include "core/Globals.h"
#include "core/Level.h"

#include "Bird.h"
#include "Pipe.h"
#include "Ground.h"

using namespace std;

int main(){
	window.setFramerateLimit(60);
	view.reset(sf::FloatRect(0, 0, 144, 256));
	window.setView(view);

	// Statics
	sf::Texture bg_tex;
	bg_tex.loadFromFile("images/background.png");
	sf::Sprite bg_spr(bg_tex);

	sf::Texture game_over_tex;
	game_over_tex.loadFromFile("images/game_over.png");
	sf::Sprite game_over_spr(game_over_tex);
	game_over_spr.setPosition(30,68);

	sf::Texture get_ready_tex;
	get_ready_tex.loadFromFile("images/get_ready.png");
	sf::Sprite get_ready_spr(get_ready_tex);
	get_ready_spr.setPosition(30, 68);

	sf::Texture score_card_tex;
	score_card_tex.loadFromFile("images/score_card.png");
	sf::Sprite score_card_spr(score_card_tex);
	score_card_spr.setPosition(20, 90);

	// Sounds
	resources.loadSound("sounds/flap.wav");
	resources.loadSound("sounds/impact.wav");

	// Actors
	game.addActor(shared_ptr<Actor>(new Pipe(144, 130, "u")));
	game.addActor(shared_ptr<Actor>(new Pipe(144, -60, "d")));
	game.addActor(shared_ptr<Actor>(new Pipe(229, 130, "u")));
	game.addActor(shared_ptr<Actor>(new Pipe(229, -60, "d")));

	g_player = game.addActor(shared_ptr<Actor>(new Bird(50, 50)));
	
	game.addActor(shared_ptr<Actor>(new Ground()));
	
	// Text
	sf::Font font;
	font.loadFromFile("flappy_font.ttf");
	sf::Text score_txt(to_string(g_score),font);
	score_txt.setPosition(64, 8);
	score_txt.setScale(0.75, 0.75);

	// score on card
	sf::Text score_card_txt(to_string(g_score), font);
	score_card_txt.setPosition(115, 110);
	score_card_txt.setScale(0.25, 0.25);

	// highscore on card
	sf::Text hscore_card_txt(to_string(g_high_score), font);
	hscore_card_txt.setPosition(115, 130);
	hscore_card_txt.setScale(0.25, 0.25);

	while (window.isOpen()){
		window.clear();
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();

		window.draw(bg_spr);
		game.update();

		score_txt.setString(to_string(static_cast<int>(g_score)));
		window.draw(score_txt);

		if (game.state == Game::waiting){
			window.draw(get_ready_spr);
		}
		else if (game.state == Game::death){
			score_card_txt.setString(to_string(static_cast<int>(g_score)));
			hscore_card_txt.setString(to_string(g_high_score));

			window.draw(game_over_spr);
			window.draw(score_card_spr);
			window.draw(score_card_txt);
			window.draw(hscore_card_txt);
		}

		window.display();
	}
}
