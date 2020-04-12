#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class Container>
bool isPaliandrome(const Container& s)
{
	auto start = s.begin();
	auto end = s.end() - 1;

	while (start < end)
	{
		if (*start == *end)
		{
			start++;
			end--;
		}
		else
		{
			return false;
		}
	}

	return true;
}

template<typename T>
bool hasItem(T arr[],int length, int itemtofind)
{
	for (int i = 0;i < length;i++)
	{
		if (arr[i] == itemtofind)
		{
			return true;
		}
	}

	return false;
}




template<typename T>
auto getValue(T ptr)
{
	return getValue(*ptr);
}

template<>
auto getValue(int value)
{
	return value;
}

template<class samp = void>
constexpr int f()
{
	return 0;
}

template<int First = 0,int... Rest>
constexpr int f()
{
	return First + f<Rest...>();
}

int main()
{
	int b = 2;
	int* a = &b;
	int** c = &a;
	int*** d = &c;

	cout << sizeof(a);
	cout<<getValue(d);
	//cout<<f<1, 2, 3, 4>();
	return 0;
}

//int main()
//{
//	std::vector<string> vGroceryList;
//	std::cout << "Please Enter grocery.Press only q to exit"<<std::endl;
//	while (true)
//	{
//		std::string grc;
//		std::cin >> grc;
//		if (grc == "q")
//		{
//			break;
//		}
//		vGroceryList.push_back(grc);
//	}
//	cout << endl;
//	cout << "All Items : " << std::endl;
//
//	for (auto item : vGroceryList)
//	{
//		cout << item << std::endl;
//	}
//	//Reached Cashier popped an item
//	vGroceryList.pop_back();
//	cout << endl;
//	cout << "Items with 1 element popped: " << std::endl;
//	for (auto item : vGroceryList)
//	{
//		cout << item << std::endl;
//	}
//
//	return 0;
//}