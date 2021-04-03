#include "pch.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {

        //Here the problem can be reduced to 0 and 1 knapsack problem where there are 2 sets 
        //one which contains + elements and the other set containing - elements
        //therefore S1 - S2 = target here S2 will be the sum of elements of set containing negative signed numbers
        //S2 = Sum - S1 S1 - (sum - s1) = target = 2s1 - sum = target = (target + sum) / 2 = s1


        int sum = std::accumulate(nums.begin(), nums.end(), 0);

        int targ = (sum + S) / 2;

        vector<vector<int>> dp(nums.size() + 1, vector<int>(targ + 1, 0));

        for (int i = 0;i <= nums.size();++i)
        {
            for (int j = 0;j <= targ;++j)
            {
                if (j == 0)
                {
                    dp[i][j] = 1;
                    continue;
                }

            	if(i == 0) continue;
            	
                if ((j - nums[i - 1]) >= 0)
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[nums.size()][targ];

    }
};

class Solution1 {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        vector<vector<int>> dp(triangle.size());

        for (int i = 0;i < triangle.size();++i)
        {
            for (int j = 0;j < triangle[i].size();++j)
            {
                int optiona = INT_MAX, optionb = INT_MAX;
                if (i >= 1 && j < dp[i - 1].size())
                    optiona = std::min(optiona, triangle[i][j] + dp[i - 1][j]);
                if (i >= 1 && j >= 1 && (j - 1) < dp[i - 1].size())
                    optionb = std::min(optionb, triangle[i][j] + dp[i - 1][j - 1]);

                if (i == 0 && j == 0)
                    optiona = std::min(optiona, triangle[i][j]);

                int minVal = min(optiona, optionb);
                dp[i].push_back(minVal);
            }
        }

        int size = triangle.size();
        return *std::min_element(dp[size - 1].begin(), dp[size - 1].end());
    }
};


int main()
{
    Solution1 s;
    vector<vector<int>> v = { {2},{3, 4},{6, 5, 7},{4, 1, 8, 3} };
    cout<<s.minimumTotal(v);
}