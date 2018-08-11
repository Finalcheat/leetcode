/**
 * @file Island-Perimeter.cpp
 * @brief 岛周长(https://leetcode.com/problems/island-perimeter/description/)
 * @author Finalcheat
 * @date 2018-08-04
 */

/**
 * You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
 * Example:
 * [[0,1,0,0],
 *  [1,1,1,0],
 *  [0,1,0,0],
 *  [1,1,0,0]]
 *
 * Answer: 16
 * Explanation: The perimeter is the 16 yellow stripes in the image below:
 */

/**
 * 对于每一个岛，判断上下左右方向是否连接着岛，如果没有则周长加1。
 */


class Solution {
    public:
        int islandPerimeter(vector<vector<int>>& grid) {
            int result = 0;
            for (int row = 0; row < grid.size(); ++row) {
                const vector<int>& gridRow = grid[row];
                for (int column = 0; column < gridRow.size(); ++column) {
                    if (gridRow[column] == 1) {
                        if (column - 1 < 0 || gridRow[column - 1] == 0) {
                            ++result;
                        }
                        if (column + 1 >= gridRow.size() || gridRow[column + 1] == 0) {
                            ++result;
                        }
                        if (row - 1 < 0 || grid[row - 1][column] == 0) {
                            ++result;
                        }
                        if (row + 1 >= grid.size() || grid[row + 1][column] == 0) {
                            ++result;
                        }
                    }
                }
            }
            return result;
        }
};
