/**
 * @file Longest-Continuous-Increasing-Subsequence.cpp
 * @brief 最长递增子序列(https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/)
 * @author Finalcheat
 * @date 2018-03-10
 */

/**
 * Given an unsorted array of integers, find the length of longest continuous increasing subsequence (subarray).
 * Example 1:
 * Input: [1,3,5,4,7]
 * Output: 3
 * Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3.
 * Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4.
 * Example 2:
 * Input: [2,2,2,2,2]
 * Output: 1
 * Explanation: The longest continuous increasing subsequence is [2], its length is 1.
 */

/**
 * 递增序列很容易判断，判断当前数比上一个数大即可。同时维护一个当前递增序列长度与最大递增序列长度即可解决问题。
 */


class Solution {
    public:
        int findLengthOfLCIS(vector<int>& nums) {
            if (nums.empty()) {
                return 0;
            }
            int longest = 1;
            int curLongest = 1;
            int lastNum = nums[0];
            for (size_t i = 1; i < nums.size(); ++i) {
                if (lastNum < nums[i]) {
                    ++curLongest;
                } else {
                    curLongest = 1;
                }
                if (curLongest > longest) {
                    longest = curLongest;
                }
                lastNum = nums[i];
            }
            return longest;
        }
};
