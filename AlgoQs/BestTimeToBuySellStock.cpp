#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(int k, vector<int>& prices)
{
	int buyDay = 0;
	int sellDay = 0;
	int transactionCount = 0;

	for (int i = 1;i < prices.size();i++)
	{
		if (prices[i] < prices[buyDay])
		{

			buyDay = i;
		}
		else if (prices[i] > prices[sellDay])
		{
			sellDay = i;
		}
	}
}