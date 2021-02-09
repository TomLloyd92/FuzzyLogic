#pragma once
#include <vector>
#include "Soldier.h"
class Germans
{
public:
	Germans();

	void update();
	void draw(sf::RenderWindow& t_window);
	void setUp();

	int getArmySize() { return m_army; };
	int getDistance() { return m_distance; };


	std::vector<Soldier*> getSoldiers() { return soldiers; };

private:
	std::vector<Soldier*> soldiers;
	int m_army = 0;
	int m_distance = 0;
};