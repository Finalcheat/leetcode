/**
 * @file Reverse-String-II.cpp
 * @brief 反转字符串II(https://leetcode.com/problems/reverse-string-ii/description/)
 * @author Finalcheat
 * @date 2018-01-18
 */

/**
 * Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
 * Example:
 * Input: s = "abcdefg", k = 2
 * Output: "bacdfeg"
 */

/**
 * 没隔k个字符反转即可，注意末尾不足k个字符的情况。
 */


class Solution {
    public:
        string reverseStr(string s, int k) {
            const size_t count = s.size() / k;
            for (size_t i = 0; i <= count; i += 2) {
                if (i * k + k < s.size()) {
                    std::reverse(s.begin() + i * k, s.begin() + i * k + k);
                } else {
                    std::reverse(s.begin() + i * k, s.end());
                }
            }
            return s;
        }
};
