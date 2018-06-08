/**
 * @file Third-Maximum-Number.cpp
 * @brief 第三大的数字(https://leetcode.com/problems/third-maximum-number/)
 * @author Finalcheat
 * @date 2017-03-12
 */

/**
 * Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).
 * Example 1:
 * Input: [3, 2, 1]
 * Output: 1
 * Explanation: The third maximum is 1.
 * Example 2:
 * Input: [1, 2]
 * Output: 2
 * Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
 * Example 3:
 * Input: [2, 2, 3, 1]
 * Output: 1
 * Explanation: Note that the third maximum here means the third maximum distinct number.
 * Both numbers with value 2 are both considered as second maximum.
 */

/**
 * 遍历过程中不断调整前三大的数字即可，题目不算难，但是一些边界条件需要注意，比如输入数字中存在INT_MIN的情况。
 */

class Solution {
    public:
        int thirdMax(vector<int>& nums) {
            int first = INT_MIN;
            int second = INT_MIN;
            int third = INT_MIN;
            std::set<int> s;
            for (size_t i = 0; i < nums.size(); ++i) {
                if (s.size() < 3) {
                    s.insert(nums[i]);
                }
                if (nums[i] > first) {
                    third = second;
                    second = first;
                    first = nums[i];
                } else if (nums[i] > second && nums[i] != first) {
                    third = second;
                    second = nums[i];
                } else if (nums[i] > third && nums[i] != second && nums[i] != first) {
                    third = nums[i];
                }
            }
            if (s.size() < 3) {
                third = first;
            }
            return third;
        }
};
