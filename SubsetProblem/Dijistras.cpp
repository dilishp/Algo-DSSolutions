#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <iomanip>
#include <math.h>
#include <fstream>
#include <map>

using namespace std;

const int MAX = 100000;

int numPrimes[MAX + 1] = { 0 };

void buildPrefix()
{
	bool lookup[MAX + 1];

	memset(lookup, true, sizeof(lookup));

	for (int i = 2;(i * i) <= MAX;i++)
	{
		if (lookup[i] == true)
		{
			for (int j = i * 2;j <= MAX;j += i)
			{
				lookup[j] = false;
			}
		}
	}


	for (int i = 2;i <= MAX;i++)
	{
		numPrimes[i] = numPrimes[i - 1];
		if (lookup[i] == true)
			numPrimes[i]++;
	}
}

int getPrimeCount(int& l, int& r)
{
	return numPrimes[r] - numPrimes[l - 1];
}

//int main()
//{
//	buildPrefix();
//	int testCases;
//	cin >> testCases;
//
//	for (int i = 0;i < testCases;i++)
//	{
//		int l, r;
//		cin >> l >> r;
//		int primeCount = getPrimeCount(l, r);
//		
//		cout << primeCount * (((r - l) + 1) - primeCount) << "\n";
//	}
//
//	return 0;
//}
long long getFactor(int num)
{
	if (num == 0) return 1;
	return getFactor(num - 1) * num;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(false);
	vector<int> varr;
	int n, m, noofWays = 0;
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		int num;
		cin >> num;
		varr.push_back(num);
	}

	vector<int> comparator(m, 0);
	std::copy(varr.begin(), varr.begin() + m, comparator.begin());

	for (int i = m; i < varr.size(); ++i)
	{
		int j = i % m;
		if (varr[i] == 0)
			continue;
		else if (varr[i] != 0 && comparator[j] != 0)
			if (varr[i] != comparator[j]) { noofWays = -1; break; }
			else if (varr[i] != 0 && comparator[j] == 0)
				comparator[j] = varr[i];
	}

	if (noofWays != -1)
		noofWays = std::count_if(comparator.begin(), comparator.end(), [](int& x) {return x == 0;});

	cout << "\n" << getFactor(noofWays) % 1000000007;
	return 0;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(false);
	vector<int> varr;
	int n,m;
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		int num;
		cin >> num;
		varr.push_back(num);
	}

	map<int, int> mOccurence;
	long long noofWays = 1;
	int nCount = 0;
	int nblockCount = 1;
	bool bisarrPossible = true;

	for (size_t i = 0; i < n; i++)
	{
		
		if((i + (nblockCount * m) < n) && varr[i] && varr[i + (nblockCount * m)] && (varr[i] != varr[i + (nblockCount * m)]) )
		{
			bisarrPossible = false;
			noofWays = -1;
			break;
		}
		if (0 == i % m)
		{
			if (i)
				nblockCount++;

			mOccurence.clear();
			for (int j = (nblockCount - 1) * m;j < (nblockCount * m);j++)
			{
				if (varr[j])
				{
					mOccurence[varr[j]]++;
				}
			}
			bool searchRes = std::any_of(mOccurence.begin(), mOccurence.end(), [](std::pair<int,int> aPair)->bool {
				return (aPair.second > 1);
			});
			if (searchRes)
			{
				bisarrPossible = false;
				noofWays = -1;
				break;
			}
		}
	}


	if (bisarrPossible)
	{
		vector<long long> vNoofWays;

		int nonZeroCount = std::count_if(varr.begin(), varr.begin() + m, [](int& aNumber)->bool {
			return (aNumber != 0);
		});

		for (size_t i = m; i < n; i++)
		{
			if ((i + m) < n && 0 == varr[i%m] && varr[i])
			{
				varr[i%m] = varr[i];
				nonZeroCount++;
			}
		}

		for (size_t i = 0; i < m; i++)
		{
			if (0 == varr[i])
			{
				if ((m - (nonZeroCount)) > 1)
				{
					vNoofWays.push_back((m - (nonZeroCount)));
				}
				nonZeroCount++;
			}
		}
		
		for (size_t i = 0; i < vNoofWays.size(); i++)
		{
			noofWays *= vNoofWays[i];
			noofWays = (noofWays % 1000000007);
		}
	}
	

	cout << "\n" << noofWays;
	return 0;
}