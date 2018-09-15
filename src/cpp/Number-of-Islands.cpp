/**
 * @file Number-of-Islands.cpp
 * @brief 岛屿的个数(https://leetcode.com/problems/number-of-islands/description/)
 * @author Finalcheat
 * @date 2018-09-10
 */

/**
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
 * Example 1:
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 * Output: 1
 * Example 2:
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 * Output: 3
 */

/**
 * 深度优先搜索，遍历过程中记录是否已访问。
 */


class Solution {
    public:
        int numIslands(vector<vector<char>>& grid) {
            if (grid.empty()) {
                return 0;
            }
            vector< vector<int> > visits(grid.size(), vector<int>(grid[0].size(), 0));
            int count = 0;
            for (int row = 0; row < grid.size(); ++row) {
                for (int column = 0; column < grid[row].size(); ++column) {
                    if (_numIslands(grid, visits, row, column)) {
                        ++count;
                    }
                }
            }
            return count;
        }
    private:
        bool _numIslands(const vector< vector<char> >& grid, vector< vector<int> >& visits,
                         int row, int column) {
            if (grid[row][column] == '0') {
                return false;
            }
            if (visits[row][column] == 1) {
                return false;
            }
            visits[row][column] = 1;
            if (column - 1 >= 0) {
                _numIslands(grid, visits, row, column - 1);
            }
            if (column + 1 < grid[row].size()) {
                _numIslands(grid, visits, row, column + 1);
            }
            if (row - 1 >= 0) {
                _numIslands(grid, visits, row - 1, column);
            }
            if (row + 1 < grid.size()) {
                _numIslands(grid, visits, row + 1, column);
            }
            return true;
        }
};
