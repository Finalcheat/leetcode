/**
 * @file Isomorphic-Strings.cpp
 * @brief 同构字符串(https://leetcode.com/problems/isomorphic-strings/) 
 * @author Finalcheat
 * @date 2016-06-03
 */

/**
 * Given two strings s and t, determine if they are isomorphic.
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
 * For example,
 * Given "egg", "add", return true.
 * Given "foo", "bar", return false.
 * Given "paper", "title", return true.
 * Note:
 * You may assume both s and t have the same length.
 */

/**
 * 两个哈希表存储字符，然后遍历查找判断即可。
 */

class Solution {
    public:
        bool isIsomorphic(string s, string t) {
            if (s.size() != t.size()) {
                return false;
            }
            std::unordered_map<char, int> u1;
            std::unordered_map<char, int> u2;
            for (size_t i = 0; i < s.size(); ++i) {
                const char c1 = s[i];
                const char c2 = t[i];
                if (u1[c1] != u2[c2]) {
                    return false;
                }
                u1[c1] = i + 1;
                u2[c2] = i + 1;
            }
            return true;
        }
};
