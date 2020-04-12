#include "pch.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

vector<int> findCoOcurrenceWordsLine(string fileName,vector<string> queryWords)
{
	ifstream fin;

	fin.open(fileName);

	if (!fin.is_open())
	{
		return {};
	}

	map<int, vector<string>> mlinenovsWords;
	int lineNo = 1;

	while (!fin.eof())
	{
		string line;
		getline(fin, line);

		stringstream lineStream(line);

		string word;

		vector<string> vlineWords;
		while (lineStream >> word)
		{
			//To remove characters such as . or ,
			word.erase(remove_if(word.begin(), word.end(), [](char ch) {
				if (ch == '.' || ch == ',')
				{
					return true;
				}
				return false;
			}),word.end());

			vlineWords.push_back(word);
		}

		mlinenovsWords[lineNo++] = vlineWords;
	}
	
	vector<int> linenos;

	for (auto& line : mlinenovsWords)
	{
		bool bFound = all_of(queryWords.begin(), queryWords.end(), [&](string word) {
			return find(line.second.begin(), line.second.end(), word) != line.second.end();
		});

		if(bFound)
			linenos.push_back(line.first);
	}

	return linenos;
}

void main()
{
	string fileName;
	cout << " \nEnter File Name : ";
	cin >> fileName;

	while (true)
	{
		cin.ignore(256, '\n');
		cout << " \nEnter space - separated words :";
		string lineofwords;
		getline(cin, lineofwords);
		stringstream stream(lineofwords);
		string word;
		vector<string> queryWOrds;
		while (stream >> word)
		{
			queryWOrds.push_back(word);
		}

		if (queryWOrds[0] == "q")
			break;

		vector<int> lineNos = findCoOcurrenceWordsLine(fileName, queryWOrds);
		cout << "\nThe co - occurance for: ";
		for (string word : queryWOrds)
		{
			cout << word << ", ";
		}
		cout << "\nlines : ";
		for (int lineno : lineNos)
		{
			cout << lineno << ", ";
		}
	}
	
}