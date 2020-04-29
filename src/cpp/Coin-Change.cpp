/**
 * @file Coin-Change.cpp
 * @brief 硬币兑换(https://leetcode.com/problems/coin-change/)
 * @author Finalcheat
 * @date 2020-04-29
 */

/**
 * You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
 * Example 1:
 * Input: coins = [1, 2, 5], amount = 11
 * Output: 3
 * Explanation: 11 = 5 + 5 + 1
 * Example 2:
 * Input: coins = [2], amount = 3
 * Output: -1
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 */

/**
 * 动态规划，用map作为dp的辅助结构，dp[i]代表i兑换的最小数量。这里有个奇怪的testcase是coins=[1]，amount=0的时候返回竟然是0，按照题意难道不是应该返回-1才对？这里代码只能针对0做特殊处理。
 */

class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {
            if (coins.empty()) {
                return -1;
            }
            if (amount <= 0) {
                return 0;
            }
            initDpMap(coins);
            return coinDp(coins, amount);
        }
    private:
        void initDpMap(const vector<int>& coins) {
            for (const int coin : coins) {
                dpMap[coin] = 1;
            }
        }
        int coinDp(const vector<int>& coins, int amount) {
            if (amount == 0) {
                return 0;
            } else if (amount < 0) {
                return -1;
            }
            std::map<int, int>::const_iterator iter = dpMap.find(amount);
            if (iter != dpMap.end()) {
                return iter->second;
            }
            int minimum = -1;
            for (const int coin : coins) {
                if (amount < coin) {
                    continue;
                }
                const int cur = coinDp(coins, amount - coin);
                if (cur != -1) {
                    if (minimum != -1) {
                        minimum = std::min(minimum, cur + 1);
                    } else {
                        minimum = cur + (1);
                    }
                }
            }
            dpMap[amount] = minimum;
            return minimum;
        }
    private:
        std::map<int, int> dpMap;
};
