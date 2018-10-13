/**
 * @file Container-With-Most-Water.cpp
 * @brief 盛最多水的容器(https://leetcode.com/problems/container-with-most-water/description/)
 * @author Finalcheat
 * @date 2018-10-09
 */

/**
 * Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 * Note: You may not slant the container and n is at least 2.
 * Example:
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
 */

/**
 * 从两边开始扫描计算当前面积，遇到大的则更新最大面积，否则根据当前first和last的height决定是++first还是--last。
 */


class Solution {
    public:
        int maxArea(vector<int>& height) {
            int maximum = 0;
            int first = 0;
            int last = height.size() - 1;
            while (first < last) {
                const int firstHeight = height[first];
                const int lastHeight = height[last];
                const int minHeight = std::min(firstHeight, lastHeight);
                const int curArea = minHeight * (last - first);
                if (curArea > maximum) {
                    maximum = curArea;
                }
                if (firstHeight < lastHeight) {
                    ++first;
                } else {
                    --last;
                }
            }
            return maximum;
        }
};
