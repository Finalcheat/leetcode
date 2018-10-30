/**
 * @file Subsets.cpp
 * @brief 子集(https://leetcode.com/problems/subsets/description/)
 * @author Finalcheat
 * @date 2018-10-22
 */

/**
 * Given a set of distinct integers, nums, return all possible subsets (the power set).
 * Note: The solution set must not contain duplicate subsets.
 * Example:
 * Input: nums = [1,2,3]
 * Output:
 * [
 *   [3],
 *   [1],
 *   [2],
 *   [1,2,3],
 *   [1,3],
 *   [2,3],
 *   [1,2],
 *   []
 * ]
 */

/**
 * 递归遍历即可。
 */


class Solution {
    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            vector< vector<int> > result;
            vector<int> cur;
            _subsets(nums, 0, result, cur);
            return result;
        }
    private:
        void _subsets(const vector<int>& nums, size_t idx, vector< vector<int> >& result, vector<int>& cur) {
            result.push_back(cur);
            if (idx == nums.size()) {
                return;
            }
            for (; idx < nums.size(); ++idx) {
                cur.push_back(nums[idx]);
                _subsets(nums, idx + 1, result, cur);
                cur.pop_back();
            }
        }
};
