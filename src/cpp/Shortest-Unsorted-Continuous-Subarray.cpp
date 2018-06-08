/**
 * @file Shortest-Unsorted-Continuous-Subarray.cpp
 * @brief 最短无序连续子数组(https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/)
 * @author Finalcheat
 * @date 2018-06-05
 */

/**
 * Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.
 * You need to find the shortest such subarray and output its length.
 * Example 1:
 * Input: [2, 6, 4, 8, 10, 9, 15]
 * Output: 5
 * Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
 */

/**
 * 初看起来感觉很麻烦，需要遍历所有符合要求的连续子数组然后做长度比较，这时候应该换个角度看问题。
 * 考虑Input: [2, 6, 4, 8, 10, 9, 15]最终排序后的数组为[2, 4, 6, 8, 9, 10, 15]
 * 最开始变动的元素是6，最后变动的元素时9
 * 所以只需要将数组排序后与原数组相同位置对比，元素相同则继续，否则就是最短子数组的起始位置了，结束位置同理，从后面扫描即可。
 */


class Solution {
    public:
        int findUnsortedSubarray(vector<int>& nums) {
            assert(nums.size() > 0);
            vector<int> v(nums.begin(), nums.end());
            std::sort(v.begin(), v.end());

            size_t i = 0;
            while (i < v.size() && v[i] == nums[i]) {
                ++i;
            }

            size_t j = v.size() - 1;
            while (j > i && v[j] == nums[j]) {
                --j;
            }

            return (j - i + 1);
        }
};
