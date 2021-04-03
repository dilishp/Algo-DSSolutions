#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        unordered_map<int, vector<vector<int>>> umap;

        for (int i = 0;i < candidates.size();++i)
        {
    		for(int curSum = 1;curSum <= target;++curSum)
    		{
                int tempSum =  curSum - candidates[i];
                if (tempSum > 0 && !umap[tempSum].empty())
                {
                    vector<vector<int>> temp =  umap[tempSum];
                    for (auto& vec : temp)
                    {
                        vec.push_back(candidates[i]);
                        umap[curSum].push_back(vec);
                    }
                }
                else if (tempSum == 0)
                {
                    vector<int> initVec;
                    initVec.push_back(candidates[i]);
                    umap[curSum].push_back(initVec);
                }
    		}
    	}

        return umap[target];
    }
};

int main()
{
    Solution s;
    vector<int> cand = { 2,3,6,7 };
    auto res = s.combinationSum(cand, 7);
    return 0;
}