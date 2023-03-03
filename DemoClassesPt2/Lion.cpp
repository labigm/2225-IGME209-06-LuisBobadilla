#include "Lion.h"

Lion::Lion() : Animal(4)
{
	std::cout << "I am an LION" << std::endl;
}
Lion::Lion(int a_nLegs): Animal(a_nLegs)
{
	this->m_nLegs = a_nLegs;
	std::cout << "I am an LION" << std::endl;
}

void Lion::Move(void)
{
	std::cout << "I Move by: walking" << std::endl;
}