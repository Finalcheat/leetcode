/**
 * @file Buddy-Strings.cpp
 * @brief 亲密字符串(https://leetcode.com/problems/buddy-strings/description/)
 * @author Finalcheat
 * @date 2018-09-05
 */

/**
 * Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.
 * Example 1:
 * Input: A = "ab", B = "ba"
 * Output: true
 * Example 2:
 * Input: A = "ab", B = "ab"
 * Output: false
 * Example 3:
 * Input: A = "aa", B = "aa"
 * Output: true
 * Example 4:
 * Input: A = "aaaaaaabc", B = "aaaaaaacb"
 * Output: true
 * Example 5:
 * Input: A = "", B = "aa"
 * Output: false
 */

/**
 * 长度不同的字符串直接返回false，遍历过程尝试交换某个不相同的字符并且记录字符出现次数，相等的字符串并且某个字符出现次数大于等于2为true。
 */


class Solution {
    public:
        bool buddyStrings(string A, string B) {
            if (A.size() != B.size()) {
                return false;
            }
            std::unordered_map<char, size_t> u;
            size_t maximum = 0;
            int idx = -1;
            for (int i = 0; i < A.size(); ++i) {
                const char ca = A[i];
                const char cb = B[i];
                if (ca != cb) {
                    if (idx < 0) {
                        idx = i;
                    } else if (idx < A.size()) {
                        if (A[idx] != cb || B[idx] != ca) {
                            return false;
                        }
                        idx = A.size();
                    } else {
                        return false;
                    }
                }
                size_t count = ++u[ca];
                if (count > maximum) {
                    maximum = count;
                }
            }
            if (idx < 0) {
                return maximum > 1;
            } else if (idx < A.size()) {
                return false;
            }
            return true;
        }
};
