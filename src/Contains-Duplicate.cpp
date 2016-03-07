/**
 * @file Contains-Duplicate.cpp
 * @brief 验证是否包含重复值(https://leetcode.com/problems/contains-duplicate/)
 * @author Finalcheat
 * @date 2016-03-07
 */

/**
 * Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
 */

/**
 * 对数组排序，排序后相同的值必定连在一起，遍历一遍验证即可。
 */
class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            std::sort(nums.begin(), nums.end());
            for (size_t i = 1; i < nums.size(); ++i) {
                if (nums[i] == nums[i - 1]) {
                    return true;
                }
            }
            return false;
        }
};
