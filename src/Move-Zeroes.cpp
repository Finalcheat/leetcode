/**
 * @file Move-Zeroes.cpp
 * @brief 将0移动到数组后面(https://leetcode.com/problems/move-zeroes/) 
 * @author Finalcheat
 * @date 2016-03-07
 */

/**
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 * For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
 * Note:
 *  1. You must do this in-place without making a copy of the array.
 *  2. Minimize the total number of operations.
 */

/**
 * 将0移动到后面，也就是把非0值移动到前面，然后后面全部填0即可。
 */
class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            size_t zeroNum = 0;
            for (size_t i = 0; i < nums.size(); ++i) {
                if (nums[i] != 0) {
                    nums[zeroNum++] = nums[i];
                }
            }
            while (zeroNum < nums.size()) {
                nums[zeroNum++] = 0;
            }
        }
};
