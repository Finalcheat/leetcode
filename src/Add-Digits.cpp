/**
 * @file Add-Digits.cpp
 * @brief 加数字(https://leetcode.com/problems/add-digits/)
 * @author Finalcheat
 * @date 2016-03-12
 */

/**
 * Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
 * For example:
 * Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
 */

/**
 * 数学问题，详情请看https://en.wikipedia.org/wiki/Digital_root
 */

class Solution {
    public:
        int addDigits(int num) {
            return (num - 1) % 9 + 1;
        }
};
