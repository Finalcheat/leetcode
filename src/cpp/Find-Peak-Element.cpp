/**
 * @file Find-Peak-Element.cpp
 * @brief 寻找数组中的Peak元素(https://leetcode.com/problems/find-peak-element/) 
 * @author Finalcheat
 * @date 2016-05-13
 */

/**
 * A peak element is an element that is greater than its neighbors.
 * Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
 * The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
 * You may imagine that num[-1] = num[n] = -∞.
 * For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
 */

/**
 * 简单的做法是遍历数组比较前后元素即可。
 * 还可以用二分搜索的思想去解，middle位置比前后元素大就直接返回，否则必在middle前后区间，若middle-1比middle大，则在前区间，否则在后区间。
 */

class Solution {
    public:
        // 二分搜索
        int findPeakElement(vector<int>& nums) {
            int begin = 0;
            int end = nums.size() - 1;
            int middle = 0;
            int length = nums.size();
            while (begin <= end) {
                middle = (begin + end) / 2;
                if ((middle == 0 || nums[middle] >= nums[middle - 1]) &&
                    (middle == length - 1 || nums[middle] >= nums[middle + 1])) {
                    return middle;
                } else if (middle > 0 && nums[middle - 1] > nums[middle]) {
                    end = middle - 1;
                } else {
                    begin = middle + 1;
                }
            }
            return middle;
        }
        
        // 遍历数组搜索
        int _findPeakElement(vector<int>& nums) {
            if (nums.size() < 2) {
                return 0;
            }
            for (size_t i = 1; i < nums.size() - 1; ++i) {
                if (nums[i] >= nums[i - 1] && nums[i] >= nums[i + 1]) {
                    return i;
                }
            }
            if (nums[0] >= nums[1]) {
                return 0;
            }
            int length = nums.size();
            if (nums[length - 1] >= nums[length - 1]) {
                return length - 1;
            }
            return 0;
        }
};
