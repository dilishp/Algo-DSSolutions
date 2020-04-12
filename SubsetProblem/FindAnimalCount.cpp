#include "pch.h"
#include <iostream>
#include <vector>

int calculate_animal_x(int initial, int m)
{
	int month = 1;
	std::vector<int> vmonthAnimalCount(m + 1);
	vmonthAnimalCount[month - 1] = initial;

	while (month <= m)
	{
		if (0 == month % 2)
		{
			if ((month - 6) >= 0 && vmonthAnimalCount[month - 6] > 0)
			{
				--vmonthAnimalCount[month - 1];
			}
			vmonthAnimalCount[month] = (vmonthAnimalCount[month - 1] * 2) + vmonthAnimalCount[month - 1];
		}
		else
		{
			if ((month - 3) >= 0)
			{
				--vmonthAnimalCount[month - 3];
				vmonthAnimalCount[month] = vmonthAnimalCount[month - 1] - 1;
			}
			else
			{
				vmonthAnimalCount[month] = (vmonthAnimalCount[month - 1]);
			}
		}
		++month;
	}

	return vmonthAnimalCount[m];

}

int main()
{
	int animalCount = calculate_animal_x(1, 9);

	return 0;
}