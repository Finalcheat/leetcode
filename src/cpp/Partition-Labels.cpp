/**
 * @file Partition-Labels.cpp
 * @brief 划分字母区间(https://leetcode.com/problems/partition-labels/description/)
 * @author Finalcheat
 * @date 2018-09-20
 */

/**
 * A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.
 * Example 1:
 * Input: S = "ababcbacadefegdehijhklij"
 * Output: [9,7,8]
 * Explanation:
 * The partition is "ababcbaca", "defegde", "hijhklij".
 * This is a partition so that each letter appears in at most one part.
 * A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
 */

/**
 * 记录每个字符最后出现位置，遍历过程中对每个字符定位最后位置，如果最后位置等于当前位置，则从当前位置分割。
 */


class Solution {
    public:
        vector<int> partitionLabels(string S) {
            std::unordered_map<char, int> u;
            for (int i = 0; i < S.size(); ++i) {
                const char c = S[i];
                u[c] = i;
            }
            int first = 0;
            int last = 0;
            vector<int> result;
            for (int i = 0; i < S.size(); ++i) {
                const char c = S[i];
                const int idx = u[c];
                if (idx > last) {
                    last = idx;
                }
                if (last == i) {
                    result.push_back(last - first + 1);
                    first = i + 1;
                }
            }
            return result;
        }
};
