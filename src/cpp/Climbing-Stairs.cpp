/**
 * @file Climbing-Stairs.cpp
 * @brief 爬楼梯(https://leetcode.com/problems/climbing-stairs/)
 * @author Finalcheat
 * @date 2016-03-14
 */

/**
 * You are climbing a stair case. It takes n steps to reach to the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 */

/**
 * 其实就是斐波那契数列问题。
 */

class Solution {
    public:
        int climbStairs(int n) {
            if (n < 4) {
                return n;
            }
            int a = 2, b = 3, c = 5;  
            for (int i = 5; i <= n; ++i)  
            {  
                a = c;  
                c = b+c;  
                b = a;  
            }  
            return c;  
        }
};
