/**
 * @file Jump-Game.cpp
 * @brief 跳跃游戏(https://leetcode.com/problems/jump-game/) 
 * @author Finalcheat
 * @date 2016-05-20
 */

/**
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Determine if you are able to reach the last index.
 * For example:
 * A = [2,3,1,1,4], return true.
 * A = [3,2,1,0,4], return false.
 */

/**
 * 用一个变量维护能跳到的最远距离，最后判断最远距离是否在数组范围内即可。
 */

class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int maxJump = 0;
            for (size_t i = 0; i < nums.size() && i <= maxJump; ++i) {
                int value = nums[i] + i;
                if (value > maxJump) {
                    maxJump = value;
                }
            }
            return maxJump >= nums.size() - 1;
        }
};
