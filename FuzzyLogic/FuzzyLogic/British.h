#pragma once
#include <vector>
#include "Soldier.h"
class British
{
public:
	British();

	void update();
	void draw(sf::RenderWindow& t_window);
	void setUp();

	int getArmySize() { return m_army; };
	void setArmySize(int t_armySize) { m_army = t_armySize; };

	std::vector<Soldier*> getSoldiers() { return soldiers; };

private:
	std::vector<Soldier*> soldiers;
	int m_army = 0;
};