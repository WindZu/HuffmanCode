#pragma once
#ifndef _HUFFMANTREE_H
#define _HUFFMANTREE_H

#include <iostream>
using namespace std;
#include "stdafx.h"
#include "SeqList.h"
#include "MyString.h"
#include "TriElement.h"
#include "string.h"
#include "HuffmanChar.h"
#include <fstream>

class HuffmanTree
{
public:
	MyString charset;//字符集
	SeqList<TriElement> huftree;//结点顺序表
	

	HuffmanChar huff[256];
	MyString codestr;//
	MyString str1;//以MyString字符串保存Huffman编码
	int CharCount=0 ;//字符数
	int totalcount=0 ;//记录文件中字符总数

	int charcount = 0;
	MyString cc;
	SeqList<TriElement> hh;
	MyString str;

public:
	//HuffmanTree(int weight[], int n);//指定权值集合构造Huffman树
	HuffmanTree();
	void HuffmanTreeBuild();
	void printCode();//输出所有字符的编码
	MyString encode(int i);//返回charset[i]字符的编码字符串
	MyString encode();//编码，数据压缩

	void decode();
	void decode(MyString &codestr);//译码，数据解压缩

	void GetFrequency();//获取各个字符频数
	void add(char c);//添加新出现的字符
	int judge(char c);//判断该字符是否已存在

};


#endif // !_HUFFMANTREE_H
