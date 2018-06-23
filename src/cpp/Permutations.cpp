/**
 * @file Permutations.cpp
 * @brief 全排列(https://leetcode.com/problems/permutations/description/)
 * @author Finalcheat
 * @date 2018-06-23
 */

/**
 * Given a collection of distinct integers, return all possible permutations.
 * Example:
 * Input: [1,2,3]
 * Output:
 * [
 *   [1,2,3],
 *   [1,3,2],
 *   [2,1,3],
 *   [2,3,1],
 *   [3,1,2],
 *   [3,2,1]
 * ]
 */

/**
 * 递归不断交换两个数即可。
 */


class Solution {

    public:
        vector<vector<int>> permute(vector<int>& nums) {
            vector< vector<int> > result;
            _permute(nums, 0, result);
            return result;
        }

    private:
        void _permute(vector<int>& nums, size_t idx, vector< vector<int> >& result) {
            for (size_t i = idx; i < nums.size(); ++i) {
                std::swap(nums[idx], nums[i]);
                if (idx + 1 == nums.size()) {
                    result.push_back(nums);
                } else {
                    _permute(nums, idx + 1, result);
                }
                std::swap(nums[i], nums[idx]);
            }
        }
};
