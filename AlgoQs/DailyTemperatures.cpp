#include "pch.h"
#include <stack>
#include <vector>

using namespace std;

vector<int> dailyTemperatures(vector<int>& T) {
    if (T.size() == 0)
        return {};

    vector<int> vDays(T.size(), 0);
    stack<int> s;
    for (int i = 0;i < T.size();++i)
    {
        while (!s.empty() && T[i] > T[s.top()])
        {
            int top = s.top();
            vDays[top] = i - top;
            s.pop();
        }
        s.push(i);
    }

    return vDays;
}

int main()
{
    vector<int> T = { 73, 74, 75, 71, 69, 72, 76, 73 };
    auto vec = dailyTemperatures(T);
    return 0;
}