/**
 * @file Peak-Index-in-a-Mountain-Array.cpp
 * @brief 山脉峰值(https://leetcode.com/problems/peak-index-in-a-mountain-array/description/)
 * @author Finalcheat
 * @date 2018-07-22
 */

/**
 * Let's call an array A a mountain if the following properties hold:
 * A.length >= 3
 * There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
 * Given an array that is definitely a mountain, return any i such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].
 * Example 1:
 * Input: [0,1,0]
 * Output: 1
 * Example 2:
 * Input: [0,2,1,0]
 * Output: 1
 */

/**
 * 最简单的方法，遍历数组，遇到当前值比前一个值小的，则前一个元素为山脉峰值。
 */


class Solution {
    public:
        int peakIndexInMountainArray(vector<int>& A) {
            for (size_t i = 1; i < A.size(); ++i) {
                if (A[i] < A[i - 1]) {
                    return i - 1;
                }
            }
            return -1;
        }
};
