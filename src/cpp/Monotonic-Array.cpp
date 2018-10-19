/**
 * @file Monotonic-Array.cpp
 * @brief 非递减数列(https://leetcode.com/problems/monotonic-array/description/)
 * @author Finalcheat
 * @date 2018-10-18
 */

/**
 * An array is monotonic if it is either monotone increasing or monotone decreasing.
 * An array A is monotone increasing if for all i <= j, A[i] <= A[j].  An array A is monotone decreasing if for all i <= j, A[i] >= A[j].
 * Return true if and only if the given array A is monotonic.
 * Example 1:
 * Input: [1,2,2,3]
 * Output: true
 * Example 2:
 * Input: [6,5,4,4]
 * Output: true
 * Example 3:
 * Input: [1,3,2]
 * Output: false
 * Example 4:
 * Input: [1,2,4,5]
 * Output: true
 * Example 5:
 * Input: [1,1,1]
 * Output: true
 */

/**
 * 按照规则遍历即可。
 */


class Solution {
    public:
        bool isMonotonic(vector<int>& A) {
            if (A.size() <= 1) {
                return true;
            }
            size_t idx = 1;
            for (; idx < A.size(); ++idx) {
                if (A[idx - 1] > A[idx]) {
                    idx = 1;
                    break;
                }
            }
            if (idx == A.size()) {
                return true;
            }
            for (; idx < A.size(); ++idx) {
                if (A[idx - 1] < A[idx]) {
                    return false;
                }
            }
            return true;
        }
};
