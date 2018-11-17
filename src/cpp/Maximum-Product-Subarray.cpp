/**
 * @file Maximum-Product-Subarray.cpp
 * @brief 乘积最大子序列(https://leetcode.com/problems/maximum-product-subarray/description/)
 * @author Finalcheat
 * @date 2018-09-04
 */

/**
 * Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.
 * Example 1:
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 * Example 2:
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 */

/**
 * 跟最大子序和差不多，要注意的是乘积最大子序列中可能含有负数(负负得正)，所以遍历过程中不仅要维持局部乘积最大值，同时也要维持局部乘积最小值。
 */


class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            assert(nums.size() >= 1);
            int curMaximum = nums[0];
            int curMinimum = curMaximum;
            int maximum = curMaximum;
            for (size_t i = 1; i < nums.size(); ++i) {
                int preMaximum = curMaximum;
                curMaximum = std::max(curMaximum * nums[i], curMinimum * nums[i]);
                curMaximum = std::max(curMaximum, nums[i]);
                curMinimum = std::min(preMaximum * nums[i], curMinimum * nums[i]);
                curMinimum = std::min(curMinimum, nums[i]);
                if (curMaximum > maximum) {
                    maximum = curMaximum;
                }
            }
            return maximum;
        }
};
