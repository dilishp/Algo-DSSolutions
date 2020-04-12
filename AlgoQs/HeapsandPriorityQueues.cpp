//Using C++ use STL vector class to implement a heap class and then use the heap class to implement a priority_queue class (Section 8.4 in the textbook).You need to construct a test program to help test the correctness of your code.
//
//————————
//
//heap.h
#include "pch.h"
#ifndef _HEAP_H_
#define _HEAP_H_

#include <iostream>
#include <vector>
#include <algorithm>

// This class implements an unbounded max heap.

// class invariant: heap property is satisfied for a max heap

template <typename T>
class heap
{
public:
	heap();
	// postcondition: empty heap has been created
	unsigned int size() const;
	// postcondition: number of elements in a heap has been returned
	bool is_empty() const;
	// postcondtion: returned whether the heap is empty
	void insert(const T& item);
	// postcondition: item has been added
	void remove();
	// precondition: heap is not empty
	// postcondition: largest item has been removed from the heap
	T max() const;
	// precondition: heap is not empty
	// postcondition: copy of largest element in the heap has been returned
	T& max();
	// precondition: heap is not empty
	// postcondition: access to largest element in the heap has been returned
private:
	std::vector<T> v;
	unsigned int max_child(unsigned int index) const;
	// precondition: element at index has children
	// postcondition: index of the larger child has been returned
	// if there is only 1 child - index of that child has been returned
};

//#include "heap.template"

#endif // _HEAP_H_


//—————————

//priority_queue.h

#ifndef _PRIORITY_QUEUE_H
#define _PRIORITY_QUEUE_H

//#include "heap.h"

template <typename T>
class priority_queue
{
public:
	priority_queue()
	{

	}
	// postcondition: empty priority_queue has been created
	void pop()
	{
		h.remove();
	}
	// precondition: priority_queue is not emtpy
	// postcondition: highest priority item has been removed
	void push(const T& item)
	{
		h.insert(item);
	}
	// postcondition: item has been inserted
	bool empty() const
	{
		return h.is_empty();
	}
	// postcondition: returned whether priority queue is empty
	unsigned int size() const
	{
		return h.size();
	}
	// postcondition: returned number of items in the priority queue
	T top() const
	{
		return h.max();
	}
	// precondition: priority queue is not empty
	// postcondition: copy of highest priority item has been returned
private:
	heap<T> h;
};

//#include "priority_queue.template"

#endif // _PRIORITY_QUEUE_H

template<typename T>
heap<T>::heap()
{
	v.clear();
}

template<typename T>
unsigned int heap<T>::size() const
{
	return v.size();
}

template<typename T>
bool heap<T>::is_empty() const
{
	return (v.size() == 0);
}

template<typename T>
void heap<T>::insert(const T & item)
{
	v.push_back(item);

	//Check if Max-Heap Property is maintained or not
	//Bottom-Up Approach
	//Heapify Again after each insertions
	//Heapification is the process to check if the root node
	//is less than one of its childs then swap will happen
	//in the case of a Max Heap
	int n = v.size();
	for (int i = (n/2); i >= 1; --i)
	{
		int maxChild = max_child(i);

		if (v[i - 1] < v[maxChild])
		{
			std::swap(v[i - 1], v[maxChild]);
		}
	}
}

template<typename T>
void heap<T>::remove()
{
	if (is_empty())
		return;

	std::swap(v[0], v[v.size() - 1]);

	v.pop_back();

	//heapify
	//While deleting a node from the heap 
	//Swap the max Node with the last Node and 
	//Do Heapify again and remove the last node
	int n = v.size();
	for (size_t i = n/2; i >= 1; --i)
	{
		int maxChild = max_child(i);

		if (v[i - 1] < v[maxChild])
		{
			std::swap(v[i - 1], v[maxChild]);
		}
	}
}

template<typename T>
T heap<T>::max() const
{
	return v[0];
}

template<typename T>
T & heap<T>::max()
{
	return v[0];
}

template<typename T>
unsigned int heap<T>::max_child(unsigned int index) const
{
	//Returns the max child of the two childs of a node
	int leftchild = 2 * index;
	int rightchild = 2 * index + 1;
	int n = v.size();
	if (leftchild - 1 < n && rightchild - 1 < n)
	{
		return v[leftchild - 1] > v[rightchild - 1] ?
			leftchild - 1 : rightchild - 1;
	}

	if (leftchild - 1 < n)
	{
		return leftchild - 1;
	}

	if (rightchild - 1 < n)
	{
		return rightchild - 1;
	}

	return 0;
}

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>

class Heap {

public:
	void push(int value); // insert value; //duplicates are allowed
	void pop(); // delete the min element
	int top();
	bool empty();

private:
	unsigned int min_child(unsigned int index) const;
	std::vector<int> vdata; //store the binary heap tree as a dynamic array
};

#endif

// please implement

//#include "heap.h"
#include <iostream>
using std::cout;

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value) {
	vdata.push_back(value);

	//Check if Min-Heap Property is maintained or not
	//Bottom-Up Approach
	int n = vdata.size();
	for (int i = (n / 2); i >= 1; --i)
	{
		int minChild = min_child(i);

		if (vdata[minChild] < vdata[i - 1])
		{
			std::swap(vdata[i - 1], vdata[minChild]);
		}
	}
}

//Finds teh minimum child among the left or right child
unsigned int Heap::min_child(unsigned int index) const
{
	int leftchild = 2 * index;
	int rightchild = 2 * index + 1;
	int n = vdata.size();
	if (leftchild - 1 < n && rightchild - 1 < n)
	{
		return vdata[leftchild - 1] > vdata[rightchild - 1] ?
			rightchild - 1 : leftchild - 1;
	}

	if (leftchild - 1 < n)
	{
		return leftchild - 1;
	}

	if (rightchild - 1 < n)
	{
		return rightchild - 1;
	}

	return 0;
}
// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop() {
	if (vdata.size() == 0)
		return;

	std::swap(vdata[0], vdata[vdata.size() - 1]);

	vdata.pop_back();

	//heapify
	int n = vdata.size();
	for (size_t i = n / 2; i >= 1; --i)
	{
		int minChild = min_child(i);

		if (vdata[minChild] < vdata[i - 1])
		{
			std::swap(vdata[i - 1], vdata[minChild]);
		}
	}
}

// Returns the minimum element in the heap
int Heap::top() {
	//returns the topmost element
	return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty() {
	return vdata.size() == 0;
}

int main()
{
	heap<int> maxHeap;

	maxHeap.insert(1);
	maxHeap.insert(2);
	maxHeap.insert(4);
	maxHeap.insert(10);
	maxHeap.insert(8);
	maxHeap.insert(3);


	//insert 99
	maxHeap.insert(99);


	std::cout <<"Max Element of the Heap is " << maxHeap.max();

	//Removing the maxElement

	maxHeap.remove();

	cout << "\nMax Heap after the removal of the max element :\n";
	while (!maxHeap.is_empty())
	{
		cout <<"   "<< maxHeap.max();
		maxHeap.remove();
	}

	return 0;
}