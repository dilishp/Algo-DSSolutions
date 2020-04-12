#include "pch.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void main()
{
	string NAME[10];
	float GRADES[10][10] = { 0.0 };
	char LG[10];

	ifstream fin;
	fin.open("Students.txt");
	if (!fin.is_open())
	{
		return;
	}

	string line;
	int nindex = 0;

	while (getline(fin,line))
	{
		stringstream stream(line);

		stream >> NAME[nindex];

		float marks;
		int gradeIndex = 0;
		while (stream >> marks)
		{
			if (marks == 0)
			{
				LG[nindex] = 'W';
			}
			GRADES[nindex][gradeIndex] = marks;
			gradeIndex++;
		}
		if (gradeIndex < 10)
		{
			LG[nindex] = 'W';
		}
		nindex++;
	}

	//Calculating the letter grades
	for (size_t i = 0; i < 10; i++)
	{
		if (LG[i] == 'W')
			continue;
		float sum = 0.0;
		for (size_t j = 0; j < 10; j++)
		{
			sum += GRADES[i][j];
		}
		float avg = sum / 10;
		if (avg > 70)
		{
			LG[i] = 'G';
		}
		else if (avg < 70 && avg >= 50)
		{
			LG[i] = 'F';
		}
		else if (avg < 50)
		{
			LG[i] = 'P';
		}
	}

	//Display
	cout << setw(10) << "Name" << setw(70) << "Grades" << setw(40) << "Letter Grade"<<endl;

	for (size_t i = 0; i < 10; i++)
	{
		cout << setw(10) << NAME[i];
		for (size_t j = 0; j < 10; j++)
		{
			cout << setw(10) << GRADES[i][j];
		}
		cout << setw(10) << LG[i] << endl;
	}
}