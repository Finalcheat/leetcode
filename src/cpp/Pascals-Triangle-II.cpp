/**
 * @file Pascals-Triangle-II.cpp
 * @brief 杨辉三角II(https://leetcode.com/problems/pascals-triangle-ii/)
 * @author Finalcheat
 * @date 2016-05-30
 */

/**
 * Given an index k, return the kth row of the Pascal's triangle.
 * For example, given k = 3,
 * Return [1,3,3,1].
 * Note:
 * Could you optimize your algorithm to use only O(k) extra space?
 */

/**
 * 用一个中间变量存储要求的行数上一行的杨辉三角值，循环中不断更新替换即可。
 */

class Solution {
    public:
        vector<int> getRow(int rowIndex) {
            std::vector<int> result;
            std::vector<int> tmp;
            for (int i = 0; i <= rowIndex; ++i) {
                result.resize(i + 1);
                result[0] = 1;
                for (int j = 1; j < i; ++j) {
                    result[j] = tmp[j - 1] + tmp[j];
                }
                result[i] = 1;
                tmp.resize(i + 1);
                std::copy(result.begin(), result.end(), tmp.begin());
            }
            return result;
        }
};
