/**
 * @file Factorial-Trailing-Zeroes.cpp
 * @brief 阶乘结果数字后缀0的个数(https://leetcode.com/problems/factorial-trailing-zeroes/) 
 * @author Finalcheat
 * @date 2016-06-05
 */

/**
 * Given an integer n, return the number of trailing zeroes in n!.
 * Note: Your solution should be in logarithmic time complexity.
 */

/**
 * 计算包含的2和5组成的pair的个数就可以了，5的个数比2少，所以2和5组成的pair的个数由5的个数决定。
 */

class Solution {
    public:
        int trailingZeroes(int n) {
            int count = 0;
            while (n > 0) {
                int num = n / 5;
                count += num;
                n = num;
            }
            return count;
        }
};
