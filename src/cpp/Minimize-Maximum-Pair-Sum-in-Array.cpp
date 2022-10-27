/**
 * @file Minimize-Maximum-Pair-Sum-in-Array.cpp
 * @brief 最小化数组中的最大对和(https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/)
 * @author Finalcheat
 * @date 2022-10-27
 */

/**
 * The pair sum of a pair (a,b) is equal to a + b. The maximum pair sum is the largest pair sum in a list of pairs.
 * * For example, if we have pairs (1,5), (2,3), and (4,4), the maximum pair sum would be max(1+5, 2+3, 4+4) = max(6, 5, 8) = 8.
 * Given an array nums of even length n, pair up the elements of nums into n / 2 pairs such that:
 * * Each element of nums is in exactly one pair, and
 * * The maximum pair sum is minimized.
 * Return the minimized maximum pair sum after optimally pairing up the elements.
 * Example 1:
 * Input: nums = [3,5,2,3]
 * Output: 7
 * Explanation: The elements can be paired up into pairs (3,3) and (5,2).
 * The maximum pair sum is max(3+3, 5+2) = max(6, 7) = 7.
 * Example 2:
 * Input: nums = [3,5,4,2,4,6]
 * Output: 8
 * Explanation: The elements can be paired up into pairs (3,5), (4,4), and (6,2).
 * The maximum pair sum is max(3+5, 4+4, 6+2) = max(8, 8, 8) = 8.
 */

/**
 * 首先排序，首尾组成pair，最后取max即可。
 */

class Solution {
public:
  int minPairSum(vector<int>& nums) {
    assert(nums.size() % 2 == 0);
    std::sort(nums.begin(), nums.end());
    std::vector<int> pairSum(nums.size() / 2);
    for (size_t i = 0; i < pairSum.size(); ++i) {
      pairSum[i] = nums[i] + nums[nums.size() - i - 1];
    }
    return *std::max_element(pairSum.begin(), pairSum.end());
  }
};
