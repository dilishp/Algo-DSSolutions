#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int longestOnes(vector<int> A, int K) {
	int i = 0;
	int j = 0;
	int maxLength = 0;
	int swapCount = 0;

	while (i <= j && j < A.size())
	{
		if (A[j] == 1 && swapCount <= K)
		{
			j++;
		}
		else if (A[j] == 0 && swapCount < K)
		{
			swapCount++;
			j++;
		}
		else if (i == j)
		{
			j++;
			if (A[i] == 0)
				swapCount++;
		}
		else if ((A[j] == 0 && swapCount == K) || swapCount > K)
		{
			if (j - i > maxLength && swapCount == K)
			{
				maxLength = j - i;
			}
			if (A[i] == 0 && swapCount > 0)
			{
				swapCount--;
			}
			i++;
		}
		
	}

	if (j - i > maxLength && swapCount <= K)
		maxLength = j - i;

	return maxLength;

}

int main()
{
	longestOnes({0,0,0,0}, 0);
}