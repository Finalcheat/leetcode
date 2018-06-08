/**
 * @file Minimum-Moves-to-Equal-Array-Elements-II.cpp
 * @brief 最小移动次数使数组相等II(https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii)
 * @author Finalcheat
 * @date 2017-03-09
 */

/**
 * Given a non-empty integer array, find the minimum number of moves required to make all array elements equal, where a move is incrementing a selected element by 1 or decrementing a selected element by 1.
 * You may assume the array's length is at most 10,000.
 * Example:
 * Input:
 * [1,2,3]
 * Output:
 * 2
 * Explanation:
 * Only two moves are needed (remember each move increments or decrements one element):
 * [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
 */

/**
 * 和I类似，想办法得到最终数组相等的值然后遍历求差即可，最终的值是数组排序后中间元素的值。
 */

class Solution {
    public:
        int minMoves2(vector<int>& nums) {
            if (nums.empty()) {
                return 0;
            }
            std::sort(nums.begin(), nums.end());
            int mid = nums[nums.size() / 2];
            int count = 0;
            for (size_t i = 0; i < nums.size(); ++i) {
                count += abs(mid - nums[i]);
            }
            return count;
        }
};
