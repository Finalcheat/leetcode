/**
 * @file Intersection-of-Two-Arrays-II.cpp
 * @brief 两个数组的相同数字II(https://leetcode.com/problems/intersection-of-two-arrays-ii/)
 * @author Finalcheat
 * @date 2016-05-22
 */

/**
 * Given two arrays, write a function to compute their intersection.
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
 * Note:
 * * Each element in the result should appear as many times as it shows in both arrays.
 * * The result can be in any order.
 */

/**
 * 使用std::unordered_map，将nums1中的数字作为key，出现次数作为value，然后遍历nums2查找对比即可。
 */

class Solution {
    public:
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
            std::unordered_map<int, int> numsMap;
            for (size_t i = 0; i < nums1.size(); ++i) {
                ++numsMap[nums1[i]];
            }
            std::vector<int> result;
            for (size_t i = 0; i < nums2.size(); ++i) {
                std::unordered_map<int, int>::iterator it = numsMap.find(nums2[i]);
                if (it != numsMap.end()) {
                    result.push_back(nums2[i]);
                    if (--it->second == 0) {
                        numsMap.erase(it);
                    }
                }
            }
            return result;
        }
};
