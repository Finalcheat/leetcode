/**
 * @file Minimum-ASCII-Delete-Sum-for-Two-Strings.cpp
 * @brief 两个字符串的最小ASCII删除和(https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/)
 * @author Finalcheat
 * @date 2018-07-01
 */

/**
 * Given two strings s1, s2, find the lowest ASCII sum of deleted characters to make two strings equal.
 * Example 1:
 * Input: s1 = "sea", s2 = "eat"
 * Output: 231
 * Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
 * Deleting "t" from "eat" adds 116 to the sum.
 * At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
 * Example 2:
 * Input: s1 = "delete", s2 = "leet"
 * Output: 403
 * Explanation: Deleting "dee" from "delete" to turn the string into "let",
 * adds 100[d]+101[e]+101[e] to the sum.  Deleting "e" from "leet" adds 101[e] to the sum.
 * At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
 * If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
 */

/**
 * 动态规划，用dp数组辅助，记录最大相同子序列的ASCII码值，最后所有字符之和减去最大相同子序列ASCII码值的两倍即可。
 */


class Solution {
    public:
        int minimumDeleteSum(string s1, string s2) {
            std::vector< std::vector<int> > dp(s1.size() + 1, std::vector<int>(s2.size() + 1, 0));
            for (size_t i = 1; i <= s1.size(); ++i) {
                for (size_t j = 1; j <= s2.size(); ++j) {
                    if (s1[i - 1] == s2[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1] + s1[i - 1];
                    } else {
                        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
            int s1Sum = std::accumulate(s1.begin(), s1.end(), 0);
            int s2Sum = std::accumulate(s2.begin(), s2.end(), 0);
            int sum = s1Sum + s2Sum - 2 * dp[s1.size()][s2.size()];
            return sum;
        }
};
