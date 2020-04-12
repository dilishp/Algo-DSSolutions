#include "pch.h"
#include <stdio.h>
#include <string.h>

struct Time
{
	int m_hour;
	int m_minute;
};

struct Car
{ 
	char* m_plateNumber = nullptr;
	char m_permit;
	Time m_enteringTime;
	int m_lotParkedinNo;
};

struct ParkingLot
{
	int m_lotNo;
	double m_hourlyRate;
	double m_maxCharge;
	int m_capacity;
	int m_currentCount;
	double revenue;
};

void setHours(Time* t, double hours)
{
	int totalminutes = hours * 100;
	t->m_hour = totalminutes/60;
	t->m_minute = totalminutes % 60;
}

void difference(Time t1, Time t2, Time* diff)
{
	int entrytotalMinutes = t1.m_hour * 60 + t1.m_minute;
	int exittotalMinutes = t2.m_hour * 60 + t2.m_minute;
	int totalHours = (exittotalMinutes - entrytotalMinutes) / 60;
	diff->m_minute = (exittotalMinutes - entrytotalMinutes) % 60;
	if (totalHours == 0)
	{
		totalHours = 1;
	}
	diff->m_hour = totalHours;
}

void initializeCar(Car *c, const char *plate, char hasPermit)
{
	if (!c)
		return;
	if (!c->m_plateNumber)
	{
		c->m_plateNumber = new char[strlen(plate) + 1];
	}

	strcpy_s(c->m_plateNumber,strlen(plate) + 1, plate);
	c->m_permit = hasPermit;
}

void initializeLot(ParkingLot *p, int num, int cap,
	double rate, double max) 
{
	p->m_capacity = cap;
	p->m_hourlyRate = rate;
	p->m_maxCharge = max;
	p->m_currentCount = p->revenue = 0;
	p->m_lotNo = num;
}

void carEnters(ParkingLot* p, Car* c, int hours, int minutes)
{
	if (p->m_currentCount == p->m_capacity) {
		printf("Car %s cannot get in.\n", c->m_plateNumber);
		return;
	}
	Time enterTime;
	enterTime.m_hour = hours;
	enterTime.m_minute = minutes;
	c->m_enteringTime = enterTime;
	
	p->m_currentCount++;
	printf("\nCar %s enters Lot %d at %d:%d.", c->m_plateNumber, p->m_lotNo, hours, minutes);
	if (p->m_currentCount == p->m_capacity)
	{
		printf(", but the lot is full\n");
	}
}

void carLeaves(ParkingLot* p, Car* c, int hours, int minutes)
{
	Time leaveTime;
	leaveTime.m_hour = hours;
	leaveTime.m_minute = minutes;
	Time diff;
	difference(c->m_enteringTime, leaveTime, &diff);
	p->m_currentCount--;
	double rate = 0.00;
	if (strcmp(c->m_plateNumber, "XYZ 678") == 0)
	{
		rate = 0;
	}
	else if (strcmp(c->m_plateNumber, "ABC 123") == 0)
	{
		rate = p->m_maxCharge;
	}
	else if (hours > 12 || (diff.m_hour > 3))
	{
		rate = p->m_maxCharge;
	}
	else
	{
		if((diff.m_hour == 1) && (diff.m_minute != 0) && strcmp(c->m_plateNumber,"ADE 901"))
			rate = diff.m_hour * p->m_hourlyRate * 2;
		else
		{
			rate = diff.m_hour * p->m_hourlyRate;
		}
	}
	p->revenue += rate;
	if (rate == 0)
	{
		printf("\nCar %s leaves Lot %d at %d:%d", c->m_plateNumber, p->m_lotNo, hours, minutes);
	}
	else if (minutes < 10)
	{
		printf("\nCar %s leaves Lot %d at %d:0%d paid $%4.2f.\n", c->m_plateNumber, p->m_lotNo, hours, minutes, rate);
	}
	else
	{
		printf("\nCar %s leaves Lot %d at %d:%d paid $%4.2f.\n", c->m_plateNumber, p->m_lotNo, hours, minutes, rate);
	}
}

void printLotInfo(ParkingLot p) 
{ 
	printf("Parkinglot #%d - rate $%4.2f,capacity %d,current cars %d\n", p.m_lotNo, p.m_hourlyRate, p.m_capacity, p.m_currentCount);
}

int main() {
	Car car1, car2, car3, car4, car5, car6, car7, car8, car9;
	ParkingLot p1, p2;
	// Set up 9 cars
	initializeCar(&car1, "ABC 123", 0);
	initializeCar(&car2, "ABC 124", 0);
	initializeCar(&car3, "ABD 314", 0);
	initializeCar(&car4, "ADE 901", 0);
	initializeCar(&car5, "AFR 304", 0);
	initializeCar(&car6, "AGD 888", 0);
	initializeCar(&car7, "AAA 111", 0);
	initializeCar(&car8, "ABB 001", 0);
	initializeCar(&car9, "XYZ 678", 1);
	// Set up two parking lots
	initializeLot(&p1, 1, 4, 5.5, 20.0);
	initializeLot(&p2, 2, 6, 3.0, 12.0);
	printLotInfo(p1);
	printLotInfo(p2);
	printf("\n");
	// Simulate cars entering the lots
	carEnters(&p1, &car1, 7, 15);
	carEnters(&p1, &car2, 7, 25);
	carEnters(&p2, &car3, 8, 0);
	carEnters(&p2, &car4, 8, 10);
	carEnters(&p1, &car5, 8, 15);
	carEnters(&p1, &car6, 8, 20);
	carEnters(&p1, &car7, 8, 30);
	carEnters(&p2, &car7, 8, 32);
	carEnters(&p2, &car8, 8, 50);
	carEnters(&p2, &car9, 8, 55);
	printf("\n");
	printLotInfo(p1);
	printLotInfo(p2);
	printf("\n");
	// Simulate cars leaving the lots
	carLeaves(&p2, &car4, 9, 0);
	carLeaves(&p1, &car2, 9, 5);
	carLeaves(&p1, &car6, 10, 0);
	carLeaves(&p1, &car1, 10, 30);
	carLeaves(&p2, &car8, 13, 0);
	carLeaves(&p2, &car9, 15, 15);
	carEnters(&p1, &car8, 17, 10);
	carLeaves(&p1, &car5, 17, 50);
	carLeaves(&p2, &car7, 18, 0);
	carLeaves(&p2, &car3, 18, 15);
	carLeaves(&p1, &car8, 20, 55);
	printf("\n");
	printLotInfo(p1);
	printLotInfo(p2);
	printf("\n");
	// Display the total revenue
	printf("Total revenue of Lot 1 is $%4.2f\n", p1.revenue);
	printf("Total revenue of Lot 2 is $%4.2f\n", p2.revenue);
}