#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/*n2 complexity*/

int kJumpn2(vector<int> v,int K)
{
	vector<int> temp(v.size(),1);

	int j = 1;

	while (j < v.size())
	{
		int i = 0;

		while (i < j)
		{
			if ((v[j] - v[i]) >= K)
			{
				temp[j] = max(temp[j],temp[i] + 1);
			}
			i++;
		}
		
		j++;
	}

	return *std::max_element(temp.begin(), temp.end());

}


int KKumpnlogn(vector<int> v, int K)
{

	std::multiset<int> p;
	std::multiset<int> ::iterator it;
	p.clear();
	//sort(arr,arr+n);
	for (int i = 0;i < v.size();i++)
	{
		int tmp = v[i];
		it = p.upper_bound(tmp - K);
		if (it == p.end())
		{
			//cout<<i<<" index\n";
			p.insert(tmp);
			continue;
		}
		if (*it > tmp)
		{
			p.erase(it);
			p.insert(tmp);
		}
	}
	return p.size();
}
int main()
{
	int maxJumps = KKumpnlogn({ 1,3,1,4,5,7,10 }, 2);
	return 0;
}