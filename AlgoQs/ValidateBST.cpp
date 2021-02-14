#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

class Solution {
    void inOrderSearch(TreeNode* root, vector<int>& vec)
    {
        if (NULL == root)
            return;

        inOrderSearch(root->left, vec);
        vec.push_back(root->val);
        inOrderSearch(root->right, vec);
    }
public:
    bool isValidBST(TreeNode* root) {
        if (NULL == root)
            return true;

        if (root->left && root->left->val >= root->val)
            return false;

        if (root->right && root->right->val <= root->val)
            return false;

        vector<int> vec;
        inOrderSearch(root, vec);

        std::set<int> aSet;
        for (auto num : vec)
        {
            aSet.insert(num);
        }
        //check if the vector is sorted
        return std::is_sorted(vec.begin(), vec.end()) &&
            aSet.size() == vec.size();
    }
};

struct Stock
{
    string name;
    float shares;
    float buyPrice;
    float currentPrice;
    string stockType;
};

void enterDetails(Stock& s)
{
    cout << "\nEnter the stock name : ";
    getline(cin, s.name);
    cin.ignore(numeric_limits<int>::max(), '\n');
    cout << "\nEnter number of shares : ";
    cin >> s.shares;
    cin.ignore(numeric_limits<int>::max(), '\n');
    cout << "\nEnter the Buy Price : ";
    cin >> s.buyPrice;
    cin.ignore(numeric_limits<int>::max(), '\n');
    cout << "\nEnter the Current Price : ";
    cin >> s.currentPrice;
    cin.ignore(numeric_limits<int>::max(), '\n');
    cout << "\nEnter the stock type : ";
    getline(cin, s.stockType);
}

std::tuple<float, float, float> calculate(Stock s)
{
    float totalCost = s.buyPrice * s.shares;
    float  currentValue = s.currentPrice * s.shares;
    float profit = currentValue - totalCost;
    return { totalCost, currentValue, profit };
}

int main()
{
    Stock s;
    enterDetails(s);
    auto [totalCost, currentValue, profit] = calculate(s);
    cout << "\ntotal Cost : " << totalCost;
    cout << "\nCurrent Value : " << currentValue;
    cout << "\nprofit : " << profit;



   /* vector<vector<int>> edges =
    {
        {1,0 }, { 1,2 }, { 1,3 }
    };

    MinHeighTrees trees;
    trees.findMinHeightTrees(4, edges);*/
}
//int main()
//{
//    TreeNode* root = new TreeNode(5, new TreeNode(4), new TreeNode(6, new TreeNode(3), new TreeNode(7)));
//
//    Solution s;
//    s.isValidBST(root);
//}