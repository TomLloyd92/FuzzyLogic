#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>
#include "Globals.h"

class Soldier
{
public:
	Soldier(int t_type);
	~Soldier();

	//GetSprite
	sf::Sprite getSprite();

	void setUp();

	void update();

	void draw(sf::RenderWindow& t_window);

private:

	sf::Sprite soldier;
	sf::Texture soldText;
	
	sf::Vector2f goalPos;

	bool m_german = false;
	bool m_british = false;

};