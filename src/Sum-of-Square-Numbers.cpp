/**
 * @file Sum-of-Square-Numbers.cpp
 * @brief 平方数之和(https://leetcode.com/problems/sum-of-square-numbers/description/)
 * @author Finalcheat
 * @date 2018-03-16
 */

/**
 * Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.
 * Example 1:
 * Input: 5
 * Output: True
 * Explanation: 1 * 1 + 2 * 2 = 5
 * Example 2:
 * Input: 3
 * Output: False
 */

/**
 * 用一个set保存平方数，然后遍历判断即可。
 */


class Solution {
    public:
        bool judgeSquareSum(int c) {
            std::set<int> s;
            int i = 0;
            s.insert(i++);
            const int sqrtNum = std::sqrt(c);
            while (i <= sqrtNum) {
                s.insert(i * i);
                ++i;
            }
            for (int i = 0; i <= sqrtNum; ++i) {
                const int value = c - (i * i);
                if (value < 0) {
                    return false;
                }
                auto iter = s.find(value);
                if (iter != s.end()) {
                    return true;
                }
            }
            return false;
        }
};
