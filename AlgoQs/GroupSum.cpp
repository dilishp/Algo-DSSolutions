#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

bool groupSum(int start,vector<int> nums,int target)
{
	if (start >= nums.size())
		return target == 0;

	if (target == 0)
		return true;

	if (target < 0)
		return false;

	return groupSum(start + 1, nums, target - nums[start]) ||
		groupSum(start + 1, nums, target);
}
int main()
{
	if (groupSum(0, { 2, 4, 8 }, 10))
	{
		cout << "\nTrue";
	}
	else
	{
		cout << "\nFalse";
	}
	if (groupSum(1, { 2, 4, 8 }, 10))
	{
		cout << "\nTrue";
	}
	else
	{
		cout << "\nFalse";
	}
	if (groupSum(0, { 2, 4, 8 }, 14))
	{
		cout << "\nTrue";
	}
	else
	{
		cout << "\nFalse";
	}
	if (groupSum(0, {2, 4, 8}, 9))
	{
		cout << "\nTrue";
	}
	else
	{
		cout << "\nFalse";
	}
}