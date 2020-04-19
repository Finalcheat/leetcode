/**
 * @file Minimum-Absolute-Difference.cpp
 * @brief 最小差值(https://leetcode.com/problems/minimum-absolute-difference/)
 * @author Finalcheat
 * @date 2020-04-19
 */

/**
 * Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements. 
 * Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows
 * * a, b are from arr
 * * a < b
 * * b - a equals to the minimum absolute difference of any two elements in arr
 * Example 1:
 * Input: arr = [4,2,1,3]
 * Output: [[1,2],[2,3],[3,4]]
 * Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.
 * Example 2:
 * Input: arr = [1,3,6,10,15]
 * Output: [[1,3]]
 * Example 3:
 * Input: arr = [3,8,-10,23,19,-4,-14,27]
 * Output: [[-14,-10],[19,23],[23,27]]
 */

/**
 * 排序后对比相邻元素。
 */

class Solution {
    public:
        vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
            assert(arr.size() >= 2);
            std::sort(arr.begin(), arr.end());
            int minimum = arr[1] - arr[0];
            vector<vector<int>> result;
            vector<int> cur(arr.begin(), arr.begin() + 2);
            result.push_back(cur);
            for (size_t i = 2; i < arr.size(); ++i) {
                const int curDiff = arr[i] - arr[i - 1];
                if (curDiff < minimum) {
                    minimum = curDiff;
                    result.clear();
                    cur[0] = arr[i - 1];
                    cur[1] = arr[i];
                    result.push_back(cur);
                } else if (curDiff == minimum) {
                    cur[0] = arr[i - 1];
                    cur[1] = arr[i];
                    result.push_back(cur);
                }
            }
            return result;
        }
};
