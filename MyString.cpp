#include "stdafx.h"
#include "MyString.h"

#pragma region init(char *s, int length)��ʼ���������� ָ����ֵ������ ˽��

void MyString::init(char *s, int length)
{
	this->n = strlen(s);
	this->length = (n * 2) > length ? (n * 2) : length;
	this->element = new char[this->length];//�����ַ�����
	for (int i = 0; s[i] != '\0'; i++)
		this->element[i] = s[i];
	this->element[this->n] = '\0';
}
#pragma endregion

#pragma region ���캯��
MyString::MyString(char *s, int length)
{
	this->init(s, length);
}

MyString::MyString(char ch)
{
	this->init("");
	this->n = 1;
	this->element[0] = ch;
	this->element[1] = '\0';
}

MyString::MyString(MyString &str)
{
	this->init(str.element);
}

#pragma endregion

#pragma region ��������
MyString::~MyString()
{
	//delete[] this->element;
}
#pragma endregion

#pragma region ����=����������

MyString& MyString::operator=(MyString &str)
{
	this->~MyString();
	this->init(str.element);
	return *this;
}

MyString& MyString::operator=(char *str)
{
	this->~MyString();
	this->init(str);
	return *this;
}

#pragma endregion

#pragma region ����<<����������

ostream& operator<<(ostream& out, MyString &str)
{
	out << "\"" << str.element << "\"";
	return out;
}

#pragma endregion

#pragma region ��ǰ��ָ��λ�ò��봮

void MyString::insert(int i, MyString &str)
{
	if (str.n == 0)
		return;
	if (i<0)
		i = 0;
	if (i > n)
		i = n;

	char *temp = this->element;
	if (this->length <= this->n + str.n)
	{
		this->length = (this->n + str.n + 1) * 2;
		this->element = new char[this->length];
		for (int j = 0; j < i; j++)
			this->element[j] = temp[j];
	}

	for (int j = this->n; j >= i; j--)
		this->element[j + str.n] = temp[j];

	if (temp != this->element)
		delete[] temp;

	for (int j = 0; j < str.n; j++)
		this->element[i + j] = str.element[j];
	this->n += str.n;
}

void MyString::insert(int i, char ch)
{
	this->insert(i, MyString(ch));
}


#pragma endregion

#pragma region void upperCase();����������Сд��ĸת���ɴ�д��ĸ

void MyString::upperCase()//����������Сд��ĸת���ɴ�д��ĸ
{
	for (int i = 0; i < this->n; i++)
		if (this->element[i] >= 'a'&&this->element[i] <= 'z')
			this->element[i] = this->element[i] - 32;
}

#pragma endregion

#pragma region void lowerCase();���������д�д��ĸת����Сд��ĸ

void MyString::lowerCase()//����������Сд��ĸת���ɴ�д��ĸ
{
	for (int i = 0; i < this->n; i++)
		if (this->element[i] >= 'A'&&this->element[i] <= 'Z')
			this->element[i] = this->element[i] + 32;
}

#pragma endregion

#pragma region MyString substring(int i, int len);//���شӵ�i���ַ���ʼ����Ϊlen���Ӵ�
MyString MyString::substring(int i, int len)
{
	if (i >= 0 && i < n && len >= 0)
	{
		if (len > n - i)
			len = n - i;
		MyString sub;//�����մ�����
		sub.n = len;
		for (int j = 0; j < len; j++)
			sub.element[j] = this->element[i + j];
		sub.element[len] = '\0';
		return sub;
	}
	else
		throw out_of_range("����iָ���ַ���Ż�len������Χ");
}
MyString MyString::substring(int i)
{
	return substring(i, this->n - i + 1);
}

#pragma endregion

#pragma region int count();//���ش�����
int MyString::count()
{
	return this->n;
}
#pragma endregion

#pragma region BF
int MyString::search(MyString &pattern, int start)
{
	int i = start, j = 0;
	while (i < this->n)
	{
		if (this->element[i] == pattern.element[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
		if (j == pattern.n)
			return i - j;
	}
	return -1;
}
#pragma endregion

void MyString::reverse()
{
	//char *temp = new char[this->n];
	//for (int i = 0; i<n; i++)
	//{
	//	temp[i] = this->element[n- 1];
	//}
	//this->element = temp;
	for (int i = 0; i < this->n / 2; i++)
	{
		int end = this->n - i - 1;
		char temp = element[end];
		element[end] = element[i];
		element[i] = temp;
	}

	//delete[] temp;
}


MyString MyString::operator+=(MyString &str)
{
	this->insert(this->n, str);
	return *this;
}


MyString MyString::operator+=(char *str)
{
	int l = strlen(str);
	this->insert(this->n, MyString(str, l));
	return *this;
}
MyString MyString::operator+=(char ch)
{
	this->insert(this->n, MyString(ch));
	return *this;
}

char& MyString::operator[](int i)
{
	return this->element[i];
}