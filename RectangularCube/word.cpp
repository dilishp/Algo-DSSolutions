#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Dwellings
{
public:
	Dwellings(string address);
	~Dwellings();
	virtual void toString() = 0;
	string getAddress() const;
private:
	string m_address;
};

Dwellings::Dwellings(string address):m_address(address)
{

}

Dwellings::~Dwellings()
{
}

string Dwellings::getAddress() const
{
	return m_address;
}

//class House : public Dwellings
//{
//public:
//	House(string address,int propertySize);
//	~House();
//	void toString() override;
//private:
//	int m_propertySize;
//};

//House::House(string address, int propertySize):Dwellings(address),m_propertySize(propertySize)
//{
//}
//
//House::~House()
//{
//}
//
//void House::toString()
//{
//	cout << "\n A home at " << Dwellings::getAddress() << " with " << m_propertySize << " square feet of property";
//}

class Apartment : public Dwellings
{
public:
	Apartment(string address, int apartmentNo);
	~Apartment();
	void toString() override;
private:
	int m_apartmentNo;
};

Apartment::Apartment(string address, int apartmentNo) :Dwellings(address), m_apartmentNo(apartmentNo)
{

}

Apartment::~Apartment()
{
}

void Apartment::toString()
{
	cout << "\n An apartment at " << Dwellings::getAddress() << " , apartment number " << m_apartmentNo;
}

int main() {
	string address;
	string usrOption;
	int propertySize = 0;
	int aptNumber = 0; // Not all necessary variables are defined here
	vector<Dwellings*> vDwellings;

	do {
		cout << endl << "Option: " << endl;
		cin >> usrOption;

		if (usrOption == "print") {
			cout << "\n** Dwelling List **" << endl;
			for (size_t i = 0; i < vDwellings.size(); i++)
			{
				vDwellings[i]->toString();
			}
		}

		else if (usrOption == "house") {
			cout << "\nAddress: " << endl;
			cin >> address;
			cout << "\nProperty Size: " << endl;
			cin >> propertySize;
			Dwellings* dwelling = new House(address, propertySize);
			vDwellings.push_back(dwelling);
		}

		else if (usrOption == "apartment") {
			cout << "\nAddress: " << endl;
			cin >> address;
			cout << "\nApartment Number: " << endl;
			cin >> aptNumber;
			Dwellings* dwelling = new Apartment(address, aptNumber);
			vDwellings.push_back(dwelling);
		}

	} while (usrOption != "quit");
	return 0;
}