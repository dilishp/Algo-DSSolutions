#include "pch.h"
#include <iostream>

using namespace std;

template<typename T>
bool isEven(T num)
{
	if (num % 2 == 0)
		return true;
}

void add(int a, int b)
{
	cout << a + b;
}

typedef void(*sample)(int a, int b);

void main()
{
	sample s = add;
	s(2, 3);
	
	/*int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int min = arr[0];
	int max = arr[0];
	int length = sizeof(arr) / sizeof(arr[0]);

	for (size_t i = 0; i < length; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}

		if (arr[i] > max)
		{
			max = arr[i];
		}
	}*/

	cout << isEven<int>(4);

	/*cout << "\nMin :" << min;
	cout << "\nMax :" << max;*/


}