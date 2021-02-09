#include "Germans.h"


Germans::Germans()
{
	srand(time(NULL));
	m_army = (rand() % 29) + 1 ;
	m_distance = (rand() % 29) + 1;
}

void Germans::update()
{
	for (Soldier* soldier : soldiers)
	{
		soldier->update();
	}

}

void Germans::draw(sf::RenderWindow& t_window)
{
	for (Soldier * soldier : soldiers)
	{
		soldier->draw(t_window);
	}

	soldiers.size();
}

void Germans::setUp()
{
	for (int i = 0; i < m_army; i++)
	{
		Soldier* soldier = new Soldier(1);

		soldier->setUp();

		soldiers.push_back(soldier);
	}
}
