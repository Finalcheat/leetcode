/**
 * @file Two-Sum-II-Input-array-is-sorted.cpp
 * @brief 数组两个元素的和II(https://leetcode.com/problems/two-sum-ii-input-array-is-sorted)
 * @author Finalcheat
 * @date 2017-03-01
 */

/**
 * Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
 * The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. 
 * Please note that your returned answers (both index1 and index2) are not zero-based.
 * You may assume that each input would have exactly one solution and you may not use the same element twice.
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 */

/**
 * 设置两个指针，一个指向头，另一个指向尾，查找是否相加得到目标值，否则向中间移动。
 */


class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
            vector<int>::const_iterator first = numbers.begin();
            vector<int>::const_iterator last = --numbers.end();
            vector<int> result;
            while (first < last) {
                const int dis = target - *first;
                while (first < last && *last > dis) {
                    --last;
                }
                if (last <= first) {
                    break;
                }
                if (*last == dis) {
                    result.push_back(first - numbers.begin() + 1);
                    result.push_back(last - numbers.begin() + 1);
                    return result;
                } else {
                    ++first;
                }
            }
            return result;
        }
};
