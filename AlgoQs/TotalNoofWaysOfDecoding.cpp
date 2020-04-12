#include "pch.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace  std;

//Recursive approach
int numDecodings(string s)
{
	if (s.length() == 0)
	{
		return 1;
	}

	int oneDigit;
	stringstream ss1(s.substr(0, 1));
	ss1 >> oneDigit;
	int twoDigit;
	stringstream ss2(s.substr(0, 2));
	ss2 >> twoDigit;

	if (oneDigit > 0 && twoDigit >= 10 && twoDigit <= 26)
	{
		return (numDecodings(s.substr(1, s.length() - 1)) +
			numDecodings(s.substr(2, s.length() - 2)));
	}

	else if (oneDigit > 0)
	{
		return numDecodings(s.substr(1, s.length() - 1));
	}

	else
	{
		return 0;
	}
}

//Bottom-Up Approach
int numDecodingsdp(string s)
{
	vector<int> dp(s.length() + 1, 0);

	dp[0] = 1;
	dp[1] = s[0] == '0' ? 0 : 1;

	for (int i = 2;i < s.length();i++)
	{
		int oneDigit;
		stringstream ss1(s.substr(i, 1));
		ss1 >> oneDigit;
		int twoDigit;
		stringstream ss2(s.substr(i - 1, 2));
		ss2 >> twoDigit;

		if (oneDigit > 0)
			dp[i] += dp[i - 1];

		if (twoDigit >= 10 && twoDigit <= 26)
			dp[i] += dp[i - 2];
	}

	return dp[s.length() - 1];
}

int main()
{
	numDecodingsdp("123");
}