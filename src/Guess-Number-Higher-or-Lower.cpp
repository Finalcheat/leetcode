/**
 * @file Guess-Number-Higher-or-Lower.cpp
 * @brief 猜数字游戏(https://leetcode.com/problems/guess-number-higher-or-lower/)
 * @author Finalcheat
 * @date 2016-07-19
 */

/**
 * We are playing the Guess Game. The game is as follows:
 * I pick a number from 1 to n. You have to guess which number I picked.
 * Every time you guess wrong, I'll tell you whether the number is higher or lower.
 * You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):
 * -1 : My number is lower
 *  1 : My number is higher
 *  0 : Congrats! You got it!
 * Example:
 * n = 10, I pick 6.
 * Return 6.
 */

/**
 * 二分搜索查找即可。
 */

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
    public:
        int guessNumber(int n) {
            int begin = 1;
            int end = n;
            while (begin <= end) {
                const int num = begin + (end - begin) / 2;
                const int b = guess(num);
                if (b == 1) {
                    // My number is lower
                    begin = num + 1;
                } else if (b == -1) {
                    // My number is higher
                    end = num - 1;
                } else {
                    return num;
                }
            }
            return -1;
        }
};
