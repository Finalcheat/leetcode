/**
 * @file Longest-Consecutive-Sequence.cpp
 * @brief 最长连续序列(https://leetcode.com/problems/longest-consecutive-sequence/description/)
 * @author Finalcheat
 * @date 2018-08-12
 */

/**
 * Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 * Your algorithm should run in O(n) complexity.
 * Example:
 * Input: [100, 4, 200, 1, 3, 2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
 */

/**
 * 先插入set中，在遍历过程中查找当前值+-是否在set中，若在不断更新最长序列值同时删掉set中值。
 */


class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            std::unordered_set<int> u;
            for (const int num : nums) {
                u.insert(num);
            }
            int maximum = 0;
            for (const int num : nums) {
                int count = 1;
                int next = num + 1;
                std::unordered_set<int>::const_iterator iter;
                while ((iter = u.find(next)) != u.end()) {
                    u.erase(iter);
                    ++next;
                    ++count;
                }
                int prev = num - 1;
                while ((iter = u.find(prev)) != u.end()) {
                    u.erase(iter);
                    --prev;
                    ++count;
                }
                u.erase(num);
                if (count > maximum) {
                    maximum = count;
                }
            }
            return maximum;
        }
};
