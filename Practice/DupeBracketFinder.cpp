#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isRedundantBracketPresent(string str)
{
	vector<char> expressionVector;

	vector<char> vParanthesis = { '(' };

	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
			continue;

		expressionVector.push_back(str[i]);

		if (str[i] == ')')
		{
			auto startitr = find_end(expressionVector.begin(), expressionVector.end(),
				vParanthesis.begin(), vParanthesis.end(), [](char a, char b) {return a == b;});
			int nDistance = distance(startitr, expressionVector.end());
			if (2 == nDistance)
			{
				return true;
			}
			else
			{
				expressionVector.erase(startitr, expressionVector.end());
			}
		}

	}
	return false;
}

int main()
{
	string str = "((a + b) + ())";

	bool bresult = isRedundantBracketPresent(str);
}