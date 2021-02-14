#include <iostream>

#include "pch.h"
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Solution {
    bool isCycle(vector<vector<int>> graph, vector<int> state, int currNode)
    {
        //DFS Approach
        //To find the Back Edge
        //Start with ANy node
        //Explore one of the neighbours and mark that neighbour as visiting
        //Then further explore its neighbours
        //Continue until there are no neighbours of the node
        //Then backtrack mark the node as visited 
        //In the process if we find that the node we are referring to is visited
        //Then a cycle exists.
        if (state[currNode] == 1)
        {
            return true;
        }

        if (state[currNode] == 0)
        {
            state[currNode] = 1;
            for (int i = 0;i < graph[currNode].size();++i)
            {
                if (isCycle(graph, state, graph[currNode][i]))
                {
                    return true;
                }
            }
        }
        state[currNode] = 2;

        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //Make Adjacency List
        vector<vector<int>> graph(numCourses);
        vector<int> degree(numCourses, 0);
        for (auto& p : prerequisites)
        {
            graph[p[1]].push_back(p[0]);
            degree[p[0]]++;
        }

        vector<int> state(numCourses, 0);
        for (int i = 0;i < numCourses;++i)
        {
            if (isCycle(graph, state, i))
                return false;
        }
        return true;
        //BFS Approach
        //The approach tells that first find the node with zero dependency
        //Add that node to the queue 
        //Explore its neighbours
        //Decrement the count of the degree of its neighbours by one as one of the course is completed
        //If the degree falls to 0 then add to the queue.
        //At the end just check if we are able to cover all courses.
        queue<int> q;
        for (int i = 0;i < numCourses;++i)
        {
            if (degree[i] == 0)
            {
                q.push(i);
            }
        }
        int nodesCompleted = 0;
        while (!q.empty())
        {
            int node = q.front();
            ++nodesCompleted;
            q.pop();
            for (int curr : graph[node])
            {
                if (--degree[curr] == 0)
                {
                    q.push(curr);
                }
            }
        }

        return nodesCompleted == numCourses;
    }
};

class MinHeighTrees {
    int DFS(vector<vector<int>>& graph, vector<int> state, int& maxHeight,
        int currHeight, int currNode)
    {
        if (state[currNode] == 2)
            return currHeight;

        if (state[currNode] == 0)
        {
            state[currNode] = 1;
            for (auto& node : graph[currNode])
            {
            	if(state[node] == 0)
            	{
                    maxHeight = max(maxHeight,
                        DFS(graph, state, maxHeight,currHeight + 1, node));
            	}
            }
        }

        state[currNode] = 2;

        return currHeight;
    }
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        vector<vector<int>> graph(n);
        vector<int> state(n, 0);

        for (auto& edg : edges)
        {
            graph[edg[0]].push_back(edg[1]);
            graph[edg[1]].push_back(edg[0]);
        }
        vector<int> res;
        vector<int> roots;
        vector<int> heights;
        int minHeight = INT_MAX;
        for (int i = 0;i < n;++i)
        {
            int maxHeight = 0;
            DFS(graph, state, maxHeight, 0, i);
            roots.push_back(i);
            heights.push_back(maxHeight);
            minHeight = min(minHeight, maxHeight);
        }

    	for(int i = 0;i < heights.size();++i)
    	{
    		if(heights[i] == minHeight)
    		{
                res.push_back(roots[i]);
    		}
    	}
        return res;
    }
};

struct Stock
{
    string name;
    float shares;
    float buyPrice;
    float currentPrice;
    string stockType;
};

void enterDetails(Stock& s)
{
    cout << "\nEnter the stock name";
    getline(cin, s.name);
    cout << "\nEnter number of shares";
    cin >> s.shares;
    cout << "\nEnter the Buy Price";
    cin >> s.buyPrice;
    cout << "\nEnter the Current Price";
    cin >> s.currentPrice;
    cout << "\nEnter the stock type";
    getline(cin, s.stockType);
}

std::tuple<float,float,float> calculate(Stock s)
{
    float totalCost = s.buyPrice * s.shares;
    float  currentValue = s.currentPrice * s.shares;
    float profit = currentValue - totalCost;
    return { totalCost, currentValue, profit };
}

int main()
{
    Stock s;
    enterDetails(s);
    auto [totalCost, currentValue, profit]= calculate(s);
    cout << "\ntotal Cost : " << totalCost;
    cout << "\nCurrent Value : " << currentValue;
    cout << "\nprofit : " << profit;


	
    vector<vector<int>> edges =
    {
        {1,0 }, { 1,2 }, { 1,3 }
    };

    MinHeighTrees trees;
    trees.findMinHeightTrees(4, edges);
}