#include "pch.h"
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

long long findNoofSacksStolen(vector<int> vSacks)
{
	long long maxSacks = 0;
	stack<int> sSacks;

	int i = 0;

	while (i < vSacks.size())
	{
		if (sSacks.empty() || (vSacks[i] >= vSacks[sSacks.top()]))
		{
			sSacks.push(i);
			i++;
		}
		else
		{
			while (!sSacks.empty() && vSacks[i] < vSacks[sSacks.top()])
			{
				int top = sSacks.top();
				sSacks.pop();
				if (!sSacks.empty())
				{
					if (vSacks[top] * (i - sSacks.top() - 1) > maxSacks)
					{
						maxSacks = vSacks[top] * (i - sSacks.top() - 1);
					}
				}
				else
				{
					if (vSacks[top] * i > maxSacks)
					{
						maxSacks = vSacks[top] * i;
					}
				}
				
			}
		}
	}
	

	while (!sSacks.empty())
	{
		int top = sSacks.top();
		sSacks.pop();
		if (!sSacks.empty())
		{
			if (vSacks[top] * (i - sSacks.top() - 1) > maxSacks)
			{
				maxSacks = vSacks[top] * (i - sSacks.top() - 1);
			}
		}
		else
		{
			if (vSacks[top] * i > maxSacks)
			{
				maxSacks = vSacks[top] * i;
			}
		}
	}

	return maxSacks;
}

int main()
{
	findNoofSacksStolen({ 2,1,2,3,1 });
}

