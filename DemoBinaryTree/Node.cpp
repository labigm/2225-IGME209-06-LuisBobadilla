#include "Node.h"
//Node::Node()
//{
//	data = 0;
//	pLeft = nullptr;
//	pRight = nullptr;
//}
Node::Node(int input)
{
	data = input;
	pLeft = nullptr;
	pRight = nullptr;
}
void Node::Display(void)
{
	
	
	if(pLeft)
		pLeft->Display();
	
	if(pRight)
		pRight->Display();
	std::cout << data << std::endl;
}
void Node::Release(void)
{
	// delete any allocated memory
	if (pLeft)
	{
		pLeft->Release();
		delete pLeft;
	}

	if (pRight)
	{
		pRight->Release();
		delete pRight;
	}

	data = 0; //for the sake of showing how 
	//to reinitialize any info I may have
}

void Node::Push(int input)
{
	if (input == data)
		return;

	if (input < data) //input is smaller
	{
		if (pLeft) //does it exist?
		{
			pLeft->Push(input);
		}
		else
		{
			pLeft = new Node(input);
		}
	}
	else //input is larger
	{
		if (pRight) //does it exist?
		{
			pRight->Push(input);
		}
		else
		{
			pRight = new Node(input);
		}
	}
}
Node::~Node()
{
	//TODO release memory
	if (pLeft)
	{
		//pLeft->Release();
		delete pLeft;
	}

	if (pRight)
	{
		//pRight->Release();
		delete pRight;
	}

	data = 0; //for the sake of showing how 
	//to reinitialize any info I may have
}