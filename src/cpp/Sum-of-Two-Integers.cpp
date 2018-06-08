/**
 * @file Sum-of-Two-Integers.cpp
 * @brief 两个数字相加(https://leetcode.com/problems/sum-of-two-integers)
 * @author Finalcheat
 * @date 2017-03-01
 */

/**
 * Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.\
 * Example:
 * Given a = 1 and b = 2, return 3.
 */

/**
 * 两个数相加(不能使用+-符号^_^)，对这种题目不太感兴趣，尽是奇淫技巧，基本思路就是用异或、与、或等操作得到bit和进位进行操作。
 */


class Solution {
    public:
        int getSum(int a, int b) {
            int sum = a;
            while (b)
            {
                sum = a ^ b;
                b = (a & b) << 1;
                a = sum;
            }
            return sum;
        }
};
