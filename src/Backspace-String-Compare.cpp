/**
 * @file Backspace-String-Compare.cpp
 * @brief 退格字符串比较(https://leetcode.com/problems/backspace-string-compare/description/)
 * @author Finalcheat
 * @date 2018-06-04
 */

/**
 * Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.
 * Example 1:
 * Input: S = "ab#c", T = "ad#c"
 * Output: true
 * Explanation: Both S and T become "ac".
 * Example 2:
 * Input: S = "ab##", T = "c#d#"
 * Output: true
 * Explanation: Both S and T become "".
 * Example 3:
 * Input: S = "a##c", T = "#a#c"
 * Output: true
 * Explanation: Both S and T become "c".
 * Example 4:
 * Input: S = "a#c", T = "b"
 * Output: false
 * Explanation: S becomes "c" while T becomes "b".
 */

/**
 * 最简单的方法按规则得到最终的两个字符串直接比较即可。
 */


class Solution {
    public:
        bool backspaceCompare(string S, string T) {
            string ss;
            for (size_t i = 0; i < S.size(); ++i) {
                const char c = S[i];
                if (c == '#') {
                    if (!ss.empty()) {
                        ss.pop_back();
                    }
                } else {
                    ss.push_back(c);
                }
            }

            string tt;
            for (size_t i = 0; i < T.size(); ++i) {
                const char c = T[i];
                if (c == '#') {
                    if (!tt.empty()) {
                        tt.pop_back();
                    }
                } else {
                    tt.push_back(c);
                }
            }

            return (ss == tt);
        }
};
