/**
 * @file Pascals-Triangle.cpp
 * @brief 杨辉三角(https://leetcode.com/problems/pascals-triangle/) 
 * @author Finalcheat
 * @date 2016-05-29
 */

/**
 * Given numRows, generate the first numRows of Pascal's triangle.
 * For example, given numRows = 5,
 * Return
 * [
 *  [1],
 *  [1,1],
 *  [1,2,1],
 *  [1,3,3,1],
 *  [1,4,6,4,1]
 * ]
 */

/**
 * 循环相加即可。
 */

class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            std::vector<std::vector<int>> result;
            if (numRows != 0) {
                result.push_back(std::vector<int>{1});
            }
            for (int i = 1; i < numRows; ++i) {
                std::vector<int> tmp(i + 1);
                tmp[0] = 1;
                for (int j = 1; j < i; ++j) {
                    tmp[j] = result[i - 1][j - 1] + result[i - 1][j];
                }
                tmp[i] = 1;
                result.push_back(tmp);
            }
            return result;
        }
};
