#include "pch.h"
#include <iostream>

using namespace std;

void guessWord(char guessedLetter, char* originalWord)
{
	if (!originalWord)
	{
		return;
	}
	static char* partialArray = new char[strlen(originalWord) + 1];
	size_t i = 0;
	for (i = 0; i < strlen(originalWord); i++)
	{
		if (guessedLetter == originalWord[i])
		{
			partialArray[i] = guessedLetter;
		}
		else
		{
			partialArray[i] = '*';
		}
	}
	partialArray[i] = '\0';
}

void main()
{
	char originalWord[] = "Programming";

	guessWord('g', originalWord);
}