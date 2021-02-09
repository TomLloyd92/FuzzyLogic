#pragma once

#include <iostream>		//String
#include <algorithm>	//Min Max

//Fuzzy logic class
class FuzzyLogic
{
public:
	//Constructor + Destuctor 
	FuzzyLogic();
	~FuzzyLogic();

	//Threat Calculation
	float threatLevel(float t_amountEnimies, float t_distance);

	//Get Deployment
	float getDeployment() { return m_deployment; };


private:
	//Range
	void m_enemiesFuzzy(float t_amountEnimies);
	//Distance
	void m_distanceFuzzy(float t_distance);
	//Rule Matrix Function
	void m_ruleMatrix();
	//Defuzz
	float m_unitDeploy();

	//Graph Functions
	float m_fuzzyGrade(float value, float x0, float x1);
	float m_fuzzyTriangle(float value, float x0, float x1, float x2);
	float m_fuzzyTrap(float value, float x0, float x1, float x2, float x3);

	//And Or Not Functions
	float m_fuzzyAND(float A, float B) { return std::min(A, B); };
	float m_fuzzyOR(float A, float B) { return std::max(A, B); };
	float m_fuzzyNOT(double A) { return 1.0 - A; };

	//Size 
	float m_tiny = 0;
	float m_small = 0;
	float m_moderate = 0;
	float m_large = 0;

	//Range
	float m_close = 0;
	float m_medium = 0;
	float m_far = 0;

	//Threat Probibility
	float m_lowThreat = 0;
	float m_mediumThreat = 0;
	float m_highThreat = 0;

	//DISTANCES
	//Close - Start + End 
	const float CLOSE_DISTANCE_START = 0;
	const float CLOSE_DISTANCE_END = 30;
	//Medium - Start + Peaks + End
	const float MEDIUM_DISTANCE_START = 10;
	const float MEDIUM_DISTANCE_FIRST_PEAK = 30;
	const float MEDIUM_DISTANCE_SECOND_PEAK = 50;
	const float MEDIUM_DISTANCE_END = 70;
	//Far - Start + Peak
	const float FAR_START = 50;
	const float FARPEAK = 70;

	//ENEMY SIZE
	//Tiny - Start + End
	const float TINY_START = 0;
	const float TINY_END = 10;
	//Small Start + Peaks + End
	const float SMALL_START = 2.5;
	const float SMALL_FIRST_PEAK = 10;
	const float SMALL_SECOND_PEAK = 15;
	const float SMALL_END = 20;
	//Moderate - Start + Peaks + End
	const float MODERATE_START = 15;
	const float MODERATE_FIRST_PEAK = 20;
	const float MODERATE_SECOND_PEAK = 25;
	const float MODERATE_END = 30;
	//LargeAndInCharge - Start + Peak
	const float LARGE_START = 25;
	const float LARGE_PEAK = 30;

	//Response
	const int LOW = 10;
	const int MEDIUM = 30;
	const int HIGH = 50;

	//Amount to be deployed
	int m_deployment = 0;
};