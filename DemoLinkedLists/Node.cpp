#include "Node.h"
Node::Node(int input)
{
	data = input;
	pLeft = nullptr;
}
void Node::Display(void)
{
	std::cout << data << std::endl;
}