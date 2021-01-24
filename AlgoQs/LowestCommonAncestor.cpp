#include "pch.h"
#include <iostream>


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int lca(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& res)
{
    if (NULL == root)
        return 0;

    int curNodeCount = 0;

    if (root->val == p->val ||
        root->val == q->val)
        ++curNodeCount;

    int l = lca(root->left, p, q, res);
    int r = lca(root->right, p, q, res);
	
    if (res == NULL && (curNodeCount + l + r) == 2)
    {
        res = root;
    }

    return curNodeCount + l + r;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* res = NULL;
    lca(root, p, q, res);
    return res;
}

int main()
{
    TreeNode* root = new TreeNode(3);
    TreeNode* aNode1 = new TreeNode(5);
    TreeNode* aNode2 = new TreeNode(1);
    TreeNode* aNode3 = new TreeNode(6);
    TreeNode* aNode4 = new TreeNode(2);
    TreeNode* aNode5 = new TreeNode(0);
    TreeNode* aNode6 = new TreeNode(8);
    TreeNode* aNode7 = new TreeNode(7);
    TreeNode* aNode8 = new TreeNode(4);

    root->left = aNode1;
    root->right = aNode2;
    aNode1->left = aNode3;
    aNode1->right = aNode4;
    aNode2->left = aNode5;
    aNode2->right = aNode6;
    aNode4->left = aNode7;
    aNode4->right = aNode8;


	
    lowestCommonAncestor(root, new TreeNode(5), new TreeNode(4));
}