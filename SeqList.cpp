#include "stdafx.h"
//#include "SeqList.h"
//
//template <class T>
//SeqList<T>::SeqList(int length)
//{
//	this->element = new T[length];
//	this->length = length;
//	this->n = 0;
//}
//
//template <class T>
//SeqList<T>::SeqList(int length, T x)//length个元素值为x
//{
//	this->element = new T[length];
//	this->length = this->n = length;
//	for (int i = 0; i < this->n; i++)
//	{
//		this->element[i] = x;
//	}
//}
//
//template <class T>
//SeqList<T>::SeqList(T values[], int n)
//{
//	this->init(values, n);
//}
//
//template <class T>
//void SeqList<T>::init(T values[], int n)
//{
//	this->length = n * 2;
//	this->element = new T[length];
//	this->n = n;
//	for (int i = 0; i < n; i++)
//	{
//		this->element[i] = values[i];
//	}
//}
//
//template <class T>
//SeqList<T>::~SeqList()
//{
//	delete[] this->element;
//}
//
//#pragma region insert函数
//
//template <class T>
//void SeqList<T>::insert(int i, T x)
//{
//	if (i < 0)
//		i = 0;
//	if (i > this->n)
//		i = this->n;
//	T *temp = this->element;
//	if (this->n == this->length)
//	{
//		this->length *= 2;
//		this->element = new T[this->length];
//		for (int j = 0; j < i; j++)
//			this->element[j] = temp[j];
//	}
//
//	for (int j = this->n-1; j >= i; j--)
//	{
//		this->element[j + 1] = temp[j];
//	}
//	if (temp != this->element)
//		delete[] temp;
//	this->element[i] = x;
//	this->n++;
//}
//
//template <class T>
//void SeqList<T>::insert(T x)
//{
//	insert(this->n,x);
//}
//#pragma endregion
//
//template <class T>
//T& SeqList<T>::operator[](int i)
//{
//	return this->element[i];
//}