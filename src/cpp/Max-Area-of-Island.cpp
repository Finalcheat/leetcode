/**
 * @file Max-Area-of-Island.cpp
 * @brief 岛屿的最大面积(https://leetcode.com/problems/max-area-of-island/description/)
 * @author Finalcheat
 * @date 2018-07-26
 */

/**
 * Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
 * Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)
 * Example 1:
 * [[0,0,1,0,0,0,0,1,0,0,0,0,0],
 *  [0,0,0,0,0,0,0,1,1,1,0,0,0],
 *  [0,1,1,0,1,0,0,0,0,0,0,0,0],
 *  [0,1,0,0,1,1,0,0,1,0,1,0,0],
 *  [0,1,0,0,1,1,0,0,1,1,1,0,0],
 *  [0,0,0,0,0,0,0,0,0,0,1,0,0],
 *  [0,0,0,0,0,0,0,1,1,1,0,0,0],
 *  [0,0,0,0,0,0,0,1,1,0,0,0,0]]
 * Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
 * Example 2:
 * [[0,0,0,0,0,0,0,0]]
 * Given the above grid, return 0.
 */

/**
 * 深度优先搜索，建立一个visit数组辅助结构记录位置是否已经被访问。
 */


class Solution {
    public:
        int maxAreaOfIsland(vector<vector<int>>& grid) {
            if (grid.empty()) {
                return 0;
            }
            vector< vector<int> > visit(grid.size(), vector<int>(grid[0].size(), 0));
            int result = 0;
            for (int row = 0; row < grid.size(); ++row) {
                for (int column = 0; column < grid[row].size(); ++column) {
                    result = max(result, _maxAreaOfIsland(grid, visit, row, column));
                }
            }
            return result;
        }
    private:
        int _maxAreaOfIsland(const vector< vector<int> >& grid, vector< vector<int> >& visit,
                             int row, int column) {
            if (grid[row][column] == 0) {
                return 0;
            }
            if (visit[row][column] == 1) {
                return 0;
            }
            visit[row][column] = 1;
            int count = 1;
            if (column - 1 >= 0) {
                count += _maxAreaOfIsland(grid, visit, row, column - 1);
            }
            if (column + 1 < grid[0].size()) {
                count += _maxAreaOfIsland(grid, visit, row, column + 1);
            }
            if (row - 1 >= 0) {
                count += _maxAreaOfIsland(grid, visit, row - 1, column);
            }
            if (row + 1 < grid.size()) {
                count += _maxAreaOfIsland(grid, visit, row + 1, column);
            }
            return count;
        }
};
