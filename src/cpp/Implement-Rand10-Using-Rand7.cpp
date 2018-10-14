/**
 * @file Implement-Rand10-Using-Rand7.cpp
 * @brief 使用Rand7实现Rand10(https://leetcode.com/problems/implement-rand10-using-rand7/description/)
 * @author Finalcheat
 * @date 2018-09-15
 */

/**
 * Given a function rand7 which generates a uniform random integer in the range 1 to 7, write a function rand10 which generates a uniform random integer in the range 1 to 10.
 * Do NOT use system's Math.random().
 * Example 1:
 * Input: 1
 * Output: [7]
 * Example 2:
 * Input: 2
 * Output: [8,4]
 * Example 3:
 * Input: 3
 * Output: [8,1,10]
 * Note:
 * 1. rand7 is predefined.
 * 2. Each testcase has one argument: n, the number of times that rand10 is called.
 */

/**
 * 使用rand7产生rand49，然后过滤掉40以上的数得到rand40，最后模10即可。
 */


// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
    public:
        int rand10() {
            int num = 0;
            do {
                num = rand49();
            } while (num >= 40);
            return num % 10 + 1;
        }
    private:
        // return 0 ~ 48 randomly
        int rand49()
        {
            return 7 * (rand7() - 1) + rand7() - 1;
        }
};
