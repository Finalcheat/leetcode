/**
 * @file Diagonal-Traverse.cpp
 * @brief 对角线穿越(https://leetcode.com/problems/diagonal-traverse/)
 * @author Finalcheat
 * @date 2017-03-04
 */

/**
 * Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.
 * Example:
 * Input:
 * [
 *  [ 1, 2, 3 ],
 *  [ 4, 5, 6 ],
 *  [ 7, 8, 9 ]
 * ]
 * Output:  [1,2,4,7,5,3,6,8,9]
 */

/**
 * 从坐标值(0,0)开始遍历，如果方向向上则(x+1,y-1)，否则(x-1,y+1)，遍历过程中遇到坐标值超出矩阵则修改相应的坐标以及调整方向，直到矩阵所有数字遍历完。
 */

class Solution {
    public:
        vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
            if (matrix.empty()) {
                return vector<int>();
            }
            int indexX = 0;
            int indexY = 0;
            bool direction = true;
            int rows = matrix.size();
            int columns = matrix[0].size();
            int length = rows * columns;
            vector<int> result;
            while (length) {
                if (indexY < 0) {
                    indexY = 0;
                    direction = !direction;
                } else if (indexY >= rows) {
                    indexX = indexX + 1;
                    direction = !direction;
                } else if (indexX < 0) {
                    indexX = 0;
                    direction = !direction;
                } else if (indexX >= columns) {
                    indexY = indexY + 1;
                    direction = !direction;
                }
                if (indexY < rows && indexX < columns) {
                    result.push_back(matrix[indexY][indexX]);
                    --length;
                }
                if (direction) {
                    indexX += 1;
                    indexY -= 1;
                } else {
                    indexX -= 1;
                    indexY += 1;
                }
            }
            return result;
        }
};
