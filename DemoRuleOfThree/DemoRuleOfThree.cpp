// DemoRuleOfThree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Main.h"

int main()
{
    std::cout << "Rule of 3 Demo\n";
    Foo o1(5);
    Foo o2(7);
    o1.m_pContentList[0] = 20;
    o1.Print();
    o2.Print();
    std::cout << "\n";
    o1 = o1;
    o1.Print();
    o2.Print();
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
