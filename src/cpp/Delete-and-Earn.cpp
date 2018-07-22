/**
 * @file Delete-and-Earn.cpp
 * @brief 删除和收入(https://leetcode.com/problems/delete-and-earn/description/)
 * @author Finalcheat
 * @date 2018-07-22
 */

/**
 * Given an array nums of integers, you can perform operations on the array.
 * In each operation, you pick any nums[i] and delete it to earn nums[i] points. After, you must delete every element equal to nums[i] - 1 or nums[i] + 1.
 * You start with 0 points. Return the maximum number of points you can earn by applying such operations.
 * Example 1:
 * Input: nums = [3, 4, 2]
 * Output: 6
 * Explanation:
 * Delete 4 to earn 4 points, consequently 3 is also deleted.
 * Then, delete 2 to earn 2 points. 6 total points are earned.
 * Example 2:
 * Input: nums = [2, 2, 3, 3, 3, 4]
 * Output: 9
 * Explanation:
 * Delete 3 to earn 3 points, deleting both 2's and the 4.
 * Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
 * 9 total points are earned.
 * Note:
 * The length of nums is at most 20000.
 * Each element nums[i] is an integer in the range [1, 10000].
 */

/**
 * 动态规划，dp[i]存储到数字i时的最大收入，对比dp[i - 2]、dp[i - 1]、dp[i]的值即可。
 * 题目有数字的范围[1, 10000]，所以生成dp容量为10001大小数组即可。
 */


class Solution {
    public:
        int deleteAndEarn(vector<int>& nums) {
            const size_t len = 10000;
            std::vector<int> dp(len + 1, 0);
            for (const auto num : nums) {
                assert(num <= len);
                dp[num] += num;
            }
            for (size_t i = 2; i <= len; ++i) {
                dp[i] = std::max(dp[i - 1], dp[i - 2] + dp[i]);
            }
            return dp[len];
        }
};
