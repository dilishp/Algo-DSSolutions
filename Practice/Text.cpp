#include "pch.h"
#include<iostream>
#include <string>
#include <fstream>
#include "Text.h"

using namespace std;

//No need to define the class Text again as it is being already defined in the header file.

//Default constructor that initializes all 4 counters to 0.
Text::Text()
{
	charCount = 0;
	upperCasecount = 0;
	lowerCaseCount = 0;
	digitCount = 0;
}

//Setter Function that reads the argument file and updates the upperCasecount, lowerCaseCount, and digitCount variables during each iteration of the loop
void Text::updateCounters(string fname)
{
	ifstream inputFile;
	inputFile.open(fname);

	if (!inputFile)
	{
		cout << "Error opening file. Make sure the spelling of the filename matches the spelling of the actual file." << endl;
		cout << "Or It may not exist where indicated" << endl;
		system("pause");
	}

	while (!inputFile.eof())
	{
		//Read each line of the file into a string variable called line
		getline(inputFile, line);
		//Get the total number of characters in the line variable using string.length() method and that count to the charCount variable
		charCount = charCount + line.length();

		//Now read each character of the line and store it in the ch variable 
		//Earlier we were reading the character from file 
		//inputFile >> ch which is wrong
		for (size_t i = 0; i < line.length(); i++)
		{
			ch = line[i];

			//if the character being read is upper case, lower case or a digit, then increment the corresponding counter variables
			if (isupper(ch))
				upperCasecount = upperCasecount + 1;
			if (islower(ch))
				lowerCaseCount = lowerCaseCount + 1;
			if (isdigit(ch))
				digitCount = digitCount + 1;
		}
	}
	inputFile.close();
}

//Getter function that displays the values stored in all 3 counters
void Text::displayCounters() const
{
	cout << "Total Character count: " << charCount << endl << endl;
	cout << "Uppercase characters: " << upperCasecount << endl;
	cout << "Lowercase characters: " << lowerCaseCount << endl;
	cout << "Digits: " << digitCount << endl << endl;
}
