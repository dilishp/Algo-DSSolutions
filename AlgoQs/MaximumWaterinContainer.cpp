#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxArea(vector<int>& height)
{
	int i = 0, j = height.size() - 1;

	int maxArea = INT_MIN;

	while (i < j)
	{
		int area = (j - i) * std::min(height[i], height[j]);
		if(area > maxArea)
		{
			maxArea = area;
		}
		if(height[i] > height[j])
		{
			j--;
		}
		else if(height[i] < height[j])
		{
			i++;
		}
		else
		{
			i++;
			j--;
		}
	}

	return maxArea;
}