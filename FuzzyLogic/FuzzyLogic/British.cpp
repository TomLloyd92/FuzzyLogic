#include "British.h"

British::British()
{
}

void British::update()
{
	for (Soldier* soldier : soldiers)
	{
		soldier->update();
	}
}

void British::draw(sf::RenderWindow& t_window)
{
	for (Soldier* soldier : soldiers)
	{
		soldier->draw(t_window);
	}

	//soldiers.size();
}

void British::setUp()
{
	for (int i = 0; i < m_army; i++)
	{
		Soldier* soldier = new Soldier(2);

		soldier->setUp();

		soldiers.push_back(soldier);
	}
}
