/**
 * @file 4Sum.cpp
 * @brief 四数之和(https://leetcode.com/problems/4sum/description/)
 * @author Finalcheat
 * @date 2018-10-25
 */

/**
 * Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
 * Note:
 * The solution set must not contain duplicate quadruplets.
 * Example:
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 * A solution set is:
 * [
 *   [-1,  0, 0, 1],
 *   [-2, -1, 1, 2],
 *   [-2,  0, 0, 2]
 * ]
 */

/**
 * 排序+双指针前后扫描即可。
 */


class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            vector< vector<int> > result;
            std::sort(nums.begin(), nums.end());
            std::set< vector<int> > s;
            for (int i = 0; i < nums.size(); ++i) {
                for (int j = i + 1; j < nums.size(); ++j) {
                    int first = j + 1;
                    int last = nums.size() - 1;
                    while (first < last) {
                        const int curSum = nums[i] + nums[j] + nums[first] + nums[last];
                        if (curSum == target) {
                            vector<int> v{nums[i], nums[j], nums[first], nums[last]};
                            const auto pair = s.insert(v);
                            if (pair.second) {
                                result.push_back(v);
                            }
                        }
                        if (curSum < target) {
                            ++first;
                        } else {
                            --last;
                        }
                    }
                }
            }
            return result;
        }
};
