#include "pch.h"
#include <iostream>
#include <string>
#include <array>
#include <iomanip>

using namespace std;

void main()
{
	std::array<string,4> cropName;
	int acres = 1000;
	std::array<double, 4> cost, yield, priceperbushel, increasedata;
	double MinimumGrossProfit[4], MaximumGrossProfit[4];
	for (size_t cnt = 0; cnt < 4;cnt++)
	{
		char cropN[15];
		cout << "Enter the crop name :";
		cin.getline(cropN,sizeof(cropN));
		cropName[cnt] = cropN;
		cout << endl;
		cout << "Enter cost, yield, price per bushel, and increase data :";
		cin >> cost[cnt] >> yield[cnt] >> priceperbushel[cnt] >> increasedata[cnt];
		cout << endl;
		MinimumGrossProfit[cnt] = (yield[cnt] * priceperbushel[cnt] * acres) - (acres * cost[cnt]);
		MaximumGrossProfit[cnt] = (MinimumGrossProfit[cnt] + (MinimumGrossProfit[cnt] * (increasedata[cnt] / 100)));
		cin.ignore();
	}
	cout << "Crop    Minimum Profit   Maximum Profit    Average Profit" << endl;
	std::array<double,4> avgprofit;
	for (size_t cnt = 0;cnt < 4;cnt++)
	{
		avgprofit[cnt] = (MinimumGrossProfit[cnt] + MaximumGrossProfit[cnt]) / 2;
		cout << cropName[cnt] << setw(10) << MinimumGrossProfit[cnt] << setw(10) << MaximumGrossProfit[cnt] << setw(10) << avgprofit[cnt] <<endl;
	}
	auto itr = std::max_element(avgprofit.begin(), avgprofit.end());
	int index = std::distance(avgprofit.begin(), itr);
	cout << "Old MacDonald, you should plant : " << cropName[index];
}