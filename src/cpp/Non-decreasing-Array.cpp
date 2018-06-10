/**
 * @file Non-decreasing-Array.cpp
 * @brief 非递减数组(https://leetcode.com/problems/non-decreasing-array/description/)
 * @author Finalcheat
 * @date 2018-06-10
 */

/**
 * Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.
 * We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).
 * Example 1:
 * Input: [4,2,3]
 * Output: True
 * Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
 * Example 2:
 * Input: [4,2,1]
 * Output: False
 * Explanation: You can't get a non-decreasing array by modify at most one element.
 * Note: The n belongs to [1, 10,000].
 */

/**
 * 这道题比较容易出错，在遍历过程中找到要修改的值后将标记设为true，往后再搜索发现不符合非递减则返回false，否则最终返回true。
 */


class Solution {
    public:
        bool checkPossibility(vector<int>& nums) {
            if (nums.empty()) {
                return true;
            }
            bool modify = false;
            int prev = nums[0];
            int max = prev;
            for (size_t i = 1; i < nums.size(); ++i) {
                int cur = nums[i];
                if (prev > cur) {
                    if (!modify) {
                        int prevMin = std::min(max, prev);
                        if (i == 1 || prevMin < cur) {
                            prev = cur;
                        }
                        modify = true;
                        continue;
                    } else {
                        return false;
                    }
                } else {
                    prev = cur;
                }
                if (!modify && nums[i - 1] > max) {
                    max = nums[i - 1];
                }
            }
            return true;
        }
};
