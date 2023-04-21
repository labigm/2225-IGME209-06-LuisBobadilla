// DemoThread.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <thread>
#include "Fibonacci.h"
#include <vector>

typedef unsigned int uint;
using namespace std;

void count(uint a_nLimit)
{
    int value = 0;
    for (uint i = 0; i < a_nLimit; i++)
    {
        value ++;
    }
    cout << value << endl;
}
void countAndPrint(uint a_nLimit)
{
    int value = 0;
    for (uint i = 0; i < a_nLimit; i++)
    {
        value++;
        cout << value << endl;
    }
}

void demo1()
{
    countAndPrint(100000);
}

void hello()
{
    cout << "hello ";
}
void helloCount(uint count)
{
    for (uint i = 0; i < count; i++)
    {
        hello();
        cout << i << endl;
    }
}
void goodbye()
{
    cout << "bye ";
}
void goodbyeCount(uint count)
{
    for (uint i = 0; i < count; i++)
    {
        goodbye();
        cout << i << endl;
    }
}
void demo2()
{
    hello();
    goodbye();
}
void demo3()
{
    helloCount(100000);
    goodbyeCount(100000);
}
void demo4()
{
    thread helloThread(helloCount, 100000);
    thread byeThread(goodbyeCount, 100000);

    helloThread.join();
    byeThread.join();
}
void demo5()
{
    Fibonacci fib;
    for (uint i = 1; i < 46; i++)
    {
        cout << i << " -> ";
        fib.PrintFibNumber(i);
    }
}
void demo6()
{
    thread demo(demo5);
    thread helloThread(helloCount, 100000);
    demo.join();
    helloThread.join();
}
void demo7()
{
    Fibonacci fib;
    vector<thread> threadList;
    int threadCount = 46;
    for (int i = 0; i < threadCount; i++)
    {
        cout << i << " -> ";
        threadList.push_back(thread(&Fibonacci::PrintFibNumber, fib, i));
    }
    for (int i = 0; i < threadCount; i++)
    {
        threadList[i].join();
    }
    std::cout << "The print is a mess, but it saved more than half the time!\n";
}

int main()
{
    std::cout << "This code is meant to help you understand threading!\n";
    DWORD startTime = GetTickCount();
    demo7();
    cout << "Time: " << (GetTickCount() - startTime) / 1000.0f << "s." << endl;
}
