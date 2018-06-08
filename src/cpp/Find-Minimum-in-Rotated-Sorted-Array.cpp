/**
 * @file Find-Minimum-in-Rotated-Sorted-Array.cpp
 * @brief 在旋转已排序的数组中搜索最小元素(https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)
 * @author Finalcheat
 * @date 2016-03-25
 */

/**
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * Find the minimum element.
 * You may assume no duplicate exists in the array.
 */

/**
 * 二分搜索搞定
 */

class Solution {
    public:
        int findMin(vector<int>& nums) {
            int left = 0;
            int right = nums.size() - 1;
            while (nums[left] > nums[right]) {
                const int middle = (left + right) / 2;
                if (nums[middle] >= nums[left] && nums[middle] >nums[right]) {
                    left = middle + 1;
                } else {
                    right = middle;
                }
            }
            return nums[left];
        }
};
