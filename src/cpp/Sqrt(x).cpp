/**
 * @file Sqrt(x).cpp
 * @brief 求x的平方根(https://leetcode.com/problems/sqrtx/) 
 * @author Finalcheat
 * @date 2016-05-15
 */

/**
 * Implement int sqrt(int x).
 * Compute and return the square root of x.
 */

/**
 * [牛顿迭代法](https://en.wikipedia.org/wiki/Newton%27s_method)
 */

class Solution {
    public:
        int mySqrt(int x) {
            if (x == 0) {
                return 0;
            }
            double prev = 0;
            double result = 1;
            while (result != prev)
            {
                prev = result;
                result = (result + x / result) / 2;
            }
            return int(result);
        }
};
