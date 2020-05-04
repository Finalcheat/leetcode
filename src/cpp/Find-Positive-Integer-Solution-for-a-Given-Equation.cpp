/**
 * @file Find-Positive-Integer-Solution-for-a-Given-Equation.cpp
 * @brief 求一个给定方程的正整数解(https://leetcode.com/problems/find-positive-integer-solution-for-a-given-equation/)
 * @author Finalcheat
 * @date 2020-05-04
 */

/**
 * Given a function  f(x, y) and a value z, return all positive integer pairs x and y where f(x,y) == z.
 * The function is constantly increasing, i.e.:
 * * f(x, y) < f(x + 1, y)
 * * f(x, y) < f(x, y + 1)
 * The function interface is defined like this:
 * interface CustomFunction {
 * public:
 *   // Returns positive integer f(x, y) for any given positive integer x and y.
 *   int f(int x, int y);
 * };
 * For custom testing purposes you're given an integer function_id and a target z as input, where function_id represent one function from an secret internal list, on the examples you'll know only two functions from the list.
 * You may return the solutions in any order.
 * Example 1:
 * Input: function_id = 1, z = 5
 * Output: [[1,4],[2,3],[3,2],[4,1]]
 * Explanation: function_id = 1 means that f(x, y) = x + y
 * Example 2:
 * Input: function_id = 2, z = 5
 * Output: [[1,5],[5,1]]
 * Explanation: function_id = 2 means that f(x, y) = x * y
 * Constraints:
 * * 1 <= function_id <= 9
 * * 1 <= z <= 100
 * * It's guaranteed that the solutions of f(x, y) == z will be on the range 1 <= x, y <= 1000
 * * It's also guaranteed that f(x, y) will fit in 32 bit signed integer if 1 <= x, y <= 1000
 */

/**
 * 根据题目的要求遍历1000以内的x、y即可，因为f函数是增长的，碰到大于z值的直接跳到下一个循环即可，这里还可以用二分搜索加快速度，不过这里值最大只有1000，简单遍历就够了。
 */

/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
    public:
        vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
            const int max = 1000;
            vector<vector<int>> result;
            for (int x = 1; x <= max; ++x) {
                for (int y = 1; y <= max; ++y) {
                    const int value = customfunction.f(x, y);
                    if (value == z) {
                        vector<int> item(2);
                        item[0] = x;
                        item[1] = y;
                        result.push_back(item);
                    } else if (value > z) {
                        break;
                    }
                }
            }
            return result;
        }
};
