#include "pch.h"

//Car.h

#include <iostream>

using namespace std;



class Car
{
public:
	 int getPurchasePrice() const;
	void setPurchasePrice(int price);
	void calculateCurrentValue(int userCurrentYear);
	void printInfo();
	void setModelYear(int year);
private:
	int m_Model;
	int m_PurchasePrice;
	int m_CurrentValue;
};

//Car.cpp

#include "Car.h"

int Car::getPurchasePrice() const
{
	return m_PurchasePrice;
}

void Car::setPurchasePrice(int price) {
	m_PurchasePrice = price;
}

void Car::calculateCurrentValue(int cy) {
	double depreciationRate = 0.15;
	int carAge = cy - m_Model;
	m_CurrentValue = (m_PurchasePrice * pow((1 - depreciationRate), carAge));
}

void Car::printInfo()
{
	cout << "\nCar's Information : ";
	cout << "\nModel Year : " << m_Model;
	cout << "\nPurchase price : " << m_PurchasePrice;
	cout << "\n Current Value : " << m_CurrentValue;
}

void Car::setModelYear(int year)
{
	m_Model = year;
}

//Main.cpp

#include "Car.h"


int main()
{
	int userYear;
	int userPrice;
	int userCurrentYear;
	Car myCar;

	cin >> userYear;
	cin >> userPrice;
	cin >> userCurrentYear;

	myCar.setModelYear(userYear);
	myCar.setPurchasePrice(userPrice);
	myCar.calculateCurrentValue(userCurrentYear);

	myCar.printInfo();

	return 0;
}
