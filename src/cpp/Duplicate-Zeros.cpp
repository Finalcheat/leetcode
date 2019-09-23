/**
 * @file Duplicate-Zeros.cpp
 * @brief 重复零(https://leetcode.com/problems/duplicate-zeros/)
 * @author Finalcheat
 * @date 2019-09-23
 */

/**
 * Given a fixed length array arr of integers, duplicate each occurrence of zero, shifting the remaining elements to the right.
 * Note that elements beyond the length of the original array are not written.
 * Do the above modifications to the input array in place, do not return anything from your function.
 * Example 1:
 * Input: [1,0,2,3,0,4,5,0]
 * Output: null
 * Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
 * Example 2:
 * Input: [1,2,3]
 * Output: null
 * Explanation: After calling your function, the input array is modified to: [1,2,3]
 */

/**
 * 从后往前搜索，遇到0则将元素后移。
 */

class Solution {
    public:
        void duplicateZeros(vector<int>& arr) {
            for (int i = arr.size() - 1; i >= 0; --i) {
                if (arr[i] == 0) {
                    for (int j = arr.size() - 1; j > i; --j) {
                        arr[j] = arr[j - 1];
                    }
                    if (i + 1 < arr.size()) {
                        arr[i + 1] = 0;
                    }
                }
            }
        }
};
