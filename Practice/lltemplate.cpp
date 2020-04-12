#include "pch.h"
#include <iostream>
#include <stdexcept>

template <class T>
struct ListNode
{
	T data;
	ListNode<T>* next;
	ListNode<T>* prev;

	ListNode() {
		next = nullptr;
		prev = nullptr;
		//Call default constructor for type T
		// produces 0 for primitive types
		data = T();
	}

	ListNode(T value) {
		next = nullptr;
		prev = nullptr;
		data = value;
	}
};

//Forward declate DoublyLinkedList so we can make it a friend
template<class T>
class DoublyLinkedList;


template<class T>
class LinkedListIterator
{
	//Give DoublyLinkedList access to private information
	friend class DoublyLinkedList<T>;

private:
	ListNode<T>* currentNode;

public:
	//Constructor - takes pointer to ListNode
	LinkedListIterator(ListNode<T>* const location)
	{
		currentNode = location;
	}

	//Dereference iterator to retrieve data in current node
	// return reference to allow modification
	T& operator*()
	{
		///TODO - return data from current node
		return *currentNode->data;
	}

	//Advance iterator position by one
	LinkedListIterator& operator++()
	{

		++currentNode;
		return *this;
	}

	//Compare two iterators with ==
	bool operator==(const LinkedListIterator& other) const
	{
		return currentNode == other.currentNode;
	}

	//Compare two iterators with !=
	bool operator!=(const LinkedListIterator& other) const
	{
		return currentNode != other.currentNode;
	}
};


template <class T>
class DoublyLinkedList
{
protected:
	ListNode<T>* head;
	ListNode<T>* tail;
	int length;

public:

	///-------------New Iterator Stuff-----------------------

	/**
	 * @brief Get iterator pointing to first thing in list (item after dummy head node)
	 */
	LinkedListIterator<T> begin();

	/**
	 * @brief Get iterator pointing to location after last thing in list (always the dummy)
	 */
	LinkedListIterator<T> end();

	/**
	 * @brief Find desired value in the list, return an iterator to that value
	 *          or to end() if value not found
	 */
	LinkedListIterator<T> findValue(const T& value);

	/**
	 * @brief Insert given value
	 */
	void insert(LinkedListIterator<T> location, const T& value);

	/**
	 * @brief Take an iterator and delete the node it points to
	 * @return Iterator pointing to node after one deleted
	 */
	LinkedListIterator<T> erase(LinkedListIterator<T> location);


	///---------------Other stuff-------------------------------
	DoublyLinkedList();
	~DoublyLinkedList();

	int listSize();

	void insertAt(int index, T value);
	void removeAt(int index);
	T retrieveAt(int index);

	template <class R>
	friend ostream& operator <<(ostream& os, const DoublyLinkedList<R>& theList);
};

///-------------New Iterator Stuff-----------------------

template <class T>
LinkedListIterator<T> DoublyLinkedList<T>::begin() {
	//Construct iterator that points to item after head
	return LinkedListIterator<T>(head->next);
}

template <class T>
LinkedListIterator<T> DoublyLinkedList<T>::end() {
	//Construct iterator that points to tail
	return LinkedListIterator<T>(tail);
}

template <class T>
void DoublyLinkedList<T>::insert(LinkedListIterator<T> location, const T& value) {
	//Make a new node with desired value
	ListNode<T>* newNode = new ListNode<T>(value);

	LinkedListIterator<T> aNode.currentNode = head;
	while (aNode.currentNode != tail)
	{
		if (aNode.currentNode == location.currentNode)
		{
			newNode->next = aNode.currentNode->next;
			newNode->prev = aNode.currentNode->next->prev;
			aNode.currentNode->next->prev = newNode;
			aNode.currentNode->next = newNode;
			break;
		}
		aNode.currentNode++;
	}
	length++;
}

template <class T>
LinkedListIterator<T> DoublyLinkedList<T>::erase(LinkedListIterator<T> location) {
	if (location.currentNode == tail || location.currentNode == head)     //Don't allow erasure of dummys
		return location;

	LinkedListIterator<T> aNode.currentNode = head;
	LinkedListIterator<T> prevNode;
	while (aNode.currentNode != tail)
	{
		if (aNode.currentNode == location.currentNode)
		{
			prevNode.currentNode->next = aNode.currentNode->next;
			aNode.currentNode->next->prev = aNode.currentNode->prev;
			break;
		}
		prevNode.currentNode = aNode.currentNode;
		aNode.currentNode++;
	}

	return ++aNode;
	
}


template <class T>
LinkedListIterator<T> DoublyLinkedList<T>::findValue(const T& value) {
	//Get an iterator to head
	LinkedListIterator<T> currentIt = begin();

	while (currentIt != end())
	{
		if (currentIt.currentNode->data == value)
		{
			break;
		}
		currentIt.currentNode++;
	}

	return currentIt;
}




