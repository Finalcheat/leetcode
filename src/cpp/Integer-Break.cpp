/**
 * @file Integer-Break.cpp
 * @brief 分解整数乘积最大(https://leetcode.com/problems/integer-break/) 
 * @author Finalcheat
 * @date 2016-04-19
 */

/**
 * Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.
 * For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).
 * Note: you may assume that n is not less than 2.
 */

/**
 * 动态规划解决，将一个数不断拆分成2或者3。
 */

class Solution {
    public:
        int integerBreak(int n) {
            if (n <= 3) {
                return n - 1;
            }
            std::vector<int> result(n + 1, 1);
            result[2] = 2;
            result[3] = 3;
            for (int i = 4; i <= n; ++i) {
                result[i] = std::max(result[i - 2] * 2, result[i - 3] * 3);
            }
            return result[n];
        }
};
