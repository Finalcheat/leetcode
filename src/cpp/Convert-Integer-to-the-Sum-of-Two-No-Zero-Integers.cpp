/**
 * @file Convert-Integer-to-the-Sum-of-Two-No-Zero-Integers.cpp
 * @brief 将整数转换为两个非零整数的和(https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/)
 * @author Finalcheat
 * @date 2020-05-17
 */

/**
 * Given an integer n. No-Zero integer is a positive integer which doesn't contain any 0 in its decimal representation.
 * Return a list of two integers [A, B] where:
 * A and B are No-Zero integers.
 * A + B = n
 * It's guarateed that there is at least one valid solution. If there are many valid solutions you can return any of them.
 * Example 1:
 * Input: n = 2
 * Output: [1,1]
 * Explanation: A = 1, B = 1. A + B = n and both A and B don't contain any 0 in their decimal representation.
 * Example 2:
 * Input: n = 11
 * Output: [2,9]
 * Example 3:
 * Input: n = 10000
 * Output: [1,9999]
 * Example 4:
 * Input: n = 69
 * Output: [1,68]
 * Example 5:
 * Input: n = 1010
 * Output: [11,999]
 * Constraints:
 * * 2 <= n <= 10^4
 */

/**
 * 遍历1到n/2的数字i，判断i和n-i是否包含0，如果都不包含0，符合要求跳出循环。
 */

class Solution {
    public:
        vector<int> getNoZeroIntegers(int n) {
            vector<int> result(2);
            for (int i = 1; i <= n / 2; ++i) {
                if (!isContainZero(i) && !isContainZero(n - i)) {
                    result[0] = i;
                    result[1] = n - i;
                    break;
                }
            }
            return result;
        }
    private:
        bool isContainZero(int n) {
            if (n < 10) {
                return false;
            }
            if (n % 10 == 0) {
                return true;
            }
            return isContainZero(n / 10);
        }
};
