/**
 * @file Divisor-Game.cpp
 * @brief 除数游戏(https://leetcode.com/problems/divisor-game/)
 * @author Finalcheat
 * @date 2020-04-28
 */

/**
 * Alice and Bob take turns playing a game, with Alice starting first.
 * Initially, there is a number N on the chalkboard.  On each player's turn, that player makes a move consisting of:
 * * Choosing any x with 0 < x < N and N % x == 0.
 * * Replacing the number N on the chalkboard with N - x.
 * Also, if a player cannot make a move, they lose the game.
 * Return True if and only if Alice wins the game, assuming both players play optimally.
 * Example 1:
 * Input: 2
 * Output: true
 * Explanation: Alice chooses 1, and Bob has no more moves.
 * Example 2:
 * Input: 3
 * Output: false
 * Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.
 */

/**
 * 判断奇偶，偶数必获胜。
 */

class Solution {
    public:
        bool divisorGame(int N) {
            return N % 2 == 0;
        }
};
