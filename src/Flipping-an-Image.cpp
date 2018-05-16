/**
 * @file Flipping-an-Image.cpp
 * @brief 翻转图像(https://leetcode.com/problems/flipping-an-image/description/)
 * @author Finalcheat
 * @date 2018-05-16
 */

/**
 * Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image.
 * To flip an image horizontally means that each row of the image is reversed.  For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].
 * To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].
 * Example 1:
 * Input: [[1,1,0],[1,0,1],[0,0,0]]
 * Output: [[1,0,0],[0,1,0],[1,1,1]]
 * Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
 * Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
 * Example 2:
 * Input: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
 * Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 * Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
 * Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 */

/**
 * 按照规则来写代码就行了，没什么难度。
 */


class Solution {
    public:
        vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
            vector<vector<int>> result;
            for (size_t row = 0; row < A.size(); ++row) {
                vector<int> vRow;
                for (int column = A[row].size() - 1; column >= 0; --column) {
                    vRow.push_back(A[row][column]);
                }
                result.push_back(vRow);
            }

            for (size_t row = 0; row < result.size(); ++row) {
                for (size_t column = 0; column < result[row].size(); ++column) {
                    result[row][column] = !result[row][column];
                }
            }
            return result;
        }
};
