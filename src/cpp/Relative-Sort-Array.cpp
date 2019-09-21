/**
 * @file Relative-Sort-Array.cpp
 * @brief 相对排序数组(https://leetcode.com/problems/relative-sort-array/)
 * @author Finalcheat
 * @date 2019-09-21
 */

/**
 * Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.
 * Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2.  Elements that don't appear in arr2 should be placed at the end of arr1 in ascending order.
 * Example 1:
 * Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
 * Output: [2,2,2,1,4,3,3,9,6,7,19]
 */

/**
 * 使用hashtable作为辅助结构记录元素相对顺序，然后写排序比较函数即可。
 */

class Solution {
    public:
        vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
            std::unordered_map<int, size_t> u;
            for (size_t i = 0; i < arr2.size(); ++i) {
                u[arr2[i]] = i;
            }
            std::sort(arr1.begin(), arr1.end(), [&](const int& l, const int& r) {
                const auto iterL = u.find(l);
                const auto iterR = u.find(r);
                if (iterL == u.end() && iterR == u.end()) {
                    return l <= r;
                } else if (iterL == u.end()) {
                    return false;
                } else if (iterR == u.end()) {
                    return true;
                }
                return iterL->second <= iterR->second;
            });
            return arr1;
        }
};
