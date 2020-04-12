#include "pch.h"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

//First Iterate through the stations and calculate the 
//fuel while reaching that station
//If the fuel is negative then that means that
//We need to refuel selectively using the capacity
//Continue this activity until we reach the target station.

int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {

	int currentFuel = startFuel;
	priority_queue<int> fuel;
	int refuelCount = 0;
	int prevStationDistance = 0;

	if (currentFuel >= target)
	{
		return 0;
	}

	for (auto station : stations)
	{
		currentFuel -= (station[0] - prevStationDistance);
		prevStationDistance = station[0];

		while (currentFuel < 0 && !fuel.empty())
		{
			currentFuel += fuel.top();
			fuel.pop();
			refuelCount++;
		}

		if (currentFuel < 0)
			return -1;

		fuel.push(station[1]);
	}

	currentFuel -= (target - prevStationDistance);
	while (currentFuel < 0 && !fuel.empty())
	{
		currentFuel += fuel.top();
		fuel.pop();
		refuelCount++;
	}

	if (currentFuel < 0)
		return -1;

	return refuelCount;
}

int main()
{
	vector<vector<int>> stations = {{25,30}};
	cout << minRefuelStops(100, 50, stations);
}