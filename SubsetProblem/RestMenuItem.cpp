#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct MenuItemType
{
	string itemName;
	double _value;

	MenuItemType(string item, double value) :itemName(item), _value(value)
	{

	}
};

void getData(vector<MenuItemType>& menuList, int index)
{
	int itemno;
	cout << "\nEnter item number : ";
	cin >> itemno;
	switch (itemno)
	{
	case 1:
	{
		MenuItemType item("Plain Egg", 1.45);
		menuList.push_back(item);
		break;
	}
	case 2:
	{
		MenuItemType item("Bacon and Egg", 2.45);
		menuList.push_back(item);
		break;
	}
	case 3:
	{
		MenuItemType item("Muffin", 0.99);
		menuList.push_back(item);
		break;
	}
	case 4:
	{
		MenuItemType item("French Toast", 1.99);
		menuList.push_back(item);
		break;
	}
	case 5:
	{
		MenuItemType item("Fruit Basket", 2.49);
		menuList.push_back(item);
		break;
	}
	case 6:
	{
		MenuItemType item("Cereal", 0.69);
		menuList.push_back(item);
		break;
	}
	case 7:
	{
		MenuItemType item("Coffee", 0.50);
		menuList.push_back(item);
		break;
	}
	case 8:
	{
		MenuItemType item("Tea", 0.75);
		menuList.push_back(item);
		break;
	}
	default:
		break;
	}
}

void printCheck(vector<MenuItemType>& menuList)
{
	cout.precision(0.2);
	cout << "\nWelcome to Johnny's Resturant \n\n";
	double billAmount = 0.00;
	for (MenuItemType item : menuList)
	{
		cout << item.itemName << "  $" << item._value;
		billAmount += item._value;
		cout << "\n";
	}
	cout << "\nTax  $" <<fixed << setprecision(2) << 0.05 * billAmount;
	billAmount += 0.05 * billAmount;
	cout.precision(0.2);
	cout << "\nBill Amount  $" << fixed << setprecision(2)<< billAmount;
}

void showMenu(vector<MenuItemType>& menuList)
{
	cout << "\nWelcome to Johnny's Resturant \n\n----Today's Menu----\n\n \n1 : Plain Egg $1.45 \n2 : Bacon and Egg $2.45 \n3 : Muffin $0.99 \n4 : French Toast $1.99 \n5 : Fruit Basket $2.49 \n6 : Cereal $0.69 \n7 : Coffee $0.50 \n8 : Tea $0.75";
	cout << " \nYou can make up to 8 single order selections\n\n Do you want to make selection Y / y(Yes), N / n(No) :";
	char choice;
	cin >> choice;
	int index = 0;
	while ((choice == 'y') || (choice == 'Y'))
	{
		if (index > 8)
			break;
		getData(menuList, index);
		index++;
		cout << "\nSelect another item Y / y(Yes), N / n(No) :";
		cin >> choice;
	}
	printCheck(menuList);
}



void main()
{
	vector<MenuItemType> menuList;
	showMenu(menuList);
}

