/**
 * @file Valid-Anagram.cpp
 * @brief 验证变位词(https://leetcode.com/problems/valid-anagram/)
 * @author Finalcheat
 * @date 2016-03-07
 */

/**
 * Given two strings s and t, write a function to determine if t is an anagram of s.
 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
 * Note:
 * You may assume the string contains only lowercase alphabets.
 */

/**
 * 对字符串进行排序，然后遍历比较是否相等即可。
 */

class Solution {
    public:
        bool isAnagram(string s, string t) {
            if (s.size() != t.size()) {
                return false;
            }
            std::sort(s.begin(), s.end());
            std::sort(t.begin(), t.end());
            for (size_t i = 0; i < s.size(); ++i) {
                if (s[i] != t[i]) {
                    return false;
                }
            }
            return true;
        }
};
