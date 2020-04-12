#include "pch.h"
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

//class vector
//{
//public:
//	vector() :vector(initialsize)
//	{
//		cout << "\nObject of class vector was created using the vector() constructor";
//		
//	}
//	vector(size_t size) :_size(size)
//	{
//		cout << "\nObject of class vector was created using the vector(size_t) constructor";
//		data = new int[_size] {0};
//	}
//
//	vector(int* arr, size_t size)
//	{
//		data = new int[size];
//		for (size_t i = 0; i < size; i++)
//		{
//			data[i] = arr[i];
//		}
//		_size = size;
//	}
//
//	void assign(int* arr, size_t size)
//	{
//		if (data)
//		{
//			delete[] data;
//			_size = 0;
//		}
//
//		data = new int[size];
//		for (size_t i = 0; i < size; i++)
//		{
//			data[i] = arr[i];
//		}
//		_size = size;
//	}
//
//	friend ostream& operator << (const ostream& out, const vector& v)
//	{
//		cout << "\nVector : size(3)";
//		cout << "\ndata[0] :" << data[0];
//		cout << "\ndata[1] :" << data[1];
//		cout << "\ndata[2] :" << data[2];
//	}
//
//	vector add(const vector& v)
//	{
//		int sizeofnewv = (this->_size > v._size) ? v._size : this->_size;
//		vector res(sizeofnewv);
//
//		int k = 0;
//		for (size_t i = 0,j = 0; i < this->_size,j < v._size; i++,j++)
//		{
//			res.data[k] = this->data[i] + v.data[j];
//			k++;
//		}
//
//		return res;
//	}
//
//	vector operator + (const vector& v)
//	{
//		int sizeofnewv = (this->_size > v._size) ? this->_size : v._size;
//		vector res(sizeofnewv);
//
//		int k = 0;
//		for (size_t i = 0, j = 0; i < this->_size, j < v._size; i++, j++)
//		{
//			res.data[k] = this->data[i] + v.data[j];
//			k++;
//		}
//
//		return res;
//	}
//
//	int& operator[](int index)
//	{
//		if(index < _size)
//			return data[index];
//
//		return data[0];
//	}
//
//	void resize(size_t size)
//	{
//		data = (int*)realloc(data, size);
//	}
//
//	const_iterator operator+(int k)
//	{
//		iterator<int,>(data + k);
//	}
//
//	~vector()
//	{
//		if(data)
//			delete[] data;
//		_size = 0;
//		cout << "\nObject of class vector is deleted";
//	}
//private:
//	const int initialsize = 3;
//	int _size;
//public:
//	vector<int> data;
//};


class STLVector
{
public:

	STLVector();
	~STLVector();

	using const_iterator = typename vector<int>::const_iterator;

	using iterator = typename vector<int>::iterator;

	const_iterator operator+(int k)
	{
		if( )
	}
private:
	vector<int> data;
};

STLVector::STLVector()
{
}

STLVector::~STLVector()
{
}