/**
 * @file Degree-of-an-Array.cpp
 * @brief 数组的度(https://leetcode.com/problems/degree-of-an-array/description/)
 * @author Finalcheat
 * @date 2018-09-02
 */

/**
 * Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.
 * Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.
 * Example 1:
 * Input: [1, 2, 2, 3, 1]
 * Output: 2
 * Explanation:
 * The input array has a degree of 2 because both elements 1 and 2 appear twice.
 * Of the subarrays that have the same degree:
 * [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
 * The shortest length is 2. So return 2.
 * Example 2:
 * Input: [1,2,2,3,1,4,2]
 * Output: 6
 */

/**
 * 找出出现次数最多的元素下标相减对比即可。
 */


class Solution {
    public:
        int findShortestSubArray(vector<int>& nums) {
            int maximum = 0;
            std::map<int, std::vector<int> > m;
            for (int i = 0; i < nums.size(); ++i) {
                const int num = nums[i];
                auto iter = m.find(num);
                int count;
                if (iter != m.end()) {
                    vector<int>& idxs = iter->second;
                    idxs.push_back(i);
                    count = idxs.size();
                } else {
                    vector<int> idxs;
                    idxs.push_back(i);
                    m[num] = idxs;
                    count = 1;
                }
                if (count > maximum) {
                    maximum = count;
                }
            }
            int degree = nums.size();
            for (auto iter = m.begin(); iter != m.end(); ++iter) {
                const std::vector<int>& idxs = iter->second;
                if (idxs.size() != maximum) {
                    continue;
                }
                for (int i = 0; i <= idxs.size() - maximum; ++i) {
                    int dist = std::abs(idxs[i] - idxs[i + maximum - 1]);
                    if (dist < degree) {
                        degree = dist;
                    }
                }
            }
            return degree + 1;
        }
};
