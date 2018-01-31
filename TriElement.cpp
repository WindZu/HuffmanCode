#include "stdafx.h"
#include "TriElement.h"


ostream& operator<<(ostream& out, TriElement &e)
{
	out << "(" << e.data << "," << e.parent << "," << e.left << "," << e.right << ")";
	return out;
}

bool TriElement::isLeaf()
{
	return this->left == -1 && this->right == -1;
}


bool TriElement::operator==(TriElement &e)
{
	return this->data == e.data;
}
