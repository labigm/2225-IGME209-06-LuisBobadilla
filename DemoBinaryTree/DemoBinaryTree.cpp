// DemoLinkedLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Node.h"
#include <vector>
typedef unsigned int uint;
int main()
{
	//Node* temp = new Node[10];

	//typedef Node* pointerToNode;
	//pointerToNode* nodeList = new pointerToNode[5];

	//Node** nodeList = new Node*[5];

	Node* pRoot = new Node(5);
	pRoot->Push(9);
	pRoot->Push(5);
	pRoot->Push(9);
	pRoot->Push(6);
	pRoot->Push(3);
	pRoot->Push(1);


	pRoot->Display();
	//pRoot->Release();
	
	delete pRoot; // TODO: We are leaking memory
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
