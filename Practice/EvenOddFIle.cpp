#include "pch.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string inpFileName;
	
	while (true)
	{
		cout << "Enter the name of the input file" << endl;
		cin >> inpFileName;
		if (inpFileName.find(".txt", inpFileName.size() - 4) != string::npos)
		{
			break;
		}
		else
		{
			cout << "Only File Names ending with .txt are accepted!" << endl;
		}
	}

	ifstream fin;

	fin.open(inpFileName, ios::binary);

	if (!fin.is_open())
	{
		cout << "Failed to open the file to read:" << inpFileName<<endl;
		return 1;
	}

	int nReadWordCount = 0,nEvenWordCount = 0,nOddWordCount = 0;

	ofstream evenFile, oddFile;

	string tempinpFIle = inpFileName;

	string evenFileName = inpFileName.insert(inpFileName.length() - 4, "-even");
	inpFileName.erase(inpFileName.length() - 9, 5);
	string oddFileName = inpFileName.insert(inpFileName.length() - 4, "-odd");

	evenFile.open(evenFileName);
	oddFile.open(oddFileName);
	while (!fin.eof())
	{
		string aWord;
		fin >> aWord;
		nReadWordCount++;
		if (aWord.length() % 2 == 0)
		{
			evenFile << aWord << endl;
			nEvenWordCount++;
		}
		else
		{
			oddFile << aWord << endl;
			nOddWordCount++;
		}
	}

	cout << nReadWordCount << " words read in from " << tempinpFIle << endl;
	cout << nEvenWordCount << " words written to " << evenFileName << endl;
	cout << nOddWordCount << " words written to " << oddFileName << endl;

	return 0;

}