#include "BST.h"
#include "Node.h"
#include <iostream>
using namespace std;
BinarySearchTree::BinarySearchTree()
{
	SetRoot(nullptr);
	root->SetLeft(nullptr);
	root->SetRight(nullptr);
	elements_count = 0;
	
}
BinarySearchTree::BinarySearchTree(int elements[], unsigned int count)
{
	for (unsigned int i = 0; i < count; i++)
		Add(elements[i]);
	elements_count += count;
}
Node* BinarySearchTree::GetRoot()
{
	return root;
}
void BinarySearchTree::SetRoot(Node* node)
{
	root->SetData(node->GetData());
	root->SetLeft(node->GetLeft());
	root->SetRight(node->GetRight());
}
Node* BinarySearchTree::SearchByValue(int val)
{
	Node* node = GetRoot();
	if (node==nullptr)cout << "The list is empty.";
	else
		while (node!=nullptr)
		{
			if (val <node->GetData())
			{
				node = node->GetLeft();
			}
			else
				if (val > node->GetData())
				{
					node = node->GetRight();
				}
				else
					return node;
		}
		return nullptr;
}
void BinarySearchTree::Preorder(Node* listIterator)
{
	if (listIterator==nullptr) return;
	cout << listIterator->GetData() << " ";
	Preorder(listIterator->GetLeft());
	Preorder(listIterator->GetRight());
}
Node* BinarySearchTree::Insert(int value, Node* node)
{   
	if (node==nullptr) {
        Node *temp = new Node(value);
        node = temp;
		elements_count++;
		return node;
    }
    if (value < node -> GetData()) {

	   node->SetLeft(Insert(value, node->GetLeft()));
    }
	if (value > node->GetData()) {
		node->SetRight(Insert(value, node->GetRight()));
	}
	else
		return node;
}
Node* BinarySearchTree::Add(int value)
{
	SetRoot(Insert(value, GetRoot()));
	return GetRoot();
}

BinarySearchTree::~BinarySearchTree()
{
	DestroyRecursive(GetRoot());
}
void BinarySearchTree::DestroyRecursive(Node *p)
{
	if (p!=nullptr)
	{
		DestroyRecursive(p->GetLeft());
		DestroyRecursive(p->GetRight());
		delete p;
	}
}
Node* BinarySearchTree::FindMin(Node* node)
{
	Node* current = node;

	while (current && current->GetLeft() != NULL)
		current = current->GetLeft();

	return current;
}
Node* BinarySearchTree::Delete(int value) 
{
	root=Remove(GetRoot(), value);
	return GetRoot();
}
 Node* BinarySearchTree::Remove(Node* node, int value)
{
	if (node == nullptr)
		return node;

	if (value < node->GetData())
		node->SetLeft(Remove(node->GetLeft(), value));

	else if (value > node->GetData())
		node->SetRight(Remove(node->GetRight(), value));

	else {
		if (node->GetLeft() == nullptr && node->GetRight() == nullptr)
			return nullptr;

		else if (node->GetLeft() == nullptr) {
			Node* temp = node->GetRight();
			delete node;
			return temp;
		}
		else if (node->GetRight() == nullptr) {
			Node* temp = node->GetLeft();
			delete node;
			return temp;
		}


		Node* temp = FindMin(node->GetRight());


		node->SetData( temp->GetData());


		node->SetRight(Remove(node->GetRight(), temp->GetData()));
	}
	return node;
}


BinarySearchTree::BinarySearchTree(int value)
{
	root = new Node(value);
	elements_count = 1;
}
bool BinarySearchTree::Modify(int old_value, int new_value)
{
	Node* node;
	node = SearchByValue(old_value);
	if (node != nullptr)
	{
		node->SetData(new_value);
		return true;
	}
	else
	{
		cout << "The value doesn't exist.";
		return false;
	}
}
void BinarySearchTree::PrintPreorder()
{
	Node* iterator = GetRoot();
	Preorder(iterator);
}