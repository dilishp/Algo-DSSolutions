#include "pch.h"
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex m;

void cross(int* num,bool* bCrosed,int& number, size_t& numberIndex, const int size)
{
	//Locking for each thread
	m.lock();
	for (size_t i = numberIndex; i < size; i++)
	{
		if (bCrosed[i] && num[i] % number == 0)
		{
			bCrosed[i] = false;
		}
	}
	//Unlocking the Critical section
	m.unlock();
}

int main()
{
	const int size = 10;

	int nums[size] = { 2,3,4,5,6,7,8,9,10,11 };
	bool bCrossed[size] = { true,true,true,true,true,true,true,true,true,true };
	thread t[size];

	for (size_t i = 0; i < 10; i++)
	{
		t[i] = thread(cross, nums,bCrossed,std::ref(nums[i]),std::ref(i),size);
	}

	for (size_t i = 0; i < 10; i++)
	{
		t[i].join();
	}

	cout << "\nCrossed Elements : ";

	for (size_t i = 0; i < 10; i++)
	{
		cout << std::boolalpha << bCrossed[i]<<"   ";
	}
	
	return 0;
}