#include "Soldier.h"

Soldier::Soldier(int t_type)
{
	if (t_type == 1)
	{
		m_british = false;
		m_german = true;
	}
	else if (t_type == 2)
	{
		m_german = false;
		m_british = true;
	}
}

Soldier::~Soldier()
{

}

sf::Sprite Soldier::getSprite()
{
	return soldier;
}

void Soldier::setUp()
{
	if (m_german)
	{
		if (!soldText.loadFromFile("Assets\\Images\\german.png"))
		{
			std::cout << "problem loading german texture" << std::endl;
		}
	}
	else if (m_british)
	{
		if (!soldText.loadFromFile("Assets\\Images\\british.jpg"))
		{
			std::cout << "problem loading British texture" << std::endl;
		}
	}

	soldier.setTexture(soldText);

	//Init Pos
	if(m_german)
	{
		soldier.setScale(0.03, 0.03);
		goalPos = sf::Vector2f(rand() % SCREEN_WIDTH, rand() % ((SCREEN_HEIGHT) / 2));

		soldier.setPosition(goalPos.x, (rand() % 100 ) - 100);
	}
	else if (m_british)
	{
		soldier.setScale(0.1, 0.1);
		goalPos = sf::Vector2f(rand() % SCREEN_WIDTH, (SCREEN_HEIGHT - (rand() % ((SCREEN_HEIGHT) / 2 ))));

		soldier.setPosition(goalPos.x, SCREEN_HEIGHT + rand() % 100 );
	}
}

void Soldier::update()
{
	if (m_german)
	{
		if (soldier.getPosition().y <= goalPos.y)
		{
			soldier.setPosition(soldier.getPosition().x, soldier.getPosition().y + 1);
		}
	}
	else if (m_british)
	{
		if (soldier.getPosition().y >= goalPos.y)
		{
			//soldier.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

			soldier.setPosition(soldier.getPosition().x, soldier.getPosition().y - 1);
		}
	}

}

void Soldier::draw(sf::RenderWindow& t_window)
{
	t_window.draw(soldier);
}
