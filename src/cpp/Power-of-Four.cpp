/**
 * @file Power-of-Four.cpp
 * @brief 判断一个数字是否是4的幂次方(https://leetcode.com/problems/power-of-four/) 
 * @author Finalcheat
 * @date 2016-05-05
 */

/**
 * Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
 * Example:
 * Given num = 16, return true. Given num = 5, return false.
 */

/**
 * 循环除以4即可，注意判断边界条件。
 */

class Solution {
    public:
        bool isPowerOfFour(int num) {
            if (num <= 0) {
                return false;
            }
            while (num > 1) {
                if (num % 4 != 0) {
                    return false;
                }
                num /= 4;
            }
            return num == 1;
        }
};
