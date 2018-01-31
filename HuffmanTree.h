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
	MyString charset;//�ַ���
	SeqList<TriElement> huftree;//���˳���
	

	HuffmanChar huff[256];
	MyString codestr;//
	MyString str1;//��MyString�ַ�������Huffman����
	int CharCount=0 ;//�ַ���
	int totalcount=0 ;//��¼�ļ����ַ�����

	int charcount = 0;
	MyString cc;
	SeqList<TriElement> hh;
	MyString str;

public:
	//HuffmanTree(int weight[], int n);//ָ��Ȩֵ���Ϲ���Huffman��
	HuffmanTree();
	void HuffmanTreeBuild();
	void printCode();//��������ַ��ı���
	MyString encode(int i);//����charset[i]�ַ��ı����ַ���
	MyString encode();//���룬����ѹ��

	void decode();
	void decode(MyString &codestr);//���룬���ݽ�ѹ��

	void GetFrequency();//��ȡ�����ַ�Ƶ��
	void add(char c);//����³��ֵ��ַ�
	int judge(char c);//�жϸ��ַ��Ƿ��Ѵ���

};


#endif // !_HUFFMANTREE_H
