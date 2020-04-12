#include "pch.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//Recursive Approach Top Down
int coinChangeRecursive(std::vector<int>& coins, int amount) {

	if (amount == 0)
		return 0;
	if (amount < 0)
		return (INT_MAX - 1);

	int count = (INT_MAX - 1);

	for (int coin : coins)
	{
		count = std::min( coinChangeRecursive(coins,amount - coin),count);
	}

	return count + 1;
	
}

//Bottom Up Approach
int coinChange(std::vector<int>& coins, int amount)
{
	vector<int> dp(amount + 1, INT_MAX - 1);

	dp[0] = 0;

	for (int i = 1;i <= amount;++i)
	{
		for(int j = 0;j < coins.size();++j)
		{
			if (i >= coins[j])
				dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
		}
	}

	if (dp[amount] == INT_MAX || dp[amount] == INT_MAX - 1)
		return -1;

	return dp[amount];
}
int main()
{
	vector<int> coins = {1,2};
	cout << coinChange(coins, 3);
}