#pragma once
#include <iostream>
class Node
{
public:
	int data = 0;
	Node* pLeft = nullptr;
	Node* pRight = nullptr;

	Node();
	Node(int input);
	void Display(void);
	void Push(int input);
	~Node();
};

