/**
 * @file 3Sum-Closest.cpp
 * @brief 最接近的三数之和(https://leetcode.com/problems/3sum-closest/description/)
 * @author Finalcheat
 * @date 2018-10-06
 */

/**
 * Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
 * Example:
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

/**
 * 先排序，然后遍历元素时(第一个数)设定双指针首尾扫描确定第二个数和第三个数，求和与target比较。
 */


class Solution {
    public:
        int threeSumClosest(vector<int>& nums, int target) {
            std::sort(nums.begin(), nums.end());
            int minimum = INT_MAX;
            int result = 0;
            for (size_t i = 0; i < nums.size(); ++i) {
                int cur = nums[i];
                size_t first = i + 1;
                size_t last = nums.size() - 1;
                while (first < last) {
                    int curTarget = cur + nums[first] + nums[last];
                    if (curTarget < target) {
                        ++first;
                    } else {
                        --last;
                    }
                    const int distance = std::abs(curTarget - target);
                    if (distance < minimum) {
                        minimum = distance;
                        result = curTarget;
                    }
                }
            }
            return result;
        }
};
