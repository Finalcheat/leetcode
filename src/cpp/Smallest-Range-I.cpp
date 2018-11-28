/**
 * @file Smallest-Range-I.cpp
 * @brief 最小差值I(https://leetcode.com/problems/smallest-range-i/description/)
 * @author Finalcheat
 * @date 2018-11-26
 */

/**
 * Given an array A of integers, for each integer A[i] we may choose any x with -K <= x <= K, and add x to A[i].
 * After this process, we have some array B.
 * Return the smallest possible difference between the maximum value of B and the minimum value of B.
 * Example 1:
 * Input: A = [1], K = 0
 * Output: 0
 * Explanation: B = [1]
 * Example 2:
 * Input: A = [0,10], K = 2
 * Output: 6
 * Explanation: B = [2,8]
 * Example 3:
 * Input: A = [1,3,6], K = 3
 * Output: 0
 * Explanation: B = [3,3,3] or B = [4,4,4]
 */

/**
 * 题目不难，只是题意难理解，找到最大最小值差值与k的两倍对比即可。
 */


class Solution {
    public:
        int smallestRangeI(vector<int>& A, int K) {
            assert(A.size() > 0);
            int maximum = A[0];
            int minimum = A[0];
            for (size_t i = 1; i < A.size(); ++i) {
                const int num = A[i];
                if (num > maximum) {
                    maximum = num;
                }
                if (num < minimum) {
                    minimum = num;
                }
            }
            const int diff = maximum - minimum;
            const int k2 = std::abs(K * 2);
            if (k2 >= diff) {
                return 0;
            }
            return diff - k2;
        }
};
