#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;



int maxStudents(vector<vector<char>>& seats) {

	if (0 == seats.size())
		return 0;

	vector<vector<int>> arrangment1(seats.size(),vector<int>(seats[0].size(),0));
	vector<vector<int>> arrangment2(seats.size(), vector<int>(seats[0].size(), 0));
	int arr1Count = 0;
	int arr2Count = 0;

	for (int i = 0;i < seats.size();++i)
	{
		for (int j = 0;j < seats[i].size();++j)
		{
			if (seats[i][j] == '.')
			{
				if (0 == i)
				{
					if ((0 == j && arrangment1[i][j + 1] != 1) ||
						((seats[i].size() - 1) == j && arrangment1[i][j - 1] != 1) ||
						(0 != j && (seats[i].size() - 1) != j && (arrangment1[i][j + 1] != 1) &&
						(arrangment1[i][j - 1] != 1)))
					{
						arrangment1[i][j] = 1;
						arr1Count++;
					}

					if ((0 == j && arrangment2[i][j + 1] != 1) ||
						((seats[i].size() - 1) == j && arrangment2[i][j - 1] != 1) ||
						(0 != j && (seats[i].size() - 1) != j && arrangment2[i][j + 1] != 1 &&
						arrangment2[i][j - 1] != 1))
					{
						if (arrangment1[i][j] != 1)
						{
							arrangment2[i][j] = 1;
							arr2Count++;
						}
					}

				}
				else
				{
					if (((0 == j && arrangment1[i][j + 1] != 1 && arrangment1[i - 1][j + 1] != 1) ||
						((seats[i].size() - 1) == j && arrangment1[i][j - 1] != 1 && arrangment1[i - 1][j - 1] != 1)) ||
						(0 != j && (seats[i].size() - 1) != j && arrangment1[i][j + 1] != 1 &&
						arrangment1[i][j - 1] != 1 && arrangment1[i - 1][j + 1] != 1
							&& arrangment1[i - 1][j - 1] != 1))
					{
						arrangment1[i][j] = 1;
						arr1Count++;
					}

					if (((0 == j && arrangment2[i][j + 1] != 1 && arrangment2[i - 1][j + 1] != 1) ||
						((seats[i].size() - 1) == j && arrangment2[i][j - 1] != 1 && arrangment2[i - 1][j - 1] != 1)) ||
						(0 != j && (seats[i].size() - 1) != j && arrangment2[i][j + 1] != 1 &&
						arrangment2[i][j - 1] != 1 && arrangment2[i - 1][j + 1] != 1
							&& arrangment2[i - 1][j - 1] != 1))
					{
						//if(arrangment1[i][j] != 1)
						{
							arrangment2[i][j] = 1;
							arr2Count++;
						}
					}
				}
			}
		}
	}

	return  max(arr1Count, arr2Count);
}

int countDigitOne(int n) {
	int count = 0;
	for (int i = 1;i <= n;++i)
	{
		string num = to_string(i);
		count += std::count_if(num.begin(), num.end(), [&](char chr) {
			return chr == '1';
		});
	}
	return count;
}


int main()
{
	vector<vector<char>> seats = { {'#', '.', '.', '.', '#'},{'.', '#', '.', '#', '.'},{'.', '.', '#', '.', '.'},{'.', '#', '.', '#', '.'},{'#', '.', '.', '.', '#'} };

	countDigitOne(13);
}

//	maxStudents(seats);
//}