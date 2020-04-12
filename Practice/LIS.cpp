#include "pch.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int actualLIS(int arr[], int nLength)
{
	int* LIS = new int[nLength];

	std::fill_n(LIS, nLength, 1);

	for (int i = 0;i < nLength;i++)
	{
		for (int j = 0;j < i;j++)
		{
			if ((arr[i] > arr[j]) && (LIS[i] < LIS[j] + 1))
			{
				LIS[i] = LIS[j] + 1;
			}
		}
	}

	int max = 0;

	for (int i = 0;i < nLength;i++)
	{
		if (max < LIS[i])
		{
			max = LIS[i];
		}
	}

	return max;
}

bool isSumUtil(std::vector<int>& vec, int index, int sumSofar, int sumReqd, std::vector<bool>&mask)
{
	if (sumReqd == 0)
		return true;

	if (sumReqd < sumSofar)
		return false;

	if (sumReqd == sumSofar)
	{
		return isSumUtil(vec, index, 0, sumReqd, mask);
	}

	for (int i = 0; i < vec.size(); ++i)
	{
		isS
	}

}

std::string isSubsetSum(std::vector<int>& v1, int k)
{
	if (v1.size() == 0)
		return "true";

	int sumSoFar = 0;

	std::vector<bool> mask(v1.size(), false);


	// sumTillNow
	// TargetSum
	// vec mask
	// v1
	// current index
}

int main()
{
	int arr[] = { 6,4,3,5,7,8,9,2,10,1,13 };
	int length = sizeof(arr) / sizeof(int);

	cout<<"Length of LIS is :"<< actualLIS(arr, length);

	return 0;
}

