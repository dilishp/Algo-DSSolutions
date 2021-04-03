#include "pch.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
    unordered_map<int, vector<pair<int, int>>> _graph;
    int m_k;
    int _dst;
    int minVal = INT_MAX;

    void DFS(int cost, int currentStop, int stops, vector<int>& _visited)
    {
        if (currentStop == _dst)
        {
            minVal = min(minVal, cost);
            return;
        }

        if (stops > m_k)
            return;

        _visited[currentStop] = 1;

        int retVal = INT_MAX;
        for (auto p : _graph[currentStop])
        {
            if (_visited[p.first] == 0)
            {
                if (cost + p.second > minVal) continue;
                DFS(cost + p.second, p.first, stops + 1, _visited);
            }
        }

        _visited[currentStop] = 0;
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        //Create Adjacency list

        for (auto vec : flights)
        {
            _graph[vec[0]].emplace_back(vec[1], vec[2]);
        }
        m_k = K;
        _dst = dst;
        //start with source
        vector<int> visited(n, 0);
        DFS(0, src, 0, visited);
        return minVal == INT_MAX ? -1 : minVal;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> flights = { {0,1,100},{1,2,100},{0,2,500} };
    int res = s.findCheapestPrice(4, flights, 0, 2, 1);
    return 0;
}