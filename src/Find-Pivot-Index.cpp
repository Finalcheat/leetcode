/**
 * @file Find-Pivot-Index.cpp
 * @brief 寻找中枢点(https://leetcode.com/problems/find-pivot-index/description/)
 * @author Finalcheat
 * @date 2018-01-24
 */

/**
 * Given an array of integers nums, write a method that returns the "pivot" index of this array.
 * We define the pivot index as the index where the sum of the numbers to the left of the index is equal to the sum of the numbers to the right of the index.
 * If no such index exists, we should return -1. If there are multiple pivot indexes, you should return the left-most pivot index.
 * Example 1:
 * Input:
 * nums = [1, 7, 3, 6, 5, 6]
 * Output: 3
 * Explanation:
 * The sum of the numbers to the left of index 3 (nums[3] = 6) is equal to the sum of numbers to the right of index 3.
 Also, 3 is the first index where this occurs.
 * Example 2:
 * Input:
 * nums = [1, 2, 3]
 * Output: -1
 * Explanation:
 * There is no index that satisfies the conditions in the problem statement.
 */

/**
 * 先算出总和，然后遍历数组过程中总和减去数组index上的值判断是否是已遍历的两倍，是则直接返回，否则继续。
 */


class Solution {
    public:
        int pivotIndex(vector<int>& nums) {
            int leftSum = 0;
            int sum = std::accumulate(nums.begin(), nums.end(), 0);
            for (size_t i = 0; i < nums.size(); ++i) {
                if (sum - nums[i] == leftSum * 2) {
                    return i;
                }
                leftSum += nums[i];
            }
            return -1;
        }
};
