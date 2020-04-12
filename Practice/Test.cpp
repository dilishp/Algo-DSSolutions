#include "pch.h"
#include <iostream>

void main()
{
	char* arr;
	arr = new char[20]{"hello"};
	arr =(char*) realloc(arr, 30);
	delete[] arr;
}