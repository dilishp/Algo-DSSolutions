#include "pch.h"
#include <vector>
#include <algorithm>
#include <string>
#include <set>

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

std::string MinWindow(string s, string t) {
    if (s.length() == 0)
        return "";

    if (s == t)
        return s;

    string temp = s;

    std::multiset<char> sset;
    std::multiset<char> tset;

    for (char c : t)
    {
        tset.insert(c);
    }

    for (int i = 0;i < s.length();++i)
    {
        if (tset.find(s[i]) == tset.end())
        {
            s[i] = '-';
        }
    }

    int i = 0, j = 1;
    string maxString = "";
    int minLen = INT_MAX;
	bool isFirst = true;
    while (i <= j && j < s.length())
    {
        if (!isalpha(s[i]))
        {
            ++i;
            continue;
        }
        else if(isFirst)
        {
            sset.insert(s[i]);
            isFirst = false;
        }


        if (!isalpha(s[j]))
        {
            ++j;
            continue;
        }
        else
        {
            sset.insert(s[j]);
        }

       

        if (std::includes(sset.begin(), sset.end(),
            tset.begin(), tset.end()) &&
            (j - i + 1) < minLen)
        {
            minLen = (j - i) + 1;
            maxString = temp.substr(i, minLen);
            sset.erase(s[i]);
            ++i;
        }

        if (!std::includes(sset.begin(), sset.end(),
            tset.begin(), tset.end()) && isalpha(s[i]))
        {
            ++j;
        }
    }

    return maxString;
}

int main()
{
	MinWindow("ADOBECODEBANC",
		"ABC");
}
