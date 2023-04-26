// DemoThreadPt2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <thread>
#include "Fibonacci.h"
#include <vector>
#include <mutex>
#include <chrono>

typedef unsigned int uint;
using namespace std;

void hello()
{
    std::thread::id this_id = this_thread::get_id();
    cout << "hello_" << this_id << endl;
}

void demo1()
{
    vector<thread> threadlist;
    for (uint i = 0; i < 1000; i++)
    {
        threadlist.push_back(thread(hello));
    }
    for (uint i = 0; i < 1000; i++)
    {
        threadlist[i].join();
    }
}

mutex m;
void helloMutex()
{
    std::thread::id this_id = this_thread::get_id();
    m.lock();
    cout << "helloMutex_" << this_id << endl;
    m.unlock();
}

void demo2()
{
    vector<thread> threadlist;
    for (uint i = 0; i < 1000; i++)
    {
        threadlist.push_back(thread(helloMutex));
    }
    for (uint i = 0; i < 1000; i++)
    {
        threadlist[i].join();
    }
}

int incrementValue()
{
    static int value = 0;
    value++;
    return value;
 }

void demo3()
{
    int value = 0;
    for (uint i = 0; i < 1000; i++)
    {
        incrementValue();
    }
    cout << incrementValue() << endl;
}

void demo4()
{
    thread threadlist[1000];
    
    for (uint i = 0; i < 1000; i++)
        threadlist[i] = thread(incrementValue);

    for (uint i = 0; i < 1000; i++)
        threadlist[i].join();

    cout << incrementValue() << endl;
}

void demo5()
{
    auto myLambda = [](int num)
    {
        cout << "argument = " << num << endl;
    };
    for(uint i = 0; i < 1000; i++)
        myLambda(i);
}

void demo6()
{
    auto myLambda = [](int num)
    {
        m.lock();
        cout << "argument = " << num << endl;
        m.unlock();
    };
    thread threadlist[1000];

    for (uint i = 0; i < 1000; i++)
        threadlist[i] = thread(myLambda, i);

    for (uint i = 0; i < 1000; i++)
        threadlist[i].join();
}

bool done = false;
void loading()
{
    while (!done)
    {
        cout << "loading..." << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
}

void demo7()
{
    thread t(loading);
    std::cin.get();
    done = true;
    t.join();
}

int main()
{
    std::cout << "This file is meant to help you understand threads... even more!\n";
    DWORD startTime = GetTickCount();
    demo7();
    cout << "Time: " << (GetTickCount() - startTime) / 1000.0f << "s." << endl;
}
