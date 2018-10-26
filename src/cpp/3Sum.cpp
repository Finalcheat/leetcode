/**
 * @file 3Sum.cpp
 * @brief 三数之和(https://leetcode.com/problems/3sum/description/)
 * @author Finalcheat
 * @date 2018-10-10
 */

/**
 * Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 * Note:
 * The solution set must not contain duplicate triplets.
 * Example:
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * A solution set is:
 * [
 *   [-1, 0, 1],
 *   [-1, -1, 2]
 * ]
 */

/**
 * 先排序，然后遍历元素时(第一个数)设定双指针首尾扫描确定第二个数和第三个数，求和与0比较。
 */


class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector< vector<int> > result;
            std::sort(nums.begin(), nums.end());
            for (size_t i = 0; i < nums.size(); ++i) {
                size_t first = i + 1;
                size_t last = nums.size() - 1;
                while (first < last) {
                    const int curSum = nums[i] + nums[first] + nums[last];
                    if (curSum == 0) {
                        vector<int> v{nums[i], nums[first], nums[last]};
                        const auto pair = s.insert(v);
                        if (pair.second) {
                            result.push_back(v);
                        }
                    }
                    if (curSum < 0) {
                        ++first;
                    } else {
                        --last;
                    }
                }
            }
            return result;
        }
    private:
        std::set< vector<int> > s;
};
