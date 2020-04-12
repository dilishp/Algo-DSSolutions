#include "pch.h"
#include <vector>
#include <algorithm>

using namespace std;

/*
The strategy is to find the minimum ticket cost for each valid day given in the days vector
Then find the ticket cost of the subsequent days from the days already computed(DP)
Here the dp[i] denotes the minimum ticket cost for the ith day.
dp array is created from 0th day to the max day in the days vector
For each day ticket cost = dp(i - ticketDays[j]) + costs[j]
and find the minimum across all the ticket group booking days available.
*/

int mincostTickets(vector<int>& days, vector<int>& costs) 
{
    int maxDay = *std::max_element(days.begin(), days.end());
    vector<int> dp(maxDay + 1, INT_MAX);
    vector<int> ticketdays = { 1,7,30 };
    dp[0] = 0;
    int daysCounter = 0;
    for (int i = 1;i <= maxDay;++i)
    {
        if (i == days[daysCounter])
        {
            for (int j = 0;j < costs.size();++j)
            {

                if (i - ticketdays[j] < 0 || daysCounter == 0)
                {
                    dp[i] = std::min(costs[j], dp[i]);
                }
                else
                {
                    auto itr = std::lower_bound(days.begin(), days.end(), (i - ticketdays[j]));
                    int validDay = 0;
                    if (itr != days.end())
                    {
                        if (*itr > (i - ticketdays[j]) && itr != days.begin())
                        {
                            validDay = *(--itr);
                        }
                        else if(*itr == (i - ticketdays[j]))
                            validDay = *itr;
                    }
                    dp[i] = std::min(dp[validDay] + costs[j], dp[i]);
                }
            }
            daysCounter++;
        }
    }

    return dp[maxDay];
}

int main()
{
    vector<int> day = { 2,3,4,6,8,12,14,18,19,26,27,28};
    vector<int> costs = { 2,9,31 };
    mincostTickets(day, costs);
}