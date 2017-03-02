/**
 * @file Minimum-Moves-to-Equal-Array-Elements.cpp
 * @brief 最小移动次数使数组相等(https://leetcode.com/problems/minimum-moves-to-equal-array-elements)
 * @author Finalcheat
 * @date 2017-03-02
 */

/**
 * Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.
 * Example:
 * Input:
 * [1,2,3]
 * Output:
 * 3
 * Explanation:
 * Only three moves are needed (remember each move increments two elements):
 * [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
 */

/**
 * 将n-1个元素加1，可以换个思路相等于将最大元素减1，最终减到最小那个元素的值。
 */

class Solution {
    public:
        int minMoves(vector<int>& nums) {
            int minNum = *std::min_element(nums.begin(), nums.end());
            int result = 0;
            for (size_t i = 0; i < nums.size(); ++i) {
                result += nums[i] - minNum;
            }
            return result;
        }
};
