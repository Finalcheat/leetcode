/**
 * @file Combination-Sum-III.cpp
 * @brief 组合总和III(https://leetcode.com/problems/combination-sum-iii/description/)
 * @author Finalcheat
 * @date 2018-10-21
 */

/**
 * Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
 * Note:
 * * All numbers will be positive integers.
 * * The solution set must not contain duplicate combinations.
 * Example 1:
 * Input: k = 3, n = 7
 * Output: [[1,2,4]]
 * Example 2:
 * Input: k = 3, n = 9
 * Output: [[1,2,6], [1,3,5], [2,3,4]]
 */

/**
 * dfs搜索即可。
 */


class Solution {
    public:
        vector<vector<int>> combinationSum3(int k, int n) {
            vector< vector<int> > result;
            vector<int> curV;
            dfs(k, 1, n, 0, result, curV);
            return result;
        }
    private:
        void dfs(int k, int idx, int n, int curN, vector< vector<int> >& result, vector<int>& curV) {
            if (curV.size() >= k) {
                if (n == curN) {
                    result.push_back(curV);
                }
                return;
            }
            for (; idx <= 9; ++idx) {
                curV.push_back(idx);
                dfs(k, idx + 1, n, curN + idx, result, curV);
                curV.pop_back();
            }
        }
};
