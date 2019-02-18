/**
 * @file Delete-Columns-to-Make-Sorted.cpp
 * @brief 删除列以使之有序(https://leetcode.com/problems/delete-columns-to-make-sorted/description/)
 * @author Finalcheat
 * @date 2018-11-28
 */

/**
 * We are given an array A of N lowercase letter strings, all of the same length.
 * Now, we may choose any set of deletion indices, and for each string, we delete all the characters in those indices.  The remaining rows of strings form columns when read north to south.
 * For example, if we have an array A = ["abcdef","uvwxyz"] and deletion indices {0, 2, 3}, then the final array after deletions is ["bef","vyz"], and the remaining columns of A are ["b","v"], ["e","y"], and ["f","z"].  (Formally, the c-th column is [A[0][c], A[1][c], ..., A[A.length-1][c]].)
 * Suppose we chose a set of deletion indices D such that after deletions, each remaining column in A is in non-decreasing sorted order.
 * Return the minimum possible value of D.length.
 * Example 1:
 * Input: ["cba","daf","ghi"]
 * Output: 1
 * Explanation:
 * After choosing D = {1}, each column ["c","d","g"] and ["a","f","i"] are in non-decreasing sorted order.
 * If we chose D = {}, then a column ["b","a","h"] would not be in non-decreasing sorted order.
 * Example 2:
 * Input: ["a","b"]
 * Output: 0
 * Explanation: D = {}
 * Example 3:
 * Input: ["zyx","wvu","tsr"]
 * Output: 3
 * Explanation: D = {0, 1, 2}
 */

/**
 * 题意难理解，对比每个位置的字符是否升序即可。
 */


class Solution {
    public:
        int minDeletionSize(vector<string>& A) {
            assert(A.size() > 0);
            const size_t len = A[0].size();
            int count = 0;
            for (size_t i = 0; i < len; ++i) {
                char c = A[0][i];
                for (size_t j = 1; j < A.size(); ++j) {
                    if (A[j][i] < c) {
                        ++count;
                        break;
                    }
                    c = A[j][i];
                }
            }
            return count;
        }
};
