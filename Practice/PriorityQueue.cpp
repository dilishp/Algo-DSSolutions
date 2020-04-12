#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
class vpriority_queue
{
public:
	vpriority_queue()
	{
		maxIndex = 0;
		recomputeMaxIndex = false;
	}

	void push(const T& item)
	{
		pqVector.push_back(item);
		recomputeMaxIndex = true;
	}

	void pop() throw()
	{
		if (pqVector.empty())
		{
			throw std::exception("Underflow exception");
		}

		if (recomputeMaxIndex)
		{
			maxIndex = findMaxIndex();
			recomputeMaxIndex = false;
		}

		pqVector[maxIndex] = pqVector.back();
		pqVector.pop_back();

		recomputeMaxIndex = true;
	}

	T& top()
	{
		if (pqVector.empty())
		{
			throw std::exception("Underflow exception");
		}

		if (recomputeMaxIndex)
		{
			maxIndex = findMaxIndex();
			recomputeMaxIndex = false;
		}

		return pqVector[maxIndex];
	}

	const T& top() const
	{
		return top();
	}

	bool empty() const
	{
		return pqVector.empty();
	}

	int size() const
	{
		return pqVector.size();
	}

private:
	std::vector<T> pqVector;
	int maxIndex;
	bool recomputeMaxIndex;

	int findMaxIndex() const
	{
		auto itr = std::max_element(pqVector.begin(), pqVector.end());
		return std::distance(pqVector.begin(), itr);
	}
};

void main()
{
	int arr[5] = { 6,2,3,5,4 };

	vpriority_queue<int> pq;


	for (size_t i = 0; i < 5; i++)
	{
		pq.push(arr[i]);
	}

	std::cout << pq.top() << "   ";
	pq.pop();

	std::cout << pq.top() << "   ";
	pq.pop();

	pq.push(10);

	pq.push(1);

	std::cout << pq.top() << "  ";
	pq.pop();

	std::cout << pq.top() << "  ";
	pq.pop();

}