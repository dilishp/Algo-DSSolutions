#include "pch.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

string isGuessCorrect(string receivedmsg, string guessesMsg)
{
	unordered_map<char, int> rcvmsgmap, guessesMsgMap;

	for (char ch : receivedmsg)
	{
		if (ch != ' ')
		{
			rcvmsgmap[toupper(ch)]++;
		}
	}

	for (char ch : guessesMsg)
	{
		if (ch != ' ')
			guessesMsgMap[toupper(ch)]++;
	}

	for (std::pair<char, int> aPair : guessesMsgMap)
	{
		auto itr = rcvmsgmap.find(aPair.first);

		if (rcvmsgmap.end() != itr && itr->second >= aPair.second)
		{
			continue;
		}

		return "NO";
	}

	return "YES";
}

int findmaxSum(vector<int>& v, int size)
{
	int l = 0;
	int r = l + 1;

	int maxsum = 0;

	while (l < r && l < size && r < size)
	{
		int sum = abs(v[l] - v[r]) + abs(l - r);
		if (sum >= maxsum)
		{
			maxsum = sum;
			++r;
		}
		else
		{
			++l;
		}
	}

	return maxsum;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	//int noofTestCases;
	//cin >> noofTestCases;
	//int weight;
	//for (size_t i = 0; i < noofTestCases; i++)
	//{
	//	vector<int> v;
	//	int size;
	//	cin >> size;
	//	for (size_t i = 0; i < size; i++)
	//	{
	//		int num;
	//		cin >> num;
	//		v.push_back(num);
	//	}
	//	weight = findmaxSum(v, size);
	//	cout << "\n" << weight;
	//}

	//std::string s;
	
	isGuessCorrect("cherry@@@ is love, pondi!!!!","Pondicherry is love");

	return 0;
}