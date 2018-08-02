/**
 * @file Minimum-Path-Sum.cpp
 * @brief 路线上元素和的最小值(https://leetcode.com/problems/minimum-path-sum/description/)
 * @author Finalcheat
 * @date 2018-07-29
 */

/**
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 * Note: You can only move either down or right at any point in time.
 * Example:
 * Input:
 * [
 *   [1,3,1],
 *   [1,5,1],
 *   [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 */

/**
 * 动态规划，dp[i][j]表示到达i，j格子的路径元素和最小值，等于min(dp[i - 1][j], dp[j][j - 1])。
 */


class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
            vector< vector<int> > dp(grid.size(), vector<int>(grid[0].size()));
            for (int row = 0; row < grid.size(); ++row) {
                const vector<int>& gridRow = grid[row];
                for (int column = 0; column < gridRow.size(); ++column) {
                    if (row == 0 && column == 0) {
                        dp[0][0] = gridRow[0];
                        continue;
                    }
                    int left = std::numeric_limits<int>::max();
                    if (column - 1 >= 0) {
                        left = dp[row][column - 1];
                    }
                    int top = std::numeric_limits<int>::max();;
                    if (row - 1 >= 0) {
                        top = dp[row - 1][column];
                    }
                    dp[row][column] = std::min(left, top) + gridRow[column];
                }
            }
            const vector<int>& lastRow = dp[dp.size() - 1];
            return lastRow[lastRow.size() - 1];
        }
};
