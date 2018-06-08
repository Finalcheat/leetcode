/**
 * @file Increasing-Triplet-Subsequence.cpp
 * @brief 递增的三元子序列(https://leetcode.com/problems/increasing-triplet-subsequence/) 
 * @author Finalcheat
 * @date 2016-05-19
 */

/**
 * Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
 * Formally the function should:
 * Return true if there exists i, j, k 
 * such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
 * Your algorithm should run in O(n) time complexity and O(1) space complexity.
 * Examples:
 * Given [1, 2, 3, 4, 5],
 * return true.
 * Given [5, 4, 3, 2, 1],
 * return false.
 */

/**
 * 遍历的同时记录最小元素和第二小元素，发现比这两者小的就更新，否则就是发现子序列。
 */

class Solution {
    public:
        bool increasingTriplet(vector<int>& nums) {
            if (nums.size() < 3) {
                return false;
            }
            int minimum = INT_MAX;
            int secondMinimum = minimum;
            for (size_t i = 0; i < nums.size(); ++i) {
                const int value = nums[i];
                if (value <= minimum) {
                    minimum = value;
                } else if (value <= secondMinimum) {
                    secondMinimum = value;
                } else {
                    return true;
                }
            }
            return false;
        }
};
