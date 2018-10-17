/**
 * @file Array-Nesting.cpp
 * @brief 组合(https://leetcode.com/problems/array-nesting/description/)
 * @author Finalcheat
 * @date 2018-10-12
 */

/**
 * A zero-indexed array A of length N contains all integers from 0 to N-1. Find and return the longest length of set S, where S[i] = {A[i], A[A[i]], A[A[A[i]]], ... } subjected to the rule below.
 * Suppose the first element in S starts with the selection of element A[i] of index = i, the next element in S should be A[A[i]], and then A[A[A[i]]]… By that analogy, we stop adding right before a duplicate element occurs in S.
 * Example 1:
 * Input: A = [5,4,0,3,1,6,2]
 * Output: 4
 * Explanation:
 * A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.
 * One of the longest S[K]:
 * S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
 */

/**
 * 遍历过程中dfs搜索，对于访问过的元素在vistied中标记。
 */


class Solution {
    public:
        int arrayNesting(vector<int>& nums) {
            vector<int> visited(nums.size(), 0);
            int maximum = 0;
            for (int i = 0; i < nums.size(); ++i) {
                int count = 0;
                int idx = i;
                while (visited[idx] == 0) {
                    ++count;
                    visited[idx] = 1;
                    idx = nums[idx];
                }
                if (count > maximum) {
                    maximum = count;
                }
            }
            return maximum;
        }
};
