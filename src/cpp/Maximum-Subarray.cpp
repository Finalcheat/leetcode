/**
 * @file Maximum-Subarray.cpp
 * @brief 最大子序和(https://leetcode.com/problems/maximum-subarray/description/)
 * @author Finalcheat
 * @date 2018-09-03
 */

/**
 * Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
 * Example:
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 */

/**
 * 用cur变量维持当前局部最大子序和，用maximum维持全局最大子序和，遍历判断更新即可。
 */


class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            assert(nums.size() >= 1);
            int cur = nums[0];
            int maximum = cur;
            for (size_t i = 1; i < nums.size(); ++i) {
                cur = std::max(cur + nums[i], nums[i]);
                maximum = std::max(maximum, cur);
            }
            return maximum;
        }
};
