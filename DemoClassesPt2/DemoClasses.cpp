// DemoClasses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Foo.h"
#include "Baz.h"
#include "Bar.h"

#include "Animal.h"
#include "Lion.h"
#include "Eagle.h"
#include "Hipogriff.h"
int main()
{
    std::cout << "Hello World!\n";
    Animal oAnimal(100);
    oAnimal.m_nLegs = 99;
    std::cout << "\n";

    Eagle oEagle;
    oEagle.Move();
    oEagle.m_nLegs = 3;
    std::cout << "\n";

    Lion oLion(4);
    oLion.Move();
    oLion.m_nLegs = 4;
    std::cout << "\n";

    Hipogriff oHipogriff;
    oHipogriff.Move();
    oHipogriff.m_nLegs = 6;
    std::cout << "\n";

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
