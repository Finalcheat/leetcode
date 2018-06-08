/**
 * @file Single-Element-in-a-Sorted-Array.cpp
 * @brief 有序数组的单一元素(https://leetcode.com/problems/single-element-in-a-sorted-array/description/)
 * @author Finalcheat
 * @date 2018-03-18
 */

/**
 * Given a sorted array consisting of only integers where every element appears twice except for one element which appears once. Find this single element that appears only once.
 * Example 1:
 * Input: [1,1,2,3,3,4,4,8,8]
 * Output: 2
 * Example 2:
 * Input: [3,3,7,7,10,11,11]
 * Output: 10
 * Note: Your solution should run in O(log n) time and O(1) space.
 */

/**
 * 最简单的做法是遍历，但题目要求O(log n)时间复杂度，自然想到二分查找，题目中所求的单一元素必然出现在偶数下标位置中，对比前后元素，如果都不同则是所求，否则继续二分找。
 */


class Solution {
    public:
        int singleNonDuplicate(vector<int>& nums) {
            assert(nums.size() >= 3);
            assert(nums.size() % 2 != 0);
            if (nums[0] != nums[1]) {
                return nums[0];
            }
            const size_t size = nums.size();
            if (nums[size - 1] != nums[size - 2]) {
                return nums[size - 1];
            }
            int begin = 0;
            int end = size - 1;
            while (begin < end) {
                int cursor = begin + (end - begin) / 2;
                if (cursor % 2 != 0) {
                    ++cursor;
                }
                if (nums[cursor] == nums[cursor - 1]) {
                    end = cursor;
                    continue;
                } else if (nums[cursor] == nums[cursor + 1]) {
                    begin = cursor;
                    continue;
                }
                return nums[cursor];
            }
            return -1;
        }
};
