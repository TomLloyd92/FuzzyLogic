#include "FuzzyLogic.h"

FuzzyLogic::FuzzyLogic()
{
}

FuzzyLogic::~FuzzyLogic()
{
}

float FuzzyLogic::threatLevel(float t_amountEnimies, float t_distance)
{
	//Probability functions
	m_enemiesFuzzy(t_amountEnimies);
	m_distanceFuzzy(t_distance);

	//Rule Implementation
	m_ruleMatrix();

	//Defuzzification
	float deploy = m_unitDeploy();

	return deploy;
}

void FuzzyLogic::m_enemiesFuzzy(float t_amountEnimies)
{
	//Enimies Amount Probability
	m_tiny = m_fuzzyTriangle(t_amountEnimies, -TINY_END, TINY_START, TINY_END);
	m_small = m_fuzzyTrap(t_amountEnimies, SMALL_START, SMALL_FIRST_PEAK, SMALL_SECOND_PEAK, SMALL_END);
	m_moderate = m_fuzzyTrap(t_amountEnimies, MODERATE_START, MODERATE_FIRST_PEAK, MODERATE_SECOND_PEAK, MODERATE_END);
	m_large = m_fuzzyGrade(t_amountEnimies, LARGE_START, LARGE_PEAK);

	//Debug Tests
	
	std::cout << "Tiny: " << m_tiny << std::endl;
	std::cout << "small: " << m_small << std::endl;
	std::cout << "Moderate: " << m_moderate << std::endl;
	std::cout << "large: " << m_large << std::endl;
	
}

void FuzzyLogic::m_distanceFuzzy(float t_distance)
{
	m_close = m_fuzzyTriangle(t_distance, -CLOSE_DISTANCE_END, CLOSE_DISTANCE_START, CLOSE_DISTANCE_END);
	m_medium = m_fuzzyTrap(t_distance, MEDIUM_DISTANCE_START, MEDIUM_DISTANCE_FIRST_PEAK, MEDIUM_DISTANCE_SECOND_PEAK, MEDIUM_DISTANCE_END);
	m_far = m_fuzzyGrade(t_distance ,FAR_START, FARPEAK);

	//Debug Tests
	
	std::cout << "Close: " << m_close << std::endl;
	std::cout << "Medium: " << m_medium << std::endl;
	std::cout << "Far: " << m_far << std::endl;
	
}

void FuzzyLogic::m_ruleMatrix()
{
	//Code implementation of the Rule for threat matrix
	m_lowThreat = m_fuzzyOR(m_fuzzyAND(m_medium, m_tiny), m_fuzzyAND(m_medium, m_small));
	m_mediumThreat = m_fuzzyAND(m_close, m_tiny);
	m_highThreat = m_fuzzyAND(m_close, m_fuzzyNOT(m_medium));
}

float FuzzyLogic::m_unitDeploy()
{
	//Final Decider on how many units to deploy
	m_deployment = (m_lowThreat * LOW + m_mediumThreat * MEDIUM + m_highThreat * HIGH) / (m_lowThreat + m_mediumThreat + m_highThreat);
	return m_deployment;
}

float FuzzyLogic::m_fuzzyGrade(float value, float x0, float x1)
{
	float result = 0;
	float x = value;

	//Before the Gradient
	if (x <= x0)
	{
		result = 0;
	}
	//On the incline of the gradient
	else if (x > x1)
	{
		result = 1;
	}
	//At the top most value of the gradient
	else
	{
		result = ((x - x0) / (x1 - x0));
	}

	return result;
}

float FuzzyLogic::m_fuzzyTriangle(float value, float x0, float x1, float x2)
{
	float result = 0;
	float x = value;

	//Falls outside the Triangle
	if ((x <= x0) || (x >= x2))
	{
		result = 0;
	}
	//At the peak of the Triangle
	else if (x == x1)
	{
		result = 1;
	}
	//Incline of Triangle
	else if ((x > x0) && (x < x1))
	{
		result = ((x - x0) / (x1 - x0));
	}
	//Decline of Triangle
	else
	{
		result = ((x2 - x) / (x2 - x1));
	}

	return result;
}

float FuzzyLogic::m_fuzzyTrap(float value, float x0, float x1, float x2, float x3)
{
	float result = 0;

	float x = value;

	//Falls outside the Trap
	if ((x <= x0) || (x >= x3))
	{
		result = 0;
	}
	//At Peak of Trap
	else if ((x >= x1) && (x <= x2))
	{
		result = 1;
	}
	//On Incline of Trap
	else if ( (x > x0) && ( x < x1) )
	{
		result = ((x - x0) / (x1 - x0));
	}
	//Decline of the Trap
	else
	{
		result = ((x3 - x) / (x3 - x2));
	}


	return result;
}
