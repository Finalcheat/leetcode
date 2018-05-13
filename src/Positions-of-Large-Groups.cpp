/**
 * @file Positions-of-Large-Groups.cpp
 * @brief Positions of Large Groups(https://leetcode.com/problems/positions-of-large-groups/description/)
 * @author Finalcheat
 * @date 2018-05-13
 */

/**
 * In a string S of lowercase letters, these letters form consecutive groups of the same character.
 * For example, a string like S = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z" and "yy".
 * Call a group large if it has 3 or more characters.  We would like the starting and ending positions of every large group.
 * The final answer should be in lexicographic order.
 * Example 1:
 * Input: "abbxxxxzzy"
 * Output: [[3,6]]
 * Explanation: "xxxx" is the single large group with starting  3 and ending positions 6.
 * Example 2:
 * Input: "abc"
 * Output: []
 * Explanation: We have "a","b" and "c" but no large group.
 * Example 3:
 * Input: "abcdddeeeeaabbbcd"
 * Output: [[3,5],[6,9],[12,14]]
 */

/**
 * 记录上一个数字，记录重复出现次数，记录上一个数字位置，循环过程中判断即可。
 */


class Solution {
    public:
        vector<vector<int>> largeGroupPositions(string S) {
            int prev = S[0];
            int start = 0;
            int repeatCount = 1;
            vector<vector<int>> result;
            for (size_t i = 1; i < S.size(); ++i) {
                if (S[i] != prev) {
                    if (repeatCount >= 3) {
                        result.push_back(vector<int>{start, i - 1});
                    }
                    prev = S[i];
                    start = i;
                    repeatCount = 1;
                } else {
                    ++repeatCount;
                }
            }
            if (repeatCount >= 3) {
                result.push_back(vector<int>{start, S.size() - 1});
            }
            return result;
        }
};
