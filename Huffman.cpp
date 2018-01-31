// Huffman.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "HuffmanTree.h"


int main()
{
	HuffmanTree tree;
	tree.HuffmanTreeBuild();
	tree.encode();//±àÂë²¢´æ´¢
	tree.decode();

	return 0;
}
