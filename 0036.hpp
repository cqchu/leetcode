#ifndef __0036_H
#define __0036_H

/**************************************************
Description:
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
    Each row must contain the digits 1-9 without repetition.
    Each column must contain the digits 1-9 without repetition.
    Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
A partially filled sudoku which is valid.
The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Example 1:
Input:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: true

Example 2:
Input:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being 
    modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

Note:
    A Sudoku board (partially filled) could be valid but is not necessarily solvable.
    Only the filled cells need to be validated according to the mentioned rules.
    The given board contain only digits 1-9 and the character '.'.
    The given board size is always 9x9.
**************************************************/

#include <vector>
#include <set>

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> column(9);
        vector<set<char>> row(9);
        vector<set<char>> grid(9);

        bool findFlag = false;
        for (int y=0; y<9 && !findFlag; y++) {
            for (int x=0; x<9 && !findFlag; x++) {
                if (board[y][x] != '.') {
                    // for column
                    if (column[x].find(board[y][x]) != column[x].end())
                        findFlag = true;
                    else
                        column[x].insert(board[y][x]);
                    // for row
                    if (row[y].find(board[y][x]) != row[y].end())
                        findFlag = true;
                    else
                        row[y].insert(board[y][x]);
                    // for grid
                    int gridIdx = (y / 3)*3 + (x / 3);
                    if (grid[gridIdx].find(board[y][x]) != grid[gridIdx].end())
                        findFlag = true;
                    else
                        grid[gridIdx].insert(board[y][x]);

                }
            }
        }
        return !findFlag;
    }
};

#endif