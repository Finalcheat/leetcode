/**
 * @file Best-Time-to-Buy-and-Sell-Stock-with-Transaction-Fee.cpp
 * @brief 买卖股票的最佳时间含交易费(https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/)
 * @author Finalcheat
 * @date 2018-07-15
 */

/**
 * Your are given an array of integers prices, for which the i-th element is the price of a given stock on day i; and a non-negative integer fee representing a transaction fee.
 * You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction. You may not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)
 * Return the maximum profit you can make.
 * Example 1:
 * Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
 * Output: 8
 * Explanation: The maximum profit can be achieved by:
 * * Buying at prices[0] = 1
 * * Selling at prices[3] = 8
 * * Buying at prices[4] = 4
 * * Selling at prices[5] = 9
 * The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
 */

/**
 * 动态规划，profit表示第i天没有股票时的最大收益，stockProfit表示第i天拥有股票时的最大收益。
 */


class Solution {
    public:
        int maxProfit(vector<int>& prices, int fee) {
            assert(prices.size() >= 1);
            int profit = 0;
            int stockProfit = -prices[0];
            for (size_t i = 1; i < prices.size(); ++i) {
                profit = max(profit, stockProfit + prices[i] - fee);
                stockProfit = max(stockProfit, profit - prices[i]);
            }
            return profit;
        }
};
