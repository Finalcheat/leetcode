/**
 * @file Predict-the-Winner.cpp
 * @brief 预测赢家(https://leetcode.com/problems/predict-the-winner/description/)
 * @author Finalcheat
 * @date 2018-10-13
 */

/**
 * Given an array of scores that are non-negative integers. Player 1 picks one of the numbers from either end of the array followed by the player 2 and then player 1 and so on. Each time a player picks a number, that number will not be available for the next player. This continues until all the scores have been chosen. The player with the maximum score wins.
 * Given an array of scores, predict whether player 1 is the winner. You can assume each player plays to maximize his score.
 * Example 1:
 * Input: [1, 5, 2]
 * Output: False
 * Explanation: Initially, player 1 can choose between 1 and 2.
 * If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2).
 * So, final score of player 1 is 1 + 2 = 3, and player 2 is 5.
 * Hence, player 1 will never be the winner and you need to return False.
 * Example 2:
 * Input: [1, 5, 233, 7]
 * Output: True
 * Explanation: Player 1 first chooses 1. Then player 2 have to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
 * Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.
 */

/**
 * 动态规划。
 */


class Solution {
    public:
        bool PredictTheWinner(vector<int>& nums) {
            vector< vector<int> > dp(nums.size(), vector<int>(nums.size(), -1024));
            const int result = _PredictTheWinner(nums, 0, nums.size() - 1, dp);
            return result >= 0;
        }
    private:
        int _PredictTheWinner(const vector<int>& nums, int first, int last, vector< vector<int> >& dp) {
            if (dp[first][last] < 0) {
                if (first == last) {
                    dp[first][first] = nums[first];
                } else {
                    dp[first][last] = std::max(nums[first] - _PredictTheWinner(nums, first + 1, last, dp),
                                            nums[last] - _PredictTheWinner(nums, first, last - 1, dp));
                }
            }
            return dp[first][last];
        }
};
