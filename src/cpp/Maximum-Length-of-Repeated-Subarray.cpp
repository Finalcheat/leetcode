/**
 * @file Maximum-Length-of-Repeated-Subarray.cpp
 * @brief 重复子数组的最大长度(https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/)
 * @author Finalcheat
 * @date 2018-06-30
 */

/**
 * Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.
 * Example 1:
 * Input:
 * A: [1,2,3,2,1]
 * B: [3,2,1,4,7]
 * Output: 3
 * Explanation:
 * The repeated subarray with maximum length is [3, 2, 1].
 */

/**
 * 动态规划，用dp数组辅助，dp[i][j]代表数组A前i项和数组B前j项子数组的最大长度。
 */


class Solution {
    public:
        int findLength(vector<int>& A, vector<int>& B) {
            std::vector< std::vector<int> > dp(A.size() + 1, std::vector<int>(B.size() + 1, 0));
            int maximum = 0;
            for (size_t i = 1; i < dp.size(); ++i) {
                for (size_t j = 1; j < dp[i].size(); ++j) {
                    if (A[i - 1] == B[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    } else {
                        dp[i][j] = 0;
                    }
                    maximum = std::max(maximum, dp[i][j]);
                }
            }

            return maximum;
        }
};
