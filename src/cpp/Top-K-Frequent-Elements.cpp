/**
 * @file Top-K-Frequent-Elements.cpp
 * @brief 前k项频繁出现的元素(https://leetcode.com/problems/top-k-frequent-elements/) 
 * @author Finalcheat
 * @date 2016-05-04
 */

/**
 * Given a non-empty array of integers, return the k most frequent elements.
 * For example,
 * Given [1,1,1,2,2,3] and k = 2, return [1,2].
 * Note: 
 * * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * * Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
 */

/**
 * 使用std::map，key作为元素值，value作为出现的次数，然后反转key-value，最后遍历std::map的前k项即可。
 */

class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            if (nums.size() == 0) {
                return std::vector<int>();
            }
            std::map<int, int> numsMap;
            for (size_t i = 0; i < nums.size(); ++i) {
                ++numsMap[nums[i]];
            }
            std::map<int, std::vector<int>, std::greater<int>> numsCountMap;
            typedef std::map<int, std::vector<int>, std::greater<int>>::iterator mapIt;
            for (std::map<int, int>::const_iterator it = numsMap.begin(); it != numsMap.end(); ++it) {
                mapIt findIt = numsCountMap.find(it->second);
                if (findIt != numsCountMap.end()) {
                    std::vector<int>& values = findIt->second;
                    values.push_back(it->first);
                } else {
                    std::vector<int> values;
                    values.push_back(it->first);
                    numsCountMap[it->second] =  values;
                }
            }
            std::vector<int> result;
            int count = 0;
            for (mapIt it = numsCountMap.begin(); it != numsCountMap.end(); ++it) {
                if (count >= k) {
                    break;
                }
                const std::vector<int>& values = it->second;
                for (size_t i = 0; i < values.size(); ++i) {
                    result.push_back(values[i]);
                }
                count += values.size();
            }
            return result;
        }
};
