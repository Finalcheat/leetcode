/**
 * @file Power-of-Three.cpp
 * @brief 判断一个数是否是3的幂(https://leetcode.com/problems/power-of-three/) 
 * @author Finalcheat
 * @date 2016-04-05
 */

/**
 * Given an integer, write a function to determine if it is a power of three.
 */

/**
 * 不断除以3即可，不能整除的肯定不是3的幂。
 */

class Solution {
    public:
        bool isPowerOfThree(int n) {
            if (n <= 0) {
                return false;
            }
            while (n != 1) {
                if (n % 3 != 0) {
                    return false;
                }
                n /= 3;
            }
            return true;
        }
};
