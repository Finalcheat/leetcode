/**
 * @file Longest-Harmonious-Subsequence.cpp
 * @brief 最长和谐子序列(https://leetcode.com/problems/longest-harmonious-subsequence/description/)
 * @author Finalcheat
 * @date 2018-03-10
 */

/**
 * We define a harmonious array is an array where the difference between its maximum value and its minimum value is exactly 1.
 * Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.
 * Example 1:
 * Input: [1,3,2,2,5,2,3,7]
 * Output: 5
 * Explanation: The longest harmonious subsequence is [3,2,2,2,3].
 */

/**
 * 利用hashtable记录各数字所在位置，遍历数组找出数字+-1的个数，选出多的加上本身的个数。
 */


class Solution {

    public:
        int findLHS(vector<int>& nums) {
            std::unordered_map<int, std::vector<size_t>> u;
            for (size_t i = 0; i < nums.size(); ++i) {
                auto iter = u.find(nums[i]);
                if (iter != u.end()) {
                    std::vector<size_t>& indexs = iter->second;
                    indexs.push_back(i);
                } else {
                    std::vector<size_t> initIndexs;
                    initIndexs.push_back(i);
                    u[nums[i]] = initIndexs;
                }
            }
            int maxCount = 0;
            for (size_t i = 0; i < nums.size(); ++i) {
                const int num = nums[i];

                const int incrSum = num + 1;
                auto iter = u.find(incrSum);
                int incrCount = 0;
                if (iter != u.end()) {
                    incrCount += findCounts(i, iter->second);
                }

                const int decrSum = num - 1;
                iter = u.find(decrSum);
                int decrCount = 0;
                if (iter != u.end()) {
                    decrCount += findCounts(i, iter->second);
                }

                int max = std::max(incrCount, decrCount);
                if (max > 0) {
                    iter = u.find(num);
                    max += findCounts(i, iter->second);
                }

                if (max > maxCount) {
                    maxCount = max;
                }
            }
            return maxCount;
        }

    private:
        int findCounts(const size_t curIndex, const std::vector<size_t>& indexs) {
            for (size_t i = 0; i < indexs.size(); ++i) {
                if (indexs[i] >= curIndex) {
                    return (indexs.size() - i);
                }
            }
            return 0;
        }

};
