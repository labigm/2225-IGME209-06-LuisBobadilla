#include "Animal.h"

Animal::Animal()
{
	std::cout << "I am an ANIMAL" << std::endl;
}
Animal::Animal(int a_nLegs)//: m_nLegs(a_nLegs)
{
	m_nLegs = a_nLegs;
	std::cout << "I am an ANIMAL with " << m_nLegs
		<< " legs." << std::endl;
}
void Animal::Move(void)
{
	std::cout << "I Move by: -----" << std::endl;
}
