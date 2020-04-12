#include "pch.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>

using namespace std;

//matrix.h
class Matrix
{
public:
	Matrix();
	Matrix(string file);
	~Matrix();
	Matrix& operator + (const Matrix& add);
	Matrix& operator - (const Matrix& sub);
	Matrix& operator ^ (const Matrix& power);
	friend ostream& operator << (ostream& out, const Matrix& mat);
	void displayRow(int row);
private:
	int size;
	int** mat;
};

//matrix.cpp
Matrix::Matrix()
{
	size = 0;
	mat = nullptr;
}

Matrix::Matrix(string file)
{
	ifstream fin;
	fin.open(file);

	if (!fin.is_open())
		return;

	fin >> size;

	mat = new int*[size];

	for (size_t i = 0; i < size; i++)
	{
		mat[i] = new int[size];
	}

	string in;
	int row = 0, column = 0, count = 0;

	//reading the new line
	char ch;
	fin.get(ch);

	while (std::getline(fin, in))
	{
		stringstream ss(in);
		int num;
		while (ss >> num)
		{
			mat[row][column] = num;
			++column;
		}
		column = 0;
		++row;
	}

}

Matrix::~Matrix()
{
	for (size_t i = 0; i < size; i++)
	{
		delete[] mat[i];
	}

	delete[] mat;
	size = 0;
}

Matrix&  Matrix::operator+(const Matrix& add)
{
	if (this->size == add.size)
	{
		for (size_t i = 0; i < size; i++)
		{
			for (size_t j = 0; j < size; j++)
			{
				this->mat[i][j] += add.mat[i][j];
			}
		}
	}

	return *this;
}

Matrix&  Matrix::operator-(const Matrix& sub)
{
	if (this->size == sub.size)
	{
		for (size_t i = 0; i < size; i++)
		{
			for (size_t j = 0; j < size; j++)
			{
				this->mat[i][j] -= sub.mat[i][j];
			}
		}
	}
	
	return *this;
}

Matrix& Matrix::operator^(const Matrix & power)
{
	if (this->size == power.size)
	{
		for (size_t i = 0; i < size; i++)
		{
			for (size_t j = 0; j < size; j++)
			{
				this->mat[i][j] = pow(this->mat[i][j], power.mat[i][j]);
			}
		}
	}

	return *this;
}

void Matrix::displayRow(int row)
{
	for (size_t i = 0; i < size; i++)
	{
		cout<< this->mat[row][i];
		if (i != (size - 1))
			cout << ",";
	}
	cout << "\n";
}

ostream & operator<<(ostream & out, const Matrix & mat)
{
	for (size_t i = 0; i < mat.size; i++)
	{
		for (size_t j = 0; j < mat.size; j++)
		{
			out << mat.mat[i][j];
			if (j != (mat.size - 1))
				out << ",";
		}
		cout << "\n";
	}
	cout << "\n";

	return out;
}

//main.cpp
int main()
{
	Matrix m1("m1.txt");
	Matrix m2("m2.txt");

	Matrix m3, m4,m7;

	cout << "\nA:\n";
	cout << m1;
	
	cout << "\nB:\n";
	cout << m2;

	m3 = m1 + m2;

	cout << "\n A = A + B\n";
	cout << m3;

	Matrix m5("m1.txt");

	cout << "\nA:\n";
	cout << m5;

	cout << "\nB:\n";
	cout << m2;

	m4 = m5 - m2;

	cout << "\n A = A - B\n";
	cout << m4;

	Matrix m6("m1.txt");

	cout << "\nA:\n";
	cout << m6;

	cout << "\nB:\n";
	cout << m2;

	m7 = m6 ^ m2;

	cout << "\n A = A ^ B\n";
	cout << m7;

	return 0;
}