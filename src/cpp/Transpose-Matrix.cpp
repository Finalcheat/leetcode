/**
 * @file Transpose-Matrix.cpp
 * @brief 转置矩阵(https://leetcode.com/problems/transpose-matrix/description/)
 * @author Finalcheat
 * @date 2018-07-23
 */

/**
 * Given a matrix A, return the transpose of A.
 * The transpose of a matrix is the matrix flipped over it's main diagonal, switching the row and column indices of the matrix.
 * Example 1:
 * Input: [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [[1,4,7],[2,5,8],[3,6,9]]
 * Example 2:
 * Input: [[1,2,3],[4,5,6]]
 * Output: [[1,4],[2,5],[3,6]]
 */

/**
 * 遍历添加就行了，没什么难度。
 */


class Solution {
    public:
        vector<vector<int>> transpose(vector<vector<int>>& A) {
            vector< vector<int> > result;
            if (A.empty()) {
                return result;
            }
            for (size_t column = 0; column < A[0].size(); ++column) {
                vector<int> item(A.size());
                for (size_t row = 0; row < A.size(); ++row) {
                    item[row] = A[row][column];
                }
                result.push_back(item);
            }
            return result;
        }
};
