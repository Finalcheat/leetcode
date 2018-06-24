/**
 * @file Random-Pick-Index.cpp
 * @brief 随机选择目标数(https://leetcode.com/problems/random-pick-index/description/)
 * @author Finalcheat
 * @date 2018-06-24
 */

/**
 * Given an array of integers with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.
 * Note:
 The array size can be very large. Solution that uses too much extra space will not pass the judge.
 * Example:
 * int[] nums = new int[] {1,2,3,3,3};
 * Solution solution = new Solution(nums);
 * // pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
 * solution.pick(3);
 * // pick(1) should return 0. Since in the array only nums[0] is equal to 1.
 * solution.pick(1);
 */

/**
 * https://en.wikipedia.org/wiki/Reservoir_sampling
 * 水塘抽样算法
 */


class Solution {
    public:
        Solution(vector<int> nums) : v (nums) {
        }

        int pick(int target) {
            const size_t k = 1;
            int R[k];
            size_t targetCount = 0;
            size_t i = 0;
            for (; i < v.size(); ++i) {
                if (v[i] == target) {
                    R[0] = i;
                    ++targetCount;
                    break;
                }
            }

            std::random_device rd;
            for (++i; i < v.size(); ++i) {
                if (v[i] != target) {
                    continue;
                }
                ++targetCount;
                const size_t j = rd() % targetCount;
                if (j < k) {
                    R[0] = i;
                }
            }

            return R[0];
        }

    private:
        vector<int> v;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
