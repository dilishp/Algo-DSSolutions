#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Text.h"

using namespace std;

int main()
{
	//Create an object of the type Text
	Text textobj;

	//Call the setter function that counts all the upper case, lower case digit characters in the file
	//File name given is input.txt which is present in the same folder as the cpp file.
	textobj.updateCounters("input.txt");

	//Call the Getter function that displays ll the upper case, lower case digit characters in the file
	textobj.displayCounters();

	system("pause");
	return 0;
}