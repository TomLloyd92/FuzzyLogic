#include "Gameplay.h"

GamePlay::GamePlay()
{
	std::cout << "Press Enter To Deploy Troops" << std::endl;
}

GamePlay::~GamePlay()
{
}

void GamePlay::update(sf::Time t_deltaTime, sf::RenderWindow& t_window)
{
	m_germans.update();
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		m_sendTroops = true;
	}

	if (!troopsSent)
	{
		if (m_sendTroops)
		{
			std::cout << "Enemies: " << m_germans.getArmySize() << std::endl;
			std::cout << "Distance: " << m_germans.getDistance() << std::endl;

			sendForces();
			troopsSent = true;
			m_sendTroops = false;

	
		}
	}


	if (troopsSent)
	{
		m_british.update();
	}

	//std::cout << FL.getDeployment() << std::endl;
}

void GamePlay::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_background);

	m_germans.draw(t_window);

	if (troopsSent)
	{
		m_british.draw(t_window);
	}
}

void GamePlay::setup(sf::Font& t_font)
{ 
	m_germans.setUp();

	//Load the Background SpriteSheet
	if (!m_backgroundTexture.loadFromFile("Assets\\Images\\battlefield.jpg"))
	{
		std::cout << "problem loading Background texture" << std::endl;
	}


	m_background.setTexture(m_backgroundTexture); 

	m_amount = m_germans.getArmySize();
	m_distance = m_germans.getDistance();
}

void GamePlay::initialise()
{
}

void GamePlay::sendForces()
{
	//DYNAMIC ARMY
	float amountToDeploy = FL.threatLevel(m_amount, m_distance );

	//TESTING EXample amount
	//float amountToDeploy = FL.threatLevel(8, 25);

	std::cout << "Deploying:" << amountToDeploy << " Troops to the battle field" << std::endl;

	m_british.setArmySize(amountToDeploy);

	//Set up army
	m_british.setUp();

}
