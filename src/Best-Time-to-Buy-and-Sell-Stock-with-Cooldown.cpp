/**
 * @file Best-Time-to-Buy-and-Sell-Stock-with-Cooldown.cpp
 * @brief 最佳时间买入卖出股票(https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)
 * @author Finalcheat
 * @date 2016-04-17
 */

/**
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
 * * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 * * After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
 * Example:
 * prices = [1, 2, 3, 0, 2]
 * maxProfit = 3
 * transactions = [buy, sell, cooldown, buy, sell]
 */

/**
 * 动态规划。循环中计算第i天买卖的最大收益。
 */

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            if (prices.size() <= 1) {
                return 0;
            }
            int buy = -prices[0];
            int pre_buy = 0;
            int sell = 0;
            int pre_sell = 0;
            for (size_t i = 0; i < prices.size(); ++i) {
                pre_buy = buy;
                buy = std::max(pre_sell - prices[i], pre_buy);
                pre_sell = sell;
                sell = std::max(pre_buy + prices[i], pre_sell);
            }
            return sell;
        }
};
