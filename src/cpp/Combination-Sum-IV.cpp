/**
 * @file Combination-Sum-IV.cpp
 * @brief 组合总和Ⅳ(https://leetcode.com/problems/combination-sum-iv/description/)
 * @author Finalcheat
 * @date 2018-10-23
 */

/**
 * Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.
 * Example:
 * nums = [1, 2, 3]
 * target = 4
 * The possible combination ways are:
 * (1, 1, 1, 1)
 * (1, 1, 2)
 * (1, 2, 1)
 * (1, 3)
 * (2, 1, 1)
 * (2, 2)
 * (3, 1)
 * Note that different sequences are counted as different combinations.
 * Therefore the output is 7.
 */

/**
 * 动态规划，将数字拆分。
 */


class Solution {
    public:
        int combinationSum4(vector<int>& nums, int target) {
            vector<int> dp(target + 1, 0);
            dp[0] = 1;
            for (int i = 1; i <= target; ++i) {
                for (const int num : nums) {
                    if (num > i) {
                        continue;
                    }
                    dp[i] += dp[i - num];
                }
            }
            return dp[dp.size() - 1];
        }
};
