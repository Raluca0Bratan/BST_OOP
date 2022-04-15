#pragma once
class Node {
private:
	int key;
	Node* left;
	Node* right;
public:
	Node();
	Node(int val);
	void SetData(int val);
	int GetData();
	Node* GetLeft();
	Node* GetRight();
	void SetLeft(Node* leftNode);
	void SetRight(Node* rightNode);


};