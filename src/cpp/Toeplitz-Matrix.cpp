/**
 * @file Toeplitz-Matrix.cpp
 * @brief 常对角矩阵(https://leetcode.com/problems/toeplitz-matrix/description/)
 * @author Finalcheat
 * @date 2018-03-13
 */

/**
 * A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.
 * Now given an M x N matrix, return True if and only if the matrix is Toeplitz.
 * Example 1:
 * Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
 * Output: True
 * Explanation:
 * 1234
 * 5123
 * 9512
 * In the above grid, the diagonals are "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]", and in each diagonal all elements are the same, so the answer is True.
 * Example 2:
 * Input: matrix = [[1,2],[2,2]]
 * Output: False
 * Explanation:
 * The diagonal "[1, 2]" has different elements.
 */

/**
 * 这道题如果用正向思维去判断true的话会比较麻烦，可以反过来判断false的情况就很简单了，只需要判断当前元素与左上角元素是否相等即可。
 */


class Solution {
    public:
        bool isToeplitzMatrix(vector<vector<int>>& matrix) {
            assert(matrix.size() > 0);
            const size_t rowSize = matrix.size();
            const size_t columnSize = matrix[0].size();
            for (size_t row = 0; row < rowSize; ++row) {
                for (size_t column = 0; column < columnSize; ++column) {
                    if (row > 0 && column > 0 && matrix[row - 1][column - 1] != matrix[row][column]) {
                        return false;
                    }
                }
            }
            return true;
        }
};
