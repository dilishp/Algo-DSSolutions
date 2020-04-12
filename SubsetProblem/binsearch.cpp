#include "pch.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


// In the array A at every step we have two 
// choices for each element either  we can 
// ignore the element or we can include the 
// element in our subset 
void subsetsUtil(vector<int>& A, vector<vector<int> >& res,
	vector<int>& subset, int index)
{
	res.push_back(subset);
	for (int i = index; i < A.size(); i++) {

		// include the A[i] in subset. 
		subset.push_back(A[i]);

		// move onto the next element. 
		subsetsUtil(A, res, subset, i + 1);

		// exclude the A[i] from subset and triggers 
		// backtracking. 
		subset.pop_back();
	}

	return;
}

// below function returns the subsets of vector A. 
vector<vector<int> > subsets(vector<int>& A)
{
	vector<int> subset;
	vector<vector<int> > res;

	// keeps track of current element in vector A; 
	int index = 0;
	subsetsUtil(A, res, subset, index);

	return res;
}

// Driver Code. 
int main()
{
	// find the subsets of below vector. 
	vector<int> array = { 1, 2, 3 };

	// res will store all subsets. 
	// O(2 ^ (number of elements inside array)) 
	// because at every step we have two choices 
	// either include or ignore. 
	vector<vector<int> > res = subsets(array);

	// Print result 
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}

	return 0;
}

bool binarySearch(string name, vector<string> arr, int leftindex, int rightindex)
{
	if (rightindex >= leftindex) {
		int mid = (leftindex + rightindex) / 2;

		if (arr[mid] == name)
			return true;

		if (arr[mid] > name)
			return binarySearch(name,arr, leftindex, mid - 1);

		return binarySearch(name,arr, mid + 1, rightindex);
	}

 
	return false;
}

int getCellsCount(string fileName)
{
	ifstream fin;
	fin.open(fileName);
	if (!fin.is_open())
		return {};

	string firstline;
	getline(fin, firstline);

	string line;
	int lineno = 1;
	int sumRow = 0, sumColumn = 0;
	while (getline(fin, line))
	{
		stringstream ss(line);
		int num;
		while (ss >> num)
		{
			if (lineno == 1)
				sumRow += num;
			else if(lineno == 2)
				sumColumn += num;
		}
		if (lineno == 2)
			break;
		lineno++;
	}
	if (sumRow == sumColumn)
		return sumRow;
}

bool binarySearch(string name,vector<string> arr)
{
	sort(arr.begin(), arr.end());
	return binarySearch(name, arr, 0, (arr.size() - 1));
}

//void main()
//{
//	vector<string> arr = getVector("Students.txt");
//	string name = "jackk";
//	bool bresult = binarySearch(name, arr);
//}