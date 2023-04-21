#include "Fibonacci.h"
void Fibonacci::PrintFibNumber(int _number)
{
	std::cout << "<" << CalculateFibNumber(_number) << ">" << std::endl;
}

int Fibonacci::CalculateFibNumber(int _number)
{
	if (_number <= 2) {
		return 1;
	}
	int first = CalculateFibNumber(_number - 1);
	int second = CalculateFibNumber(_number - 2);
	return  first + second;
}