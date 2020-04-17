/**
 * @file Minimum-Number-of-Steps-to-Make-Two-Strings-Anagram.cpp
 * @brief 最小次数使两个字符串成为变位词(https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/)
 * @author Finalcheat
 * @date 2020-04-17
 */

/**
 * Given two equal-size strings s and t. In one step you can choose any character of t and replace it with another character.
 * Return the minimum number of steps to make t an anagram of s.
 * An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.
 * Example 1:
 * Input: s = "bab", t = "aba"
 * Output: 1
 * Explanation: Replace the first 'a' in t with b, t = "bba" which is anagram of s.
 * Example 2:
 * Input: s = "leetcode", t = "practice"
 * Output: 5
 * Explanation: Replace 'p', 'r', 'a', 'i' and 'c' from t with proper characters to make t anagram of s.
 * Example 3:
 * Input: s = "anagram", t = "mangaar"
 * Output: 0
 * Explanation: "anagram" and "mangaar" are anagrams.
 * Example 4:
 * Input: s = "xxyyzz", t = "xxyyzz"
 * Output: 0
 * Example 5:
 * Input: s = "friend", t = "family"
 * Output: 4
 */

/**
 * 总体思路就是统计字符频次。
 */

class Solution {
    public:
        int minSteps(string s, string t) {
            assert(s.size() == t.size());
            std::unordered_map<char, int> u;
            for (const char c : s) {
                ++u[c];
            }
            int step = 0;
            for (const char c : t) {
                auto iter = u.find(c);
                if (iter != u.end()) {
                    if (--(iter->second) == 0) {
                        u.erase(iter);
                    }
                } else {
                    ++step;
                }
            }
            return step;
        }
};
