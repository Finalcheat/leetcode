/**
 * @file Magic-Squares-In-Grid.cpp
 * @brief 矩阵中的幻方(https://leetcode.com/problems/magic-squares-in-grid/description/)
 * @author Finalcheat
 * @date 2018-08-28
 */

/**
 * A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.
 * Given an grid of integers, how many 3 x 3 "magic square" subgrids are there?  (Each subgrid is contiguous).
 * Example 1:
 * Input: [[4,3,8,4],
 *         [9,5,1,9],
 *         [2,7,6,2]]
 * Output: 1
 * Explanation:
 * The following subgrid is a 3 x 3 magic square:
 * 438
 * 951
 * 276
 * while this one is not:
 * 384
 * 519
 * 762
 * In total, there is only one magic square inside the given grid.
 */

/**
 * 本来以为只要行列对角线相等即可，后面提交答案出错才发现要求数字必须是1到9。。。。所以遍历的时候也判断数字范围就行了。
 */


class Solution {
    public:
        int numMagicSquaresInside(vector<vector<int>>& grid) {
            int count = 0;
            if (grid.size() < 3) {
                return count;
            }
            if (grid[0].size() < 3) {
                return count;
            }
            for (size_t row = 0; row <= grid.size() - 3; ++row) {
                for (size_t column = 0; column <= grid[row].size() - 3; ++column) {
                    if (_numMagicSquaresInside(grid, row, column)) {
                        ++count;
                    }
                }
            }
            return count;
        }
    private:
        bool _numMagicSquaresInside(vector< vector<int> >& grid, size_t row, size_t column) {
            int sum = 0;
            int value = 0;
            for (size_t i = 0; i < 3; ++i) {
                value = grid[row][column + i];
                if (value > 9 || value < 1) {
                    return false;
                }
                sum += value;
            }
            for (size_t i = 1; i < 3; ++i) {
                int _sum = 0;
                for (size_t j = 0; j < 3; ++j) {
                    value = grid[row + i][column + j];
                    if (value > 9 || value < 1) {
                        return false;
                    }
                    _sum += value;
                }
                if (sum != _sum) {
                    return false;
                }
            }
            for (size_t i = 0; i < 3; ++i) {
                int _sum = 0;
                for (size_t j = 0; j < 3; ++j) {
                    value = grid[row + j][column + i];
                    if (value > 9 || value < 1) {
                        return false;
                    }
                    _sum += value;
                }
                if (sum != _sum) {
                    return false;
                }
            }
            int _sum = 0;
            for (size_t i = 0; i < 3; ++i) {
                _sum += grid[row + i][column + i];
            }
            if (_sum != sum) {
                return false;
            }
            _sum = 0;
            for (int i = 2; i >= 0; --i) {
                value = grid[row + (2 - i)][column + i];
                if (value > 9 || value < 1) {
                    return false;
                }
                _sum += value;
            }
            if (_sum != sum) {
                return false;
            }
            return true;
        }
};
