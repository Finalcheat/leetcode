/**
 * @file Count-and-Say.cpp
 * @brief 计数和发言(https://leetcode.com/problems/count-and-say/description/)
 * @author Finalcheat
 * @date 2018-08-16
 */

/**
 * The count-and-say sequence is the sequence of integers with the first five terms as following:
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth term of the count-and-say sequence.
 * Note: Each term of the sequence of integers will be represented as a string.
 * Example 1:
 * Input: 1
 * Output: "1"
 * Example 2:
 * Input: 4
 * Output: "1211"
 */

/**
 * 题意比较难理解，其实就是统计上一个数单个字符的连续出现数量。
 */


class Solution {
    public:
        string countAndSay(int n) {
            string s = "1";
            for (int i = 2; i <= n; ++i) {
                char prevC = s[0];
                int count = 1;
                string ss;
                for (size_t j = 1; j < s.size(); ++j) {
                    if (s[j] == prevC) {
                        ++count;
                    } else {
                        ss += std::to_string(count) + prevC;
                        prevC = s[j];
                        count = 1;
                    }
                }
                s = ss + std::to_string(count) + prevC;
            }
            return s;
        }
};
