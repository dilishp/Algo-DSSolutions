#include "pch.h"
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int computeWeight(int size)
{
	int count = 1;
	int weight = 0;
	while (size > 0)
	{
		weight += size * count;
		++count;
		--size;
	}
	return weight;
}

int findWeightofUniqueSubaaraysv2(int* arr, int size)
{
	int i = 0;
	int j = 0;
	set<int> aSet;
	bool bwhethertoEvaluate = true;
	int weight = 0;
	int initialsize = 0;
	int erasedElements = 0;

	while (i < size && j < size)
	{
		if (aSet.find(arr[j]) == aSet.end())
		{
			if (!bwhethertoEvaluate)
			{
				int duplicate = aSet.size();
				weight -= computeWeight(duplicate);
			}
			bwhethertoEvaluate = true;
			aSet.insert(arr[j]);
			++j;
		}
		else
		{
			if (bwhethertoEvaluate)
			{
				weight += computeWeight(aSet.size());
				bwhethertoEvaluate = false;
			}
			aSet.erase(aSet.begin());
			++i;
		}
	}

	weight += computeWeight(aSet.size());

	return weight;
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int noofTestCases;
	cin >> noofTestCases;
	int weight;
	for (size_t i = 0; i < noofTestCases; i++)
	{
		int* arr;
		int size;
		cin >> size;
		arr = new int[size];
		for (size_t i = 0; i < size; i++)
		{
			cin >> arr[i];
		}
		weight = findWeightofUniqueSubaaraysv2(arr, size);
		cout <<"\n"<< weight;
		delete[] arr;
		arr = nullptr;
	}
	return 0;
}