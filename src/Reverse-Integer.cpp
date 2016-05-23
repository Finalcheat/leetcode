/**
 * @file Reverse-Integer.cpp
 * @brief 反转整型(https://leetcode.com/problems/reverse-integer/) 
 * @author Finalcheat
 * @date 2016-05-23
 */

/**
 * Reverse digits of an integer.
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 */

/**
 * 简单的反转整型数问题，需要注意的是反转后整型溢出的情况应该返回0。
 */

class Solution {
    public:
        int reverse(int x) {
            int result = 0;
            while (x) {
                const int num = x % 10;
                const int next_num = result * 10 + num;
                if (next_num / 10 != result) {
                    return 0;
                }
                result = next_num;
                x = x / 10;
            }
            return result;
        }
};
