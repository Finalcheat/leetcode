/**
 * @file Shortest-Distance-to-a-Character.cpp
 * @brief 字符的最短距离(https://leetcode.com/problems/shortest-distance-to-a-character/)
 * @author Finalcheat
 * @date 2018-05-02
 */

/**
 * Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.
 * Example 1:
 * Input: S = "loveleetcode", C = 'e'
 * Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
 * Note:
 * 1. S string length is in [1, 10000].
 * 2. C is a single character, and guaranteed to be in string S.
 * 3. All letters in S and C are lowercase.
 */

/**
 * 记录C字符出现的所有下标位置，遍历过程中找到比当前位置大的C字符下标位置，同时与前一个位置距离相比较取小值即可。
 */

class Solution {
    public:
        vector<int> shortestToChar(string S, char C) {
            vector<size_t> idxs;
            for (size_t i = 0; i < S.size(); ++i) {
                if (S[i] == C) {
                    idxs.push_back(i);
                }
            }
            vector<int> result;
            size_t prevCIdx = 0;
            for (size_t i = 0; i < S.size(); ++i) {
                if (S[i] == C) {
                    prevCIdx = i;
                    result.push_back(0);
                } else {
                    vector<size_t>::const_iterator iter = std::upper_bound(idxs.begin(), idxs.end(), i);
                    if (iter != idxs.end()) {
                        size_t minDist = (S[prevCIdx] == C) ? std::min(*iter - i, i - prevCIdx) : (*iter - i);
                        result.push_back(minDist);
                    } else {
                        result.push_back(i - prevCIdx);
                    }
                }
            }
            return result;
        }
};
