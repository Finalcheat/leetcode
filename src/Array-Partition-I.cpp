/**
 * @file Array-Partition-I.cpp
 * @brief 数组分割I(https://leetcode.com/problems/array-partition-i/)
 * @author Finalcheat
 * @date 2017-05-08
 */

/**
 * Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.
 * Example 1:
 * Input: [1,4,3,2]
 * Output: 4
 * Explanation: n is 2, and the maximum sum of pairs is 4.
 */

/**
 * 排序后以两个数为一组取最小值累加即可。
 */

class Solution {
    public:
        int arrayPairSum(vector<int>& nums) {
            std::sort(nums.begin(), nums.end());
            int sum = 0;
            for (size_t i = 0; i < nums.size(); i += 2)
            {
                sum += std::min(nums[i], nums[i + 1]);
            }
            return sum;
        }
};
