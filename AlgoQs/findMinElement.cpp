/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;

int main()
{
	int size, q;
	cin >> size >> q;
	vector<int> v(size, 0);
	vector<vector<int>> vv;
	vector<int> vsum(size, 0);
	for (int i = 0;i < q;i++)
	{
		int l, r, val;
		cin >> l >> r >> val;
		std::vector<int> temp(size,0);
		std::transform(v.begin() + (l - 1), v.begin() + r, temp.begin() + (l - 1), [&](int value) {
			return value + val;
		});
		std::transform(vsum.begin(), vsum.end(), temp.begin(), vsum.begin(), std::plus<int>());
		vv.push_back(temp);
	}

	vector<int> max;

	for (int i = 0;i < q;i++)
	{
		std::vector<int> temp(size, 0);
		std::transform(vsum.begin(), vsum.end(), vv[i].begin(), temp.begin(), std::minus<int>());
		max.push_back(*std::max_element(temp.begin(), temp.end()));
	}

	cout << *std::min_element(max.begin(), max.end()) << "\n";

	return 0;

}