#include "pch.h"
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        vector<int> LIS(nums.size(), 1);
        int maxLength = 1;
        for (int i = 1;i < nums.size();++i)
        {
            int j = i - 1;
            while (j >= 0)
            {
                if (nums[i] > nums[j])
                {
                    LIS[i] = max(LIS[i], LIS[j] + 1);
                    maxLength = max(maxLength, LIS[i]);
                }
                j--;
            }
        }

        std::unordered_map<int, vector<int>> umap;

        for (int l = 0;l < LIS.size();++l)
        {
            umap[LIS[l]].push_back(l);
        }

        unordered_map<int, int> validIndex;

        int currentLength = maxLength;
        while (currentLength >= 1)
        {
            if (currentLength == maxLength)
            {
                validIndex[currentLength] = umap[currentLength].size();
                --currentLength;
                continue;
            }
           
            int validIndexes = 0;
            for (auto index : umap[currentLength])
            {
                auto refvec = umap[currentLength + 1];
                bool b = std::any_of(refvec.begin(), refvec.end(), [&](int ind) {
                    return nums[index] < nums[ind];
                });
                if (b)
                {
                    ++validIndexes;
                }
            }
            validIndex[currentLength] = validIndexes;
            --currentLength;
        }

        int res = 1;
        for (auto pair : validIndex)
            res *= pair.second;
        return res;
    }
};