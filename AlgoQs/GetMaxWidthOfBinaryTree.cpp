#include "pch.h"
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int getMaxWidth(std::queue<TreeNode*> qu,int levelCount)
{
    int count = 0;
    int start = -1;
    int end = 0;
    while (!qu.empty())
    {
        if (start == -1 && qu.front() != nullptr)
        {
            start = count;
        }
        else if (qu.front() != nullptr)
        {
            end = count;
        }
        count++;
        qu.pop();
    }
    return (end - start) + 1;
}

int widthOfBinaryTree(TreeNode* root) {
    if (nullptr == root)
        return 0;
    int maxWidth = 1;
    queue<TreeNode*> q;
    q.push(root);
    int levelCount = 0;

    while (!q.empty())
    {
        if (getMaxWidth(q,levelCount) > maxWidth)
            maxWidth = getMaxWidth(q,levelCount);

        int levelSize = q.size();

        while (levelSize)
        {
            auto node = q.front();
            q.pop();

            if (node != nullptr)
                q.push(node->left);

            if (node != nullptr)
                q.push(node->right);

            levelSize--;
        }
        levelCount++;
    }

    return maxWidth;

}

int main()
{
    TreeNode* root = new TreeNode(1,
        new TreeNode(3, new TreeNode(5, nullptr, nullptr),new TreeNode(3,nullptr,nullptr))
        , new TreeNode(2, nullptr, new TreeNode(9, nullptr, nullptr)));

    cout << widthOfBinaryTree(root);

    return 0;
}