/**
 * @file Height-Checker.cpp
 * @brief 高度检查(https://leetcode.com/problems/height-checker/)
 * @author Finalcheat
 * @date 2019-09-17
 */

/**
 * Students are asked to stand in non-decreasing order of heights for an annual photo.
 * Return the minimum number of students not standing in the right positions.  (This is the number of students that must move in order for all students to be standing in non-decreasing order of height.)
 */

/**
 * 排序后对比即可。
 */

class Solution {
    public:
        int heightChecker(vector<int>& heights) {
            vector<int> heightsCopy(heights);
            std::sort(heightsCopy.begin(), heightsCopy.end());
            int count = 0;
            for (size_t i = 0; i < heights.size(); ++i) {
                if (heightsCopy[i] != heights[i]) {
                    ++count;
                }
            }
            return count;
        }
};
