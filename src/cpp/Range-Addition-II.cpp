/**
 * @file Range-Addition-II.cpp
 * @brief 范围求和II(https://leetcode.com/problems/range-addition-ii/description/)
 * @author Finalcheat
 * @date 2018-08-30
 */

/**
 * Given an m * n matrix M initialized with all 0's and several update operations.
 * Operations are represented by a 2D array, and each operation is represented by an array with two positive integers a and b, which means M[i][j] should be added by one for all 0 <= i < a and 0 <= j < b.
 * You need to count and return the number of maximum integers in the matrix after performing all the operations.
 * Example 1:
 * Input:
 * m = 3, n = 3
 * operations = [[2,2],[3,3]]
 * Output: 4
 * Explanation:
 * Initially, M =
 * [[0, 0, 0],
 *  [0, 0, 0],
 *  [0, 0, 0]]
 * After performing [2,2], M =
 * [[1, 1, 0],
 *  [1, 1, 0],
 *  [0, 0, 0]]
 * After performing [3,3], M =
 * [[2, 2, 1],
 *  [2, 2, 1],
 *  [1, 1, 1]]
 * So the maximum integer in M is 2, and there are four of it in M. So return 4.
 */

/**
 * 其实就是求ops的交集，由于都是从0开始的，所以也就是求ops中a、b的最小值，最后相乘即可。注意ops为空的情况。
 */


class Solution {
    public:
        int maxCount(int m, int n, vector<vector<int>>& ops) {
            if (ops.empty()) {
                return m * n;
            }
            int minimumRow = INT_MAX;
            int minimumColumn = INT_MAX;
            for (const vector<int>& op : ops) {
                int row = op[0];
                int column = op[1];
                if (row < minimumRow) {
                    minimumRow = row;
                }
                if (column < minimumColumn) {
                    minimumColumn = column;
                }
            }
            return minimumRow * minimumColumn;
        }
};
