/**
 * @file First-Missing-Positive.cpp
 * @brief 第一个丢失的正数(https://leetcode.com/problems/first-missing-positive/)
 * @author Finalcheat
 * @date 2017-04-10
 */

/**
 * Given an unsorted integer array, find the first missing positive integer.
 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.
 * Your algorithm should run in O(n) time and uses constant space.
 */

/**
 * 难点在于O(n)时间以及常数空间，可以考虑在原数组做修改标记，将小于等于n(数组长度)的数字移动到对应的下标位置，最后遍历只要值不等于下标的就是所求。
 */

class Solution {
    public:
        int firstMissingPositive(vector<int>& nums) {
            for (size_t i = 0; i < nums.size(); ++i) {
                while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i]) {
                    std::swap(nums[i], nums[nums[i] - 1]);
                }
            }

            for (size_t i = 0; i < nums.size(); ++i) {
                if (nums[i] != i + 1) {
                    return i + 1;
                }
            }

            return nums.size() + 1;
        }
};
