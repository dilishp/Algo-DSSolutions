#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Function to write the encrypted string to the file
void writeEncrptedString(vector<string> encrytedString)
{
	ofstream fout;

	fout.open("encrpted.txt");

	if (!fout.is_open())
		return;

	for (string str : encrytedString)
	{
		fout << str << " ";
	}
}

//Function to decrpt the string to verify
void decrypt(vector<string> encrptedString, int rotatekey)
{
	vector<string> decryptedstring;

	for (string aString : encrptedString)
	{
		std::transform(aString.begin(), aString.end(), aString.begin(), [&](unsigned char aChar)->unsigned char {
			if (isalpha(aChar))
			{
				if (isupper(aChar))
				{
					int tempchar = ((aChar - rotatekey) - 65);
					if (tempchar < 0)
					{
						return (unsigned char)(91 - abs(tempchar));
					}
					else
						return (unsigned char)(tempchar + 65);
				}
				int tempchar = ((aChar - rotatekey) - 97);
				if (tempchar < 0)
				{
					return (unsigned char)(123 - abs(tempchar));
				}
				else
					return (unsigned char)(tempchar + 97);
			}
			return aChar;
			});
		decryptedstring.push_back(aString);
	}

	cout << "Decrpted String is : \n";

	for (string str : decryptedstring)
	{
		cout << str << " ";
	}
}

//Reads the original Text from the File
vector<string> getOriginalText()
{
	ifstream fin;

	fin.open("OriginalText.txt");
	
	if (!fin.is_open())
		return { "" };

	vector<string> textIn;

	string text;

	while (fin >> text)
	{
		textIn.push_back(text);
	}

	return textIn;
}
//function which encypts the string and returns it
void encrypt(vector<string>& text_in,string key)
{
	int ascii_sum = 0;

	for (char ch : key)
	{
		int ascii = (int)ch;
		ascii_sum += ascii;
	}

	int rotatekey = (ascii_sum % 23) + 3;

	vector<string> encryptedstring;

	for (string aString : text_in)
	{
		std::transform(aString.begin(), aString.end(), aString.begin(), [&](unsigned char aChar)->unsigned char {
			if (isalpha(aChar))
			{
				if(isupper(aChar))
					return (unsigned char)((((aChar + rotatekey) - 65) % 26) + 65);
				return (unsigned char)((((aChar + rotatekey) - 97) % 26) + 97);
			}
			return aChar;
			});
		encryptedstring.push_back(aString);
	}

	writeEncrptedString(encryptedstring);
	decrypt(encryptedstring, rotatekey);
}



int main()
{
	vector<string> orgText = getOriginalText();
	string key = "deF";
	encrypt(orgText, key);
}