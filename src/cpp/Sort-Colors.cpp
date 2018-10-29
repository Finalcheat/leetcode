/**
 * @file Sort-Colors.cpp
 * @brief 颜色分类(https://leetcode.com/problems/sort-colors/description/)
 * @author Finalcheat
 * @date 2018-10-16
 */

/**
 * Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 * Note: You are not suppose to use the library's sort function for this problem.
 * Example:
 * Input: [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 */

/**
 * 记录0，1，2的数量，然后按数量填上去就行了。
 */


class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int zeroCount = 0;
            int oneCount = 0;
            for (const int num : nums) {
                if (num == 0) {
                    ++zeroCount;
                } else if (num == 1) {
                    ++oneCount;
                }
            }
            int twoCount = nums.size() - zeroCount - oneCount;
            for (int i = 0; i < zeroCount; ++i) {
                nums[i] = 0;
            }
            for (int i = 0; i < oneCount; ++i) {
                nums[zeroCount + i] = 1;
            }
            for (int i = nums.size() - twoCount; i < nums.size(); ++i) {
                nums[i] = 2;
            }
        }
};
