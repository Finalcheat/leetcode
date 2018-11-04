/**
 * @file Combination-Sum.cpp
 * @brief 组合总和(https://leetcode.com/problems/combination-sum/description/)
 * @author Finalcheat
 * @date 2018-09-25
 */

/**
 * Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
 * The same repeated number may be chosen from candidates unlimited number of times.
 * Note:
 * * All numbers (including target) will be positive integers.
 * * The solution set must not contain duplicate combinations.
 * Example 1:
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 *   [7],
 *   [2,2,3]
 * ]
 * Example 2:
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 *   [2,2,2,2],
 *   [2,3,3],
 *   [3,5]
 * ]
 */

/**
 * dfs遍历搜索即可。
 */


class Solution {
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            std::sort(candidates.begin(), candidates.end());
            vector< vector<int> > result;
            vector<int> cur;
            dfs(candidates, 0, target, cur, result);
            return result;
        }
    private:
        void dfs(const vector<int>& candidates, int idx, int target,
                vector<int>& cur, vector< vector<int> >& result) {
            if (target < 0) {
                return;
            } else if (target == 0) {
                result.push_back(cur);
            } else {
                for (; idx < candidates.size(); ++idx) {
                    cur.push_back(candidates[idx]);
                    dfs(candidates, idx, target - candidates[idx], cur, result);
                    cur.pop_back();
                }
            }
        }
};
