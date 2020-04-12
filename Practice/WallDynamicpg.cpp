#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

//using dynamic programming

int getLegoCombination(vector<int>& lego_heights, int target_height)
{
	int** legoCombMatrix = new int*[lego_heights.size()]{ 0 };

	for (int i = 0; i < lego_heights.size(); i++)
	{
		legoCombMatrix[i] = new int[target_height + 1] {0};
		for (int j = 0; j <= target_height; j++)
		{
			if (j == 0)
			{
				legoCombMatrix[i][j] = 1;
			}
			else if(i == 0)
			{
				legoCombMatrix[i][j] = ((j % lego_heights[0]) == 0) ? 1 : 0;
			}
			else if((j - lego_heights[i]) >= 0)
			{
				legoCombMatrix[i][j] = legoCombMatrix[i - 1][j] + legoCombMatrix[i][j - lego_heights[i]];
			}
			else
			{
				legoCombMatrix[i][j] = legoCombMatrix[i - 1][j];
			}
		}
	}

	return legoCombMatrix[lego_heights.size() - 1][target_height];
}

void main()
{
	vector<int> legoBlocks = { 1,2,4 };
	cout<<"No of Ways of building the wall :"<<getLegoCombination(legoBlocks, 4);
}