#include "pch.h"
#include <iostream>
#include <iomanip>
using namespace std;
struct node {
	int info;
	node *ptrNextNode;
};

node* addNode(node *currentNode, int i);
void printList(node *firstNode);
void deleteNode(node* headNode,int nodeValue);

int main()
{

	node *currentNode = addNode(NULL, 34);
	node *firstNode = currentNode;
	currentNode = addNode(currentNode, 39);
	currentNode = addNode(currentNode, 43);
	currentNode = addNode(currentNode, 23);
	currentNode = addNode(currentNode, 44);
	currentNode = addNode(currentNode, 21);
	currentNode = addNode(currentNode, 22);
	currentNode = addNode(currentNode, 24);
	currentNode = addNode(currentNode, 25);
	currentNode = addNode(currentNode, 26);
	currentNode = addNode(currentNode, 27);
	currentNode = addNode(currentNode, 28);
	currentNode = addNode(currentNode, 30);
	currentNode = addNode(currentNode, 31);
	currentNode = addNode(currentNode, 32);
	currentNode = addNode(currentNode, 33);
	currentNode = addNode(currentNode, 34);
	currentNode = addNode(currentNode, 35);
	currentNode = addNode(currentNode, 36);
	currentNode = addNode(currentNode, 37);
	currentNode = addNode(currentNode, 38);


	printList(firstNode);

	deleteNode(firstNode, 22);

	printList(firstNode);

	return 0;
}
//Add a new node

node *addNode(node *currentNode, int i)
{
	//create a new node
	node *firstNode = new node;
	// add to the end of the list
	if (currentNode == NULL)
	{
		firstNode->info = i;
		firstNode->ptrNextNode = NULL;
	}
	else
	{
		firstNode->info = i;
		currentNode->ptrNextNode = firstNode;
		firstNode->ptrNextNode = NULL;
	}
	return firstNode;

}

void printList(node* currentNode)
{

	while (currentNode != NULL)
	{
		cout << currentNode->info << " ";
		currentNode = currentNode->ptrNextNode;

	}

	cout << "\n\n";

}

void deleteNode(node* headNode,int nodeValue)
{
	if (nullptr == headNode)
	{
		cout << "List is Empty";
		return;
	}

	node* aNode = headNode;
	node* prevNode = nullptr;

	while (nullptr != aNode)
	{
		if (aNode->info == nodeValue)
		{
			break;
		}
		prevNode = aNode;
		aNode = aNode->ptrNextNode;
	}

	if (aNode == nullptr)
	{
		cout << "Node Not Found";
		return;
	}

	if (prevNode != nullptr)
	{
		prevNode->ptrNextNode = aNode->ptrNextNode;
		delete aNode;
	}

}