/**
 * @file Valid-Parentheses.cpp
 * @brief 判断括号组合是否有效(https://leetcode.com/problems/valid-parentheses/)
 * @author Finalcheat
 * @date 2016-04-11
 */

/**
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */

/**
 * 使用栈作辅助结构，遇到{[(字符就入栈，其他就出栈并匹配是否正确即可。
 */

class Solution {
    public:
        bool isValid(string s) {
            if (s.empty()) {
                return true;
            }
            std::stack<char> charStack;
            charStack.push(s[0]);
            for (size_t i = 1; i < s.size(); ++i) {
                char c = s[i];
                switch (c) {
                    case '(':
                    case '{':
                    case '[':
                        charStack.push(c);
                        break;
                    case ')':
                        if (charStack.empty() || charStack.top() != '(') {
                            return false;
                        }
                        charStack.pop();
                        break;
                    case '}':
                        if (charStack.empty() || charStack.top() != '{') {
                            return false;
                        }
                        charStack.pop();
                        break;
                    case ']':
                        if (charStack.empty() || charStack.top() != '[') {
                            return false;
                        }
                        charStack.pop();
                        break;
                }
            }
            return charStack.empty();
        }
};
