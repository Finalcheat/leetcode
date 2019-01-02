/**
 * @file DI-String-Match.cpp
 * @brief 增减字符串匹配(https://leetcode.com/problems/di-string-match/description/)
 * @author Finalcheat
 * @date 2018-11-29
 */

/**
 * Given a string S that only contains "I" (increase) or "D" (decrease), let N = S.length.
 * Return any permutation A of [0, 1, ..., N] such that for all i = 0, ..., N-1:
 * If S[i] == "I", then A[i] < A[i+1]
 * If S[i] == "D", then A[i] > A[i+1]
 * Example 1:
 * Input: "IDID"
 * Output: [0,4,1,3,2]
 * Example 2:
 * Input: "III"
 * Output: [0,1,2,3]
 * Example 3:
 * Input: "DDI"
 * Output: [3,2,0,1]
 */

/**
 * 按照规则遍历设置值即可。
 */


class Solution {
    public:
        vector<int> diStringMatch(string S) {
            assert(S.size() > 0);
            int minimum = 0;
            int maximum = S.size();
            vector<int> result(maximum + 1);
            size_t idx = 0;
            for (const char c : S) {
                if (c == 'I') {
                    result[idx] = minimum;
                    ++minimum;
                } else {
                    result[idx] = maximum;
                    --maximum;
                }
                ++idx;
            }
            if (S[S.size() - 1] == 'I') {
                result[idx] = minimum;
            } else {
                result[idx] = maximum;
            }
            return result;
        }
};
