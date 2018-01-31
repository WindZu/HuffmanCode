#pragma once

#ifndef _MYSTRING_H
#define _MYSTRING_H

#include <string.h>
#include <iostream>
using namespace std;

class MyString
{
public:
	char *element;//动态字符数组
	int length;//数组容量
	int n;//串长度
	void init(char *s = "", int length = 32);//init初始化串，参数 指定初值和内容
	//void getNext(int next[]);

public:
	MyString(char *s = "", int length = 32);
	MyString(char ch);
	MyString(MyString &str);

	int count();//返回串长度
	int search(MyString &pattern, int start);//从Start开始搜索匹配的字串，然后返回首个符合的字串的序号

	void insert(int i, MyString &str);//当前串指定位置插入串
	void insert(int i, char ch);

	void upperCase();//将串中所有小写字母转换成大写字母
	void lowerCase();//将串中所有大写字母转换成小写字母
	void reverse();//将当前串逆转


	MyString& operator=(MyString& str);
	MyString& operator=(char *str);

	MyString operator+=(MyString &str);
	MyString operator+=(char *str);
	MyString operator+=(char ch);

	MyString substring(int i, int len);//返回从第i个字符开始长度为len的子串
	MyString substring(int i);

	char& operator[](int i);

	friend ostream& operator<<(ostream& out, MyString &str);

	~MyString();
};


#endif // !_MYSTRING_H