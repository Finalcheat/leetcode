/**
 * @file 2-Keys-Keyboard.cpp
 * @brief 两键的键盘(https://leetcode.com/problems/2-keys-keyboard/description/)
 * @author Finalcheat
 * @date 2018-07-21
 */

/**
 * Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:
 * 1. Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
 * 2. Paste: You can paste the characters which are copied last time.
 * Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted. Output the minimum number of steps to get n 'A'.
 * Example 1:
 * Input: 3
 * Output: 3
 * Explanation:
 * Intitally, we have one character 'A'.
 * In step 1, we use Copy All operation.
 * In step 2, we use Paste operation to get 'AA'.
 * In step 3, we use Paste operation to get 'AAA'.
 */

/**
 * 动态规划，dp存储第i个字符能达到的最小次数。
 */


class Solution {
    public:
        int minSteps(int n) {
            vector<int> dp(n + 1);
            for (int i = 2; i <= n; ++i) {
                dp[i] = i;
                for (int j = i / 2; j > 1; --j) {
                    if (i % j == 0) {
                        dp[i] = min(dp[i], dp[j] + (i / j));
                    }
                }
            }
            return dp[n];
        }
};
