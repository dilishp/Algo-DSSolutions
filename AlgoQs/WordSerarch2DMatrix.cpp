#include "pch.h"
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool exists(vector<vector<char>> board, int i, int j, string& word, int index)
{
    if (index == word.length())
        return true;

    if (i < 0 || i >= board.size() ||
        j < 0 || j >= board[0].size())
        return false;

    if (board[i][j] == '-' ||
        word[index] != board[i][j])
        return false;

    ++index;
    board[i][j] = '-';

    return exists(board, i, j + 1, word, index) ||
        exists(board, i + 1, j, word, index) ||
        exists(board, i, j - 1, word, index) ||
        exists(board, i - 1, j, word, index);
}

bool exist(vector<vector<char>>& board, string word) {
	
    //vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
    for (int i = 0;i < board.size();++i)
    {
        for (int j = 0;j < board[0].size();++j)
        {
            if (board[i][j] == word[0] &&
                exists(board, i, j, word, 0))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    vector<vector<char>> v = {
        {'A','B','C','E'},
        {'S','F','E','S'},
        {'A','D','E','E'},
    };
    exist(v, "ABCEFSADEESE");
}