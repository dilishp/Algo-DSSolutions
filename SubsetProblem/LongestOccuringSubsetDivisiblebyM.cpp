#include "pch.h"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>

using namespace std;

//Write a C function that implements the Liner Search algorithm instead of Binary Search.
//However, this linear search algorithm returns the indices of the longest sorted subset of numbers in
//an array of integers of size n.The longest sorted subset of numbers must satisfy three conditions.
//First, the subset consists of unique numbers(no duplicate); second, all the numbers in this subset is
//divisible by m, the minimum size of the subset is two elements.In the main method print all values
//of all the discovered longest sorted subsets.
//Notes there could be more than one longest sorted subset(e.g., two subsets that satisfy the
//	previously stated conditions).The subsets could exist in ascending or descending order.We
//	always scan the array from left to right(0 to n - 1 indices)
//	Examples, find the longest sorted subset that is divisible by 3
//	5 3 2 8 12 6 9 9 21 30
//	The longest sorted subset that is divisible by 3 is{ 9, 21, 30 }.It exists between indices[7 - 9].Note
//{ 6, 9, 9, 21, 30 } is not the longest because the value 9 exists twice.
//Examples, find the longest sorted subset that is divisible by 2
//2 6 8 0 3 12 14 20 3 5
//The longest sorted subset that is divisible by 2 are{ 2, 6, 8 } and {12, 14, 20}.The exist between
//indices[0 - 2] and [5 - 7].Note{ 6, 9, 9, 21, 30 } is not the longest because the value 9 exists twice.
//Examples, find the longest sorted subset that is divisible by 3
//19 0 13 11 2 9 17 1 3 5
//The longest sorted subset that is divisible by 2 is empty or null .
//Examples, find the longest sorted subset that is divisible by 5
//5 15 50 3 19 80 50 10 2 7
//The longest sorted subset that is divisible by 5 are{ 5, 15, 50 } and {80, 50, 10}.The exist between
//indices[0 - 2] and [5 - 7].
//
//Elements are not sorted.
int main()
{
	vector<vector<int>> vset;
	int size = 10;
	int arr[] = { 5, 15, 50, 3, 19, 80, 50, 10, 2, 7 };
	int m = 5;
	int max_size = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] && (0 == (arr[i] % m)))
		{
			std::function<bool()> func = [&]()->bool {

				if (vset[vset.size() - 1][vset[vset.size() - 1].size() - 1] != arr[i - 1])
					return false;

				if (vset[vset.size() - 1][vset[vset.size() - 1].size() - 1] == arr[i])
					return false;

				if (vset[vset.size() - 1].size() < 2)
				{
					vset[vset.size() - 1].push_back(arr[i]);
					return true;
				}
				else if ((arr[i] > vset[vset.size() - 1][vset[vset.size() - 1].size() - 1]) &&
					(vset[vset.size() - 1][vset[vset.size() - 1].size() - 1] > vset[vset.size() - 1][vset[vset.size() - 1].size() - 2]))
				{
					vset[vset.size() - 1].push_back(arr[i]);
					return true;
				}
				else if ((arr[i] < vset[vset.size() - 1][vset[vset.size() - 1].size() - 1]) &&
					(vset[vset.size() - 1][vset[vset.size() - 1].size() - 1] < vset[vset.size() - 1][vset[vset.size() - 1].size() - 2]))
				{
					vset[vset.size() - 1].push_back(arr[i]);
					return true;
				}
				else
				{
					return false;
				}
			};

			bool bIsSetFound = false;

			if(vset.size() > 0)
				bIsSetFound = func();

			if (!bIsSetFound)
			{
				if(vset.size() && (vset[vset.size() - 1].size() > max_size))
					max_size = vset[vset.size() - 1].size();
				vector<int> aSet;
				aSet.push_back(arr[i]);
				vset.push_back(aSet);
			}
		}
	}

	if (max_size && (vset[vset.size() - 1].size() > max_size))
		max_size = vset[vset.size() - 1].size();

	if (max_size > 2)
	{
		for (auto& set : vset)
		{
			if (set.size() == max_size)
			{
				cout << "{";
				for (auto& num : set)
					cout << "  " << num << "  ";
				cout << "}\n";
			}

		}
	}
	
	return 0;
}