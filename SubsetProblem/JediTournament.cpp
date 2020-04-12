#include "pch.h"
#include <iostream>
#include <array>
#include <vector>

using namespace std;

void main()
{
	vector<array<int, 3>> jedi;

	int nNoofJedis;
	cout << "Enter the number of Jedi's";
	cin >> nNoofJedis;
	
	for (size_t i = 0; i < nNoofJedis; i++)
	{
		array<int, 3> indJedi;
		for (size_t j = 0; j < 3; j++)
		{
			int no;
			cin >> no;
			indJedi[j] = no;
		}
		jedi.push_back(indJedi);
	}
	
	for (size_t i = 0; i < nNoofJedis; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			
		}
	}
}