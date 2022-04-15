#include "Node.h"
Node::Node(int val)
{
	key = val;
	left = nullptr;
	right = nullptr;
}
Node::Node()
{
	key = 0;
	left = nullptr;
	right = nullptr;
}
void Node::SetLeft(Node* leftNode)
{
	left = leftNode;
}
void Node::SetRight(Node* rightNode)
{
	right = rightNode;
}
void Node::SetData(int val)
{
	key = val;
}
int Node::GetData()
{
	return key;
}
Node* Node::GetLeft()
{
	return left;
}
Node* Node::GetRight()
{
	return right;
}