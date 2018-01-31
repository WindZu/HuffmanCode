#pragma once

#ifndef _MYSTRING_H
#define _MYSTRING_H

#include <string.h>
#include <iostream>
using namespace std;

class MyString
{
public:
	char *element;//��̬�ַ�����
	int length;//��������
	int n;//������
	void init(char *s = "", int length = 32);//init��ʼ���������� ָ����ֵ������
	//void getNext(int next[]);

public:
	MyString(char *s = "", int length = 32);
	MyString(char ch);
	MyString(MyString &str);

	int count();//���ش�����
	int search(MyString &pattern, int start);//��Start��ʼ����ƥ����ִ���Ȼ�󷵻��׸����ϵ��ִ������

	void insert(int i, MyString &str);//��ǰ��ָ��λ�ò��봮
	void insert(int i, char ch);

	void upperCase();//����������Сд��ĸת���ɴ�д��ĸ
	void lowerCase();//���������д�д��ĸת����Сд��ĸ
	void reverse();//����ǰ����ת


	MyString& operator=(MyString& str);
	MyString& operator=(char *str);

	MyString operator+=(MyString &str);
	MyString operator+=(char *str);
	MyString operator+=(char ch);

	MyString substring(int i, int len);//���شӵ�i���ַ���ʼ����Ϊlen���Ӵ�
	MyString substring(int i);

	char& operator[](int i);

	friend ostream& operator<<(ostream& out, MyString &str);

	~MyString();
};


#endif // !_MYSTRING_H