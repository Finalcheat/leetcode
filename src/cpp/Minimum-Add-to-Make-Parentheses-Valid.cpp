/**
 * @file Minimum-Add-to-Make-Parentheses-Valid.cpp
 * @brief 最小个数添加括号有效(https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/)
 * @author Finalcheat
 * @date 2018-11-05
 */

/**
 * Given a string S of '(' and ')' parentheses, we add the minimum number of parentheses ( '(' or ')', and in any positions ) so that the resulting parentheses string is valid.
 * Formally, a parentheses string is valid if and only if:
 * * It is the empty string, or
 * * It can be written as AB (A concatenated with B), where A and B are valid strings, or
 * * It can be written as (A), where A is a valid string.
 * Given a parentheses string, return the minimum number of parentheses we must add to make the resulting string valid.
 * Example 1:
 * Input: "())"
 * Output: 1
 * Example 2:
 * Input: "((("
 * Output: 3
 * Example 3:
 * Input: "()"
 * Output: 0
 * Example 4:
 * Input: "()))(("
 * Output: 4
 */

/**
 * 记录左括号个数，遇到右括号则左括号数减1，当左括号数为0时则说明需要添加1个括号。
 */


class Solution {
    public:
        int minAddToMakeValid(string S) {
            int leftParentheses = 0;
            int count = 0;
            for (size_t i = 0; i < S.size(); ++i) {
                const char c = S[i];
                if (c == '(') {
                    ++leftParentheses;
                } else {
                    if (leftParentheses > 0) {
                        --leftParentheses;
                    } else {
                        ++count;
                    }
                }
            }
            count += leftParentheses;
            return count;
        }
};
