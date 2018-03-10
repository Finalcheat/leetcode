/**
 * @file Maximum-Product-of-Three-Numbers.cpp
 * @brief 三个数最大的乘积(https://leetcode.com/problems/maximum-product-of-three-numbers/description/)
 * @author Finalcheat
 * @date 2018-03-10
 */

/**
 * Given an integer array, find three numbers whose product is maximum and output the maximum product.
 * Example 1:
 * Input: [1,2,3]
 * Output: 6
 * Example 2:
 * Input: [1,2,3,4]
 * Output: 24
 */

/**
 * 排序，结果是最大的三个数相乘与最大的数与最小的两个数相乘（最小的两个数是负数）中大的乘积。
 */


class Solution {
    public:
        int maximumProduct(vector<int>& nums) {
            assert(nums.size() >= 3);
            std::sort(nums.begin(), nums.end(), std::greater<int>());
            const int num1 = nums[0] * nums[1] * nums[2];
            const int num2 = nums[0] * (nums[nums.size() - 1] * nums[nums.size() - 2]);
            const int maxNum = std::max(num1, num2);
            return maxNum;
        }
};
