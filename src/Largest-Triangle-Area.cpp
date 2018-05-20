/**
 * @file Largest-Triangle-Area.cpp
 * @brief 面积最大的三角形(https://leetcode.com/problems/largest-triangle-area/description/)
 * @author Finalcheat
 * @date 2018-05-20
 */

/**
 * You have a list of points in the plane. Return the area of the largest triangle that can be formed by any 3 of the points.
 * Example:
 * Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
 * Output: 2
 * Explanation:
 * The five points are show in the figure below. The red triangle is the largest.
 */

/**
 * 暴力求解法，求出所有三个点组成的三角形面积取最大的。
 * 根据三个点坐标求面积可参考wiki
 * https://zh.wikipedia.org/wiki/%E4%B8%89%E8%A7%92%E5%BD%A2#%E5%B7%B2%E7%9F%A5%E5%9D%90%E6%A0%87%E7%B3%BB%E4%B8%AD%E4%B8%89%E9%A1%B6%E7%82%B9%E5%9D%90%E6%A0%87
 */


class Solution {
    public:
        double largestTriangleArea(vector<vector<int>>& points) {
            double result = 0;
            for (size_t i = 0; i < points.size(); ++i) {
                for (size_t j = i + 1; j < points.size(); ++j) {
                    for (size_t k = j + 1; k < points.size(); ++k) {
                        result = std::max(result, triangleArea(points[i], points[j], points[k]));
                    }
                }
            }
            return result;
        }
    private:
        double triangleArea(const vector<int>& a, const vector<int>& b, const vector<int>& c) {
            return 0.5 * std::abs(a[0] * (b[1] - c[1]) + b[0] * (c[1] - a[1]) + c[0] * (a[1] - b[1]));
        }
};
