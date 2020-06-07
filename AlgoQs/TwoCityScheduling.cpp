#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

//The idea here is to calculate the profit generated for each person if the person is allocated for the city A
//instead of city B 
//Sort the profit array in the descending order 
//We will select the first N/2 members in the profit array for City A as it gives max profit
//Rest we will take it for the City B and calculate the totalCost.

int twoCitySchedCost(vector<vector<int>>& costs) {
    vector<pair<int, int>> profit;

    for (int i = 0;i < costs.size();++i)
    {
        profit.push_back({ i,costs[i][1] - costs[i][0] });
    }

    std::sort(profit.begin(), profit.end(), [](std::pair<int, int> p1, std::pair<int, int> p2)->bool {
        return p1.second > p2.second;
    });

    int totalCost = 0;
    for (int i = 0;i < profit.size();++i)
    {
        if (i < (profit.size() / 2))
            totalCost += costs[profit[i].first][0];
        else
            totalCost += costs[profit[i].first][1];
    }

    return totalCost;
}