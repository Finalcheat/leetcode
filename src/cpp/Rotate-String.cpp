/**
 * @file Rotate-String.cpp
 * @brief 旋转字符串(https://leetcode.com/problems/rotate-string/description/)
 * @author Finalcheat
 * @date 2018-03-11
 */

/**
 * We are given two strings, A and B.
 * A shift on A consists of taking string A and moving the leftmost character to the rightmost position. For example, if A = 'abcde', then it will be 'bcdea' after one shift on A. Return True if and only if A can become B after some number of shifts on A.
 * Example 1:
 * Input: A = 'abcde', B = 'cdeab'
 * Output: true
 * Example 2:
 * Input: A = 'abcde', B = 'abced'
 * Output: false
 */

/**
 * 找到B首字符在A中出现的所有位置，遍历所有位置比较即可。
 */


class Solution {
    public:
        bool rotateString(string A, string B) {
            assert(A.size() == B.size());
            if (B.empty()) {
                return true;
            }
            const char bFirstChar = B[0];
            vector<size_t> idxs;
            for (size_t i = 0; i < A.size(); ++i) {
                if (A[i] == bFirstChar) {
                    idxs.push_back(i);
                }
            }
            for (size_t i = 0; i < idxs.size(); ++i) {
                const size_t idx = idxs[i];
                bool find = true;
                for (size_t j = 1; j < B.size(); ++j) {
                    const size_t aIdx = (idx + j) % A.size();
                    if (A[aIdx] != B[j]) {
                        find = false;
                        break;
                    }
                }
                if (find) {
                    return true;
                }
            }
            return false;
        }
};
