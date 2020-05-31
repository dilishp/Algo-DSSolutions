#include <iostream>

using namespace std;
 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
    int pathSum(TreeNode* root, int actSum, int sum, int& numPath)
    {
        if (root == NULL)
            return 0;

        actSum += root->val;

        if (actSum == sum)
        {
            numPath++;
        }

        if (root->left == NULL && root->right == NULL)
            return numPath;

        pathSum(root->left, actSum, sum, numPath);
        pathSum(root->right, actSum, sum, numPath);

        return numPath;

    }
public:
    int pathSum(TreeNode* root, int sum) {

        if (root == NULL)
            return 0;

        int numPath = 0;

        return pathSum(root, 0, sum, numPath) +
            pathSum(root->left, sum) +
            pathSum(root->right, sum);
    }
};