#include "pch.h"
#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;

class CIS14 {
public:
	bool isInputInDictionary(string* s, unordered_set<string> &dict);
};

bool CIS14::isInputInDictionary(string* str, unordered_set<string>& dict)
{
	if (str == nullptr)
		return false;

	if (dict.find(*str) != dict.end())
	{
		return true;
	}

	for (size_t i = 0; i < str->length(); i++)
	{
		if (isInputInDictionary(&str->substr(0,i),dict) && isInputInDictionary(&str->substr(i,str->length()-i),dict) )
		{
			return true;
		}
	}

	return false;

}

void main()
{
	unordered_set<string> dict = { "hell", "on", "owl" };
	string str = "hellonowl";
	bool bFound = CIS14().isInputInDictionary(&str,dict );
	cout << std::boolalpha << bFound;
}