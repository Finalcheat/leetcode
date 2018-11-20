/**
 * @file Minimum-Size-Subarray-Sum.cpp
 * @brief 长度最小的子数组(https://leetcode.com/problems/minimum-size-subarray-sum/description/)
 * @author Finalcheat
 * @date 2018-09-12
 */

/**
 * Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.
 * Example:
 * Input: s = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: the subarray [4,3] has the minimal length under the problem constraint.
 */

/**
 * 用left记录子数组开始位置，遍历过程不断累加，一旦发现sum>=s的时候减去nums[left]的数字同时left向右移。
 */


class Solution {
    public:
        int minSubArrayLen(int s, vector<int>& nums) {
            int minimum = INT_MAX;
            int sum = 0;
            int left = 0;
            for (int i = 0; i < nums.size(); ++i) {
                sum += nums[i];
                while (left <= i && sum >= s) {
                    minimum = std::min(minimum, i - left + 1);
                    sum -= nums[left];
                    ++left;
                }
            }
            if (minimum == INT_MAX) {
                return 0;
            }
            return minimum;
        }
};
