#include "pch.h"
//#include <iostream>
//#include <stack>
//#include <queue>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	vector<int> inputSet({ 2,4,7,9 });
//	queue<stack<int>> myPowerSet;
//
//	int nlenght = inputSet.size();
//
//	for (size_t i = 0; i < pow(nlenght,2); i++)
//	{
//		int cnt = 0;
//		stack<int> set;
//		while (cnt < 4)
//		{
//			if (i & (1 << cnt))
//				set.push(inputSet[cnt]);
//			cnt++;
//		}
//		myPowerSet.push(set);
//	}
//
//	return 0;
//
//}

#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

// Add any helper functions(if needed) above.
static class A
{
public:
	A()
	{
		cout << "\nConstructor called";
	}

	static int i;

	void print()
	{
		cout << "\nHello";
	}
};

int A::i;

//void main()
//{
//	cout << "\nInside Main";
//	A::A();
//	A::A().print();
//	cout << A::i;
//}



// namespace std have been included for this problem.
#include <vector>
#include<algorithm>

using namespace std;

vector<int> getHashVector(string input)
{
	vector<int> hashbuck;
	int i = 0;
	vector<char> inputv;
	for (char ch : input)
	{
		auto itr1 = find(inputv.begin(), inputv.end(), ch);
		if (itr1 != inputv.end())
		{
			int index = std::distance(inputv.begin(), itr1);
			hashbuck.push_back(hashbuck[index]);
		}
		else
		{
			hashbuck.push_back(i);
		}
		inputv.push_back(ch);
		i++;
	}

	return hashbuck;
}
// Add any helper functions(if needed) above.
bool is_isomorphic(string input1, string input2)
{
	if (input1.length() != input2.length())
		return false;

	if (getHashVector(input1) == getHashVector(input2))
		return true;

	return false;
}

void copy_arr(double target1[], double source[], int size)
{
	for (int i = 0;i < size;i++)
	{
		target1[i] = source[i];
	}
}

void copy_ptr(double* target2, double* source, int size)
{
	for (int i = 0;i < size;i++)
	{
		*(target2 + i) = *(source + i);
	}
}

void copy_ptrs(double* target3, double* source, double* lastptr)
{
	int i = 0;
	while ((source + i) < lastptr)
	{
		*(target3 + i) = *(source + i);
		i++;
	}
}
void main()
{
	double source[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };

	double target1[5];

	double target2[5];

	double target3[5];

	copy_arr(target1, source, 5);

	copy_ptr(target2, source, 5);

	copy_ptrs(target3, source, source + 5);

	printf("\nSource array : ");

	for (int i = 0;i < 5;i++)
	{
		printf("%f  ", source[i]);
	}
	
	printf("\nCopied by subscript : ");

	for (int i = 0;i < 5;i++)
	{
		printf("%f  ", target1[i]);
	}

	printf("\nCopied by pointer : ");

	for (int i = 0;i < 5;i++)
	{
		printf("%f  ", target2[i]);
	}

	printf("\nCopied using pointer range : ");

	for (int i = 0;i < 5;i++)
	{
		printf("%f  ", target3[i]);
	}
}


