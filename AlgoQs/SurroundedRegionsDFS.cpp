#include "pch.h"
#include <vector>

using namespace std;

//The Idea here is to find all the regions which are not surrounded by X
//This can be found by checking the boundary O and performing DFS on these 
//O and making the O discovered to * for later use.

//After this translate the O remaining to X and * to O.
//Similar Question Number of Islands

void performDFS(vector<vector<char>>& board, int i, int j)
{
    if (i < 0 || (i >= board.size()) || j < 0 || (j >= board[0].size()))
        return;

    if (board[i][j] == 'X')
        return;

    if (board[i][j] == '*')
        return;

    if (board[i][j] == 'O')
        board[i][j] = '*';

    performDFS(board, i, j + 1);
    performDFS(board, i + 1, j);
    performDFS(board, i, j - 1);
    performDFS(board, i - 1, j);
}

void solve(vector<vector<char>>& board) {
    for (int i = 0;i < board.size();++i)
    {
        for (int j = 0;j < board[i].size();++j)
        {
            if (board[i][j] == 'O')
            {
                if (i == 0 || i == (board.size() - 1)
                    || j == 0 || j == (board[0].size() - 1))
                {
                    performDFS(board, i, j);
                }
            }

        }
    }


    for (int i = 0;i < board.size();++i)
    {
        for (int j = 0;j < board[i].size();++j)
        {
            if (board[i][j] == '*')
            {
                board[i][j] = 'O';
            }
            else if (board[i][j] == 'O')
            {
                board[i][j] = 'X';
            }
        }
    }
}