#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct TemperatureData
{
	long m_recordId;
	string m_city;
	string m_country;
	char m_rain;
	int m_humidity;
	int m_daytemp[3];
	float m_avgtemp;
};

const TemperatureData tempdata[] = {
	{10212,"Dubai","UAE",'N',20,{40,45,44}},
	{10213,"London","UK",'Y',0,{10,12,8}},
	{10215,"Paris","France",'Y',2,{15,20,12}}
};

void read(TemperatureData t[], int n)
{
	for (size_t i = 0; i < n; i++)
	{
		t[i].m_city = tempdata[i].m_city;
		t[i].m_recordId = tempdata[i].m_recordId;
		t[i].m_country = tempdata[i].m_country;
		t[i].m_humidity = tempdata[i].m_humidity;
		t[i].m_rain = tempdata[i].m_rain;
		for (size_t j = 0;  j < 3;  j++)
		{
			t[i].m_daytemp[j] = tempdata[i].m_daytemp[j];
		}
	}
}

void findavgtemp(TemperatureData t[], int n)
{
	for (size_t i = 0; i < n; i++)
	{
		t[i].m_avgtemp = (float)(t[i].m_daytemp[0] + t[i].m_daytemp[1] + t[i].m_daytemp[2]) / 3;
	}
}

void display(TemperatureData t[], int n)
{
	cout << "Record Id" << setw(20) << "City" << setw(20) << "Country" << setw(20) <<
		"Rain" << setw(20) << "humidity" << setw(20) << "day1" << setw(20) <<
		"day2" << setw(20) << "day3" << setw(20) << "avgTemp";

	cout << endl << endl;
	for (size_t i = 0; i < n; i++)
	{
		cout << t[i].m_recordId << setw(20) << t[i].m_city << setw(20) << t[i].m_country << setw(20) <<
			t[i].m_rain << setw(20) << t[i].m_humidity << setw(20) << t[i].m_daytemp[0] << setw(20) <<
			t[i].m_daytemp[1] << setw(20) << t[i].m_daytemp[2] << setw(20) << t[i].m_avgtemp;
		cout << endl;
	}
}

float findHighestAvgTemp(TemperatureData t[], int n)
{
	float max = t[0].m_avgtemp;
	for (size_t i = 1; i < n; i++)
	{
		if (t[i].m_avgtemp > max)
		{
			max = t[i].m_avgtemp;
		}
	}

	return max;
}

int findCitybyId(TemperatureData t[], int id, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		if (t[i].m_recordId == id)
		{
			return i;
		}
	}

	return -1;
}

void main()
{
	TemperatureData t[3];
	int n = 3;

	read(t, n);

	findavgtemp(t, n);

	display(t, n);

	float maxtemp = findHighestAvgTemp(t, n);

	for (size_t i = 0; i < n; i++)
	{
		if (t[i].m_avgtemp == maxtemp)
		{
			cout << "\n\nThe city with hghest average temperature is : " << t[i].m_city<<"\n";
		}
	}
	long recordId;
	cout << "\nEnter the record Id : ";
	cin >> recordId;

	int index = findCitybyId(t, recordId, n);

	if (index != -1)
	{
		cout << "\n\nThe name of the city with Id " << recordId << " is " << t[index].m_city << "-" << t[index].m_country;
	}
	else
	{
		cout << "\nRecord Not found";
	}
}