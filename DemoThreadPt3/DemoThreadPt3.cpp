// DemoThreadPt3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <future>

using namespace std;

int factorial(int n)
{
    int res = 1;
    for (int i = n; i > 1; i--)
    {
        res *= i;
    }
    cout << "Factorial is: " << res << endl;
    return res;
}

int factorialWithFuture(future<int>& n)
{
    int start = n.get(); // get the promised value
    int res = 1;
    for (int i = start; i > 1; i--)
    {
        res *= i;
    }
    cout << "Factorial is: " << res << endl;
    return res;
}
int factorialWithSharedFuture(shared_future<int> n)
{
    int start = n.get(); // get the promised value
    int res = 1;
    for (int i = start; i > 1; i--)
    {
        res *= i;
    }
    cout << "Factorial is: " << res << endl;
    return res;
}

void demo1()
{
    factorial(5);
}
void demo2()
{
    future<int> myFutureReturn = async(factorial, 5);
    cout << "Return is: " << myFutureReturn.get() << endl;
}
void demo3()
{
    promise<int> myPromise;
    future<int> myFuture = myPromise.get_future();
    future<int> myFutureReturn = async(launch::async, factorialWithFuture, ref(myFuture));
    this_thread::sleep_for(chrono::milliseconds(20));
    myPromise.set_value(5);
    cout << "Return is: " << myFutureReturn.get() << endl;
}
void demo4() // broken promise
{
    promise<int> myPromise;
    future<int> myFuture = myPromise.get_future();
    future<int> myFutureReturn = async(launch::async, factorialWithFuture, ref(myFuture));
    this_thread::sleep_for(chrono::milliseconds(20));
    myPromise.set_exception(make_exception_ptr(runtime_error("I'm sorry")));
    if(myFutureReturn._Is_ready())
        cout << "Return is: " << myFutureReturn.get() << endl;
}
void demo5()
{
    promise<int> myPromise;
    future<int> myFuture = myPromise.get_future();
    shared_future<int> sharedFuture = myFuture.share();

    const int FUTURECOUNT = 5;

    future<int> future[FUTURECOUNT];

    for (int i = 0; i < FUTURECOUNT; i++)
    {
        future[i] = async(launch::async, factorialWithSharedFuture, sharedFuture);
    }

    myPromise.set_value(5);

    for (int i = 0; i < 5; i++)
    {
        if (future[i]._Is_ready())
            cout << "Return is: " << future[i].get() << endl;
    }
}

int main()
{
    cout << "This code is meant to help you understand futures and promises!\n";
    demo5();
}