/**
 * @file Split-a-String-in-Balanced-Strings.cpp
 * @brief 将字符串分割成平衡的字符串(https://leetcode.com/problems/split-a-string-in-balanced-strings/)
 * @author Finalcheat
 * @date 2020-04-20
 */

/**
 * Balanced strings are those who have equal quantity of 'L' and 'R' characters.
 * Given a balanced string s split it in the maximum amount of balanced strings.
 * Return the maximum amount of splitted balanced strings.
 * Example 1:
 * Input: s = "RLRRLLRLRL"
 * Output: 4
 * Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.
 * Example 2:
 * Input: s = "RLLLLRRRLR"
 * Output: 3
 * Explanation: s can be split into "RL", "LLLRRR", "LR", each substring contains same number of 'L' and 'R'.
 * Example 3:
 * Input: s = "LLLLRRRR"
 * Output: 1
 * Explanation: s can be split into "LLLLRRRR".
 * Example 4:
 * Input: s = "RLRRRLLRLL"
 * Output: 2
 * Explanation: s can be split into "RL", "RRRLLRLL", since each substring contains an equal number of 'L' and 'R'
 */

/**
 * 贪心算法，碰到L字符-1，R字符+1，当前平衡值=0就分割。
 */

class Solution {
    public:
        int balancedStringSplit(string s) {
            int curCharCount = 0;
            int count = 0;
            for (const char c : s) {
                if (c == 'L') {
                    --curCharCount;
                } else {
                    ++curCharCount;
                }
                if (curCharCount == 0) {
                    ++count;
                }
            }
            return count;
        }
};
