#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string sentence,searchsentence;

	cout << "Please Enter in a sentence : ";
	getline(cin, sentence);
	cout << "\n";
	cin.ignore(3, '\n');
	cout << "Please Enter in a search sentence : ";
	cin >> searchsentence;
	cout << "\n";
	int count = 0;
	int offset = 0;
	while (true)
	{
		if(count > 0)
			offset = sentence.find(searchsentence,(offset + searchsentence.length()));
		else
			offset = sentence.find(searchsentence);

		if (offset < 0)
			break;
		count++;
	}
	

	cout << "Found Search "<<searchsentence <<"  "<<  count  <<" Times in the sentence";


}
