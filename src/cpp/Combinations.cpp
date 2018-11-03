/**
 * @file Combinations.cpp
 * @brief 组合(https://leetcode.com/problems/combinations/description/)
 * @author Finalcheat
 * @date 2018-10-11
 */

/**
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 * Example:
 * Input: n = 4, k = 2
 * Output:
 * [
 *   [2,4],
 *   [3,4],
 *   [2,3],
 *   [1,2],
 *   [1,3],
 *   [1,4],
 * ]
 */

/**
 * 递归dfs搜索即可。
 */


class Solution {
    public:
        vector<vector<int>> combine(int n, int k) {
            vector< vector<int> > result;
            vector<int> cur;
            dfs(result, cur, 1, n, k);
            return result;
        }
    private:
        void dfs(vector< vector<int> >& result, vector<int>& cur, int curIdx, int n, int k) {
            if (cur.size() >= k) {
                result.push_back(cur);
                return;
            }
            for (int i = curIdx; i <= n; ++i) {
                cur.push_back(i);
                dfs(result, cur, i + 1, n, k);
                cur.pop_back();
            }
        }
};
