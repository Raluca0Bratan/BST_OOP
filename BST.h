#pragma once
#include "Node.h"
class BinarySearchTree
{
private: Node *root;
	   int elements_count;
	   Node* Insert(int value, Node* node);
	   Node* Remove(Node* root, int value);
	   void Preorder(Node* listIterator);
	   void DestroyRecursive(Node* p);
	   Node* FindMin(Node* node);

public:
	BinarySearchTree();
	BinarySearchTree(int elements[], unsigned int count);
	BinarySearchTree(int value);
	~BinarySearchTree();
	Node* GetRoot();
	void SetRoot(Node *node);
	Node* SearchByValue(int val);
	Node* Add(int value);
	Node* Delete(int value);
	bool Modify(int old_value, int new_value);
	void PrintPreorder();
};