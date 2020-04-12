#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

struct Smaple
{
	void print();
};

void Smaple::print()
{
	cout << "Hello";
}

template<typename Item>
class heap
{
public:
	int getParent(int& i) { return (i - 1) / 2; }
	void push(const Item& entry)
	{
		int i = used;
		data[used++] = entry;

		while (i != 0 && data[getParent(i)] > data[i])
		{
			swap(data[getParent(i)], data[i]);
			i = parent(i);
		}
	}
	int left(int i) { return (2 * i + 1); }

	int right(int i) { return (2 * i + 2); }

	void MinHeapify(int i)
	{
		int l = left(i);
		int r = right(i);
		int smallest = i;
		if (l < used && data[l] < data[i])
			smallest = l;
		if (r < used && data[r] < data[smallest])
			smallest = r;
		if (smallest != i)
		{
			swap(&data[i], &data[smallest]);
			MinHeapify(smallest);
		}
	}
	Item pop()
	{
		Item max = data[used - 1];
		data[0] = data[used - 1];
		used--;
		MinHeapify(0);
		return max;
	}
private:
	Item data[20];
	size_t used;
};

class StringList
{
	int findLetter(StringList* node,char letter)
	{
		static int letterCount = 0;							//Initialise the count varable as static to maintain its state
															//across function call

		if (node == nullptr)						//Exit Condition at the end of the list
		{
			return letterCount;						//Return the letter count value at the end
		}

		for (char ch : node->text)				//Taking each string from the node and counting the number
												//of matching characters
		{
			if (ch == letter)
			{
				letterCount++;
			}
		}
		findLetter(node->next,letter);			//Recursive call to the function to move to the next node
	}

private:
	string text;
	StringList* prev;
	StringList* next;
};

void main()
{
	int ary[] = { 23,12,3,-4,-10,35,11,8,18 };
	int index = 0;
	int min = ary[0];
	int arraysize = sizeof(ary) / sizeof(ary[0]);
	while (index < arraysize)
	{
		if (ary[index] < min)
		{
			min = ary[index];
		}
		index++;
	}

	cout << "Min Element : " << min;
}