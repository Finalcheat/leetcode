/**
 * @file Remove-All-Adjacent-Duplicates-In-String.cpp
 * @brief 删除字符串中所有相邻的重复项(https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/)
 * @author Finalcheat
 * @date 2019-09-19
 */

/**
 * Given a string S of lowercase letters, a duplicate removal consists of choosing two adjacent and equal letters, and removing them.
 * We repeatedly make duplicate removals on S until we no longer can.
 * Return the final string after all such duplicate removals have been made.  It is guaranteed the answer is unique.
 * Example 1:
 * Input: "abbaca"
 * Output: "ca"
 * Explanation:
 * For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
 */

/**
 * 使用栈作为辅助结构，当前元素与栈顶元素不相等就入栈，相等就出栈，最后栈中的字符就是结果。
 */

class Solution {
    public:
        string removeDuplicates(string S) {
            if (S.empty()) {
                return "";
            }
            std::stack<char> stackHelper;
            stackHelper.push(S[0]);
            for (size_t i = 1; i < S.size(); ++i) {
                const char c = S[i];
                if (!stackHelper.empty() && c == stackHelper.top()) {
                    stackHelper.pop();
                } else {
                    stackHelper.push(c);
                }
            }
            string result;
            while (!stackHelper.empty()) {
                result += stackHelper.top();
                stackHelper.pop();
            }
            std::reverse(result.begin(), result.end());
            return result;
        }
};
