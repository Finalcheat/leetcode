/**
 * @file Longest-Uncommon-Subsequence-I.cpp
 * @brief 最长非公共子序列I(https://leetcode.com/problems/longest-uncommon-subsequence-i/description/)
 * @author Finalcheat
 * @date 2018-03-14
 */

/**
 * Given a group of two strings, you need to find the longest uncommon subsequence of this group of two strings. The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.
 * A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.
 * The input will be two strings, and the output needs to be the length of the longest uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.
 * Example 1:
 * Input: "aba", "cdc"
 * Output: 3
 * Explanation: The longest uncommon subsequence is "aba" (or "cdc"),
 * because "aba" is a subsequence of "aba",
 * but not a subsequence of any other strings in the group of two strings.
 */

/**
 * 比较字符串长度，长度的为所求；长度相同比较是否相等。
 */


class Solution {
    public:
        int findLUSlength(string a, string b) {
            const size_t aSize = a.size();
            const size_t bSize = b.size();
            if (aSize == bSize) {
                return a == b ? -1 : aSize;
            }
            return std::max(aSize, bSize);
        }
};
