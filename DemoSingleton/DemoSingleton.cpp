// DemoSingleton.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LightMngr.h"
void PrintLights(void);
void PrintLights2(void);
int main()
{
    std::cout << "Hello World!\n";
    LightMngr* lightMngr = LightMngr::GetInstance();
    for(uint i = 0; i < 10000; i++)
        LightMngr* lightMngr2 = LightMngr::GetInstance();
    lightMngr->ListContent();
    PrintLights();
    PrintLights2();
}
void PrintLights(void)
{
    LightMngr* lightMngr = LightMngr::GetInstance();
    lightMngr->ListContent();
}
void PrintLights2(void)
{
    LightMngr* lightMngr = LightMngr::GetInstance();
    lightMngr->ListContent();
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
