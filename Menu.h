#pragma once
#include "BST.h"
#include <iostream>
using namespace std;
class Menu : BinarySearchTree
{
public:
	void Go()
	{   
		BinarySearchTree mytree(7);
		int choice;
		int aux,new_value;
		cout << "         Welcome to the menu!" << endl << endl;
		cout << "0. Exit" << endl;
		cout << "1. Add" << endl;
		cout << "2. Modify" << endl;
		cout << "3. Remove" << endl;
		cout << "4. View." << endl;
		while(1)
		{
			cin >> choice;
			switch (choice)
			{
			case 0: exit(0);
					break;
			case 1:
				cout << "The value to Add:";
				cin >> aux;
				mytree.SetRoot(Add(aux));
				break;
			case 2:
				cout << "The value to Modify:";
				cin >> aux;
				cout << "The new value:";
				cin >> new_value;
				if (mytree.Modify(aux, new_value))
					cout << "Modified with succcess!";
				break;
			case 3:
				cout << "The value to Remove:";
				cin >> aux;
				mytree.SetRoot(Delete(aux));
				break;
			case 4:
				mytree.PrintPreorder();
				break;
			}
		}
	}
};