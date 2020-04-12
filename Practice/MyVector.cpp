#include "pch.h"
#include <iostream>

using namespace std;

class MyVector {

	struct Node {

		int value;

		Node *next;

		Node(int val, Node* ptr) :value(val), next(ptr)
		{

		}
	};

	Node *head, *tail;

public:

	MyVector() = default;


	~MyVector()
	{
		clear();
	}

	void push_back(int i)
	{
		if (!head)
		{
			head = new Node(i, nullptr);
			return;
		}
		Node* nodeptr = head;
		while (nodeptr->next != nullptr)
		{
			nodeptr = nodeptr->next;
		}

		Node* newNode = new Node(i, nullptr);
		nodeptr->next = newNode;
	}

	void pop_back()
	{
		if (!head)
		{
			return;
		}

		Node* nodeptr = head;
		Node* prevNode = nullptr;
		while (nodeptr->next != nullptr)
		{
			prevNode = nodeptr;
			nodeptr = nodeptr->next;
		}

		delete nodeptr;

		prevNode->next = nullptr;
	}

	int &at(int i)
	{
		if (i < size())
		{
			Node* nodeptr = head;
			for (int index = 0;index < i;index++)
			{
				nodeptr = nodeptr->next;
			}

			return nodeptr->value;
		}
	}

	void clear()
	{
		if (!head)
		{
			return;
		}
		Node* nodeptr = head;
		while (nodeptr->next != nullptr)
		{
			Node* prevNode = nodeptr;
			nodeptr = nodeptr->next;
			delete prevNode;
		}

		delete nodeptr;
	}

	int size()
	{
		int nNodeCount = 0;
		Node* nodeptr = head;
		while (nodeptr->next != nullptr)
		{
			nNodeCount++;
			nodeptr = nodeptr->next;
		}
		return nNodeCount;
	}

	void insert(int pos, int i)
	{
		if (pos > size())
		{
			return;
		}

		Node* nodeptr = head;
		Node* prevNode = nullptr;
		
		for (int index = 0;index < pos;index++)
		{
			prevNode = nodeptr;
			nodeptr = nodeptr->next;
		}

		Node* newNode = new Node(i, nodeptr);

		prevNode->next = newNode;

	}

};

int main()
{
	/*system("clear");

	MyVector v;

	for (int i = 0; i < 15; i++)
		v.push_back(1 + rand() % 100);

	for (int i = 0; i < v.size(); i++)
		cout << v.at(i) << " ";

	cout << v.size() << endl;

	v.at(3) = -22;

	cout << v.at(3) << endl;

	try
	{
		v.insert(3, -88);
		for (int i = 0; i < v.size(); i++)
			cout << v.at(i) << " ";

		cout << endl;
	}
	catch (const char* e)
	{
		cout << e << endl;
	}


	try
	{
		v.pop_back();
		for (int i = 0; i < v.size(); i++)
			cout << v.at(i) << " ";

	}
	catch (const char* e)
	{
		cout << e << endl;
	}*/

	const char* ptr = "Hello\
	world";
	cout << ptr;

}