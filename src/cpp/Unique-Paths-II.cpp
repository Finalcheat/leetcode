/**
 * @file Unique-Paths-II.cpp
 * @brief 不同路径II(https://leetcode.com/problems/unique-paths-ii/description/)
 * @author Finalcheat
 * @date 2018-10-05
 */

/**
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 * Now consider if some obstacles are added to the grids. How many unique paths would there be?
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * Note: m and n will be at most 100.
 * Example 1:
 * Input:
 * [
 *   [0,0,0],
 *   [0,1,0],
 *   [0,0,0]
 * ]
 * Output: 2
 * Explanation:
 * There is one obstacle in the middle of the 3x3 grid above.
 * There are two ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down -> Down
 * 2. Down -> Down -> Right -> Right
 */

/**
 * 动态规划，dp[i][j]表示到达第i行第j列的路径数量，dp[i][j] = dp[i - 1][j] + dp[i][j - 1]，如果obstacleGrid[i][j]==1，则dp[i][j]=0。
 */


class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            if (obstacleGrid.empty()) {
                return 0;
            }
            vector< vector<int> > dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
            for (int row = 0; row < obstacleGrid.size(); ++row) {
                for (int column = 0; column < obstacleGrid[row].size(); ++column) {
                    if (obstacleGrid[row][column]) {
                        dp[row][column] = 0;
                        continue;
                    }
                    if (row == 0 && column == 0) {
                        dp[0][0] = 1;
                        continue;
                    }
                    int left = 0;
                    if (column - 1 >= 0) {
                        left = dp[row][column - 1];
                    }
                    int top = 0;
                    if (row - 1 >= 0) {
                        top = dp[row - 1][column];
                    }
                    dp[row][column] = left + top;
                }
            }
            return dp[dp.size() - 1][dp[0].size() - 1];
        }
};
