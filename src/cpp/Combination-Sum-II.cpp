/**
 * @file Combination-Sum-II.cpp
 * @brief 组合总和II(https://leetcode.com/problems/combination-sum-ii/description/)
 * @author Finalcheat
 * @date 2018-10-03
 */

/**
 * Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
 * Each number in candidates may only be used once in the combination.
 * Note:
 * * All numbers (including target) will be positive integers.
 * * The solution set must not contain duplicate combinations.
 * Example 1:
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 *   [1, 7],
 *   [1, 2, 5],
 *   [2, 6],
 *   [1, 1, 6]
 * ]
 * Example 2:
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 *   [1,2,2],
 *   [5]
 * ]
 */

/**
 * dfs搜索，去重使用std::set即可。
 */


class Solution {
    public:
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            vector< vector<int> > result;
            if (candidates.empty()) {
                return result;
            }
            std::sort(candidates.begin(), candidates.end());
            vector<int> cur;
            dfs(candidates, -1, target, result, cur);
            return result;
        }
    private:
        void dfs(const vector<int>& candidates, const int idx, const int target,
                vector< vector<int> >& result, vector<int>& cur) {
            if (target < 0) {
                return;
            } else if (target == 0) {
                const auto pair = s.insert(cur);
                if (pair.second) {
                    result.push_back(cur);
                }
            } else {
                for (int i = idx + 1; i < candidates.size(); ++i) {
                    const int num = candidates[i];
                    cur.push_back(num);
                    dfs(candidates, i, target - num, result, cur);
                    cur.pop_back();
                }
            }
        }
    private:
        std::set< vector<int> > s;
};
