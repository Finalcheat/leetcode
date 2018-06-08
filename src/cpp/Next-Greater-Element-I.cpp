/**
 * @file Next-Greater-Element-I.cpp
 * @brief 下一个大的元素(https://leetcode.com/problems/next-greater-element-i/)
 * @author Finalcheat
 * @date 2017-02-16
 */

/**
 * Given two strings s and t which consist of only lowercase letters.
 * You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.
 * The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.
 * Example 1:
 * Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
 * Output: [-1,3,-1]
 * Explanation:
 * For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
 * For number 1 in the first array, the next greater number for it in the second array is 3.
 * For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
 * Example 2:
 * Input: nums1 = [2,4], nums2 = [1,2,3,4].
 * Output: [3,-1]
 * Explanation:
 * For number 2 in the first array, the next greater number for it in the second array is 3.
 * For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
 */

/**
 * 使用栈存储遍历中的元素，然后下一元素与栈顶元素相比较，大于则用map对应存储起来。
 */

class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
            stack<int> s;
            unordered_map<int, int> u;
            for (size_t i = 0; i < nums.size(); ++i) {
                int n = nums[i];
                while (s.size() && s.top() < n) {
                    u[s.top()] = n;
                    s.pop();
                }
                s.push(n);
            }
            vector<int> result(findNums.size());
            for (size_t i = 0; i < findNums.size(); ++i) {
                if (u.find(findNums[i]) != u.end()) {
                    result[i] = u[findNums[i]];
                } else {
                    result[i] = -1;
                }
            }
            return result;
        }
};
