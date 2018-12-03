/**
 * @file Sort-Array-By-Parity.cpp
 * @brief 按奇偶排列数组(https://leetcode.com/problems/sort-array-by-parity/description/)
 * @author Finalcheat
 * @date 2018-11-03
 */

/**
 * Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.
 * You may return any answer array that satisfies this condition.
 * Example 1:
 * Input: [3,1,2,4]
 * Output: [2,4,3,1]
 * The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 */

/**
 * 双指针前后遍历交换即可。
 */


class Solution {
    public:
        vector<int> sortArrayByParity(vector<int>& A) {
            int first = 0;
            int last = A.size() - 1;
            while (first < last) {
                while (first < last && (A[first] % 2 == 0)) {
                    ++first;
                }
                while (first < last && (A[last] % 2 == 1)) {
                    --last;
                }
                if (first < last) {
                    std::swap(A[first], A[last]);
                }
            }
            return A;
        }
};
