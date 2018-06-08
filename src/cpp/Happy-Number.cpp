/**
 * @file Happy-Number.cpp
 * @brief 快乐数(https://leetcode.com/problems/happy-number/) 
 * @author Finalcheat
 * @date 2016-04-03
 */

/**
 * Write an algorithm to determine if a number is "happy".
 * A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
 * Example: 19 is a happy number
 * - 1 * 1 + 9 * 9 = 82
 * - 8 * 8 + 2 * 2 = 68
 * - 6 * 6 + 8 * 8 = 100
 * - 1 * 1 + 0 * 0 + 0 * 0 = 1
 */

/**
 * 根据快乐数的定义，在循环中分解出每个数字，然后平方相加即可。
 * 需要注意的是死循环这种情况，比如2这个数
 * - 2 * 2 = 4
 * - 4 * 4 = 16
 * - 1 * 1 + 6 * 6 = 37
 * - 3 * 3 + 7 * 7 = 58
 * - 5 * 5 + 8 * 8 = 89
 * - 8 * 8 + 9 * 9 = 145
 * - 1 * 1 + 4 * 4 + 5 * 5 = 42
 * - 4 * 4 + 2 * 2 = 20
 * - 2 * 2 + 0 * 0 = 4
 * 可以看出4死循环了，所以必须记录曾经出现过的数字，这里简单用std::set即可。
 */

class Solution {
    public:
        bool isHappy(int n) {
            std::set<int> s;
            while (n != 1) {
                int result = 0;
                while (n) {
                    result += (n % 10) * (n % 10);
                    n = n / 10;
                }
                if (result == 1) {
                    return true;
                }
                n = result;
                if (s.find(n) == s.end()) {
                    s.insert(n);
                } else {
                    break;
                }
            }
            return n == 1;
        }
};
