/**
 * @file Subtract-the-Product-and-Sum-of-Digits-of-an-Integer.cpp
 * @brief 数字乘积减数字和(https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/)
 * @author Finalcheat
 * @date 2020-04-11
 */

/**
 * Given an integer number n, return the difference between the product of its digits and the sum of its digits.
 * Example 1:
 * Input: n = 234
 * Output: 15
 * Explanation:
 * Product of digits = 2 * 3 * 4 = 24
 * Sum of digits = 2 + 3 + 4 = 9
 * Result = 24 - 9 = 15
 * Example 2:
 * Input: n = 4421
 * Output: 21
 * Explanation:
 * Product of digits = 4 * 4 * 2 * 1 = 32
 * Sum of digits = 4 + 4 + 2 + 1 = 11
 * Result = 32 - 11 = 21
 */

/**
 * 分离数字就行，没什么难度。
 */

class Solution {
    public:
        int subtractProductAndSum(int n) {
            int product = 1;
            int sum = 0;
            while (n) {
                const int digit = n % 10;
                product *= digit;
                sum += digit;
                n /= 10;
            }
            return (product - sum);
        }
};
