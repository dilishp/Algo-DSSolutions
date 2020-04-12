#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

bool checkSubarraySum(std::vector<int> nums, int k) {
	vector<int> vsum(nums.size(), 0);

	//Fill the sum vector

	for (int i = 0;i < nums.size();++i)
	{
		if (0 == i)
			vsum[i] = nums[i];
		else
			vsum[i] = vsum[i - 1] + nums[i];
	}

	//use the sum vector for the rest of the calculation
	int j = 1;

	while (j < nums.size())
	{
		int i = 0;

		if(k == 0)
		{
			if (vsum[j] == 0)
				return true;
		}
		else if ((vsum[j] % k) == 0)
			return true;

		while (i < (j - 1))
		{
			int sum = vsum[j] - vsum[i];

			if (k == 0)
			{
				if (sum == 0)
					return true;
			}
			else if ((sum % k) == 0)
				return true;

			++i;
		}
		++j;
	}

	return false;
}

int main()
{
	checkSubarraySum({ 5,0,0 }, 0);
}
