/**
* @file Range-Sum-Query-Immutable.cpp
* @brief 区间和(https://leetcode.com/problems/range-sum-query-immutable/) 
* @author Finalcheat
* @date 2016-05-27
*/

/**
 * Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
 * Example:
 * Given nums = [-2, 0, 3, -5, 2, -1]
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 * Note:
 * * You may assume that the array does not change.
 * * There are many calls to sumRange function.
 */

/**
 * 看到There are many calls to sumRange function.这句就应该知道要缓存结果了，可以新建一个数组，数组的i位置存储原数组0到i之间的累加和，要求区间和的时候直接新数组dpNums[j] - dpNums[i - 1]即可，O(1)时间复杂度。
 */

class NumArray {
    public:
        NumArray(vector<int> &nums) {
            dpNums.resize(nums.size());
            int sum = 0;
            for (size_t i = 0; i < nums.size(); ++i) {
                sum += nums[i];
                dpNums[i] = sum;
            }
        }

        int sumRange(int i, int j) {
            return i == 0 ? dpNums[j] : dpNums[j] - dpNums[i - 1];
        }
        
    private:
        std::vector<int> dpNums;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
