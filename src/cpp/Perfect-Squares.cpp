/**
 * @file Perfect-Squares.cpp
 * @brief 完全平方(https://leetcode.com/problems/perfect-squares/)
 * @author Finalcheat
 * @date 2020-05-03
 */

/**
 * Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
 * Example 1:
 * Input: n = 12
 * Output: 3
 * Explanation: 12 = 4 + 4 + 4.
 * Example 2:
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 */

/**
 * https://zh.wikipedia.org/wiki/%E5%9B%9B%E5%B9%B3%E6%96%B9%E5%92%8C%E5%AE%9A%E7%90%86
 * 根据四平方和定理得知答案只可能是1、2、3、4，1、2的情况很好判断，3遍历即可，最后无答案就是4。
 */

class Solution {
    public:
        int numSquares(int n) {
            const int x = (int)sqrt(n);
            if (x * x == n) {
                return 1;
            }
            int result = 4;
            for (int i = 1; i <= x; ++i) {
                for (int j = 1; j <= (int)sqrt(n - i * i); ++j) {
                    const int value = n - (i * i + j * j);
                    if (value == 0) {
                        return 2;
                    }
                    const int k = (int)sqrt(value);
                    if (k * k == value) {
                        result = 3;
                    }
                }
            }
            return result;
        }
};
