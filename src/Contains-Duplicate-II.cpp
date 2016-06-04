/**
 * @file Contains-Duplicate-II.cpp
 * @brief 包含重复值II(https://leetcode.com/problems/contains-duplicate-ii/) 
 * @author Finalcheat
 * @date 2016-06-04
 */

/**
 * Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
 */

/**
 * 使用哈希表，key是数组的值，value是数组所在位置，循环遍历更新和计算差值即可。
 */

class Solution {
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            std::unordered_map<int, int> numsMap;
            for (size_t i = 0; i < nums.size(); ++i) {
                auto it = numsMap.find(nums[i]);
                if (it != numsMap.end()) {
                    const int difference = i - it->second;
                    if (difference <= k) {
                        return true;
                    }
                }
                numsMap[nums[i]] = i;
            }
            return false;
        }
};
