// DemoLinkedLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Node.h"
#include <vector>
typedef unsigned int uint;
int main()
{
    std::cout << "Hello World!\n";
    std::vector<Node*> nodeList;
    
    uint uNodes = 5;
    for (uint i = 0; i < uNodes; i++)
    {
        Node* var = new Node(i);
        nodeList.push_back(var);
    }

    for (uint i = 0; i < uNodes - 1; i++)
    {
        nodeList[i]->pNext = nodeList[(i+1)];
    }

    Node* pTemp = new Node(40);
    nodeList[2]->pNext = pTemp;
    pTemp->pNext = nodeList[3];

    //Display by the std::vector
    //for (uint i = 0; i < uNodes; i++)
    //{
    //    nodeList[i]->Display();
    //}

    //Display by the Linked list
    Node* pCurrent = nullptr;
    
    if(nodeList.size() > 0)
        pCurrent = nodeList[0];

    while (pCurrent)
    {
        pCurrent->Display();
        pCurrent = pCurrent->pNext;
    }

    //clear memory
    for (uint i = 0; i < uNodes; i++)
    {
        delete nodeList[i];
    }

    delete pTemp;
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
