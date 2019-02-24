/**
 * @file Fibonacci-Number.cpp
 * @brief 斐波纳契数(https://leetcode.com/problems/fibonacci-number/)
 * @author Finalcheat
 * @date 2019-02-24
 */

/**
 * The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,
 * F(0) = 0,   F(1) = 1
 * F(N) = F(N - 1) + F(N - 2), for N > 1.
 * Given N, calculate F(N).
 * Example 1:
 * Input: 2
 * Output: 1
 * Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
 * Example 2:
 * Input: 3
 * Output: 2
 * Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
 * Example 3:
 * Input: 4
 * Output: 3
 * Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
 */

/**
 * 斐波纳契数，递归或者循环迭代都可以，递归慢循环迭代快，或者用数学公式直接得结果。
 */


class Solution {
    public:
        int fib(int N) {
            if (N < 2) {
                return N;
            }
            int a = 0;
            int b = 1;
            int result = 0;
            for (int i = 2; i <= N; ++i) {
                result = a + b;
                a = b;
                b = result;
            }
            return result;
        }
};
