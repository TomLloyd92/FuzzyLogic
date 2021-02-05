#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <array>

#include "FuzzyLogic.h"

class GamePlay
{
public:
	GamePlay();
	~GamePlay();
	void update(sf::Time t_deltaTime, sf::RenderWindow& t_window);
	void render(sf::RenderWindow& t_window);
	void setup(sf::Font& t_font);
	void initialise();
private:
	//Font
	sf::Font m_font;

	FuzzyLogic FL;

};