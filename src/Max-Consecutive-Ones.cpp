/**
 * @file Max-Consecutive-Ones.cpp
 * @brief 1连续出现的最大次数(https://leetcode.com/problems/next-greater-element-i/)
 * @author Finalcheat
 * @date 2017-02-23
 */

/**
 * Given a binary array, find the maximum number of consecutive 1s in this array.
 * Example 1:
 * Input: [1,1,0,1,1,1]
 * Output: 3
 * Explanation: The first two digits or the last three digits are consecutive 1s.
 * The maximum number of consecutive 1s is 3.
 * Note:
 * The input array will only contain 0 and 1.
 * The length of input array is a positive integer and will not exceed 10,000
 */

/**
 * 遍历过程中记录当前1连续出现的次数，然后与最大出现次数相比，若大于则更新最大出现次数。
 */

class Solution {
    public:
        int findMaxConsecutiveOnes(vector<int>& nums) {
            int currentConsecutive = 0;
            int maxConsecutive = 0;
            for (size_t i = 0; i < nums.size(); ++i) {
                if (nums[i] == 1) {
                    ++currentConsecutive;
                } else {
                    currentConsecutive = 0;
                }
                if (currentConsecutive > maxConsecutive) {
                    maxConsecutive = currentConsecutive;
                }
            }
            return maxConsecutive;
        }
};
