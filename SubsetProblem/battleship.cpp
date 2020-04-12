#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

bool battleship(vector<vector<int>>& matrix,vector<string> coordinates)
{
	bool bInvalidCoordinatesfound = false;
	for (size_t i = 0; i < matrix.size(); i++)
	{
		for (size_t j = 0; j < matrix[i].size(); j++)
		{
			if (matrix[i][j] == 1)
			{
				if (bInvalidCoordinatesfound)
					return false;

				auto itr = find_if(coordinates.begin(), coordinates.end(), [&](string aCoordinate)->bool {
					if (!bInvalidCoordinatesfound)
					{
						int row = aCoordinate[1] - '0';
						int column = (aCoordinate[0] - 'A');
						if (row > matrix.size() || (column > matrix[i].size()))
						{
							std::cout << "\n Invalid Coordinates Entered. Game Over !";
							bInvalidCoordinatesfound = true;
							return false;
						}
						return (row == (i + 1) && (column == j));
					}
					else
					{
						return false;
					}
				});

				if (itr != coordinates.end())
				{
					matrix[i][j] = 0;
				}
			}
		}
	}

	if (bInvalidCoordinatesfound)
		return false;
	else
		return true;
}

void main()
{
	ifstream fin;

	string filename;
	std::cout << "\nEnter the file name to be read : ";
	std::cin >> filename;

	fin.open(filename);

	if (!fin.is_open())
		return;

	vector<vector<int>> matrix;
	string matline;
	while (std::getline(fin, matline))
	{
		stringstream ss(matline);
		int matrixvalue;
		vector<int> rowmat;
		while (ss >> matrixvalue)
		{
			rowmat.push_back(matrixvalue);
		}
		matrix.push_back(rowmat);
	}
	

	vector<string> vCoordinates;
	string line;
	std::cin.ignore(255, '\n');
	std::cout << "\nEnter the coordinates : ";
	std::getline(std::cin, line);

	stringstream ssccoordinates(line);

	string coordinates;

	while (ssccoordinates >> coordinates)
	{
		vCoordinates.push_back(coordinates);
	}

	bool result = battleship(matrix, vCoordinates);
	int count = 0;
	for (auto row : matrix)
	{
		count += count_if(row.begin(), row.end(), [](int& element)->bool {
			return (element == 1);
		});
	}

	if (result && (0 == count))
	{
		std::cout << "\nYou Won the battle";
	}
	else if(0 != count && result)
	{
		std::cout << "\n " << count << " Targets remaining. You Lost !";
	}

}