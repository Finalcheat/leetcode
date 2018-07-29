/**
 * @file Custom-Sort-String.cpp
 * @brief 自定义排序字符串(https://leetcode.com/problems/custom-sort-string/description/)
 * @author Finalcheat
 * @date 2018-07-25
 */

/**
 * S and T are strings composed of lowercase letters. In S, no letter occurs more than once.
 * S was sorted in some custom order previously. We want to permute the characters of T so that they match the order that S was sorted. More specifically, if x occurs before y in S, then x should occur before y in the returned string.
 * Return any permutation of T (as a string) that satisfies this property.
 * Example :
 * Input:
 * S = "cba"
 * T = "abcd"
 * Output: "cbad"
 * Explanation:
 * "a", "b", "c" appear in S, so the order of "a", "b", "c" should be "c", "b", and "a".
 * Since "d" does not appear in S, it can be at any position in T. "dcba", "cdba", "cbda" are also valid outputs.
 */

/**
 * 用hashmap存储位置，定义cmp函数给std::sort即可。
 */


class Solution {
    public:
        string customSortString(string S, string T) {
            std::unordered_map<char, size_t> u;
            for (size_t i = 0; i < S.size(); ++i) {
                u[S[i]] = i;
            }
            std::sort(T.begin(), T.end(), [&u](const char lc, const char rc) {
                    auto lIter = u.find(lc);
                    auto rIter = u.find(rc);
                    if (lIter == u.end()) {
                        return (rIter != u.end());
                    }
                    if (rIter == u.end()) {
                        return false;
                    }
                    return (lIter->second < rIter->second);
                });
            return T;
        }
};
