/**
 * @file Find-All-Duplicates-in-an-Array.cpp
 * @brief 寻找数组中重复的数字(https://leetcode.com/problems/find-all-duplicates-in-an-array)
 * @author Finalcheat
 * @date 2017-02-27
 */

/**
 * Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 * Find all the elements that appear twice in this array.
 * Could you do it without extra space and in O(n) runtime?
 * Example:
 * Input:
 * [4,3,2,7,8,2,3,1]
 * Output:
 * [2,3]
 */

/**
 * 遍历过程中将数组中出现的数字索引位置数值取反成为负数，第二次判断为负数的时候说明该数字出现两次，直接添加到结果即可。
 */

class Solution {
    public:
        vector<int> findDuplicates(vector<int>& nums) {
            vector<int> result;
            for (size_t i = 0; i < nums.size(); ++i) {
                const int m = abs(nums[i]) - 1;
                if (nums[m] > 0) {
                    nums[m] = -nums[m];
                } else {
                    result.push_back(m + 1);
                }
            }
            return result;
        }
};
