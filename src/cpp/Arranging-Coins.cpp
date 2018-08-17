/**
 * @file Arranging-Coins.cpp
 * @brief 硬币排列(https://leetcode.com/problems/arranging-coins/description/)
 * @author Finalcheat
 * @date 2018-08-15
 */

/**
 * You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.
 * Given n, find the total number of full staircase rows that can be formed.
 * n is a non-negative integer and fits within the range of a 32-bit signed integer.
 * Example 1:
 * n = 5
 * The coins can form the following rows:
 * ¤
 * ¤ ¤
 * ¤ ¤
 * Because the 3rd row is incomplete, we return 2.
 * Example 2:
 * n = 8
 * The coins can form the following rows:
 * ¤
 * ¤ ¤
 * ¤ ¤ ¤
 * ¤ ¤
 * Because the 4th row is incomplete, we return 3.
 */

/**
 * 二分搜索找到第一个大于n数量的位置pos，最后直接返回pos-1即可。
 */


class Solution {
    public:
        int arrangeCoins(int n) {
            if (n <= 1) {
                return n;
            }
            int64_t first = 1;
            int64_t last = n;
            while (first < last) {
                int64_t middle = first + (last - first) / 2;
                int64_t sum = (1 + middle) * middle / 2;
                if (sum > n) {
                    last = middle;
                } else {
                    first = middle + 1;
                }
            }
            return first - 1;
        }
};
