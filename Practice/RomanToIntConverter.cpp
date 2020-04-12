#include "pch.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

//class romanType
//
//{
//
//public:
//
//	void setRoman(string);//Set the romaType to a new value as string(no error checking)
//
//	void setRoman(int);//Set the romanType to a new value with integer
//
//	void romanToPositiveInteger(); //convert the roman string to a number value
//
//	void printPositiveInteger() const;
//
//	void printRoman() const;
//
//	string getRoman();//Return the roman value as a string
//
//	int getValue();//return the roman value as a number
//
//	void inc();//increment the roman variable
//
//	void dec();//decrement the roman variable
//
//	void add(romanType);//add two romanType values
//
//	void add(int);//Add new integer value to existing romanType
//
//	//constructors
//
//	romanType();
//
//	romanType(string);
//
//	romanType(int);
//
//private:
//
//	string intToRoman(int); //convert an integer value into roman string representation
//
//	string romanNum;
//
//	int num;
//
//};
//
//void romanType::setRoman(std::string roman)
//{
//	romanNum = roman;
//}
//
//void romanType::setRoman(int number)
//{
//	num = number;
//}
//
//void romanType::romanToPositiveInteger()
//{
//	intToRoman(num);
//}
//
//void romanType::printPositiveInteger() const
//{
//	cout << num;
//}
//
//void printRoman() const;
//
//string getRoman();//Return the roman value as a string
//
//int getValue();//return the roman value as a number
//
//void inc();//increment the roman variable
//
//void dec();//decrement the roman variable
//
//void add(romanType);//add two romanType values
//
//void add(int);//Add new integer value to existing romanType
//
////constructors
//
//romanType();
//
//romanType(string);
//
//romanType(int);

std::map<char, int> mofRomanToInt = { {'I',1},{'V',5},{'X',10},{'L',50},{'C',100} };

void convert(std::string roman)
{
	int number = 0;
	for (size_t i = 0; i < roman.length(); i++)
	{
		if ((roman[i] == 'I' || roman[i] == 'X') && 
			(((i + 1) < roman.length()) && (roman[i + 1] != 'I')))
		{
			number += (-mofRomanToInt[roman[i]]);
		}
		else
		{
			number += (mofRomanToInt[roman[i]]);
		}
	}

	std::cout << number;
}

void main()
{
	convert("III");
}