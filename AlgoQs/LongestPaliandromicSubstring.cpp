#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isPaliandrome(string s)
{
	string temp = s;
	std::reverse(s.begin(), s.end());
	if (temp == s)
		return true;
	return false;
}

string findpaliandromesubstr(int startIndex, int endIndex, string s)
{
	if (startIndex >= endIndex)
		return  s.substr(0,1);

	string substr = s.substr(startIndex, endIndex - startIndex + 1);

	if (isPaliandrome(substr))
	{
		return substr;
	}

	string s1 = findpaliandromesubstr(startIndex + 1, endIndex, s);
	string s2 = findpaliandromesubstr(startIndex, endIndex - 1, s);

	return s1.length() > s2.length() ? s1 : s2;
}

//string longestPalindrome(string s) 
//{
//	if (1 == s.length())
//		return s;
//
//	string palSubstr = findpaliandromesubstr(0, s.length() - 1, s);
//	return palSubstr;
//}

//Approach 2
string longestPalindrome(string s)
{
	vector<string> vsuStrings;

	int startIndex = 0;
	int endIndex = s.length() - 1;


	for (size_t i = 0; i < s.length(); i++)
	{
		if (endIndex == startIndex)
			break;

		while (startIndex < endIndex)
		{
			if (s[startIndex] == s[endIndex])
			{
				string substr = s.substr(startIndex, endIndex - startIndex + 1);
				if (isPaliandrome(substr))
				{
					vsuStrings.push_back(substr);
					break;
				}
			}
			startIndex++;
		}
		startIndex = 0;
		endIndex--;
	}

	if (0 == vsuStrings.size())
		return s.substr(0,1);

	auto itr = std::max_element(vsuStrings.begin(), vsuStrings.end(), [&](string aString1,string aString2)->bool {
		return aString1.length() < aString2.length();
	});


	return *itr;
}

int main()
{
	string p = longestPalindrome("ba");
	return 0;
}

