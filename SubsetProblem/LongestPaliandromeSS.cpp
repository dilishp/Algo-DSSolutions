#include "pch.h"
#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int longestPaliandrome(string inpustString,
	int startIndex, int endIndex,
	unordered_map<string, int>& mapofKeyvsPalLenght)
{
	if (startIndex > endIndex)
		return 0;

	if (startIndex == endIndex)
		return 1;

	string key = to_string(startIndex) + "|" + to_string(endIndex);

	if (mapofKeyvsPalLenght.find(key) == mapofKeyvsPalLenght.end())
	{
		if (inpustString[startIndex] == inpustString[endIndex])
			mapofKeyvsPalLenght[key] = longestPaliandrome(inpustString,
				startIndex + 1,
				endIndex - 1,
				mapofKeyvsPalLenght) + 2;

		else
			mapofKeyvsPalLenght[key] = max(longestPaliandrome(inpustString,
				startIndex + 1,
				endIndex,
				mapofKeyvsPalLenght),
				longestPaliandrome(inpustString,
					startIndex,
					endIndex - 1,
					mapofKeyvsPalLenght));

	}

	return mapofKeyvsPalLenght[key];
}