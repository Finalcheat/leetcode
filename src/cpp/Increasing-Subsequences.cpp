/**
 * @file Increasing-Subsequences.cpp
 * @brief 递增子序列(https://leetcode.com/problems/increasing-subsequences/description/)
 * @author Finalcheat
 * @date 2018-09-27
 */

/**
 * Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2 .
 * Example:
 * Input: [4, 6, 7, 7]
 * Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
 */

/**
 * dfs搜索，注意要去重，这里简单使用set去重即可。
 */


class Solution {
    public:
        vector<vector<int>> findSubsequences(vector<int>& nums) {
            vector< vector<int> > result;
            vector<int> cur;
            dfs(nums, 0, result, cur);
            return result;
        }
    private:
        void dfs(const vector<int>& nums, const int idx, vector< vector<int> >& result, vector<int>& cur) {
            if (cur.size() >= 2) {
                const auto iter = u.find(cur);
                if (iter == u.end()) {
                    u.insert(cur);
                    result.push_back(cur);
                }
            }
            for (int i = idx; i < nums.size(); ++i) {
                if (cur.empty() || cur.back() <= nums[i]) {
                    cur.push_back(nums[i]);
                    dfs(nums, i + 1, result, cur);
                    cur.pop_back();
                }
            }
        }
    private:
        std::set< vector<int> > u;
};
