/**
 * @file Repeated-String-Match.cpp
 * @brief 重复字符串匹配(https://leetcode.com/problems/repeated-string-match/description/)
 * @author Finalcheat
 * @date 2018-06-06
 */

/**
 * Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.
 * For example, with A = "abcd" and B = "cdabcdab".
 * Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").
 * Note:
 * The length of A and B will be between 1 and 10000.
 */

/**
 * 将A不断重复填充到B的长度为止，然后判断B是否是A的子串，如果不是，要注意A的长度刚好跟B相等错开的情况，再重复一次即可。
 */


class Solution {
    public:
        int repeatedStringMatch(string A, string B) {
            assert(A.size() > 0);
            assert(B.size() > 0);
            string aa = A;
            int count = 1;
            while (aa.size() < B.size()) {
                aa += A;
                ++count;
            }
            if (aa.find(B) != string::npos) {
                return count;
            }
            aa += A;
            ++count;
            if (aa.find(B) != string::npos) {
                return count;
            }
            return -1;
        }
};
