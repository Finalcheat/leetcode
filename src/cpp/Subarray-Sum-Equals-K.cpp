/**
 * @file Subarray-Sum-Equals-K.cpp
 * @brief 子数组和为K(https://leetcode.com/problems/subarray-sum-equals-k/description/)
 * @author Finalcheat
 * @date 2018-01-28
 */

/**
 * Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
 * Example 1:
 * Input:nums = [1,1,1], k = 2
 * Output: 2
 */

/**
 * 顺序遍历暴力搜索即可。
 */


class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            int count = 0;
            int sum = 0;
            for (size_t i = 0; i < nums.size(); ++i) {
                sum += nums[i];
                if (sum == k) {
                    ++count;
                }
                int curSum = 0;
                for (size_t j = 0; j < i; ++j) {
                    curSum += nums[j];
                    if (sum - curSum == k) {
                        ++count;
                    }
                }
            }
            return count;
        }
};
