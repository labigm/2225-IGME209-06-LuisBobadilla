#include "Foo.h"

Foo::Foo()
{
	var = 5;
	Print();
}

void Foo::Print()
{
	std::cout << var << std::endl;
}