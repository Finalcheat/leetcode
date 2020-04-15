/**
 * @file Replace-Elements-with-Greatest-Element-on-Right-Side.cpp
 * @brief 将右边的元素替换为最大元素(https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/)
 * @author Finalcheat
 * @date 2020-04-15
 */

/**
 * Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.
 * After doing so, return the array.
 * Example 1:
 * Input: arr = [17,18,5,4,6,1]
 * Output: [18,6,6,6,1,-1]
 */

/**
 * 从后往前遍历记录最大元素即可。
 */

class Solution {
    public:
        vector<int> replaceElements(vector<int>& arr) {
            assert(!arr.empty());
            int maximum = -1;
            for (auto iter = arr.rbegin(); iter != arr.rend(); ++iter) {
                const int value = *iter;
                *iter = maximum;
                if (value > maximum) {
                    maximum = value;
                }
            }
            return arr;
        }
};
