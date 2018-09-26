/**
 * @file Rectangle-Overlap.cpp
 * @brief 矩形重叠(https://leetcode.com/problems/rectangle-overlap/description/)
 * @author Finalcheat
 * @date 2018-09-22
 */

/**
 * A rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) are the coordinates of its bottom-left corner, and (x2, y2) are the coordinates of its top-right corner.
 * Two rectangles overlap if the area of their intersection is positive.  To be clear, two rectangles that only touch at the corner or edges do not overlap.
 * Given two (axis-aligned) rectangles, return whether they overlap.
 * Example 1:
 * Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]
 * Output: true
 * Example 2:
 * Input: rec1 = [0,0,1,1], rec2 = [1,0,2,1]
 * Output: false
 */

/**
 * 画个图弄清楚矩形不重叠时坐标的关系即可。
 */


class Solution {
    public:
        bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
            const int l1x = rec1[0];
            const int l1y = rec1[1];
            const int r1x = rec1[2];
            const int r1y = rec1[3];
            const int l2x = rec2[0];
            const int l2y = rec2[1];
            const int r2x = rec2[2];
            const int r2y = rec2[3];
            if (l1x >= r2x || l1y >= r2y || r1x <= l2x || r1y <= l2y) {
                return false;
            }
            return true;
        }
};
