#pragma once
#include <iostream>

class Animal
{
public:
	int m_nLegs = 2;
	Animal();
	Animal(int a_nLegs);
	void Move(void);
};

