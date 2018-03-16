/**
 * @file Perfect-Number.cpp
 * @brief 完全数(https://leetcode.com/problems/perfect-number/description/)
 * @author Finalcheat
 * @date 2018-03-16
 */

/**
 * We define the Perfect Number is a positive integer that is equal to the sum of all its positive divisors except itself.
 * Now, given an integer n, write a function that returns true when it is a perfect number and false when it is not.
 * Example:
 * Input: 28
 * Output: True
 * Explanation: 28 = 1 + 2 + 4 + 7 + 14
 */

/**
 * 思路很简单，按照完全数的定义判断即可，但是这样会超时！只好调整算法尽量缩短循环次数。
 */


class Solution {
    public:
        bool checkPerfectNumber(int num) {
            int sum = 1;
            int count = num / 2;
            int i = 2;
            while (i <= count) {
                if (num % i == 0) {
                    sum += i;
                    int tmp = num / i;
                    sum += tmp;
                    count = tmp - 1;
                    if (sum > num) {
                        return false;
                    }
                }
                ++i;
            }
            return sum > 1 && sum == num;
        }
};
