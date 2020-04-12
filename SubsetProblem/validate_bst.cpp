#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <stdio.h>

using namespace std;

struct treeNode {
	int value;              /* value of the node */
	treeNode* left;  /* pointer to the left child node */
	treeNode* right; /* pointer to the right child node */
	treeNode(int val, treeNode* left, treeNode* r):value(val),left(left),right(r)
	{

	}
};

#pragma region Version1 
// namespace std have been included for this problem.
//bool validatesubtreeislessorMode(int nodeValue, treeNode* node, std::function<bool(int, int)> predicate)
//{
//	std::queue<treeNode*> nodes;
//	std::vector<int> nodeValues;
//
//	if (node)
//	{
//		nodes.push(node);
//		nodeValues.push_back(node->value);
//	}
//
//	while (!nodes.empty())
//	{
//		treeNode* aNode = nodes.front();
//		nodes.pop();
//		if (!aNode)
//			return false;
//		if (aNode->left)
//		{
//			nodeValues.push_back(aNode->left->value);
//			nodes.push(aNode->left);
//		}
//
//		if (aNode->right)
//		{
//			nodeValues.push_back(aNode->right->value);
//			nodes.push(aNode->right);
//		}
//	}
//
//	return all_of(nodeValues.begin(), nodeValues.end(), [&](int aValue)->bool {
//		return predicate(aValue, nodeValue);
//	});
//}
//// Add any helper functions(if needed) above.
//bool validate_bst(treeNode* root)
//{
//	if (root)
//	{
//		int nodeValue = root->value;
//
//		bool isleftSubtreeless = validatesubtreeislessorMode(nodeValue, root->left, std::less<int>());
//		bool isRightSubtreeMore = validatesubtreeislessorMode(nodeValue, root->right, std::greater<int>());
//
//		if (!isleftSubtreeless || !isRightSubtreeMore)
//		{
//			return false;
//		}
//
//		validate_bst(root->left);
//		validate_bst(root->right);
//	}
//
//	return true;
//}

#pragma endregion Version1

#pragma region Version2
bool is_bst(treeNode* root, int min, int max)
{
	if (root == nullptr)
	{
		return true;
	}

	if (root->value < min || root->value > max)
	{
		return false;
	}

	return is_bst(root->left, min, root->value - 1) &&
		is_bst(root->right, root->value + 1, max);
}
bool validate_bst(treeNode* root)
{
	return is_bst(root, INT_MIN, INT_MAX);
}
#pragma endregion Version2

void listAll(struct treeNode* root)
{
	int nodes[8];

}
int calculateandprintleafNode(struct treeNode* root)
{
	if (NULL == root)
	{
		return 0;
	}

	if ((NULL == root->left) && (NULL == root->right))
	{
		printf("%d", root->value);
		printf("\n");
		return 1;
	}

	return calculateandprintleafNode(root->left) + calculateandprintleafNode(root->right);
}

void addNode(struct treeNode*& root,struct treeNode* newNode)
{
	if (root == NULL)
	{
		root = newNode;
		return;
	}

	if (newNode->value > root->value)
	{
		addNode(root->right, newNode);
	}
	else
	{
		addNode(root->left, newNode);
	}
}

#include <map>

using namespace std;

// Add any helper functions(if needed) above.
vector<int> twoSum(vector<int>& nums, int target) {
	std::map<char, int> mapofNumberIndex;
	for (int i = 0;i < nums.size(); i++)
	{
		auto it = mapofNumberIndex.find(nums[i]);
		if (it != mapofNumberIndex.end())
		{
			return { it->second,i };
		}
		mapofNumberIndex[nums[i]] = i;
	}
	return {};
}

void main()
{
	//treeNode* node1 = (treeNode*)malloc(sizeof(treeNode));
	//treeNode* node2 = (treeNode*)malloc(sizeof(treeNode));
	//treeNode* node3 = (treeNode*)malloc(sizeof(treeNode));
	//treeNode* node4 = (treeNode*)malloc(sizeof(treeNode));
	//treeNode* node5 = (treeNode*)malloc(sizeof(treeNode));
	//treeNode* node6 = (treeNode*)malloc(sizeof(treeNode));
	//
	//node1->left = NULL;
	//node2->left = NULL;
	//node3->left = NULL;
	//node4->left = NULL;
	//node5->left = NULL;
	//node6->left = NULL;

	//node1->right = NULL;
	//node2->right = NULL;
	//node3->right = NULL;
	//node4->right = NULL;
	//node5->right = NULL;
	//node6->right = NULL;

	//node1->value = 20;
	//node2->value = 40;
	//node3->value = 15;
	//node4->value = 14;
	//node5->value = 30;
	//node6->value = 68;

	///*node1->left = node3;
	//node1->right = node2;
	//node3->left = node4;
	//node3->right = node5;*/

	//addNode(node1,node2);
	//addNode(node1,node3);
	//addNode(node1,node4);
	//addNode(node1,node5);
	//addNode(node1,node6);
	//
	//printf("Leaf Nodes are");
	//printf("\n");

	//printf("Leaf count : %d",calculateandprintleafNode(node1));


	///*bool validate = validate_bst(node1);
	//std::cout << ios::boolalpha << validate;*/
	std::vector<int> v = { 2,7,11,15 };
	twoSum(v, 9);
}

