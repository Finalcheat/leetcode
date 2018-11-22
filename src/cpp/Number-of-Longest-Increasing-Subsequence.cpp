/**
 * @file Number-of-Longest-Increasing-Subsequence.cpp
 * @brief 最长递增子序列的个数(https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/)
 * @author Finalcheat
 * @date 2018-10-17
 */

/**
 * Given an unsorted array of integers, find the number of longest increasing subsequence.
 * Example 1:
 * Input: [1,3,5,4,7]
 * Output: 2
 * Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].
 * Example 2:
 * Input: [2,2,2,2,2]
 * Output: 5
 * Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.
 */

/**
 * 动态规划解决即可。
 */


class Solution {
    public:
        int findNumberOfLIS(vector<int>& nums) {
            if (nums.empty()) {
                return 0;
            }
            vector<int> lenDp(nums.size(), 1);
            vector<int> countDp(nums.size(), 1);
            for (size_t i = 1; i < nums.size(); ++i) {
                for (size_t j = 0; j < i; ++j) {
                    if (nums[i] <= nums[j]) {
                        continue;
                    }
                    if (lenDp[i] == lenDp[j] + 1) {
                        countDp[i] += countDp[j];
                    } else if (lenDp[i] < lenDp[j] + 1) {
                        lenDp[i] = lenDp[j] + 1;
                        countDp[i] = countDp[j];
                    }
                }
            }
            int maximum = *std::max_element(lenDp.begin(), lenDp.end());
            int result = 0;
            for (size_t i = 0; i < lenDp.size(); ++i) {
                if (lenDp[i] == maximum) {
                    result += countDp[i];
                }
            }
            return result;
        }
};
