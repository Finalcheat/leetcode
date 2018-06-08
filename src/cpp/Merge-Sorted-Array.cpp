/**
 * @file Merge-Sorted-Array.cpp
 * @brief 合并已排序的数组(https://leetcode.com/problems/merge-sorted-array/)
 * @author Finalcheat
 * @date 2016-03-20
 */

/**
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 * Note:
 * You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
 */

/**
 * 要将结果存到nums1数组当中，nums1假设已有足够的空间。首先将nums1拷贝到nums3中，同时两个指针遍历nums2和nums3，较小的赋值到nums1中即可。
 */

class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            std::vector<int> nums3(m);
            std::copy(nums1.begin(), nums1.begin() + m, nums3.begin());
            int nums1_index = 0;
            int nums2_index = 0;
            int nums3_index = 0;
            while (nums3_index < m && nums2_index < n) {
                if (nums3[nums3_index] < nums2[nums2_index]) {
                    nums1[nums1_index] = nums3[nums3_index];
                    ++nums3_index;
                } else {
                    nums1[nums1_index] = nums2[nums2_index];
                    ++nums2_index;
                }
                ++nums1_index;
            }
            while (nums3_index < m) {
                nums1[nums1_index] = nums3[nums3_index];
                ++nums1_index;
                ++nums3_index;
            }
            while (nums2_index < n) {
                nums1[nums1_index] = nums2[nums2_index];
                ++nums1_index;
                ++nums2_index;
            }
        }
};
