/**
 * @file Pow.cpp
 * @brief 求x的n次方(https://leetcode.com/problems/powx-n/) 
 * @author Finalcheat
 * @date 2016-05-16
 */

/**
 * Implement pow(x, n).
 */

/**
 * 求x的n次方，用递归解法，注意n是负数的情况。
 */

class Solution {
    public:
        double myPow(double x, int n) {
            if (n == 0) {
                return 1;
            } else if (n == 1) {
                return x;
            }
            double value = pow(x, abs(n / 2));  
            if (n > 0) {
                if (n % 2 == 0) {
                    return value * value;
                } else {
                    return value * value * x;
                }
            }
            else {  
                if (n % 2 == 0) {
                    return 1.0 / (value * value);
                } else {
                    return 1.0 / (value * value * x);
                }
            }
            return value;
        }
};
