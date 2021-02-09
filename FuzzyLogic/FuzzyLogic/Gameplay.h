#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <array>

#include "Germans.h"
#include "British.h"
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

	//Background
	sf::Sprite m_background;
	sf::Texture m_backgroundTexture;

	
	FuzzyLogic FL;
	Germans m_germans;
	British m_british;

	bool troopsSent = false;
	bool m_sendTroops = false;

	void sendForces();

	float m_amount = 0;
	float m_distance = 0;



};