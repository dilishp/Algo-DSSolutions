// SubsetProblem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <algorithm>
#include <numeric>


void square(int number,std::promise<int>& valuePromise)
{
	valuePromise.set_value(pow(number, 2));
}

int main()
{

	std::vector<std::future<int>> valueFuture;

	std::vector<std::thread> t;

	for (size_t i = 0; i < 20; i++)
	{
		std::promise<int> valuePromise;
		valueFuture.push_back(valuePromise.get_future());
		t.push_back(std::thread(square, i, std::ref(valuePromise)));
	}

	std::vector<int> values;

	std::transform(valueFuture.begin(), valueFuture.end(), std::back_inserter(values), [](std::future<int>& ft) {
		return ft.get();
	});

	int sum = std::accumulate(values.begin(), values.end(), 0);

	for (size_t i = 0; i < 20; i++)
	{
		t[i].join();
	}
	    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
