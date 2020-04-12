#include "pch.h"
#include "pch.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef struct coin_row_solution {
	int val;
	std::vector< int > coin_indices;
} CRS;

/******************************************/

CRS coin_row(std::vector< int> coin_row) {

	CRS soln;

	//First sort the vector in decreasing order and map their corresponding indices in the 
	//another vector named indices
	vector<int> temp = coin_row;
	std::sort(temp.begin(), temp.end(), std::greater<int>());
	vector<int> indices;
	for (auto element : temp)
	{
		auto itr = std::find(coin_row.begin(), coin_row.end(), element);
		int index = std::distance(coin_row.begin(), itr);
		indices.push_back(index);
	}

	//Prepare the solnVector which contain a vector of possible sum and array indices
	vector<CRS> solnVector;
	for (int i = 0; i < coin_row.size(); i++)
	{
		int sum = 0;
		vector<int> indicesconsidered;
		indicesconsidered.push_back(indices[i]);
		sum += temp[i];
		for (int j = (i + 1); j < coin_row.size(); j++)
		{
			int index = indices[j];

			//To check whether the selected index is not adjacent
			bool bresult = std::all_of(indicesconsidered.begin(), indicesconsidered.end(), [&](int anIndex) {
				return abs(anIndex - index) > 1;
			});

			if (bresult)
			{
				//If it is not adjacent add to the considered index list and calculate the sum
				indicesconsidered.push_back(index);
				sum += temp[j];
			}
		}
		solnVector.push_back({ sum,indicesconsidered });
	}

	//Finding the Maximum sum from the possible sum
	auto itr = std::max_element(solnVector.begin(), solnVector.end(), [&](const CRS aSoln1,const CRS aSoln2)->bool {
		return aSoln1.val < aSoln2.val;
	});

	soln = *itr;

	return soln;
}

int main()
{
	CRS sol = coin_row({ 5,22,26,15,4,3,11 });

	cout << "\nMax Sum is " << sol.val;
	cout << "\nIndices are :";
	for (int index : sol.coin_indices)
	{
		cout << " " << index;
	}
}