// DemoFunctionPointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

typedef unsigned int uint;
void Print(int value)
{
    std::cout << value << ", ";
}
void AddAndPrint(int value)
{
    value++;
    std::cout << value << ", ";
}
void PrintNegated(int value)
{
    value++;
    std::cout << value * -1 << ", ";
}

void ActOnEach(std::vector<int>& input, void(*MyFunction)(int))
{
    for (int value : input)
    {
        MyFunction(value);
    }
    std::cout << std::endl;
}

int AnotherFunction()
{
    std::vector<int> myList = { 0,1,2,3,4 };
    ActOnEach(myList, PrintNegated);
    return 0;
}

int main()
{
    std::vector<int> myList = { 0,1,2,3,4};
    //ActOnEach(myList, PrintNegated);
    ActOnEach(myList, [](int value) {std::cout << value * -2 << ", "; });
    AnotherFunction();
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
