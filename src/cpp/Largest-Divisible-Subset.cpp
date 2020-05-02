/**
 * @file Largest-Divisible-Subset.cpp
 * @brief 最大可分割的一部分(https://leetcode.com/problems/largest-divisible-subset/)
 * @author Finalcheat
 * @date 2020-05-02
 */

/**
 * Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:
 * Si % Sj = 0 or Sj % Si = 0.
 * If there are multiple solutions, return any subset is fine.
 * Example 1:
 * Input: [1,2,3]
 * Output: [1,2] (of course, [1,3] will also be ok)
 * Example 2:
 * Input: [1,2,4,8]
 * Output: [1,2,4,8]
 */

/**
 * 动态规划，先排序，使用dp[i]代表第i个数最大可分割的数量，后续Sj % Si = 0的情况下，dp[j] = max(dp[j], dp[i] + 1)，最后找出最大值。
 */

class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            if (nums.empty()) {
                return vector<int>();
            }
            std::sort(nums.begin(), nums.end());
            vector<int> dp(nums.size(), 1);
            for (size_t i = 0; i < nums.size(); ++i) {
                for (size_t j = 0; j < i; ++j) {
                    if (nums[i] % nums[j] == 0) {
                        dp[i] = std::max(dp[i], dp[j] + 1);
                    }
                }
            }
            int maximum = dp[0];
            int idx = 0;
            for (int i = 0; i < dp.size(); ++i) {
                if (dp[i] > maximum) {
                    maximum = dp[i];
                    idx = i;
                }
            }
            int lastValue = nums[idx];
            vector<int> result;
            result.push_back(lastValue);
            for (int i = idx - 1; i >= 0; --i) {
                if ((dp[i] == maximum - 1) && (lastValue % nums[i] == 0)) {
                    result.push_back(nums[i]);
                    --maximum;
                    lastValue = nums[i];
                }
            }
            return result;
        }
};
