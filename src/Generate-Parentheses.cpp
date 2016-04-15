/**
 * @file Generate-Parentheses.cpp
 * @brief 生成括号配对(https://leetcode.com/problems/generate-parentheses/) 
 * @author Finalcheat
 * @date 2016-04-15
 */


/**
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 * For example, given n = 3, a solution set is:
 * "((()))", "(()())", "(())()", "()(())", "()()()"
 */

/**
 * 递归解决。当右括号剩余数量小于左括号剩余数量时，该组合不可取，直接返回；否则将左括号、右括号减1分别递归调用本身直到左右括号剩余数量为0。
 */

class Solution {
    public:
        vector<string> generateParenthesis(int n) {
            vector<string> vec;
            if (n <= 0) {
                return vec;
            }
            _generateParenthesis(n, n, "", vec);
            return vec;
        }

    private:
        void _generateParenthesis(int left, int right, const string s, vector<string>& vec) {
            if (right < left) {
                return;
            }
            if (left == 0 && right == 0) {
                vec.push_back(s);
            }
            if (left > 0) {
                _generateParenthesis(left - 1, right, s + "(", vec);
            }
            if (right > 0) {
                _generateParenthesis(left, right - 1, s + ")", vec);
            }
        }
};
