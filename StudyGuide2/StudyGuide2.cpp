// StudyGuide2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include<time.h>
#include <vector>

class foo
{
    int* pointer = nullptr;
public:
    foo()
    {
        pointer = new int();
    };
    ~foo()
    {
        if (pointer)
        {
            delete pointer;
            pointer = nullptr;
        }
    }
    void print()
    {
        std::cout << "Hi\n";
    }
};

void function()
{
    int* pExample = new int();
    delete pExample;
}
void wrapperFunc()
{
    foo oFoo;
    oFoo.print();

    foo* pFoo = new foo();
    pFoo->print();
    delete pFoo;
    
    std::unique_ptr<foo> unique(new foo());//unique pointer initialization
    unique->print();

    std::shared_ptr<foo> shared(new foo());//shared pointer initialization
    shared->print();
}

int main()
{
    srand(time(NULL)); //seed for a random
    int random = rand() % (100 - 0 ) + 0;

    std::cout << "This is a Random value: " << random << "\n";
    wrapperFunc();

    std::vector<int> intList; //example of a templated usage
    for (int i = 0; i < 10; i++)
        intList.push_back(i);
    intList.clear();
    
    _CrtDumpMemoryLeaks();
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
