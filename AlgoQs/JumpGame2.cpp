//The idea is to deal the array zone wise and find the maxReach in each zone while 
//jumping from one zone to another increment the jumpCount.
//if the maxReach has become the last index then return the jumpCount.

#include <vector>

using namespace std;

int jump(vector<int>& nums) {

	if (nums.size() <= 1)
		return 0;



	vector<int> maxReachVec(nums.size(), 0);

	for (int i = 0;i < nums.size();++i)
	{
		if (nums[i] + i >= (nums.size() - 1))
			maxReachVec[i] = (nums.size() - 1);
		else
			maxReachVec[i] = nums[i] + i;
	}

	int maxReach = 0;
	int zoneMax = 0;
	int jmpCount = 1;
	for (int i = 0;i < nums.size();++i)
	{
		if (maxReachVec[i] == (nums.size() - 1))
			return jmpCount;

		if (i == maxReach)
		{
			if (maxReachVec[i] > zoneMax)
				maxReach = maxReachVec[i];
			else
				maxReach = zoneMax;

			jmpCount++;
		}
		else
		{
			if (maxReachVec[i] > zoneMax)
			{
				zoneMax = maxReachVec[i];
			}
		}
	}

	return jmpCount;

}