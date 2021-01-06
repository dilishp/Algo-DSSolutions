#include "pch.h"
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    void getPaths(TreeNode* node, int res, int& count)
    {
        if (node->left == NULL &&
            node->right == NULL)
        {
            res = res ^ (1 << node->val);

            if ((res & (res - 1)) == 0)
                ++count;
            return;
        }

        res = res ^ (1 << node->val);

        if (node->left != NULL)
        {
            getPaths(node->left, res, count);
        }


        if (node->right != NULL)
        {
            getPaths(node->right, res, count);
        }

    }
public:
    int pseudoPalindromicPaths(TreeNode* root) {
        int count = 0;
        if (root)
            getPaths(root, 0, count);

        return count;
    }
};