#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool canCross(vector<int> stones)
{
	int i = 0, j = 1;

	int size = stones.size();

	vector<vector<int>> vJumpSteps(stones.size(),std::vector<int>());

	vJumpSteps[0].push_back(0);

	while (j < size)
	{
		int i = j - 1;

		while (i >= 0)
		{
			int diffValue = stones[j] - stones[i];
			bool bIsJumpPossible = std::any_of(vJumpSteps[i].begin(), vJumpSteps[i].end(), [&](int stepdiff) {
				return (stepdiff == diffValue) || (abs(stepdiff - diffValue) == 1);
			});
			if (bIsJumpPossible)
				vJumpSteps[j].push_back(diffValue);
			else if(i != (j - 1))
				break;
			i--;
		}

		j++;
	}
	

	if (vJumpSteps[stones.size() - 1].size() == 0)
		return false;

	return true;
}

//Given an array of non - negative integers, you are initially positioned at the first index of the array.
//
//Each element in the array represents your maximum jump length at that position.
//
//Your goal is to reach the last index in the minimum number of jumps.
//
//Example:
//
//Input: [2, 3, 1, 1, 4]
//	Output : 2
//	Explanation : The minimum number of jumps to reach the last index is 2.
//	Jump 1 step from index 0 to 1, then 3 steps to the last index.

int jump(vector<int>& nums) {

	vector<int> vJumpCount(nums.size(), 0);

	for (int i = 1;i < nums.size(); ++i)
	{
		int j = i - 1;
		vector<int> vJumpCountsFori;

		while (j >= 0)
		{
			if ((i - j) <= nums[j])
			{
				vJumpCountsFori.push_back(vJumpCount[j] + 1);
			}
			j--;
		}
		vJumpCount[i] = *std::min_element(vJumpCountsFori.begin(), vJumpCountsFori.end());
	}

	return vJumpCount[nums.size() - 1];

}
int main()
{
	//canCross({ 0,1,3,6,10,13,14 });
	vector<int> v({ 2,3,1,1,4 });
	jump(v);
}