#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;

class Tree 
{
public:
	class Node {
	public:
		Node() : left(nullptr), right(nullptr), data(0) {}
		Node(int val) : left(nullptr), right(nullptr), data(val) {}
		int data;
		Node *left, *right;
	};
	Tree() : count(0), root(nullptr) {}

	bool insert(int newVal);
	friend ostream& operator << (ostream& str, const Tree& tree); // calls print and
	// outputs count
private:
	int getHeight(Node* root) const;
	void printlevel(ostream& ostr, Node* curNode, int level) const;
	void print(ostream& ostr, Node* curNode) const; // recursive function
	Node* root;
	int count;
};

bool Tree::insert(int newval)
{
	Node* newNode = new Node(newval);
	if (nullptr == root)
	{
		root = newNode;
		count++;
		return true;
	}

	Node* tempNode = root;

	while (tempNode)
	{
		if (newval < tempNode->data)
		{
			if (tempNode->left == nullptr)
			{
				tempNode->left = newNode;
				count++;
				return true;
			}
			else
			{
				tempNode = tempNode->left;
			}
		}
		else
		{
			if (tempNode->right == nullptr)
			{
				tempNode->right = newNode;
				count++;
				return true;
			}
			else
			{
				tempNode = tempNode->right;
			}
		}
	}

	return false;
		
}

ostream& operator << (ostream& str, const Tree& tree)
{
	tree.print(str,tree.root);

	return str;
}

//int Tree::getHeight(Node* root) const
//{
//	if (nullptr == root)
//		return 0;
//
//	return max<int>((getHeight(root->left) + 1), (getHeight(root->right) + 1));
//}
//void Tree::printlevel(ostream& ostr, Node* curNode, int level) const
//{
//	if (nullptr == curNode)
//		return;
//	if (level == 1)
//		ostr << curNode->data << " ";
//	else if (level > 1)
//	{
//		printlevel(ostr, curNode->left, level - 1);
//		printlevel(ostr, curNode->right, level - 1);
//	}
//
//}
void Tree::print(ostream& ostr, Node* curNode) const
{
	if (curNode == nullptr)
		return;

	print(ostr, curNode->left);
	ostr << curNode->data << "  ";
	print(ostr, curNode->right);
}

int main()
{
	Tree tree;
	tree.insert(6);
	tree.insert(9);
	tree.insert(3);
	tree.insert(5);
	tree.insert(5);
	tree.insert(7);
	tree.insert(2);
	tree.insert(10);
	tree.insert(4);
	tree.insert(1);
	tree.insert(8);

	cout << tree;
}