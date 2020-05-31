#include "pch.h"
#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

class CIS14
{
public:
	bool isInputInDictionary(string* s, unordered_set<string>& dict);
private:
	bool isWordInDictionary(string word, unordered_set<string>& dict);
};

bool CIS14::isInputInDictionary(string* s, unordered_set<string>& dict)
{
	//Exit condition of recursion
	if (s->size() == 0)
		return true;

	for (int i = 1; i <= s->size(); i++)
	{
		//Split the given string into substrings
		//And check if the first part of the substring contains in the dictionary
		//and the remaining portion can be some how split so that it is part of the dictionary
		if (isWordInDictionary(s->substr(0, i), dict) &&
			isInputInDictionary((&s->substr(i, s->size() - i)), dict))
			return true;
	}
	return false;
}
bool CIS14::isWordInDictionary(string word, unordered_set<string>& dict)
{
	//Check if a given word is part of the dictionary or not
	return (dict.find(word) != dict.end());
}