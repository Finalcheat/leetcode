/**
 * @file Repeated-Substring-Pattern.cpp
 * @brief 重复子字符串模式(https://leetcode.com/problems/repeated-substring-pattern/description/)
 * @author Finalcheat
 * @date 2018-03-10
 */

/**
 * Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.
 * Example 1:
 * Input: "abab"
 * Output: True
 * Explanation: It's the substring "ab" twice.
 * Example 2:
 * Input: "aba"
 * Output: False
 * Example 3:
 * Input: "abcabcabcabc"
 * Output: True
 * Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
 */

/**
 * 找出与首字符相同的字符位置，遍历字符位置分组尝试匹配，成功则直接返回true，否则继续匹配直到匹配完毕返回false。
 */


class Solution {

    public:
        bool repeatedSubstringPattern(string s) {
            const size_t halfPos = s.size() / 2;
            vector<size_t> charPos;
            for (size_t i = 1; i <= halfPos; ++i) {
                if (s[i] == s[0]) {
                    charPos.push_back(i);
                }
            }
            bool result = false;
            for (size_t i = 0; i < charPos.size(); ++i) {
                result |= check(s, charPos[i]);
                if (result) {
                    return true;
                }
            }
            return false;
        }

    private:
        bool check(const string& s, const size_t pos) {
            const size_t remain = s.size() % pos;
            if (remain) {
                return false;
            }
            const size_t group = s.size() / pos;
            for (size_t i = 1; i < group; ++i) {
                for (size_t j = 0; j < pos; ++j) {
                    if (s[j] != s[j + i * pos]) {
                        return false;
                    }
                }
            }
            return true;
        }

};
