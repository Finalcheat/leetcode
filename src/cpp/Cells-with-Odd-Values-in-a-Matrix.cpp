/**
 * @file Cells-with-Odd-Values-in-a-Matrix.cpp
 * @brief 矩阵中值为奇数的单元格(https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/)
 * @author Finalcheat
 * @date 2020-05-09
 */

/**
 * Given n and m which are the dimensions of a matrix initialized by zeros and given an array indices where indices[i] = [ri, ci]. For each pair of [ri, ci] you have to increment all cells in row ri and column ci by 1.
 * Return the number of cells with odd values in the matrix after applying the increment to all indices.
 * Example 1:
 * Input: n = 2, m = 3, indices = [[0,1],[1,1]]
 * Output: 6
 * Explanation: Initial matrix = [[0,0,0],[0,0,0]].
 * After applying first increment it becomes [[1,2,1],[0,1,0]].
 * The final matrix will be [[1,3,1],[1,3,1]] which contains 6 odd numbers.
 * Example 2:
 * Input: n = 2, m = 2, indices = [[1,1],[0,0]]
 * Output: 0
 * Explanation: Final matrix = [[2,2],[2,2]]. There is no odd number in the final matrix.
 * Constraints:
 * * 1 <= n <= 50
 * * 1 <= m <= 50
 * * 1 <= indices.length <= 100
 * * 0 <= indices[i][0] < n
 * * 0 <= indices[i][1] < m
 */

/**
 * 按照规则构造最后统计即可。
 */

class Solution {
    public:
        int oddCells(int n, int m, vector<vector<int>>& indices) {
            assert(n >= 1);
            assert(m >= 1);
            vector<vector<int>> matrix(n, vector<int>(m, 0));
            for (const vector<int>& v : indices) {
                assert(v.size() == 2);
                const int row = v[0];
                const int column = v[1];
                assert(row < n);
                assert(column < m);
                for (int i = 0; i < m; ++i) {
                    ++matrix[row][i];
                }
                for (int j = 0; j < n; ++j) {
                    ++matrix[j][column];
                }
            }
            int result = 0;
            for (const vector<int>& v : matrix) {
                for (const int num : v) {
                    if (num % 2 != 0) {
                        ++result;
                    }
                }
            }
            return result;
        }
};
