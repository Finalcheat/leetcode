/**
 * @file Count-Numbers-with-Unique-Digits.cpp
 * @brief 各位不相同的数字个数(https://leetcode.com/problems/count-numbers-with-unique-digits/description/)
 * @author Finalcheat
 * @date 2018-07-15
 */

/**
 * Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10^n.
 * Example:
 * Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding
 * [11,22,33,44,55,66,77,88,99])
 */

/**
 * 动态规划，计算每*10各位不相同的数字，然后累计即可。
 */


class Solution {
    public:
        int countNumbersWithUniqueDigits(int n) {
            assert(n >= 0);
            if (n == 0) {
                return 1;
            }
            int result = 10;
            int sum = 9;
            int count = 9;
            for (size_t i = 1; i < n; ++i) {
                sum *= count;
                --count;
                result += sum;
            }
            return result;
        }
};
