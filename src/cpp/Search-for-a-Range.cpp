/**
 * @file Search-for-a-Range.cpp
 * @brief 搜索区间(https://leetcode.com/problems/search-for-a-range/)
 * @author Finalcheat
 * @date 2017-03-11
 */

/**
 * Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * If the target is not found in the array, return [-1, -1].
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 */

/**
 * 二分搜索先找到搜索区间的左位置，然后从左位置开始搜索右位置，思路很简单，就是二分搜索很容易写错。
 */

class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            if (nums.empty()) {
                return vector<int>{-1, -1};
            }
            int begin = 0;
            int end = nums.size() - 1;
            while (begin < end) {
                const int middleIndex = begin + (end - begin) / 2;
                const int middle = nums[middleIndex];
                if (middle < target) {
                    begin = middleIndex + 1;
                } else {
                    end = middleIndex;
                }
            }
            if (begin > nums.size() || nums[begin] != target) {
                return vector<int>{-1, -1};
            }
            vector<int> result{begin};
            end = nums.size() - 1;
            while (begin < end) {
                const int middleIndex = end - (end - begin) / 2;
                const int middle = nums[middleIndex];
                if (middle > target) {
                    end = middleIndex - 1;
                } else {
                    begin = middleIndex;
                }
            }
            result.push_back(end);
            return result;
        }
};
