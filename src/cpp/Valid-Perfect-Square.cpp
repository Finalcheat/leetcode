/**
 * @file Valid-Perfect-Square.cpp
 * @brief 验证完全平方数(https://leetcode.com/problems/valid-perfect-square/description/)
 * @author Finalcheat
 * @date 2018-03-01
 */

/**
 * Given a positive integer num, write a function which returns True if num is a perfect square else False.
 * Note: Do not use any built-in library function such as sqrt.
 * Example 1:
 * Input: 16
 * Returns: True
 * Example 2:
 * Input: 14
 * Returns: False
 */

/**
 * 遍历1到该数的一半的数字验证判断即可，最后要注意该数小于2的情况。
 */


class Solution {
    public:
        bool isPerfectSquare(int num) {
            for (int i = 1; i <= num / 2; ++i) {
                if (i * i == num) {
                    return true;
                }
            }
            if (num < 2) {
                return true;
            }
            return false;
        }
};
