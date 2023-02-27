// DemoContinousInput.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
void MovePlayer(short& playerX, short& playerY)
{
    if (_kbhit())
    {
        char userInput = _getch();

        switch (userInput)
        {
        case 'w':
        case 'W':
            playerY++;
            break;
        case 's':
        case 'S':
            playerY--;
            break;
        case 'a':
        case 'A':
            playerX--;
            break;
        case 'd':
        case 'D':
            playerX++;
            break;
        default:
            break;
        }
        std::cout << "Position: ( " << playerX << ", " << playerY << ")" << std::endl;
    }
}

int main()
{
    std::cout << "Hello World!\n";
    short playerX = 0;
    short playerY = 0;

    short goalX = 3;
    short goalY = 3;

    std::cout << "The goal is to reach: ( " << goalX << ", " << goalY << ")" << std::endl;
    std::cout << "Position: ( " << playerX << ", " << playerY << ")" << std::endl;

    while (!((playerX == goalX) && (playerY == goalY)))
    {
        MovePlayer(playerX, playerY);
    }
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
