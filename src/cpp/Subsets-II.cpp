/**
 * @file Subsets-II.cpp
 * @brief 子集II(https://leetcode.com/problems/subsets-ii/description/)
 * @author Finalcheat
 * @date 2018-10-15
 */

/**
 * Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
 * Note: The solution set must not contain duplicate subsets.
 * Example:
 * Input: [1,2,2]
 * Output:
 * [
 *   [2],
 *   [1],
 *   [1,2,2],
 *   [2,2],
 *   [1,2],
 *   []
 * ]
 */

/**
 * 排序+递归遍历即可。
 */


class Solution {
    public:
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            std::sort(nums.begin(), nums.end());
            vector< vector<int> > result;
            vector<int> cur;
            _subsetsWithDup(nums, 0, cur, result);
            return result;
        }
    private:
        void _subsetsWithDup(const vector<int>& nums, const int idx, vector<int>& cur,
                             vector< vector<int> >& result) {
            const auto pair = s.insert(cur);
            if (pair.second) {
                result.push_back(cur);
            }
            if (idx >= nums.size()) {
                return;
            }
            for (int i = idx; i < nums.size(); ++i) {
                cur.push_back(nums[i]);
                _subsetsWithDup(nums, i + 1, cur, result);
                cur.pop_back();
            }
        }
    private:
        std::set< vector<int> > s;
};
