#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

void main()
{
	std::ifstream fin;
	fin.open("Elevation.txt");
	if (!fin.is_open())
	{
		return;
	}
	std::string DateTitle, EastStorage, EastElevation, WestStorage, WestElevation;
	fin>> DateTitle>>EastStorage>>EastElevation>> WestStorage>> WestElevation;
	std::vector<std::pair<std::string, float>> vDateElevation;
	while (!fin.eof())
	{
		std::string date;
		float fEastStorage, eastElevation, westStorage, westElevation;
		fin >> date >> fEastStorage >> eastElevation >> westStorage >> westElevation;
		vDateElevation.push_back(std::make_pair(date, westElevation));
	}
	std::string earlierDate, laterDate;
	std::cout << "Enter Earlier Date :";
	std::cin >> earlierDate;
	std::cout << "Enter later Date";
	std::cin >> laterDate;

	auto itr = std::find_if(vDateElevation.begin(), vDateElevation.end(), [&](std::pair<std::string,float> pairDateElevation) {
		return pairDateElevation.first == laterDate;
	});
	if (itr != vDateElevation.end())
	{
		for (;itr != vDateElevation.begin();itr--)
		{
			if (itr->first == earlierDate)
			{
				std::cout << itr->first << "   " << itr->second << std::endl;
				break;
			}
			std::cout << itr->first <<"   "<<itr->second<<std::endl;
		}
	}
}