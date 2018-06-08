/**
 * @file Find-All-Numbers-Disappeared-in-an-Array.cpp
 * @brief 寻找在数组中所有丢失的数字(https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array)
 * @author Finalcheat
 * @date 2017-02-25
 */

/**
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 * Find all the elements of [1, n] inclusive that do not appear in this array.
 * Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
 * Example:
 * Input:
 * [4,3,2,7,8,2,3,1]
 * Output:
 * [5,6]
 */

/**
 * 将数组中出现的数字索引位置数值取反成为负数，最终数组中正数的位置就是所求的值。
 */


class Solution {
    public:
        vector<int> findDisappearedNumbers(vector<int>& nums) {
            for (size_t i = 0; i < nums.size(); ++i) {
                const int m = abs(nums[i]) - 1;
                if (nums[m] > 0) {
                    nums[m] = -nums[m];
                }
            }
            vector<int> result;
            for (size_t i = 0; i < nums.size(); ++i) {
                if (nums[i] > 0) {
                    result.push_back(i + 1);
                }
            }
            return result;
        }
};
