/**
 * @file Largest-Number-At-Least-Twice-of-Others.cpp
 * @brief 最大的数至少是其他数字的两倍(https://leetcode.com/problems/largest-number-at-least-twice-of-others/description/)
 * @author Finalcheat
 * @date 2018-01-08
 */

/**
 * In a given integer array nums, there is always exactly one largest element.
 * Find whether the largest element in the array is at least twice as much as every other number in the array.
 * If it is, return the index of the largest element, otherwise return -1.
 * Example 1:
 * Input: nums = [3, 6, 1, 0]
 * Output: 1
 * Explanation: 6 is the largest integer, and for every other number in the array x,
 * 6 is more than twice as big as x.  The index of value 6 is 1, so we return 1.
 * Example 2:
 * Input: nums = [1, 2, 3, 4]
 * Output: -1
 * Explanation: 4 isn't at least as big as twice the value of 3, so we return -1.
 * Note:
 * 1. nums will have a length in the range [1, 50].
 * 2. Every nums[i] will be an integer in the range [0, 99].
 */

/**
 * 找到最大数跟第二大数，最后对比即可。
 */


class Solution {
    public:
        int dominantIndex(vector<int>& nums) {
            if (nums.empty()) {
                return -1;
            }
            int max = nums[0];
            int index = 0;
            int second = -1;
            if (nums.size() > 1) {
                second = nums[1];
            }
            if (max < second) {
                int tmp = max;
                max = second;
                second = tmp;
                index = 1;
            }
            for (size_t i = 2; i < nums.size(); ++i) {
                if (nums[i] > max) {
                    second = max;
                    max = nums[i];
                    index = i;
                } else if (second < nums[i]) {
                    second = nums[i];
                }
            }
            if (max >= 2 * second) {
                return index;
            }
            return -1;
        }
};
