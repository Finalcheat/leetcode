/**
 * @file Minimum-Subsequence-in-Non-Increasing-Order.cpp
 * @brief 非递增顺序的最小子序列(https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/)
 * @author Finalcheat
 * @date 2020-04-30
 */

/**
 * Given the array nums, obtain a subsequence of the array whose sum of elements is strictly greater than the sum of the non included elements in such subsequence. 
 * If there are multiple solutions, return the subsequence with minimum size and if there still exist multiple solutions, return the subsequence with the maximum total sum of all its elements. A subsequence of an array can be obtained by erasing some (possibly zero) elements from the array. 
 * Note that the solution with the given constraints is guaranteed to be unique. Also return the answer sorted in non-increasing order.
 * Example 1:
 * Input: nums = [4,3,10,9,8]
 * Output: [10,9]
 * Explanation: The subsequences [10,9] and [10,8] are minimal such that the sum of their elements is strictly greater than the sum of elements not included, however, the subsequence [10,9] has the maximum total sum of its elements. 
 * Example 2:
 * Input: nums = [4,4,7,6,7]
 * Output: [7,7,6]
 * Explanation: The subsequence [7,7] has the sum of its elements equal to 14 which is not strictly greater than the sum of elements not included (14 = 4 + 4 + 6). Therefore, the subsequence [7,6,7] is the minimal satisfying the conditions. Note the subsequence has to returned in non-decreasing order. 
 * Example 3:
 * Input: nums = [6]
 * Output: [6]
 */

/**
 * 排序遍历即可。
 */

class Solution {
    public:
        vector<int> minSubsequence(vector<int>& nums) {
            assert(!nums.empty());
            int sum = 0;
            for (const int num : nums) {
                sum += num;
            }
            std::sort(nums.begin(), nums.end(), std::greater<int>());
            vector<int> result;
            int subSum = 0;
            for (const int num : nums) {
                result.push_back(num);
                subSum += num;
                if (subSum * 2 > sum) {
                    break;
                }
            }
            return result;
        }
};
