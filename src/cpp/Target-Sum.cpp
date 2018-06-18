/**
 * @file Target-Sum.cpp
 * @brief 目标和(https://leetcode.com/problems/target-sum/description/)
 * @author Finalcheat
 * @date 2018-06-18
 */

/**
 * You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.
 * Find out how many ways to assign symbols to make sum of integers equal to target S.
 * Example 1:
 * Input: nums is [1, 1, 1, 1, 1], S is 3.
 * Output: 5
 * Explanation:
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 * There are 5 ways to assign symbols to make the sum of nums be target 3.
 */

/**
 * 递归解法最直观，数组下标idx位置+或者-递归下去，直到idx等于数组长度，此时判断最终值是否是target，是则返回1，否则返回0。
 */


class Solution {
    public:
        int findTargetSumWays(vector<int>& nums, int S) {
            return _findTargetSumWays(nums, S, 0);
        }
    private:
        int _findTargetSumWays(const vector<int>& nums, int S, size_t idx) {
            if (idx >= nums.size()) {
                if (S == 0) {
                    return 1;
                }
                return 0;
            }

            int count1 = _findTargetSumWays(nums, S + nums[idx], idx + 1);
            int count2 = _findTargetSumWays(nums, S - nums[idx], idx + 1);

            return (count1 + count2);
        }
};
