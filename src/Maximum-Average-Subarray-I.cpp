/**
 * @file Maximum-Average-Subarray-I.cpp
 * @brief 子数组最大平均数(https://leetcode.com/problems/maximum-average-subarray-i/description/)
 * @author Finalcheat
 * @date 2018-01-31
 */

/**
 * Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.
 * Example 1:
 * Input: [1,12,-5,-6,50,3], k = 4
 * Output: 12.75
 * Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
 * Note:
 * 1. 1 <= k <= n <= 30,000.
 * 2. Elements of the given array will be in the range [-10,000, 10,000].
 */

/**
 * 其实也就是求子数组累加的最大值，可以先求出k个元素的累加值，然后遍历过程中首尾元素相减得到差值加上之前的累加值就可以避免重复计算。
 */


class Solution {
    public:
        double findMaxAverage(vector<int>& nums, int k) {
            int maxSum = 0;
            for (int i = 0; i < k; ++i) {
                maxSum += nums[i];
            }
            int cursor = 0;
            int curSum = maxSum;
            for (int i = k; i < nums.size(); ++i) {
                curSum += (nums[i] - nums[cursor]);
                if (curSum > maxSum) {
                    maxSum = curSum;
                }
                ++cursor;
            }
            const double avg = maxSum / (double)k;
            return avg;
        }
};
