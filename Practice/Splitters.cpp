#include "pch.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//Operation.h
class Operation
{
public:
	Operation(double l,double r);
	virtual ~Operation();
	virtual double perform() const = 0;
	virtual char symbol() const = 0;
	friend ostream& operator << (ostream& out, const Operation& op);
protected:
	double m_left;
	double m_right;
};

//Operation.cpp
Operation::Operation(double l, double r) :m_left(l), m_right(r)
{
}

Operation::~Operation()
{
}

ostream& operator << (ostream& out, const Operation& op)
{
	out << std::fixed << std::setprecision(2) << op.m_left 
		<< setw(10) << op.symbol() << std::fixed << std::setprecision(2)<< setw(10)
		<< op.m_right << setw(10) << " = " << setw(10) <<std::fixed << std::setprecision(2) << op.perform();

	return out;
}

//addition.h
class Addition : public Operation
{
public:
	Addition(double l, double r);
	~Addition();
	double perform() const override;
	char symbol() const override;
private:

};

//addition.cpp
Addition::Addition(double l,double r):Operation(l,r)
{
}

Addition::~Addition()
{
}

double Addition::perform() const
{
	return m_left + m_right;
}

char Addition::symbol() const
{
	return '+';
}

//subtraction.h
class Subtraction : public Operation
{
public:
	Subtraction(double l, double r);
	~Subtraction();
	double perform() const override;
	char symbol() const override;
private:

};

//subtraction.cpp
Subtraction::Subtraction(double l, double r) :Operation(l, r)
{
}

Subtraction::~Subtraction()
{
}

double Subtraction::perform() const
{
	return m_left - m_right;
}

char Subtraction::symbol() const
{
	return '-';
}

//multiplication.h
class Multiplication : public Operation
{
public:
	Multiplication(double l, double r);
	~Multiplication();
	double perform() const override;
	char symbol() const override;
private:

};

//multiplication.cpp
Multiplication::Multiplication(double l, double r) :Operation(l, r)
{
}

Multiplication::~Multiplication()
{
}

double Multiplication::perform() const
{
	return m_left * m_right;
}

char Multiplication::symbol() const
{
	return '*';
}

//division.h
class Division : public Operation
{
public:
	Division(double l, double r);
	~Division();
	double perform() const override;
	char symbol() const override;
private:

};

//division.cpp
Division::Division(double l, double r) :Operation(l, r)
{
}

Division::~Division()
{
}

double Division::perform() const
{
	return m_left / m_right;
}

char Division::symbol() const
{
	return '/';
}

//main.cpp
int main()
{
	ifstream fin;
	ofstream fout;

	fin.open("operations-in.txt");
	fout.open("operations-out.txt");

	if (!fin.is_open())
		return 0;

	char command;
	while (fin >> command)
	{
		Operation* op = nullptr;
		double num1, num2;
		fin >> num1 >> num2;
		switch (command)
		{
		case '+':
			op = new Addition(num1, num2);
			cout << (*op);
			fout << (*op);
			break;
		case '-':
			op = new Subtraction(num1, num2);
			cout << (*op);
			fout << (*op);
			break;
		case '*':
			op = new Multiplication(num1, num2);
			cout << (*op);
			fout << (*op);
			break;
		case '/':
			op = new Division(num1, num2);
			cout << (*op);
			fout << (*op);
			break;
		default:
			break;
		}
		cout << "\n";
		fout << "\n";
		if(nullptr != op)
			delete op;
	}

	fin.close();
	fout.close();
	return 0;
}

