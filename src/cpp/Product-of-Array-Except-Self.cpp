/**
 * @file Product-of-Array-Except-Self.cpp
 * @brief 除自身外数组之积(https://leetcode.com/problems/product-of-array-except-self/description/)
 * @author Finalcheat
 * @date 2018-08-05
 */

/**
 * Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
 * Example:
 * Input:  [1,2,3,4]
 * Output: [24,12,8,6]
 * Note: Please solve it without division and in O(n).
 */

/**
 * 很无聊的一道题目，要求不用除法。。。
 * 用dp1[i]、dp2[i]分别表示第i个位置前、后的积，最终结果就是dp1[i] * dp2[i]。
 */


class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            const size_t len = nums.size();
            vector<int> dp1(len);
            vector<int> dp2(len);
            int cur = 1;
            for (size_t i = 0; i < len; ++i) {
                dp1[i] = cur;
                cur *= nums[i];
            }
            cur = 1;
            for (int i = len - 1; i >= 0; --i) {
                dp2[i] = cur;
                cur *= nums[i];
            }
            vector<int> result(len);
            for (size_t i = 0; i < len; ++i) {
                result[i] = dp1[i] * dp2[i];
            }
            return result;
        }
};
