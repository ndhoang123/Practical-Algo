// https://leetcode.com/problems/valid-sudoku/
#include <bits/stdc++.h>

using namespace std;

bool isValidSudoku(vector<vector<char>> &board)
{
    unordered_set<char> row[9];
    unordered_set<char> cols[9];
    unordered_set<char> square[9];

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            char val = board[i][j];
            if(val == '.') continue;
            int pos = (i / 3) * 3 + j / 3;
            if(row[i].count(val) || cols[j].count(val) || square[pos].count(val)){
                return false;
            }
            row[i].insert(val);
            cols[j].insert(val);
            square[pos].insert(val);
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