#include "pch.h"
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
#include <numeric>

using namespace std;

struct Record
{
	double unitPrice;
	int units;
};

int main()
{
	map<string, Record> cart, itemsAvailable = {
		{"Shampoo",{23.12,6}},
		{"Hair Oil",{42.12,5}},
		{"Rice",{13.12,8}},
		{"ToothPaste",{12.12,4}},
		{"Shaving Gel",{73.12,5}}
	};

	while (true)
	{
		cout << "\nItems Available\n";
		for (auto element : itemsAvailable)
		{
			cout << element.first << "  " << element.second.unitPrice << "  " << element.second.units << endl;
		}
		cout << "\n****** Menu ******";
		cout << "\n1. Add Items to the cart";
		cout << "\n2. Remove Items to the cart";
		cout << "\n3. Display Items in the cart";
		cout << "\n4. Exit";
		cout << "\n Enter you choice : ";
		int choice;
		cin >> choice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		switch (choice)
		{
		case 1:
		{
			cout << "\n Enter the item name : ";
			string name;
			getline(cin, name);

			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "\nEnter the item units : ";
			int units;
			cin >> units;

			if (itemsAvailable.find(name) != itemsAvailable.end())
			{
				//Subtract the units from item available
				cart[name] = { itemsAvailable[name].unitPrice,units };
				itemsAvailable[name].units -= units;
			}

		}
		break;
		case 2:
		{
			cout << "\n Enter the item to remove from the cart : ";
			string name;
			getline(cin, name);

			if (cart.find(name) != cart.end())
			{
				//Add the units back to the shelf
				itemsAvailable[name].units += cart[name].units;
				cart.erase(name);
			}
		}
		break;
		case 3:
		{
			cout << "\n Items in the cart are\n";
			for (auto element : cart)
			{
				cout << element.first << "  " << element.second.unitPrice << "  " << element.second.units << endl;
			}
			cout << "\n Cart Total : ";
			//Find the cart total
			double total = std::accumulate(cart.begin(), cart.end(), 0.0, [&](double acc, std::pair<string, Record> aPair) {
				return acc + (aPair.second.unitPrice * aPair.second.units);
			});
			cout << total << endl;
		}
		break;
		case 4:
			exit(0);
			break;
		default:
			break;
		}
	}

	return 0;
}