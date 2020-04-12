#include "pch.h"
#include <List>
#include <iostream>
#include <string>
#include <algorithm>

class Event
{
	int m_hour;
	int m_day;
	int m_month;
	int m_year;
	static int id;
	int m_id;

public:
	Event(int hour, int day, int month, int year):m_hour(hour),m_day(day),m_month(month),m_year(year)
	{
		m_id = id++;
	}

	virtual void print() = 0;

	int getId()
	{
		return m_id;
	}
	int getDay()
	{
		return m_day;
	}

	int getHour()
	{
		return m_hour;
	}

	int getMonth()
	{
		return m_month;
	}

	int getYear()
	{
		return m_year;
	}
};

int Event::id = 0;

class Task:public Event
{
	std::string m_taskname;

public:
	Task(std::string taskName, int hour, int day, int month, int year) :m_taskname(taskName),Event(hour,day,month,year)
	{

	}

	void print()
	{
		std::cout << "Task with id " << getId() << " at " << getDay() << "/" << getMonth() << "/" << getYear() << "," << getHour() << ":00;" << std::endl;
		std::cout << m_taskname;
		std::cout << std::endl;
	}
};

class Appointment :public Event
{
	std::string m_personName;

public:
	Appointment(std::string personName, int hour, int day, int month, int year) :m_personName(personName), Event(hour, day, month, year)
	{

	}

	void print()
	{
		std::cout << "Appointment with id " << getId() << " at " << getDay() << "/" << getMonth() << "/" << getYear() << "," << getHour() << ":00;" << std::endl;
		std::cout << m_personName;
		std::cout << std::endl;
	}
};


class Calendar
{
	std::list<Event*> m_listofEvents;

public:
	Event* addEvent(int eventType, int year, int month, int day, int hour)
	{
		static int count = 0;
		Event* anEvent = nullptr;
		switch(eventType)
		{
		case 0:
		{
			count++;
			std::string taskName;
			std::cout << "Enter the Task Name for Task "<<count<<" ";
			std::getline(std::cin, taskName);
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			anEvent = new Task(taskName, hour, day, month, year);
			break;
		}
		case 1:
		{
			count++;
			std::string personName;
			std::cout << "Enter the Person Name for Appointment" << count<<" ";
			std::getline(std::cin, personName);
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			anEvent = new Appointment(personName, hour, day, month, year);
			break;
		}
		default:
			break;
		}
		
		m_listofEvents.push_back(anEvent);
		return anEvent;
	}

	void deleteEvent(int id)
	{
		m_listofEvents.remove_if([&](Event* anEvent)->bool {
			return (anEvent->getId() == id);
		});
	}

	void listEvents()
	{
		for (Event* anEvent : m_listofEvents)
		{
			if (anEvent)
				anEvent->print();
		}
	}

	void filterEvents(int year, int month)
	{
		for (Event* anEvent : m_listofEvents)
		{
			if ((anEvent->getMonth() == month)
				&& (anEvent->getYear() == year))
			{
				anEvent->print();
			}
		}
	}
};

void main()
{
	Calendar calendar;
	
	calendar.addEvent(0, 2019, 4, 10, 23);
	calendar.addEvent(0, 2019, 5, 6, 22);
	calendar.addEvent(0, 2019, 4, 5, 20);
	calendar.addEvent(0, 2019, 2, 19, 19);
	calendar.addEvent(0, 2019, 5, 1, 21);

	calendar.addEvent(1, 2019, 4, 1, 23);
	calendar.addEvent(1, 2019, 5, 16, 22);
	calendar.addEvent(1, 2019, 4, 15, 20);
	calendar.addEvent(1, 2019, 2, 9, 19);
	calendar.addEvent(1, 2019, 5, 1, 21);

	std::cout << "\n Listing Events \n";
	calendar.listEvents();

	calendar.deleteEvent(3);

	std::cout << "\n Listing Events after Filtering \n";

	calendar.filterEvents(2019, 4);

}