#include "pch.h"
#include <iostream>
#include <functional>

using namespace std;

void getDetailsfromUser(int& rentalOrTaxi,float& totalcost,float& arrivalTime, float& deptTime,float& airfare,float& confOrSemRegFee)
{
	cout << endl << "Enter your departure time on the first day: ";

	cin >> deptTime;

	cout << endl << "Enter your arrival time on the last day: ";

	cin >> arrivalTime;

	cout << endl << "Enter total amout of airfare in $:";

	cin >> airfare;

	totalcost += airfare;

	cout << "Enter total amount of conference or Seminar Reg Fees in $";

	cin >> confOrSemRegFee;

	totalcost += confOrSemRegFee; //total cost equals 'total cost' plus 'conference or seminar fee'.

	cout << endl;

	do {

		cout << "1:Did you: rent a car or 2: use taxi for your trip? Enter 1 or 2:";

		cin >> rentalOrTaxi;

		if (!(rentalOrTaxi == 1 || rentalOrTaxi == 2)) { cout << endl << "Invalid input. Please try again." << endl; }

	} while (!(rentalOrTaxi == 1 || rentalOrTaxi == 2));
}

float calculateTotalCost(int& milesDriven,int& typeOfCar,int& rentalFee,float& gasFee,int& daysOfTrip)
{
	cout << "Enter the total miles Driven:" << endl;

	cin >> milesDriven;

	if (typeOfCar == 1) {

		rentalFee = 20;

		gasFee = 0.24;

	}
	else if (typeOfCar == 2) {

		rentalFee = 25;

		gasFee = 0.27;

	}
	else if (typeOfCar == 3) {

		rentalFee = 30;

		gasFee = 0.32;

	}
	else if (typeOfCar == 4) {

		rentalFee = 50;

		gasFee = 0.45;

	}

	return rentalFee * daysOfTrip + gasFee * milesDriven;
}

void calculateFee(int& employeePaid,int* parkingfee,int& daysOfTrip, int& payLimit,std::function<void(int)>& aFunc)
{
	int limit = 0;
	if (90 == payLimit)
		limit = 1;
	for (int i = 0; i < (daysOfTrip - limit); i++) {

		aFunc(i);

		cin >> parkingfee[i];

		if (parkingfee[i] > payLimit) {//company cannot pay more than $10.

			employeePaid = parkingfee[i] - payLimit;

			parkingfee[i] = payLimit;

		}

	}
}

void expensesforDay0(float& deptTime,int* dinner,int* lunch,int& noOfBreakfasts,int& noOfLunches)
{
	if (deptTime > 18) {

		cout << "No expense covered for day 1";

	}
	else if (deptTime > 12) {

		cout << "Dinner is covered for day 1:Enter fee: ";

		cin >> dinner[0];

		noOfBreakfasts--; //Post-decrement '--' for the program to run through the correct number of days of the user's trip.

		noOfLunches--;

	}
	else if (deptTime > 7) {

		cout << "Enter lunch fee for day 1:";

		cin >> lunch[0];

		cout << "Enter dinner fee for day 1";

		cin >> dinner[0];

		noOfBreakfasts--;

	}
}

void expensesforlastDay(float& arrivalTime,int& noOfBreakfasts, int& noOfLunches,int& noOfDinners
						,int* breaks,int* lunch,int* dinner,int& daysOfTrip)
{
	if (arrivalTime < 8) {

		cout << "Nothing is provided by the company on last day.";

		noOfBreakfasts--;//he comes before 8 so breakfast is not provided, similarly below. The next chunk of lines is pretty self-explanatory.

		noOfLunches--;

		noOfDinners--;

	}
	else if (arrivalTime < 13) {

		cout << "Breakfast provided;Enter fee for breakfast:";

		cin >> breaks[daysOfTrip - 1];

		noOfLunches--;

		noOfDinners--;

	}
	else if (arrivalTime < 19) {

		cout << "Breakfast and lunch is reimbursed for last day; Enter breakfast fee: ";

		cin >> breaks[daysOfTrip - 1];

		cout << "Enter lunch fee:";

		cin >> lunch[daysOfTrip - 1];

		noOfDinners--;

	}
	else {

		cout << "All three meals are provided for last day;Enter breakfast fee";

		cin >> breaks[daysOfTrip - 1];

		cout << "Enter lunch fee:";

		cin >> lunch[daysOfTrip - 1];

		cout << "Enter dinner fee";

		cin >> dinner[daysOfTrip - 1];

	}
}

void calculateEmployeePaid(int i,int& employeePaid,int* breaks,int* lunch,int* dinner)
{
	if (breaks[i] > 9) { //the numbers represent the cost that the company will reimburse up to. For example, the company will reimburse breakfast up to $9.
		employeePaid += breaks[i] - 9;
		breaks[i] = 9;
	}

	if (lunch[i] > 12) {
		employeePaid += lunch[i] - 12;
		lunch[i] = 12;
	}

	if (dinner[i] > 16) {
		employeePaid += dinner[i] - 16;
		dinner[i] = 16;
	}
}

void CalculateExpenses(float& deptTime,float& arrivalTime, int& noOfBreakfasts, int& noOfLunches, int& noOfDinners
	, int* breaks, int* lunch, int* dinner, int& daysOfTrip)
{
	for (int i = 0; i < daysOfTrip; i++) {

		if (i == 0) {
			expensesforDay0(deptTime, dinner, lunch, noOfBreakfasts, noOfLunches);
		}
		else if (i == daysOfTrip - 1) {
			expensesforlastDay(arrivalTime, noOfBreakfasts, noOfLunches, noOfDinners, breaks,
				lunch, dinner, daysOfTrip);
		}
		else {
			cout << "All three meals are provided for day " << i + 1 << endl << ";Enter breakfast charge";
			cin >> breaks[i];
			cout << "Enter lunch fee:";
			cin >> lunch[i];
			cout << "Enter dinner fee";
			cin >> dinner[i];
		}

	}
}

void calculateTaxiCharges(int& rentalOrTaxi, int& milesDriven, int& typeOfCar, int& rentalFee, float& gasFee, 
	int& daysOfTrip,float& totalcost,int& totalTaxiCharges)
{
	if (rentalOrTaxi == 1) {
		totalcost += calculateTotalCost(milesDriven, typeOfCar, rentalFee, gasFee, daysOfTrip);
	}
	else {
		cout << "Enter the total Taxi charges";
		cin >> totalTaxiCharges;
		totalcost += totalTaxiCharges;
	}
}

int main(int argc, const char * argv[]) { //Command line arguments. 'argc' is argument count; it stores how many arguments that will be passed onto the main function of the program. 'argv' is argument vector' and it stores the array information. These are in this program as they are what pass the main values into the main function of the program.

	int conti = 0; //This line is for later on in the program when the user is asked whether or not they wish to use the calculator again, or quit. 'continue'

	do {

		std::cout << "Enter the number of days on your trip: ";

		int daysOfTrip;float totalcost = 0;

		cin >> daysOfTrip;

		int* parkingfee = new int[daysOfTrip];
		int* hotelFee = new int[daysOfTrip - 1]; //Minus one as hotel stays are one day shorter than a day trip. example: 3 day trip is 2 hotel nights.

		int* breaks = new int[daysOfTrip];
		int* lunch = new int[daysOfTrip];
		int* dinner = new int[daysOfTrip]; //All mealtimes coincide with the days within the trip.

		for (int i = 0; i < daysOfTrip; i++) {
			breaks[i] = 0;lunch[i] = 0;dinner[i] = 0;
		}

		int rentalOrTaxi = 0;
		float arrivalTime, deptTime, airfare, conforSemRegFee;

		getDetailsfromUser(rentalOrTaxi, totalcost, arrivalTime, deptTime, airfare, conforSemRegFee);
		
		int employeePaid = 0, typeOfCar = 0, rentalFee = 0;
		float gasFee = 0;

		if (rentalOrTaxi == 1) {

			do {

				cout << endl << "1. Sedan" << endl << "2. SUV" << endl << "3. Van" << endl << "4. Convertible" << endl;

				cin >> typeOfCar;

				if (!(typeOfCar == 1 || typeOfCar == 2 || typeOfCar == 3 || typeOfCar == 4)) cout << "Invalid input. Please try again.";

			} while (!(typeOfCar == 1 || typeOfCar == 2 || typeOfCar == 3 || typeOfCar == 4));

		}

		int milesDriven = 0, totalTaxiCharges;
		
		calculateTaxiCharges(rentalOrTaxi, milesDriven, typeOfCar, rentalFee, gasFee,
			daysOfTrip, totalcost, totalTaxiCharges);

		if (rentalOrTaxi == 1)
			//Calculate Parking Fee
			calculateFee(employeePaid, parkingfee, daysOfTrip, 10, [](int i) {cout << "Enter parking fee for day " << i << " in $";});

		//Calculate Hotel Fee
		calculateFee(employeePaid, hotelFee, daysOfTrip, 90, [](int i) {cout << "Enter hotel fee for the night " << i << " in $";});


		int noOfBreakfasts = daysOfTrip, noOfLunches = daysOfTrip, noOfDinners = daysOfTrip;

		CalculateExpenses(deptTime, arrivalTime, noOfBreakfasts, noOfLunches, noOfDinners, breaks,
			lunch, dinner, daysOfTrip);

		for (int i = 0; i < daysOfTrip; i++) {
			calculateEmployeePaid(i, employeePaid, breaks, lunch, dinner);
		}

		for (int i = 0; i < daysOfTrip; i++) {//adding reimbursement;

			totalcost += breaks[i] + lunch[i] + dinner[i] + hotelFee[i] + parkingfee[i];

		}

		cout << endl << "Total expenses reimbursed by company are " << totalcost << endl;

		cout << endl << "total Employee expenses are " << employeePaid << endl;

		cout << "Enter 0 to exit, or any other number to use this calculator again:";

		cin >> conti;

	} while (conti != 0);

	return 0;

}