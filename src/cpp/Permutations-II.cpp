/**
 * @file Permutations-II.cpp
 * @brief 全排列II(https://leetcode.com/problems/permutations-ii/description/)
 * @author Finalcheat
 * @date 2018-10-29
 */

/**
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 * Example:
 * Input: [1,1,2]
 * Output:
 * [
 *   [1,1,2],
 *   [1,2,1],
 *   [2,1,1]
 * ]
 */

/**
 * 和全排列一样的算法，去重用std::set就行了。
 */


class Solution {
    public:
        vector<vector<int>> permuteUnique(vector<int>& nums) {
            vector< vector<int> > result;
            _permute(nums, 0, result);
            return result;
        }
    private:
        void _permute(vector<int>& nums, size_t idx, vector< vector<int> >& result) {
            for (size_t i = idx; i < nums.size(); ++i) {
                std::swap(nums[i], nums[idx]);
                if (idx + 1 == nums.size()) {
                    const auto pair = s.insert(nums);
                    if (pair.second) {
                        result.push_back(nums);
                    }
                } else {
                    _permute(nums, idx + 1, result);
                }
                std::swap(nums[i], nums[idx]);
            }
        }
    private:
        std::set< vector<int> > s;
};
