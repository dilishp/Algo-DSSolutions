#include "pch.h"
#include <iostream>
#include <utility>
#include <cstdlib>
#include <string>

using namespace std;

template<typename T>
class PriorityQ
{
public:
	typedef T value_type;
	typedef size_t size_type;
	static const size_type CAPACITY = 50;
	PriorityQ() {
		used = 0;
	}

	void push(const value_type& entry, size_type priority);

	void pop();

	value_type front() const;

	size_type size() const { return used; }

	bool empty() const { return used == 0; }

private:
	size_type used;
	pair<value_type, size_type> data[CAPACITY];
	size_type findMaxPriority() const;

};


template<typename T>
void PriorityQ<T>::push(const T& entry, size_t priority)
{
	if (used < CAPACITY)
	{
		std::pair<value_type,size_type> p(entry, priority);
		data[used] = p;
		used++;
	}
}

template<typename T>
void PriorityQ<T>::pop()
{
	size_type maxPriorityIndex = findMaxPriority();

	for (size_t i = maxPriorityIndex; i < used - 1; i++)
	{
		data[i] = data[i + 1];
	}

	used--;
}

template<typename T>
T PriorityQ<T>::front() const
{
	size_t maxPriorityIndex = findMaxPriority();

	return data[maxPriorityIndex].first;
}

template<typename T>
size_t PriorityQ<T>::findMaxPriority() const
{
	size_type maxPriority = data[0].second;
	size_type maxPriorityIndex = 0;
	for (size_t i = 1; i < used; i++)
	{
		if (data[i].second > maxPriority)
		{
			maxPriority = data[i].second;
			maxPriorityIndex = i;
		}
	}

	return maxPriorityIndex;
}

int main()
{
	PriorityQ<string> pq;

	pq.push("Get Food", 10);
	pq.push("Do Laundary", 8);
	pq.push("Sleep", 10);
	pq.push("Feed Pet", 7);

	cout << "\n The contents of the queue are : ";

	while (pq.size())
	{
		cout << pq.front() << "\n";
		pq.pop();
	}

	return 0;
}
