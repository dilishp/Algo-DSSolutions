#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iomanip>

using namespace std;

class BinarySearchTree
{
public:
	char *charArray;
	BinarySearchTree(int);
	void insertNode(char);
	int extendSize(int);
	void preOrder();
	void preOrderTraverse(int);
	void postOrder();
	void postOrderTraverse(int);
	void display();

};

BinarySearchTree::BinarySearchTree(int charSize)
{
	int newSize = extendSize(charSize);

	charArray = new char[newSize];
	for (int x = 0; x < newSize; x++)
	{
		charArray[x] = NULL;
	}
}

int BinarySearchTree::extendSize(int x)
{
	int value = 0;
	for (int y = 0; y < x + 1; y++)
	{
		value = (2 * value) + 2;
	}
	return value;
}

void BinarySearchTree::insertNode(char x)
{
	int   currentIndex = 0;
	while (true)
	{
		if (charArray[currentIndex] == NULL)
		{
			charArray[currentIndex] = x;
			break;
		}
		else if (charArray[currentIndex] <= x)
		{
			if (charArray[currentIndex] == x)
			{
				break;
			}
			currentIndex = (2 * currentIndex + 2);
		}
		else if (charArray[currentIndex] >= x)
		{
			if (charArray[currentIndex] == x)
			{
				break;
			}
			currentIndex = (2 * currentIndex + 1);
		}
	}
}

void BinarySearchTree::preOrder()
{
	preOrderTraverse(0);
}

void BinarySearchTree::preOrderTraverse(int root)
{
	if (charArray[root] >= 65 && charArray[root] <= 90)
	{
		cout << charArray[root] << "\n";
		preOrderTraverse(2 * root + 1);
		if (charArray[root] < 65 && charArray[root] > 90)
		{
			preOrderTraverse((root - 1) / 2);
		}
		preOrderTraverse(2 * root + 2);
	}
}

void BinarySearchTree::postOrder()
{
	postOrderTraverse(0);

}

void BinarySearchTree::postOrderTraverse(int root)
{
	if (charArray[root] >= 65 && charArray[root] <= 90)
	{
		postOrderTraverse(2 * root + 1);
		postOrderTraverse(2 * root + 2);
		if (charArray[root] < 65 && charArray[root] > 90)
		{
			postOrderTraverse((root - 1) / 2);
		}
		cout << charArray[root] << "\n";
	}
}

void BinarySearchTree::display()
{
	for (int i = 0; i < 300; i++)
	{
		if (charArray[i] == NULL)
		{
			cout << (i + 1) << ":\tempty\n";
		}
		else
		{
			cout << (i + 1) << ":\t" << charArray[i] << "\n";
		}
	}
}

void generatingChars(char[], int size);

int main()
{
	char charArray[13];
	char anything;
	BinarySearchTree tree(13);
	generatingChars(charArray, 13);
	cout << "Binary Search Tree By Derek Sliva.\n\n";
	cout << "The generated characters are : ";
	for (int i = 0; i < 13; i++)
	{

		cout << charArray[i] << " ";
	}
	cout << "\n\n";
	cout << "Inserting Nodes.\n\n";
	for (int i = 0; i < 13; i++)
	{
		anything = charArray[i];
		tree.insertNode(anything);
	}
	cout << "Building BST is completed.\n\n";
	cout << "Values of the Binary Search tree.\n\n";
	tree.display();
	// Pre-Order Traversal .
	cout << "\nPre-Order Traversal of the BST :\n\n";
	tree.preOrder();
	// Post-Order Traversal .
	cout << "\nPost-Order Traversal of the BST :\n\n";
	tree.postOrder();
	// All right sub root values.
	cout << "\nHere are all right sub root values for the BST:\n\n";
//	tree.displayRSR();
	// All left sub root values.
	cout << "\n\nHere are all left sub root values for theBST :\n\n";
	//tree.displayLSR();
	// Counting Number of Leafs .
	//cout << "\n\nNumber of Leafs = " << tree.treeLeafsCount() ;
	// Display the leaf values.
	cout << "\n\nHere are the leaf values in the BST:\n\n";
	//tree.displayLeafValues();
	cout << "\n\n\Derek Sliva - May 1 , 2019\n\n";
}

void generatingChars(char charArray[], int size)
{
	srand(time(NULL));

	for (int i = 0; i < size; i++)
	{
		charArray[i] = (65 + (rand() % (90 - 65)));
	}

}
