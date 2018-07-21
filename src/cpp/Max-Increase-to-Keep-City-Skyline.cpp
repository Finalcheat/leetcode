/**
 * @file Max-Increase-to-Keep-City-Skyline.cpp
 * @brief 最大限度地增加城市的天际线(https://leetcode.com/problems/max-increase-to-keep-city-skyline/description/)
 * @author Finalcheat
 * @date 2018-07-21
 */

/**
 * In a 2 dimensional array grid, each value grid[i][j] represents the height of a building located there. We are allowed to increase the height of any number of buildings, by any amount (the amounts can be different for different buildings). Height 0 is considered to be a building as well.
 * At the end, the "skyline" when viewed from all four directions of the grid, i.e. top, bottom, left, and right, must be the same as the skyline of the original grid. A city's skyline is the outer contour of the rectangles formed by all the buildings when viewed from a distance. See the following example.
 * What is the maximum total sum that the height of the buildings can be increased?
 * Example:
 * Input: grid = [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]
 * Output: 35
 * Explanation:
 * The grid is:
 * [ [3, 0, 8, 4],
 *   [2, 4, 5, 7],
 *   [9, 2, 6, 3],
 *   [0, 3, 1, 0] ]
 * The skyline viewed from top or bottom is: [9, 4, 8, 7]
 * The skyline viewed from left or right is: [8, 7, 9, 3]
 * The grid after increasing the height of buildings without affecting skylines is:
 * gridNew = [ [8, 4, 8, 7],
 *             [7, 4, 7, 7],
 *             [9, 4, 8, 7],
 *             [3, 3, 3, 3] ]
 */

/**
 * 计算上下左右方向的最大值，然后遍历grid求差值即可。
 */


class Solution {
    public:
        int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
            if (grid.empty()) {
                return 0;
            }
            vector<int> tb(grid[0].size());
            vector<int> lr(grid.size());
            for (size_t column = 0; column < grid[0].size(); ++column) {
                int maximum = std::numeric_limits<int>::min();
                for (size_t row = 0; row < grid.size(); ++row) {
                    maximum = std::max(maximum, grid[row][column]);
                }
                tb[column] = maximum;
            }
            for (size_t row = 0; row < grid.size(); ++row) {
                const vector<int>& gridRow = grid[row];
                lr[row] = *std::max_element(gridRow.begin(), gridRow.end());
            }
            int result = 0;
            for (size_t row = 0; row < grid.size(); ++row) {
                const std::vector<int>& gridRow = grid[row];
                for (size_t column = 0; column < gridRow.size(); ++column) {
                    result += (std::min(lr[row], tb[column]) - gridRow[column]);
                }
            }
            return result;
        }
};
