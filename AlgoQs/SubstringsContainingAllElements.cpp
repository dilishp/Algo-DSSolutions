#include "pch.h"
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

long analyzeInvestments(string investment)
{
	unordered_map<char,int> mapofInvestment;
	int left = 0, right = 0;
	int count = 0;
	while (left < investment.size() && right <= investment.size())
	{
		if (mapofInvestment.find('A') != mapofInvestment.end() &&
			mapofInvestment.find('B') != mapofInvestment.end() &&
			mapofInvestment.find('C') != mapofInvestment.end())
		{
			//Check whether the Three Investments are present then increment left pointer to find further substrings
			++count;
			unordered_map<char,int>::iterator itr = mapofInvestment.find(investment[left]);
			if (itr->second > 1)
				itr->second--;
			else
				mapofInvestment.erase(investment[left]);
			++left;
			continue;
		}
		else
		{
			while (left > 0)
			{
				left--;
				mapofInvestment[investment[left]]++;
			}
		}
		if (right == investment.length())
			break;
		mapofInvestment[investment[right]]++;
		++right;
	}

	return count;
}

int main()
{
	cout<<"\n No of Investments : "<< analyzeInvestments("ABBCAB");
}