/**
 * @file Longest-Valid-Parentheses.cpp
 * @brief 最长有效括号(https://leetcode.com/problems/longest-valid-parentheses/)
 * @author Finalcheat
 * @date 2020-05-16
 */

/**
 * Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 * Example 1:
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 * Example 2:
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 */

/**
 * 使用栈做辅助结构，将局部范围的有效括号数压栈保存起来，'('用0记录，遇到')'匹配栈中的'('，过程中将有效括号数重新记录压栈；遇到栈为空的情况说明连续的有效括号数中断，此时需要保存局部的有效括号数。
 */

class Solution {
    public:
        int longestValidParentheses(string s) {
            if (s.empty()) {
                return 0;
            }
            int maximum = 0;
            std::stack<int> st;
            for (string::const_iterator iter = s.begin(); iter != s.end(); ++iter) {
                if (*iter == '(') {
                    st.push(0);
                } else {
                    assert(*iter == ')');
                    if (st.empty()) {
                        continue;
                    }
                    if (st.top() == 0) {
                        st.pop();
                        st.push(2);
                    } else {
                        int sum = continuousAccumulation(st);
                        if (!st.empty()) {
                            st.pop();
                            st.push(sum + 2);
                        } else {
                            if (sum > maximum) {
                                maximum = sum;
                            }
                        }
                    }
                }
            }
            while (!st.empty()) {
                if (st.top() == 0) {
                    st.pop();
                } else {
                    int sum = continuousAccumulation(st);
                    if (sum > maximum) {
                        maximum = sum;
                    }
                }
            }
            return maximum;
        }
    private:
        int continuousAccumulation(std::stack<int>& st) {
            int sum = 0;
            while (!st.empty() && st.top() != 0) {
                sum += st.top();
                st.pop();
            }
            return sum;
        }
};
