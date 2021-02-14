#include "pch.h"
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    vector<unordered_map<int, int>> umaps;
    vector<vector<int>> v;
    int maxSum(int arrIndex, int elementIndex)
    {
        vector<int> currArr = v[arrIndex];
        unordered_map<int, int> currMap = umaps[arrIndex];
        vector<int> otherArr = v[1 - arrIndex];
        unordered_map<int, int> otherMap = umaps[1 - arrIndex];

        if (elementIndex >= currArr.size())
            return 0;

        if (otherMap.find(currArr[elementIndex]) == otherMap.end())
        {
            return currArr[elementIndex] + maxSum(arrIndex, elementIndex + 1);
        }

        return currArr[elementIndex] + max(maxSum(arrIndex, elementIndex + 1),
            maxSum(1 - arrIndex, otherMap[currArr[elementIndex]] + 1));
    }
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> umap1;
        for (int i = 0;i < nums1.size();++i)
        {
            umap1[nums1[i]] = i;
        }

        unordered_map<int, int> umap2;
        for (int i = 0;i < nums2.size();++i)
        {
            umap2[nums2[i]] = i;
        }

        v = { nums1,nums2 };
        umaps = { umap1,umap2 };

        return max(maxSum(0, 0), maxSum(1, 0));
    }
};