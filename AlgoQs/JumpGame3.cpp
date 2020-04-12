#include "pch.h"
#include <vector>

using namespace std;

bool canReach(vector<int>& arr, vector<int>& v_F, vector<int>& v_B, vector<int>& vVisitedIndex, int index)
{
	if (-1 == index ||
		std::find(vVisitedIndex.begin(), vVisitedIndex.end(), index) != vVisitedIndex.end())
	{
		return false;
	}

	if (arr[index] == 0)
		return true;

	vVisitedIndex.push_back(index);

	return (canReach(arr, v_F, v_B, vVisitedIndex, v_F[index]) ||
		canReach(arr, v_F, v_B, vVisitedIndex, v_B[index]));
}


bool canReach(vector<int>& arr, int start) {

	vector<int> v_F(arr.size(), 0);
	vector<int> v_B(arr.size(), 0);

	for (int i = 0;i < arr.size();++i)
	{
		if ((i + arr[i]) > (arr.size() - 1))
		{
			v_F[i] = -1;
		}
		else
		{
			v_F[i] = i + arr[i];
		}

		if ((i - arr[i]) < 0)
		{
			v_B[i] = -1;
		}
		else
		{
			v_B[i] = i - arr[i];
		}
	}

	vector<int> vVisited;

	return canReach(arr, v_F, v_B, vVisited, start);

}

int main()
{
	vector<int> v({ 4,2,3,0,3,1,2 });
	bool  b = canReach(v, 0);
	return 0;
}