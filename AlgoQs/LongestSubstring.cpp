// AlgoQs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring(string s)
{
	int i = 0, j = 0;
	int n = s.size();
	set<char> vSet;
	int maxsize = 0;


	while (i < n && j < n)
	{
		if (vSet.find(s[j]) == vSet.end())
		{
			vSet.insert(s[j++]);
			maxsize = max(maxsize, j - i);
		}
		else
		{
			vSet.erase(s[i++]);
		}
	}

	return maxsize;
}

int main()
{
	int l = lengthOfLongestSubstring("pwwkew");
	return 0;
}

