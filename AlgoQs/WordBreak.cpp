#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
//DP Solution
//vector<bool> vb;


class Solution {
    void performDFS(vector<vector<int>>& matrix, int i, int j, vector<vector<int>> result, 
        vector<vector<bool>> visited, int& maxLen)
    {
        if (i < 0 || (i >= matrix.size()) || j < 0 || (j >= matrix[0].size()))
            return;

        if (visited[i][j])
            return;

        visited[i][j] = true;
    	
        if (i + 1 < matrix.size() &&
            matrix[i][j] > matrix[i + 1][j])
        {
            result[i][j] = max(result[i][j], result[i + 1][j] + 1);
        }

        if (j + 1 < matrix[0].size() &&
            matrix[i][j] > matrix[i][j + 1])
        {
            result[i][j] = max(result[i][j], result[i][j + 1] + 1);
        }

        if (i - 1 >= 0 &&
            matrix[i][j] > matrix[i - 1][j])
        {
            result[i][j] = max(result[i][j], result[i - 1][j] + 1);
        }

        if (j - 1 >= 0 &&
            matrix[i][j] > matrix[i][j - 1])
        {
            result[i][j] = max(result[i][j], result[i][j - 1] + 1);
        }

        maxLen = max(maxLen, result[i][j]);

        performDFS(matrix, i, j + 1, result, visited, maxLen);
        performDFS(matrix, i + 1, j, result, visited, maxLen);
        performDFS(matrix, i, j - 1, result, visited, maxLen);
        performDFS(matrix, i - 1, j, result, visited,maxLen);
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> result(matrix.size(), vector<int>(matrix[0].size(), 1));
        vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));

        int maxLength = 0;
        for (int i = 0;i < matrix.size();++i)
        {
            for (int j = 0;j < matrix[0].size();++j)
            {
                int maxLen = 1;

                performDFS(matrix, i, j, result, visited, maxLen);

                maxLength = max(maxLength, maxLen);
            }
        }
        return maxLength;
    }
};

//class Solution {
//    struct Trie
//    {
//        unordered_map<char, Trie*> umap;
//        bool isLast = false;
//    };
//    Trie* m_root;
//    void createTrie(vector<string>& wordDict)
//    {
//        Trie* root = NULL;
//        Trie* temp = NULL;
//        for (auto word : wordDict)
//        {
//            for (int i = 0;i < word.length();)
//            {
//                if (NULL == root)
//                {
//                    root = new Trie();
//                    temp = root;
//                }
//
//                while (temp != nullptr &&
//                    temp->umap.find(word[i]) != temp->umap.end())
//                {
//                    temp = temp->umap[word[i]];
//                    ++i;
//                }
//
//                if (i < word.length() &&
//                    nullptr != temp &&
//                    temp->umap.find(word[i]) == temp->umap.end())
//                {
//                    temp->umap[word[i]] = new Trie();
//                    temp = temp->umap[word[i]];
//                    ++i;
//                }
//
//                if (i == word.length())
//                    temp->isLast = true;
//            }
//            temp = root;
//        }
//        m_root = root;
//    }
//    bool isPossible(string word, Trie* temp, int index)
//    {
//        if (index == word.length() &&
//            temp->isLast == true)
//            return true;
//
//        if (temp == NULL || ((temp->isLast == false) &&
//            temp->umap.find(word[index]) == temp->umap.end()))
//            return false;
//
//        if (temp->isLast == false)
//        {
//            return isPossible(word, temp->umap[word[index]], index + 1);
//        }
//
//        if (temp->isLast == true &&
//            temp->umap.size() == 0)
//        {
//            return isPossible(word, m_root, index);
//        }
//
//        return isPossible(word, m_root, index) ||
//            isPossible(word, temp->umap[word[index]], index + 1);
//    }
//public:
//    bool wordBreak(string s, vector<string>& wordDict) {
//        //Form a trie datastructure
//        createTrie(wordDict);
//        Trie* temp = m_root;
//
//        return isPossible(s, temp, 0);
//
//    }
//};

int main()
{
    Solution s;
    vector<vector<int>> dict = { {9, 9, 4},{6, 6, 8},{2, 1, 1} };
    int result = s.longestIncreasingPath(dict);
    return 0;
}