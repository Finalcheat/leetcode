/**
 * @file Squares-of-a-Sorted-Array.cpp
 * @brief 排序数组的平方(https://leetcode.com/problems/squares-of-a-sorted-array/)
 * @author Finalcheat
 * @date 2019-01-23
 */

/**
 * Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.
 * Example 1:
 * Input: [-4,-1,0,3,10]
 * Output: [0,1,9,16,100]
 * Example 2:
 * Input: [-7,-3,2,3,11]
 * Output: [4,9,9,49,121]
 */

/**
 * 前后双指针扫描，平方后对比，较大那个写入结果并且指针移动。
 */


class Solution {
    public:
        vector<int> sortedSquares(vector<int>& A) {
            size_t first = 0;
            size_t last = A.size() - 1;
            vector<int> result(A.size());
            size_t idx = last;
            while (first <= last) {
                const int squareFirstValue = A[first] * A[first];
                const int squareLastValue = A[last] * A[last];
                if (squareFirstValue < squareLastValue) {
                    result[idx] = squareLastValue;
                    --idx;
                    --last;
                } else {
                    result[idx] = squareFirstValue;
                    --idx;
                    ++first;
                }
            }
            return result;
        }
};
