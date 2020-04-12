#include "pch.h"
#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

const int SIZE = 20;
const int FLIGHTS = 100;
// Define Structure
struct CurrentFlights {
	char carrier[SIZE + 1];           // +1 to allow for '\0' terminator
	int flightNum;
	char arrDep;
	char arrCity[SIZE + 1];           // +1 to allow for '\0' terminator
	int pubTime;
	int actTime;

	CurrentFlights()
	{

	}

	CurrentFlights(string carr, string Flight, string arrdep, string city, string pubtime, string actualTime)
	{
		strcpy_s(carrier, carr.length() + 1, carr.c_str());
		stringstream strstream(Flight);
		strstream >> flightNum;
		arrDep = arrdep[0];
		strcpy_s(arrCity, city.length() + 1, city.c_str());
		stringstream strstream1(pubtime);
		strstream >> pubTime;
		stringstream strstream2(actualTime);
		strstream >> actTime;
	}

	bool operator ==(const CurrentFlights& aFlight)
	{
		if (this->flightNum != aFlight.flightNum)
			return false;

		return true;
	}
};

void readFile(array<CurrentFlights, FLIGHTS>& arrofFlights,int& flightCount)
{
	ifstream fin;
	string fileName;

	cout << "\nEnter the File Name";
	cin >> fileName;

	fin.open(fileName);

	if (!fin.is_open())
		return;

	char buffer[120];

	fin.get(buffer, '\n');
	fin.get(buffer, '\n');

	while (!fin.eof())
	{
		string carrier, Flight, arrDep, city, pubTime, actualTime;
		fin >> carrier >> Flight >> arrDep >> city >> pubTime >> actualTime;
		fin.ignore('\n');
		arrofFlights[flightCount] = CurrentFlights(carrier, Flight, arrDep, city, pubTime, actualTime);
		flightCount++;
	}

}

void displayFlights(array<CurrentFlights, FLIGHTS>& arrofFlights)
{
	for (auto flight : arrofFlights)
	{
		cout << "\n Carrier :" << flight.carrier;
		cout << "\n Flight Number :" << flight.flightNum;
		cout << "\n Arr/Dep :" << flight.arrDep;
		cout << "\n Arrival City :" << flight.arrCity;
		cout << "\n Published Time :" << flight.pubTime;
		cout << "\n Actual Time :" << flight.actTime;
		cout << "\n\n";
	}
}

int main()
{
	std::array<CurrentFlights, FLIGHTS> arrofFlights;

	int flightCount = 0;

	readFile(arrofFlights, flightCount);

	while (true)
	{
		cout << "\n	***Menu Options*** \n";
		cout << "\n	1. Add Flight Information";
		cout << "\n	2. Delete Flight Information";
		cout << "\n3. Display All Flights";
		cout << "\n	4. Display All Arrivals or Departures";
		cout << "\n	5. Update Flight time";
		cout << "\n6. Quit";

		cout << "\n Please select an option :";
		int nChoice;
		cin >> nChoice;
		
		switch (nChoice)
		{
		case 6:
			return 0;
			break;
		case 1:
		{
			string carrier, Flight, arrDep, city, pubTime, actualTime;
			cout << "\nPlease Enter the Flight Details";
			cout << "\nCarrier : ";
			cin >> carrier;

			cout << "\nFlight No : ";
			cin >> Flight;
			cout << "\n arrDep : ";
			cin >> arrDep;
			cout << "\n city: ";
			cin >> city;
			cout << "\n pubTime : ";
			cin >> pubTime;
			cout << "\n ActTime : ";
			cin >> actualTime;

			stringstream stream(Flight);
			int flightNo;
			stream >> flightNo;

			auto itr = std::find_if(arrofFlights.begin(), arrofFlights.end(), [&](CurrentFlights& flights)->bool {
				return flights.flightNum == flightNo;
			});

			if (itr != arrofFlights.end())
			{
				cout << "\nFlight Number already Exists";
			}
			else if(flightCount < FLIGHTS)
			{
				arrofFlights[flightCount] = CurrentFlights(carrier, Flight, arrDep, city, pubTime, actualTime);
				flightCount++;
			}
			else
			{
				cout<<"\nWarning - array is full, cannot add new flight.";
			}
			
		}
		break;
		case 2:
		{
			int flightNo;
			cout << "\nEnter the Flight Number to be deleted";
			cin >> flightNo;

			auto itr = std::find_if(arrofFlights.begin(), arrofFlights.end(), [&](CurrentFlights& flights) {
				return flights.flightNum == flightNo;
			});

			if (itr == arrofFlights.end())
			{
				cout << "\n" << flightNo;
				cout << " Flight number does not exist.";
				break;
			}
			else
			{
				std::remove(arrofFlights.begin(), arrofFlights.end(), *itr);
			}
		}
		break;
		case 3:
			displayFlights(arrofFlights);
			break;
		case 4:
		{
			char ch;
			cout << "\nDisplay Arrivals or Departures(A or D)";
			cin >> ch;

			for (auto flight : arrofFlights)
			{
				if (flight.arrDep == ch)
				{
					cout << "\n Carrier :" << flight.carrier;
					cout << "\n Flight Number :" << flight.flightNum;
					cout << "\n Arr/Dep :" << flight.arrDep;
					cout << "\n Arrival City :" << flight.arrCity;
					cout << "\n Published Time :" << flight.pubTime;
					cout << "\n Actual Time :" << flight.actTime;
					cout << "\n\n";
				}
			}
		}
		break;
		case 5:
		{
			int flightNo,arrTime;
			cout << "\nPlease enter flight number to update:";
			cin >> flightNo;
			cout << "\nPlease enter new Actual Arrival time :";
			cin >> arrTime;

			auto itr = std::find_if(arrofFlights.begin(), arrofFlights.end(), [&](CurrentFlights& flights) {
				return flights.flightNum == flightNo;
			});

			if (itr == arrofFlights.end())
			{
				cout << "\n" << flightNo;
				cout << " Flight number does not exist.";
				break;
			}
			else
			{
				itr->actTime = arrTime;
			}
		}
		break;
		default:
			cout << "\nPlease choose options 1-6.";
			break;
		}
	}
	
	return 0;

}
