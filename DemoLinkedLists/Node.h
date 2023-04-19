#pragma once
#include <iostream>
class Node
{
public:
	int data = 0;
	Node* pLeft = nullptr;

	Node(int input);
	void Display(void);
};

