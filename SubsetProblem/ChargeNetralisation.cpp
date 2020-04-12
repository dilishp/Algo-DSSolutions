#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <string>


using namespace std;

/**
* A person who would like to use the services
*/
struct Customer {
	string name = "";
	string address = "";
	string email = "";
	int numMonths = 0;
};

/**
* Get shipping information from customer
* @param newCust the customer object missing shipping information
* @return customer object with shipping information filled out
*/
Customer shipping(Customer newCust) {
	//Students will complete this function
	return newCust;
}

/**
* Gets customer information including shipping address if user selects ship to my address
* @return customer object with basic information filled out
*/
Customer getCustomerInfo() {
	int selection;
	Customer newCust;
	cout << "Please enter your name\n";
	cin.ignore();
	getline(cin, newCust.name);
	cout << endl << "Please enter your email address\n";
	cin >> newCust.email;
	cout << endl << "How long have you been a customer? (Enter number of months)" << endl;
	cin >> newCust.numMonths;
	cout << "Would you like this printed now, or shipped to your address?" << endl;
	cout << "Press 1 for now" << endl;
	cout << "Press 2 for ship to my address" << endl;
	cin >> selection;
	if (selection == 1)
		newCust.address = "NOW";
	else {
		newCust = shipping(newCust);
	}
	return newCust;
}

/**
* An amount of U.S. currency
*/
struct Money {
	int dollar;
	int cent;
};

/**
* Function to fix the dollar and cent integers in case cent is less than 0 or more than 100
* @param orig original money object
* @return normalized money object
*/
Money normalizeMoney(Money orig) {
	if (orig.cent > 100) { //if cent is more than 100
		int actualcent = orig.cent % 100;
		orig.cent -= actualcent;
		orig.dollar += orig.cent / 100;
		orig.cent = actualcent;
	}
	// if cent is negative while dollar is positive
	if (orig.dollar > 0 && orig.cent < 0) {
		orig.dollar -= 1;
		orig.cent += 100;
	}
	if (orig.dollar < 0) {
		orig.cent -= 100 * abs(orig.dollar);
		orig.dollar = 0;
	}
	return orig;
}

/**
* Function that calls maintenance for the machine when the money in the cash register is
* more than $1500 or less than $50. Sets the dollar amount to 500 and cent to 0
* @param cashRegister original money object
* @return normalized money object
*/
Money maintenance(Money cashRegister) {
	//Students will complete this function
	return cashRegister;
}

/**
* Function that adjusts cost to include customer discount and shipping cost
* @param c customer object
* @param cost the original cost of the customer order
* @return money amount with discount included
*/
Money customerDiscount(Customer c, Money cost) {
	//Students will complete this function
	return cost;
}

/**
* Function that handles user entering money
* @param cashRegister the money object that represents the amount of money in the cash register
* @param cost the cost of the customer order
* @return the updated cashRegister object
*/
Money moneyExchange(Money cashRegister, Money cost) {
	int userMoney = 0;
	while (!((cost.dollar == 0 && cost.cent == 0) || (cost.cent < 0) || (cost.dollar < 0))) {
		cout << "Your remaining balance is $" << cost.dollar << "." << cost.cent << endl
			<< "Press 1 to enter 10 cents" << endl
			<< "Press 2 to enter 25 cents" << endl
			<< "Press 3 to enter 1 dollar" << endl
			<< "Press 4 to enter 5 dollars" << endl
			<< "Press 5 to enter 10 dollars" << endl
			<< "Press 6 to enter 20 dollars" << endl;
		cin >> userMoney;
		switch (userMoney)
		{
		case 1:
			// Press 1 to enter 10 cents
			cashRegister.cent += 10;
			cashRegister = normalizeMoney(cashRegister);
			cost.cent -= 10;
			cost = normalizeMoney(cost);
			break;
		case 2:
			// Press 2 to enter 25 cents
			cashRegister.cent += 25;
			cashRegister = normalizeMoney(cashRegister);
			cost.cent -= 25;
			cost = normalizeMoney(cost);
			break;
		case 3:
			// Press 3 to enter 1 dollar
			cashRegister.dollar += 1;
			cashRegister = normalizeMoney(cashRegister);
			cost.dollar -= 1;
			cost = normalizeMoney(cost);
			break;
		case 4:
			// Press 4 to enter 5 dollars
			cashRegister.dollar += 5;
			cashRegister = normalizeMoney(cashRegister);
			cost.dollar -= 5;
			cost = normalizeMoney(cost);
			break;
		case 5:
			// Press 5 to enter 10 dollars
			cashRegister.dollar += 10;
			cashRegister = normalizeMoney(cashRegister);
			cost.dollar -= 10;
			cost = normalizeMoney(cost);
			break;
		case 6:
			// Press 6 to enter 20 dollars
			cashRegister.dollar += 20;
			cashRegister = normalizeMoney(cashRegister);
			cost.dollar -= 20;
			cost = normalizeMoney(cost);
			break;
		}
	}
	//check if there is going to be any change
	Money change;
	change.dollar = abs(cost.dollar);
	change.cent = abs(cost.cent);
	change = normalizeMoney(change);
	cashRegister.dollar -= change.dollar;
	cashRegister.cent -= change.cent;
	cashRegister = normalizeMoney(cashRegister);
	cout << "Thanks for using our service! Your change is $" << change.dollar << "." << change.cent << endl << endl;
	return cashRegister;
}

/**
* Struct that contains information about photo
*/
struct Photo {
	int quantity, filter;
	string size;
	Money cost;
};

/**
* Function that represents the user interface of the photograph selection
* @param pSize the selected photograph size
* @return the cost of the order
*/
Money photoInterface(string pSize) {
	// Create an instance of Photo
	Photo newPhoto;
	newPhoto.size = pSize; //Get the size of the photographs from user selection
	//Get number of photos from user input
	cout << "How many sets of 4 photos would you like?" << endl;
	cin >> newPhoto.quantity;
	newPhoto.quantity *= 4;
	//if not passport photo, ask if user wants filters
	if (pSize != "passport") {
		cout << "Which filter would you like for your pictures?" << endl;
		cout << "Press 0 for no filter" << endl
			<< "Press 1 for Black & White" << endl
			<< "Press 2 for 50's TV" << endl
			<< "Press 3 for Film Noir" << endl
			<< "Press 4 for Negative" << endl
			<< "Press 5 to go back to the previous menu" << endl;
		cin >> newPhoto.filter;
		cout << "Get ready" << endl << "3" << endl << "2" << endl << "1" << endl;
	}
	// if user picks 5, return to the previous menu
	if (newPhoto.filter == 5) {
		newPhoto.cost.dollar = -1;
		newPhoto.cost.cent = -1;
		return newPhoto.cost;
	}
	else {
		//each fotograph is $3.50
		newPhoto.cost.dollar = 3 * newPhoto.quantity;
		newPhoto.cost.cent = 50 * newPhoto.quantity;
		newPhoto.cost = normalizeMoney(newPhoto.cost);
		//add 5% VAT to the cost
		newPhoto.cost.cent += newPhoto.cost.dollar * 5;
		newPhoto.cost = normalizeMoney(newPhoto.cost);
	}
	return newPhoto.cost;
}

/**
* display the menu and call appropriate functions
*/
void menu() {
	Money cashRegister;
	Money cost;
	Customer cust;
	cashRegister.dollar = 500;
	cashRegister.cent = 0;
	int input = 0;
	while (input != 7) {
		cout << "*********************************" << endl << "Welcome to the Photo Booth" << endl << "*********************************" << endl;
		cout << "Please make a selection below" << endl;
		cout << "Press 1 for passport picture" << endl
			<< "Press 2 for 3x2" << endl
			<< "Press 3 for 4x6" << endl
			<< "Press 4 for 5x7" << endl
			<< "Press 5 for 8x10" << endl
			<< "Press 6 for group picture" << endl
			<< "Press 7 to exit" << endl;

		cin >> input;
		switch (input)
		{
		case 1:
			// Press 1 for passport picture
			cost = photoInterface("passport");
			cust = getCustomerInfo();
			cost = customerDiscount(cust, cost);
			if (cost.dollar != -1)
				cashRegister = moneyExchange(cashRegister, cost);
			break;
		case 2:
			// Press 2 for 3x2
			cost = photoInterface("3x2");
			cust = getCustomerInfo();
			cost = customerDiscount(cust, cost);
			if (cost.dollar != -1)
				cashRegister = moneyExchange(cashRegister, cost);
			break;
		case 3:
			// Press 3 for 4x6
			cost = photoInterface("4x6");
			cust = getCustomerInfo();
			cost = customerDiscount(cust, cost);
			if (cost.dollar != -1)
				cashRegister = moneyExchange(cashRegister, cost);
			break;
		case 4:
			// Press 4 for 5x7
			cost = photoInterface("5x7");
			cust = getCustomerInfo();
			cost = customerDiscount(cust, cost);
			if (cost.dollar != -1)
				cashRegister = moneyExchange(cashRegister, cost);
			break;
		case 5:
			// Press 5 for 8x10
			cost = photoInterface("8x10");
			cust = getCustomerInfo();
			cost = customerDiscount(cust, cost);
			if (cost.dollar != -1)
				cashRegister = moneyExchange(cashRegister, cost);
			break;
		case 6:
			// Press 6 for group picture
			cost = photoInterface("group");
			cust = getCustomerInfo();
			cost = customerDiscount(cust, cost);
			if (cost.dollar != -1)
				cashRegister = moneyExchange(cashRegister, cost);
			break;
		case 7:
			// Press 7 to exit
			exit(0);
		}
		//if cashRegister has more than $1500 or less than $50, call operator function
		if (cashRegister.dollar > 1500 || cashRegister.dollar < 50)
			cashRegister = maintenance(cashRegister);
	}
}

/**
* main function that calls menu
*/
int main(int argc, const char * argv[]) {
	menu();

	return 0;
}