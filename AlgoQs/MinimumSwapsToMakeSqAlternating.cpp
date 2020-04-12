#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minNumberofSwap(string s)
{
	if (s.length() == 0)
		return 0;

	if (s.length() == 1)
		return 0;

	vector<int> v1(s.size(), 0);
	vector<int> v2(s.size(), 0);

	int i = 2;
	int firstBit = atoi(string(1, s[0]).c_str());
	int secondBit = atoi(string(1, s[1]).c_str());
	int currBitV1 = 0;
	int currBitV2 = 0;

	if(firstBit == secondBit)
	{
		//1st Way
		v1[0] = 1;
		v1[1] = v1[0];
		currBitV1 = secondBit;

		//2nd Way
		v2[0] = 0;
		v2[1] = 1;
		currBitV2 = (secondBit == 1) ? 0 : 1;
	}
	else
	{
		//1st Way
		v1[0] = 1;
		v1[1] = 2;
		currBitV1 = (secondBit == 1) ? 0 : 1;

		//2nd Way
		v2[0] = 0;
		v2[1] = 0;
		currBitV2 = secondBit;
	}
	while (i < s.length())
	{
		int bit = atoi(string(1, s[i]).c_str());

		if(bit != currBitV1)
		{
			v1[i] = v1[i - 1];
			currBitV1 = bit;
		}
		else
		{
			v1[i] = v1[i - 1] + 1;
			currBitV1 = (bit == 1) ? 0 : 1;
		}

		if(bit != currBitV2)
		{
			v2[i] = v2[i - 1];
			currBitV2 = bit;
		}
		else
		{
			v2[i] = v2[i - 1] + 1;
			currBitV2 = (bit == 1) ? 0 : 1;
		}
		i++;
	}

	return std::min(v1[s.length() - 1], v2[s.length() - 1]);
}

int main()
{
	minNumberofSwap("10111");
}