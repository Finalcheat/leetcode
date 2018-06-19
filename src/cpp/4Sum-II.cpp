/**
 * @file 4Sum-II.cpp
 * @brief 四个数之和II(https://leetcode.com/problems/4sum-ii/description/)
 * @author Finalcheat
 * @date 2018-06-19
 */

/**
 * Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.
 * To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.
 * Example:
 * Input:
 * A = [ 1, 2]
 * B = [-2,-1]
 * C = [-1, 2]
 * D = [ 0, 2]
 * Output:
 * 2
 * Explanation:
 * The two tuples are:
 * 1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
 * 2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
 */

/**
 * 最简单无脑的方法，遍历A、B、C、D的所有可能。。。时间复杂度O(n^4)，但这样肯定通不过leetcode的时间要求的
 * 可以用hash table存储D，然后遍历A、B、C的所有可能，然后在D中找到-(A+B+C)，时间复杂度O(n^3)，但这样依旧通不过
 * 还是在hash table上想办法，将A、B所有的和存储到hash table中，最后遍历C、D，然后找-(A+B)值即可，时间复杂度是O(n^2)
 */


class Solution {
    public:
        int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
            std::unordered_map<int, size_t> u;
            for (size_t i = 0; i < A.size(); ++i) {
                for (size_t j = 0; j < B.size(); ++j) {
                    ++u[A[i] + B[j]];
                }
            }

            int count = 0;
            for (size_t i = 0; i < C.size(); ++i) {
                for (size_t j = 0; j < D.size(); ++j) {
                    const int num = 0 - (C[i] + D[j]);
                    auto iter = u.find(num);
                    if (iter != u.end()) {
                        count += iter->second;
                    }
                }
            }

            return count;
        }
};
