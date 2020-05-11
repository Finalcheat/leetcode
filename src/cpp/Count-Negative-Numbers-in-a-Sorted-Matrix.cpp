/**
 * @file Count-Negative-Numbers-in-a-Sorted-Matrix.cpp
 * @brief 在一个有序的矩阵中计算负数的数量(https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/)
 * @author Finalcheat
 * @date 2020-05-11
 */

/**
 * Given a m * n matrix grid which is sorted in non-increasing order both row-wise and column-wise. 
 * Return the number of negative numbers in grid.
 * Example 1:
 * Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
 * Output: 8
 * Explanation: There are 8 negatives number in the matrix.
 * Example 2:
 * Input: grid = [[3,2],[1,0]]
 * Output: 0
 * Example 3:
 * Input: grid = [[1,-1],[-1,-1]]
 * Output: 3
 * Example 4:
 * Input: grid = [[-1]]
 * Output: 1
 * Constraints:
 * * m == grid.length
 * * n == grid[i].length
 * * 1 <= m, n <= 100
 * * -100 <= grid[i][j] <= 100
 */

/**
 * 理论上用二分搜索更快，这里偷懒简单遍历即可。
 */

class Solution {
    public:
        int countNegatives(vector<vector<int>>& grid) {
            int count = 0;
            for (const vector<int>& v : grid) {
                for (const int num : v) {
                    if (num < 0) {
                        ++count;
                    }
                }
            }
            return count;
        }
};
