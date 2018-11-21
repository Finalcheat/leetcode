/**
 * @file Next-Greater-Element-II.cpp
 * @brief 下一个更大元素II(https://leetcode.com/problems/next-greater-element-ii/description/)
 * @author Finalcheat
 * @date 2018-10-30
 */

/**
 * Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.
 * Example 1:
 * Input: [1,2,1]
 * Output: [2,-1,2]
 * Explanation: The first 1's next greater number is 2;
 * The number 2 can't find next greater number;
 * The second 1's next greater number needs to search circularly, which is also 2.
 */

/**
 * 遍历数组*2，使用栈作为辅助结构即可。
 */


class Solution {
    public:
        vector<int> nextGreaterElements(vector<int>& nums) {
            vector<int> result(nums.size(), -1);
            std::stack<int> s;
            for (int i = 0; i < nums.size() * 2; ++i) {
                const int idx = i % nums.size();
                const int num = nums[idx];
                while (!s.empty() && nums[s.top()] < num) {
                    result[s.top()] = num;
                    s.pop();
                }
                if (i < nums.size()) {
                    s.push(i);
                }
            }
            return result;
        }
};
