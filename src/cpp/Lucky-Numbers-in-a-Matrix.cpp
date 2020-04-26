/**
 * @file Lucky-Numbers-in-a-Matrix.cpp
 * @brief 矩阵中的幸运数字(https://leetcode.com/problems/lucky-numbers-in-a-matrix/)
 * @author Finalcheat
 * @date 2020-04-26
 */

/**
 * Given a m * n matrix of distinct numbers, return all lucky numbers in the matrix in any order.
 * A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.
 * Example 1:
 * Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
 * Output: [15]
 * Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column
 * Example 2:
 * Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
 * Output: [12]
 * Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
 * Example 3:
 * Input: matrix = [[7,8],[1,2]]
 * Output: [7]
 */

/**
 * 找出每行最小元素每列最大元素，最后遍历对比即可。
 */

class Solution {
    public:
        vector<int> luckyNumbers (vector<vector<int>>& matrix) {
            assert(!matrix.empty());
            assert(!matrix[0].empty());
            const size_t rows = matrix.size();
            const size_t columns = matrix[0].size();

            vector<int> minimumRows(rows);
            for (size_t row = 0; row < rows; ++row) {
                minimumRows[row] = matrix[row][0];
                for (size_t column = 1; column < columns; ++column) {
                    minimumRows[row] = std::min(minimumRows[row], matrix[row][column]);
                }
            }

            vector<int> maximumColumns(columns);
            for (size_t column = 0; column < columns; ++column) {
                maximumColumns[column] = matrix[0][column];
                for (size_t row = 1; row < rows; ++row) {
                    maximumColumns[column] = std::max(maximumColumns[column], matrix[row][column]);
                }
            }

            vector<int> result;
            for (size_t row = 0; row < rows; ++row) {
                for (size_t column = 0; column < columns; ++column) {
                    const int value = matrix[row][column];
                    if (value == minimumRows[row] && value == maximumColumns[column]) {
                        result.push_back(value);
                    }
                }
            }

            return result;
        }
};
