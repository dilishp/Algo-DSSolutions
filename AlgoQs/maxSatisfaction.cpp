#include "pch.h"
#include <algorithm>
#include <vector>

using namespace std;

class my_class
{
public:
	
};
class Solution {
    vector<int> _satisfaction;
    vector<int> _mem;
    int maxSatisfaction(int currentIndex, int dishIndex)
    {
        if (currentIndex >= _satisfaction.size())
            return 0;

        if (dishIndex > _satisfaction.size())
            return 0;

        if (_mem[currentIndex] != INT_MIN)
            return _mem[currentIndex];

        _mem[currentIndex] = max(dishIndex * _satisfaction[currentIndex] +
            maxSatisfaction(currentIndex + 1, dishIndex + 1), maxSatisfaction(currentIndex + 1, dishIndex));

        return _mem[currentIndex];
    }
public:
    int maxSatisfaction(vector<int> satisfaction) {
        _mem.assign(satisfaction.size(), INT_MIN);
        _satisfaction = satisfaction;
        std::sort(_satisfaction.begin(), _satisfaction.end());
        return maxSatisfaction(0, 1);
    }
};

int main()
{
    Solution s;
	s.maxSatisfaction({ -1,2 });
    return 0;
}