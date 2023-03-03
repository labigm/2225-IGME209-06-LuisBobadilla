#include "Eagle.h"

Eagle::Eagle() : Animal(2)
{
	std::cout << "I am an EAGLE" << std::endl;
}
Eagle::Eagle(int a_nLegs) : Animal(a_nLegs)
{
	std::cout << "I am an EAGLE" << std::endl;
};
void Eagle::Move(void)
{
	std::cout << "I Move by: flying" << std::endl;
}