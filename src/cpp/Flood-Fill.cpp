/**
 * @file Flood-Fill.cpp
 * @brief 图像渲染(https://leetcode.com/problems/flood-fill/description/)
 * @author Finalcheat
 * @date 2018-08-22
 */

/**
 * An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).
 * Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.
 * o perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.
 * At the end, return the modified image.
 * Example 1:
 * Input:
 * image = [[1,1,1],[1,1,0],[1,0,1]]
 * sr = 1, sc = 1, newColor = 2
 * Output: [[2,2,2],[2,2,0],[2,0,1]]
 * Explanation:
 * From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected
 * by a path of the same color as the starting pixel are colored with the new color.
 * Note the bottom corner is not colored 2, because it is not 4-directionally connected
 * to the starting pixel.
 */

/**
 * 递归解决即可。
 */


class Solution {
    public:
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
            assert(image.size() >= 1);
            vector< vector<int> > visits(image.size(), vector<int>(image[0].size(), 0));
            _floodFill(image, visits, sr, sc, newColor);
            return image;
        }
    private:
        void _floodFill(vector< vector<int> >& image, vector< vector<int> >& visits, int row, int column, int newColor) {
            if (visits[row][column]) {
                return;
            }
            int oldColor = image[row][column];
            image[row][column] = newColor;
            visits[row][column] = 1;
            if (row - 1 >= 0 && image[row - 1][column] == oldColor) {
                _floodFill(image, visits, row - 1, column, newColor);
            }
            if (row + 1 < image.size() && image[row + 1][column] == oldColor) {
                _floodFill(image, visits, row + 1, column, newColor);
            }
            if (column - 1 >= 0 && image[row][column - 1] == oldColor) {
                _floodFill(image, visits, row, column - 1, newColor);
            }
            if (column + 1 < image[0].size() && image[row][column + 1] == oldColor) {
                _floodFill(image, visits, row, column + 1, newColor);
            }
        }
};
