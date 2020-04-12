#include "pch.h"
#include <iostream>

using namespace std;

class EnglishWeight
{
	long m_weightinPound;
	long m_weigntinOunces;

public:
	EnglishWeight() = default;
	EnglishWeight(long weightinPound,  long weigntinOunces):m_weightinPound(weightinPound),m_weigntinOunces(weigntinOunces)
	{

	}
	friend ostream& operator <<(ostream& out, EnglishWeight& aWeight)			//ostream operator overloading
	{
		out << aWeight.m_weightinPound <<" Pound  "<<aWeight.m_weigntinOunces<<" Ounces";
		return out;
	}
	friend istream& operator >>(istream& in, EnglishWeight& aWeight)			//istream operator overloading
	{
		in >> aWeight.m_weightinPound >> aWeight.m_weigntinOunces;
		return in;
	}
	EnglishWeight operator + (EnglishWeight& aWeight)						   //Addition operator overloading
	{
		long totalWeight = (this->m_weightinPound * 16 + this->m_weigntinOunces) +
			(aWeight.m_weightinPound * 16 + aWeight.m_weigntinOunces);

		 EnglishWeight result(totalWeight / 16, totalWeight % 16);
		return result;
	}
	EnglishWeight operator - (EnglishWeight& aWeight)							//Subtraction operator overloading
	{
		long totalWeight = abs((this->m_weightinPound * 16 + this->m_weigntinOunces) -
			(aWeight.m_weightinPound * 16 + aWeight.m_weigntinOunces));

		EnglishWeight result(totalWeight / 16, totalWeight % 16);
		return result;
	}
};

void main()
{
	EnglishWeight weight1, weight2,weight3;
	cout << "Please Enter the first weight in Pond and Ounces respectively" << endl;
	cin >> weight1;
	cout << "Please Enter the second weight in Pond and Ounces respectively" << endl;
	cin >> weight2;
	cout << "Please Enter the third weight in Pond and Ounces respectively" << endl;
	cin >> weight3;

	EnglishWeight addedWeight = weight1 + weight2 + weight3;
	EnglishWeight subtractedWeight = weight1 - weight2  - weight3;

	cout << "Result of added weight is : "<<addedWeight << endl;
	cout << "Result of subtracted weight is : " << subtractedWeight << endl;

}