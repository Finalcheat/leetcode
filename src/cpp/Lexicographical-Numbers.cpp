/**
 * @file Lexicographical-Numbers.cpp
 * @brief 字典序数字(https://leetcode.com/problems/lexicographical-numbers/description/)
 * @author Finalcheat
 * @date 2018-07-30
 */

/**
 * Given an integer n, return 1 - n in lexicographical order.
 * For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].
 * Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.
 */

/**
 * 从位数考虑，首先从1开始，乘以10还是小于n的话继续，否则加1，如果大于等于n则除以10再加1。
 */


class Solution {
    public:
        vector<int> lexicalOrder(int n) {
            vector<int> result(n);
            int cur = 1;
            for (int i = 0; i < n; ++i) {
                result[i] = cur;
                if (cur * 10 <= n) {
                    cur *= 10;
                } else {
                    if (cur >= n) {
                        cur /= 10;
                    }
                    ++cur;
                    while (cur % 10 == 0) {
                        cur /= 10;
                    }
                }
            }
            return result;
        }
};
