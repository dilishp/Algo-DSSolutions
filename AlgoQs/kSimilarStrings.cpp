#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int kSimilarity(string A, string B) 
{
	int swapCount = 0;

	for (size_t i = 0; i < A.length(); i++)
	{
		if (A[i] == B[i])
			continue;

		auto itr = std::find(A.begin() + (i + 1), A.end(), B[i]);

		if (itr == A.end())
			continue;

		int indexPos = std::distance(A.begin(), itr);

		std::swap(A[indexPos], A[i]);

		++swapCount;
	}

	if (A == B)
		return swapCount;
}

int main()
{
	int swapCount = kSimilarity("aabc", "abca");
	cout << "\nSwapCount : " << swapCount;
}