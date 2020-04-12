#include "pch.h"
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

std::string minWindow(string s, string t) {
	if (s.length() == 0)
		return "";

	int i = 0, j = t.length() - 1;

	vector<pair<char, bool>> vLookUp;

	for (char c : t)
	{
		vLookUp.push_back(std::pair<char, bool>(c, false));
	}

	int minLength = INT_MAX;
	string minString;

	while (j < s.length() && i <= j)
	{
		string subStr = s.substr(i, ((j - i) + 1));
		string temp = subStr;

		for (pair<char,bool>& p : vLookUp)
		{
			p.second = false;
		}

		for (pair<char, bool>& p : vLookUp)
		{
			size_t pos = temp.find(p.first);
			if(pos != string::npos)
			{
				p.second = true;
				temp.erase(temp.begin() + pos);
			}
		}

		bool b = std::all_of(vLookUp.begin(), vLookUp.end(), [&](std::pair<char, bool> aPair)
		{
			return aPair.second == true;
		});

		if (b)
		{
			int length = subStr.length();
			if (length < minLength)
			{
				minString = subStr;
				minLength = length;
			}
			i++;
		}
		else
		{
			j++;
		}
	}

	return minString;
}

int main()
{
	minWindow("bbaa",
		"aba");
}
