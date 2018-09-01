/**
 * @file Binary-Search.cpp
 * @brief 二分搜索(https://leetcode.com/problems/binary-search/description/)
 * @author Finalcheat
 * @date 2018-08-13
 */

/**
 * Given a sorted (in ascending order) integer array nums of n elements and a target value, write a function to search target in nums. If target exists, then return its index, otherwise return -1.
 * Example 1:
 * Input: nums = [-1,0,3,5,9,12], target = 9
 * Output: 4
 * Explanation: 9 exists in nums and its index is 4
 * Example 2:
 * Input: nums = [-1,0,3,5,9,12], target = 2
 * Output: -1
 * Explanation: 2 does not exist in nums so return -1
 */

/**
 * 标准二分搜索实现即可。
 */


class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int first = 0;
            int last = nums.size() - 1;
            while (first <= last) {
                int middle = first + (last - first) / 2;
                if (nums[middle] == target) {
                    return middle;
                } else if (nums[middle] < target) {
                    first = middle + 1;
                } else {
                    last = middle - 1;
                }
            }
            return -1;
        }
};
