#include  "pch.h"
#include <iostream>
#include <algorithm>

using namespace std;

//Algorithm
//Find the local maxima and global maximum at each month
//local maxima can be found out for each month by taking the maxima of
//the previous local_maxima and the particular month revenue with the 
//Particular month revenue

int main()
{
	//Declare the array
	int a[] = { 2,-5,3,4,0,-1,5,8,-9,1,-2,0 };
	int size = 12;

	//initilaise the local maxima and global maxima to be the first element at the start
	int local_maxima = a[0];
	int global_maxima = a[0];

	//start the loop from the second element of the array
	for (int i = 1; i < size; i++)
	{
		//For each month revenue find the local_maxima
		//the local maxima will be equal to the maximum of the sum of previous local maximum
		//with the present month revenue
		//durig each pass of the loop check whether the local maximum is larger than 
		//global_maximum if that is the case then update the global_maximum

		local_maxima = std::max(local_maxima + a[i], a[i]);

		if (local_maxima > global_maxima)
			global_maxima = local_maxima;
	}

	cout << "Maximum revenue for the consecutive month is : " << global_maxima;

	return 0;
}