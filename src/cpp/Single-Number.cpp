/**
 * @file Single-Number.cpp
 * @brief 找出数组中出现一次的数字(https://leetcode.com/problems/single-number/)
 * @author Finalcheat
 * @date 2016-03-06
 */


/**
 * Given an array of integers, every element appears twice except for one. Find that single one.
 *
 */

/**
 * 利用两个相同的数做异或操作为0，0跟任意数异或得到其本身的特点解决此题。
 */ 
class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int result = 0;
            for (size_t i = 0; i < nums.size(); ++i) {
                result ^= nums[i];
            }
            return result;
        }
};
