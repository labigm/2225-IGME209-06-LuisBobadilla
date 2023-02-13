// DemoPointersCont.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::cout << "More Pointer Fun!!!\n";
    int* a = new int();
    *a = 7;
    
    std::cout << a;
    std::cout << " <- 'a's memory address\n";
    std::cout << *a;
    std::cout << " <- 'a's content.\n\n";


    int* b = nullptr;
    std::cout << b;
    std::cout << " <- 'b's memory address\n";
    b = a;
    *a = 3;
    std::cout << b;
    std::cout << " <- 'b's NEW memory address\n";
    std::cout << *b;
    std::cout << " <- 'b's content.\n\n";
    delete a;

    a = new int[5];
    for (int i = 0; i < 5; i++)
    {
        a[i] = i;
    }
    for (int i = 0; i < 5; i++)
    {
        std::cout << &a[i];
        std::cout << ", ";
    }
    std::cout << " <- 'a' addresses\n\n";
    b = a;
    for (int i = 0; i < 5; i++)
    {
        std::cout << b[i];
        std::cout << ", ";
    }
    std::cout << " <- 'b' content\n\n";

    delete[] a;
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
