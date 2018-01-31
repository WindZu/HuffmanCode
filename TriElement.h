#pragma once
#ifndef _TRIELEMENT_H
#define _TRIELEMENT_H

#include <iostream>
using namespace std;

class TriElement
{
public:
	int data, parent, left, right;

	//TriElement(int, int, int, int);

	TriElement(int data = 0, int parent = -1, int left = -1, int right = -1)
	{
		this->data = data;
		this->parent = parent;
		this->left = left;
		this->right = right;
	}

	friend ostream& operator<<(ostream& out, TriElement &e);
	bool isLeaf();
	bool operator==(TriElement &e);
private:

};


#endif // !_TRIELEMENT_H

