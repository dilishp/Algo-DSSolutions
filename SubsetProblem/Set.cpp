#include "pch.h"
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

template<typename ELEMENT_TYPE>
class Set
{
public:
	Set();
	class Iterator;
	Iterator find(ELEMENT_TYPE) const;
	Iterator begin() const;
	Iterator end() const;
	bool operator <= (const Set& aSet) const;
	bool operator >= (const Set& aSet) const;
	class Iterator
	{
	public:
		ELEMENT_TYPE& operator*(); //dereference
		Iterator operator++();
		Iterator operator--();
	};
};

template<typename ELEMENT_TYPE>
bool Set<ELEMENT_TYPE>::operator<=(const Set& aSet) const
{
	for (auto itr = begin();itr != end();itr++)
	{
		if (aSet.find(*itr) == aSet.end())
		{
			return false;
		}
	}
	return true;
}

template<typename ELEMENT_TYPE>
bool Set<ELEMENT_TYPE>::operator>=(const Set& aSet) const
{
	for (auto itr = aSet.begin();itr != aSet.end();itr++)
	{
		if (find(*itr) == end())
		{
			return false;
		}
	}
	return true;
}

bool isWordMatchConstraint(string word)
{
	if (word.length() != 7)
		return false;

	auto itr = std::find_if(word.begin(),word.end(),[&](char ch)->bool{
		return !isalpha(ch);
	});

	if (itr != word.end())
		return false;

	return true;
}

bool isWordExistsinmap(string word, map<vector<int>, string>& stringmap)
{
	auto itr = std::find_if(stringmap.begin(), stringmap.end(), [&](pair<vector<int>,string> aPair) {
		return aPair.second == word;
	});

	if (itr != stringmap.end())
		return true;

	return false;
}
void main()
{
	string word;
	cout << "Enter the word";
	map<int, vector<char>> lookupmap = {
		{2,{'A','B','C'}},
		{3,{'D','E','F'}},
		{4,{'G','H','I'}},
		{5,{'J','K','L'}},
		{6,{'M','N','O'}},
		{7,{'P','Q','R','S'}},
		{8,{'T','U','V'}},
		{9,{'W','X','Y','Z'}}
	};
	map<vector<int>, string> stringmap;
	
	while (true)
	{
		cin >> word;

		if (word == "STOP")
			break;

		if (!isWordMatchConstraint(word))
			continue;

		if (isWordExistsinmap(word, stringmap))
			continue;

		vector<int> mappednums;
		for (char& achar : word)
		{
			auto itr = std::find_if(lookupmap.begin(), lookupmap.end(), [&](pair<int, vector<char>> aPair)->bool {
				auto itr = std::find_if(aPair.second.begin(), aPair.second.end(), [&](char& ch) {
					return ch == achar;
				});
				if (itr != aPair.second.end())
					return true;
				else
					return false;
			});

			if (itr != lookupmap.end())
			{
				mappednums.push_back(itr->first);
			}
		}

		stringmap[mappednums] = word;
	}

	for (auto& pair : stringmap)
	{
		for (int num : pair.first)
			cout << num;

		cout << "   " << pair.second << "\n";
	}



}



