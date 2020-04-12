#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int countNoofBeautifulSegments(const int& size)
{
	if (size <= 2)
		return 0;

	int i = 3,cnt = 0;
	while (i <= size)
	{
		cnt++;
		i += 2;
	}

	return cnt;
}

int findBeautifulSegments(vector<long long> v)
{
	int start = 0,mid = 0,end = 0;
	int i = 0,cnt = 0;
	bool bStartAssigned = false, bMidAssigned = false, bEndAssigned = false;

	while (i < v.size())
	{
		if ((i == (v.size() - 1)) && (v[i - 1] > v[i]))
		{
			end = i;
			int size = (end - start) + 1;
			cnt += countNoofBeautifulSegments(size);
		}
		else if (i == (v.size() - 1))
		{
			break;
		}
		else if (v[i + 1] > v[i] && bStartAssigned && bMidAssigned && !bEndAssigned)
		{
			end = i;
			bEndAssigned = true;
			bMidAssigned = false;
			int size = (end - start) + 1;
			start = i;
			cnt += countNoofBeautifulSegments(size);
		}
		else if (v[i + 1] > v[i] && !bStartAssigned)
		{
			start = i;
			bStartAssigned = true;
		}
		else if (v[i + 1] < v[i] && bStartAssigned && !bMidAssigned)
		{
			mid = i;
			bMidAssigned = true;
		}
		i++;
	}

	return cnt;

}

int main()
{
	int t;
	cin >> t;
	for (size_t i = 0; i < t; i++)
	{
		int size;
		cin >> size;
		vector<long long> v;
		for (size_t i = 0; i < size; i++)
		{
			long long element;
			cin >> element;
			v.push_back(element);
			cout<<findBeautifulSegments(v)<<"\n";
		}
	}
}