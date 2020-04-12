#include "pch.h"
#include <iostream>

using namespace std;

long int calculatePower(int exponent)
{
	if (exponent == 1)
	{
		return 3;
	}
	return calculatePower( exponent - 1) * 3;
}
void main()
{
	cout << "Value : " << calculatePower(3);
}