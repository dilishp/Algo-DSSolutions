#include "pch.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

int findMaxLength(vector<int>& nums, int left, int right, int zeroCount, int oneCount)
{
    if (left >= right)
    {
        return 0;
    }

    if (zeroCount == oneCount)
    {
        return zeroCount + oneCount;
    }

    if (zeroCount > oneCount)
    {
        if (nums[left] == 0)
            return findMaxLength(nums, left + 1, right, --zeroCount, oneCount);
        else if (nums[right] == 0)
            return findMaxLength(nums, left, right - 1, --zeroCount, oneCount);

        return std::max(findMaxLength(nums, left + 1, right, zeroCount, --oneCount),
            findMaxLength(nums, left, right - 1, zeroCount, --oneCount));
    }

    if (nums[left] == 1)
        return findMaxLength(nums, left + 1, right, zeroCount, --oneCount);
    else if (nums[right] == 1)
        return findMaxLength(nums, left, right - 1, zeroCount, --oneCount);

    return std::max(findMaxLength(nums, left + 1, right, --zeroCount, oneCount),
        findMaxLength(nums, left, right - 1, --zeroCount, oneCount));

}

int findMaxLength(vector<int>& nums) {
    int zeroCount = 0;
    int oneCount = 0;
    int maxLength = 0;

    for (auto num : nums)
    {
        if (num == 0)
            zeroCount++;
        else if (num == 1)
            oneCount++;
    }

    return findMaxLength(nums, 0, nums.size() - 1, zeroCount, oneCount);
}

//Approach
//Using Unordered Map 
//Iterate through the array once and for each entry
//calculate the count and check whether that count is already 
//encountered  then 
//find the length of that subarray and compare against the maximum length
//Else push int the map the count and the index.
int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> uMapCountvsIndex;
    int count = 0;
    int maxLength = 0;
    uMapCountvsIndex[0] = -1;
    for (int i = 0;i < nums.size();++i)
    {
        count += (nums[i] == 1) ? 1 : -1;

        if (uMapCountvsIndex.find(count) != uMapCountvsIndex.end())
        {
            maxLength = std::max(maxLength, i - uMapCountvsIndex[count]);
        }
        else
        {
            uMapCountvsIndex[count] = i;
        }
    }
    return maxLength;
}

int main()
{
    vector<int> nums = { 0, 1, 1, 0, 1, 1, 1, 0 };
    cout<<findMaxLength(nums);
}