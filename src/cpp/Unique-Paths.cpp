/**
 * @file Unique-Paths.cpp
 * @brief 唯一路径(https://leetcode.com/problems/unique-paths/description/)
 * @author Finalcheat
 * @date 2018-07-28
 */

/**
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 * How many possible unique paths are there?
 * Note: m and n will be at most 100.
 * Example 1:
 * Input: m = 3, n = 2
 * Output: 3
 * Explanation:
 * From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down
 * 2. Right -> Down -> Right
 * 3. Down -> Right -> Right
 * Example 2:
 * Input: m = 7, n = 3
 * Output: 28
 */

/**
 * 动态规划，dp[i][j]表示到达i，j格子的路径个数，等于dp[i - 1][j] + dp[j][j - 1]。
 */


class Solution {
    public:
        int uniquePaths(int m, int n) {
            vector< vector<int> > dp(n, vector<int>(m));
            for (int row = 0; row < n; ++row) {
                for (int column = 0; column < m; ++column) {
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
            return dp[n - 1][m - 1];
        }
};
