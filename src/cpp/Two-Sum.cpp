/**
 * @file Two-Sum.cpp
 * @brief 数组中两个数的和等于目标值(https://leetcode.com/problems/two-sum/)
 * @author Finalcheat
 * @date 2016-05-25
 */

/**
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution.
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * The return format had been changed to zero-based indices. Please read the above updated description carefully.
 */

/**
 * 构造一个反查表，也就是用数组的值是key，位置是value，用于快速查询数组的值，然后遍历的时候只需要去查询即可。
 */

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            std::unordered_map<int, int> numsMap;
            for (size_t i = 0; i < nums.size(); ++i) {
                numsMap[nums[i]] = i;
            }
            std::vector<int> result;
            for (size_t i = 0; i < nums.size(); ++i) {
                const int value = target - nums[i];
                std::unordered_map<int, int>::const_iterator it = numsMap.find(value);
                if (it != numsMap.end() && it->second != i) {
                    result.push_back(i);
                    result.push_back(it->second);
                    break;
                }
            }
            return result;
        }
};
