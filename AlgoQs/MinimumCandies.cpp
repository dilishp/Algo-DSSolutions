#include "pch.h"
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int candy(vector<int>& ratings) {

	if (ratings.size() == 0)
		return 0;

	//Satisfying the first condition
	vector<int> dp(ratings.size(), 1);

	//Satisfy the condition that if the ratings of current child is greater than
	//the left child being considered then the candies to the current child 
	//should be greater than the left child.
	for (int i = 1;i < ratings.size();i++)
	{
		if (ratings[i] > ratings[i - 1])
			dp[i] = dp[i - 1] + 1;
	}

	//Satisfy the other part that if the current child has a higher rating then
	//the right child then we will take the max of the current candies assigned
	//to the current child and the candy of the right child + 1 
	for (int i = ratings.size() - 2;i >= 0;i--)
	{
		if (ratings[i] > ratings[i + 1])
			dp[i] = std::max(dp[i], (dp[i + 1] + 1));
	}

	return std::accumulate(dp.begin(), dp.end(), 0);

}