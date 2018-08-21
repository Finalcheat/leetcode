/**
 * @file Reshape-the-Matrix.cpp
 * @brief 重塑矩阵(https://leetcode.com/problems/reshape-the-matrix/description/)
 * @author Finalcheat
 * @date 2018-08-19
 */

/**
 * In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into a new one with different size but keep its original data.
 * You're given a matrix represented by a two-dimensional array, and two positive integers r and c representing the row number and column number of the wanted reshaped matrix, respectively.
 * The reshaped matrix need to be filled with all the elements of the original matrix in the same row-traversing order as they were.
 * If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.
 * Example 1:
 * Input:
 * nums =
 * [[1,2],
 *  [3,4]]
 * r = 1, c = 4
 * Output:
 * [[1,2,3,4]]
 * Explanation:
 * The row-traversing of nums is [1,2,3,4]. The new reshaped matrix is a 1 * 4 matrix, fill it row by row by using the previous list.
 * Example 2:
 * Input:
 * nums =
 * [[1,2],
 *  [3,4]]
 * r = 2, c = 4
 * Output:
 * [[1,2],
 *  [3,4]]
 * Explanation:
 * There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. So output the original matrix.
 */

/**
 * 按规定添加即可，没什么难度。
 */


class Solution {
    public:
        vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
            const int rows = nums.size();
            assert(rows >= 1);
            const int columns = nums[0].size();
            if (rows * columns != r * c) {
                return nums;
            }
            vector< vector<int> > result;
            int n = r * c;
            size_t row = 0;
            size_t column = 0;
            vector<int> vRow;
            while (n-- > 0) {
                vRow.push_back(nums[row][column]);
                ++column;
                if (vRow.size() == c) {
                    result.push_back(vRow);
                    vRow.clear();
                }
                if (column == columns) {
                    column = 0;
                    ++row;
                }
            }
            return result;
        }
};
