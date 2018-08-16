/**
 * @file Score-After-Flipping-Matrix.cpp
 * @brief 分数翻转矩阵(https://leetcode.com/problems/score-after-flipping-matrix/description/)
 * @author Finalcheat
 * @date 2018-07-22
 */

/**
 * We have a two dimensional matrix A where each value is 0 or 1.
 * A move consists of choosing any row or column, and toggling each value in that row or column: changing all 0s to 1s, and all 1s to 0s.
 * After making any number of moves, every row of this matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.
 * Return the highest possible score.
 * Example 1:
 * Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
 * Output: 39
 * Explanation:
 * Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
 * 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
 */

/**
 * 贪心算法，先使第一列全部为1，然后使每一列的1个数尽可能多。
 */


class Solution {
    public:
        int matrixScore(vector<vector<int>>& A) {
            if (A.empty()) {
                return 0;
            }
            vector< vector<int> > flippingMatrix(A);
            for (size_t row = 0; row < flippingMatrix.size(); ++row) {
                if (flippingMatrix[row][0] == 0) {
                    for (size_t column = 0; column < flippingMatrix[row].size(); ++column) {
                        flippingMatrix[row][column] = !flippingMatrix[row][column];
                    }
                }
            }
            for (size_t column = 1; column < flippingMatrix[0].size(); ++column) {
                int zeroCount = 0;
                for (size_t row = 0; row < flippingMatrix.size(); ++row) {
                    if (flippingMatrix[row][column] == 0) {
                        ++zeroCount;
                    }
                }
                if (zeroCount > (flippingMatrix.size() / 2)) {
                    for (size_t row = 0; row < flippingMatrix.size(); ++row) {
                        flippingMatrix[row][column] = !flippingMatrix[row][column];
                    }
                }
            }
            int result = 0;
            for (size_t row = 0; row < flippingMatrix.size(); ++row) {
                const size_t columnLen = flippingMatrix[row].size();
                for (size_t column = 0; column < columnLen; ++column) {
                    result += (flippingMatrix[row][column] << (columnLen - column - 1));
                }
            }
            return result;
        }
};
