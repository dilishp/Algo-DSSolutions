#include "pch.h"
#include <iostream>
#include <array>

using namespace std;

class SortedList
{
public:
	void insertItem(int item);
	void deleteItem(int item);
	int getSize() const;
	bool isEmpty();
	void printList();
private:
	int binary_search(int l, int r,int item);
	int m_arr[10];
	int length = 0;
};

void SortedList::insertItem(int item)
{
	//Use Insertion Sort
	if(length >= 10)
		return;

	int insertionIndex = 0;

	if(length == 0)
	{
		insertionIndex = 0;
	}
	else
	{
		insertionIndex = length;
	}
	//Linear Search
	for (int i = 0;i < length;i++)
	{
		if(m_arr[i] > item)
		{
			insertionIndex = i;
			break;
		}
	}

	for (int i = length - 1;i >= insertionIndex ;i--)
	{
		m_arr[i + 1] = m_arr[i];
	}

	m_arr[insertionIndex] = item;
	length++;

}

void SortedList::deleteItem(int item)
{
	//Use Binary Search
	int deletionIndex = binary_search(0, length, item);

	for (int i = deletionIndex; i < length - 1; i++)
	{
		m_arr[i] = m_arr[i + 1];
	}

	length--;
}

int SortedList::getSize() const
{
	return length;
}

bool SortedList::isEmpty()
{
	return (length == 0);
}

void SortedList::printList()
{
	for (int i = 0;i < length;i++)
	{
		cout << "  " << m_arr[i];
	}
}

int SortedList::binary_search(int l, int r,int item)
{
	if(r >= l)
	{
		int m = (l + (r - 1)) / 2;

		if (m_arr[m] == item)
			return m;

		else if (m_arr[m] > item)
		{
			return binary_search(l, m - 1, item);
		}

		return binary_search(m + 1, r, item);
	}
	
	return -1;
}

int main()
{
	SortedList s;
	s.insertItem(1);
	s.insertItem(4);
	s.insertItem(3);
	s.insertItem(2);

	s.printList();

	cout << endl;

	s.deleteItem(3);
	s.deleteItem(2);

	s.printList();

	return 0;

}
