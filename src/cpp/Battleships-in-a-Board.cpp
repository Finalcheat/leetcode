/**
 * @file Battleships-in-a-Board.cpp
 * @brief 甲板上的战舰(https://leetcode.com/problems/battleships-in-a-board/description/)
 * @author Finalcheat
 * @date 2018-09-19
 */

/**
 * Given an 2D board, count how many battleships are in it. The battleships are represented with 'X's, empty slots are represented with '.'s. You may assume the following rules:
 * * You receive a valid board, made of only battleships or empty slots.
 * * Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
 * * At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.
 * Example:
 * X..X
 * ...X
 * ...X
 * In the above board there are 2 battleships.
 * Invalid Example:
 * ...X
 * XXXX
 * ...X
 * This is an invalid board that you will not receive - as battleships will always have a cell separating between them.
 */

/**
 * 由于输入的都是有效的数据，遍历到X字符的时候搜索左边跟上面是否为.，如果是则结果数+1，否则继续。
 */


class Solution {
    public:
        int countBattleships(vector<vector<char>>& board) {
            int count = 0;
            for (int row = 0; row < board.size(); ++row) {
                for (int column = 0; column < board[row].size(); ++column) {
                    if (board[row][column] != 'X') {
                        continue;
                    }
                    char left = '.';
                    if (column - 1 >= 0) {
                        left = board[row][column - 1];
                    }
                    char top = '.';
                    if (row - 1 >= 0) {
                        top = board[row - 1][column];
                    }
                    if (left == '.' && top == '.') {
                        ++count;
                    }
                }
            }
            return count;
        }
};
