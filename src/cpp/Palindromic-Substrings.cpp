/**
 * @file Palindromic-Substrings.cpp
 * @brief 回文子字符串(https://leetcode.com/problems/palindromic-substrings/description/)
 * @author Finalcheat
 * @date 2018-07-15
 */

/**
 * Given a string, your task is to count how many palindromic substrings in this string.
 * The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.
 * Example 1:
 * Input: "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 * Example 2:
 * Input: "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 */

/**
 * 动态规划，dp[i][j]代表i..j子字符串是否是回文。
 */


class Solution {
    public:
        int countSubstrings(string s) {
            const size_t len = s.size();
            vector< vector<int> > dp(len, vector<int>(len, 0));
            for (size_t i = 0; i < len; ++i) {
                dp[i][i] = 1;
            }
            int count = 0;
            for (int i = 1; i < len; ++i) {
                for (int j = i - 1; j >= 0; --j) {
                    dp[i][j] = ((s[i] == s[j]) && (i - j <= 2 || dp[i - 1][j + 1]));
                    if (dp[i][j]) {
                        ++count;
                    }
                }
            }
            return count + s.size();
        }
};
