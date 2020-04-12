#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include <numeric>
#include <sstream>

using namespace std;

int main(int argc,char** argv)
{
	ifstream inputfile;
	inputfile.open("rawSalesData.txt");
	if (!inputfile.is_open())
	{
		cout << "Input File Cannot be opened";
		return 0;
	}

	int noofSalesPerson;
	inputfile >> noofSalesPerson;

	vector<string> salePersonNames;
	vector<int> weeks;
	vector<vector<double>> salesData;


	for (size_t i = 0; i < noofSalesPerson; i++)
	{
		string lastName, firstName;
		inputfile >> lastName >> firstName;
		salePersonNames.push_back(lastName);

		int noofweeks;
		inputfile >> noofweeks;
		weeks.push_back(noofweeks);

		inputfile.ignore();

		for (size_t i = 0; i < noofweeks; i++)
		{
			vector<double> weekSalesData;
			string weekSales;
			if (getline(inputfile, weekSales))
			{
				stringstream mystream(weekSales);
				double saleData;
				while (mystream >> saleData)
				{
					weekSalesData.push_back(saleData);
				}
			}
			salesData.push_back(weekSalesData);
		}

	}

	ofstream fout;
	fout.open("salesSummary.txt");
	if (!fout.is_open())
	{
		cout << "Cannot create output file";
		return 0;
	}

	fout << "No of Sales People that were Processed : " << noofSalesPerson << "\n";
	fout << "No of Weeks of Sales that were processed : " << accumulate(weeks.begin(), weeks.end(), 0)<<"\n";

	for (size_t i = 0; i < noofSalesPerson; i++)
	{
		fout << "Last Name : " << salePersonNames[i]<<"\n";
		double grandtotal = 0.0;
		for (size_t i = 0; i < weeks[i]; i++)
		{
			double total = accumulate(salesData[i].begin(), salesData[i].end(), 0.00);
			grandtotal += total;
			double avg = (total / 7);
			fout << "Total for Week " << i << " is: " << total<<"\n";
			fout << "Average for week " << i << " is: " << avg<<"\n";
		}

		fout << "Grand Total : " << grandtotal<<"\n";
		fout << "Grand Total Average : " << (double)(grandtotal / 7)<<"\n\n\n";
	}
	return 0;
}