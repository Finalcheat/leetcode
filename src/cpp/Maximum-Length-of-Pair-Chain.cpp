/**
 * @file Maximum-Length-of-Pair-Chain.cpp
 * @brief 链对最大长度(https://leetcode.com/problems/maximum-length-of-pair-chain/description/)
 * @author Finalcheat
 * @date 2018-04-08
 */

/**
 * You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.
 * Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.
 * Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.
 * Example 1:
 * Input: [[1,2], [2,3], [3,4]]
 * Output: 2
 * Explanation: The longest chain is [1,2] -> [3,4]
 */

/**
 * 按照pair的second排序，然后遍历过程中把second和first拼接起来就行了。
 */


class Solution {
    public:
        int findLongestChain(vector<vector<int>>& pairs) {
            std::sort(pairs.begin(), pairs.end(), [](const vector<int>& l, const vector<int>& r) -> bool {
                return l[1] < r[1];
            });
            vector<vector<int>>::const_iterator iter = pairs.begin();
            int count = 0;
            while (iter != pairs.end()) {
                const vector<int>& v = *iter;
                const int curEnd = v[1];
                ++count;
                ++iter;
                while (iter != pairs.end() && (*iter)[0] <= curEnd) {
                    ++iter;
                }
            }
            return count;
        }
};
