// https://leetcode.com/problems/valid-sudoku/
#include <bits/stdc++.h>

using namespace std;

bool isExisted(vector<vector<char>> board, int l, int r, int number)
{
    unordered_set<int> h;
    switch (number)
    {
    case 1:
        for (int i = 0; i < r; i++)
        {
            if (board[l][i] != '.')
            {
                if (h.find(board[l][i]) != h.end())
                {
                    return true;
                }
                else
                {
                    h.insert(board[l][i]);
                }
            }
        }
        break;
    case 2:
        for (int i = 0; i < l; i++)
        {
            if (board[i][r] != '.')
            {
                if (h.find(board[i][r]) != h.end())
                {
                    return true;
                }
                else
                {
                    h.insert(board[i][r]);
                }
            }
        }
        break;
    case 3:
        for (int i = l; i < l + 3; i++)
        {
            for (int j = r; j < r + 3; j++)
            {
                if (board[i][j] != '.')
                {
                    if (h.find(board[i][j]) != h.end())
                    {
                        return true;
                    }
                    else
                    {
                        h.insert(board[i][j]);
                    }
                }
            }
        }
        break;
    }
    return false;
}

bool isValidSudoku(vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i += 3)
    {
        for (int j = 0; j < 9; j += 3)
        {
            if (isExisted(board, i, j, 3))
            {
                return false;
            }
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (isExisted(board, i, 9, 1))
        {
            return false;
        }
    }

    for (int j = 0; j < 9; j++)
    {
        if (isExisted(board, 9, j, 2))
        {
            return false;
        }
    }

    return true;
}

int main()
{
    vector<vector<char>> board{
        {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '.', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    isValidSudoku(board) ? cout << "True" : cout << "False";
    return 0;
}