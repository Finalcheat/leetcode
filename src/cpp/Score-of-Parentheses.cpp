/**
 * @file Score-of-Parentheses.cpp
 * @brief 括号分数(https://leetcode.com/problems/score-of-parentheses/description/)
 * @author Finalcheat
 * @date 2018-07-26
 */

/**
 * Given a balanced parentheses string S, compute the score of the string based on the following rule:
 * * () has score 1
 * * AB has score A + B, where A and B are balanced parentheses strings.
 * * (A) has score 2 * A, where A is a balanced parentheses string.
 * Example 1:
 * Input: "()"
 * Output: 1
 * Example 2:
 * Input: "(())"
 * Output: 2
 * Example 3:
 * Input: "()()"
 * Output: 2
 * Example 4:
 * Input: "(()(()))"
 * Output: 6
 */

/**
 * 用变量记录括号的深度，遇到(则+1，遇到)则-1，当前后是()时累加该深度上的值。
 */


class Solution {
    public:
        int scoreOfParentheses(string S) {
            int result = 0;
            int times = 0;
            for (int i = 0; i < S.size(); ++i) {
                const char c = S[i];
                if (c == '(') {
                    ++times;
                } else {
                    --times;
                    if (i - 1 >= 0 && S[i - 1] == '(') {
                        result += (1 << times);
                    }
                }
            }
            return result;
        }
};
