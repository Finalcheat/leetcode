/**
 * @file Split-Array-into-Consecutive-Subsequences.cpp
 * @brief 分割数组为连续子序列(https://leetcode.com/problems/split-array-into-consecutive-subsequences/description/)
 * @author Finalcheat
 * @date 2018-10-26
 */

/**
 * You are given an integer array sorted in ascending order (may contain duplicates), you need to split them into several subsequences, where each subsequences consist of at least 3 consecutive integers. Return whether you can make such a split.
 * Example 1:
 * Input: [1,2,3,3,4,5]
 * Output: True
 * Explanation:
 * You can split them into two consecutive subsequences :
 * 1, 2, 3
 * 3, 4, 5
 * Example 2:
 * Input: [1,2,3,3,4,4,5,5]
 * Output: True
 * Explanation:
 * You can split them into two consecutive subsequences :
 * 1, 2, 3, 4, 5
 * 3, 4, 5
 * Example 3:
 * Input: [1,2,3,4,4,5]
 * Output: False
 */

/**
 * 两个hashtable，一个记录数字以及出现次数的映射，另一个记录需要的数字以及出现次数的映射。
 */


class Solution {
    public:
        bool isPossible(vector<int>& nums) {
            std::unordered_map<int, int> u;
            std::unordered_map<int, int> uu;
            for (const int num : nums) {
                ++u[num];
            }
            for (const int num : nums) {
                auto iter = u.find(num);
                if (iter == u.end()) {
                    continue;
                } else if (--iter->second == 0) {
                    u.erase(iter);
                }
                iter = uu.find(num);
                if (iter != uu.end()) {
                    if (--iter->second == 0) {
                        uu.erase(iter);
                    }
                    ++uu[num + 1];
                    continue;
                }
                iter = u.find(num + 1);
                if (iter == u.end()) {
                    return false;
                }
                if (--iter->second == 0) {
                    u.erase(iter);
                }
                iter = u.find(num + 2);
                if (iter == u.end()) {
                    return false;
                }
                if (--iter->second == 0) {
                    u.erase(iter);
                }
                ++uu[num + 3];
            }
            return true;
        }
};
