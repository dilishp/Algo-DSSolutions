#include "pch.h"
#include <iostream>
#include <stack>
#include <unordered_set>
#include <map>
#include <algorithm>

using namespace std;

// Function to return the count 
// of minimum stacks 
int countPiles(int n, int a[])
{

	// Keep track of occurrence 
	// of each capacity 
	map<int, int> occ;

	// Fill the occurrence map 
	for (int i = 0; i < n; i++)
		occ[a[i]]++;

	// Number of piles is 0 initially 
	int pile = 0;

	// Traverse occurrences in increasing 
	// order of capacities. 
	while (occ.size()) {

		// Adding a new pile 
		pile++;
		int size = 0;
		unordered_set<int> toRemove;

		// Traverse all piles in increasing 
		// order of capacities 
		for (auto tm : occ) {
			int mx = tm.first;
			int ct = tm.second;

			// Number of boxes of capacity mx 
			// that can be added to current pile 
			int use = min(ct, mx - size + 1);

			// Update the occurrence 
			occ[mx] -= use;

			// Update the size of the pile 
			size += use;
			if (occ[mx] == 0)
				toRemove.insert(mx);
		}

		// Remove capacities that are 
		// no longer available 
		for (auto tm : toRemove)
			occ.erase(tm);
	}
	return pile;
}

// Driver code 
int main()
{
	int a[] = { 1, 1,4,4};
	int n = sizeof(a) / sizeof(a[0]);
	cout << countPiles(n, a);

	return 0;
}