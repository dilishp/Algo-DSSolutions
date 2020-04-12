#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

void printMinimumWindowString()
{
	string inpString = "ADOBECODEBANC";
	string matchString = "AC";

	string outWindowStr;

	map<char, int> mMatchStringMap();
	

	/*while (nWindowSize < inpString.length())
	{
		for (size_t i = 0; i <= (inpString.length() - nWindowSize); i++)
		{
			string substring = inpString.substr(i, nWindowSize);
			bMatchFound = true;

			for (size_t j = 0; j < matchString.length(); j++)
			{
				if (string::npos == substring.find(matchString[j]))
				{
					bMatchFound = false;
					break;
				}
			}

			if (bMatchFound)
			{
				outWindowStr = substring;
				break;
			}

		}
		if (bMatchFound)
		{
			break;
		}
		nWindowSize++;
	}*/


	
	cout << "Minimum Window matching substring is : " << outWindowStr;
}

int main()
{
	printMinimumWindowString();
}