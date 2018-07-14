/**
 * @file Min-Cost-Climbing-Stairs.cpp
 * @brief 最小成本爬楼梯(https://leetcode.com/problems/min-cost-climbing-stairs/description/)
 * @author Finalcheat
 * @date 2018-07-14
 */

/**
 * On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).
 * Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.
 * Example 1:
 * Input: cost = [10, 15, 20]
 * Output: 15
 * Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
 * Example 2:
 * Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
 * Output: 6
 * Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
 */

/**
 * 动态规划，dp[i]记录到第i步为止最低成本，最后比较dp后两位即可。
 */


class Solution {
    public:
        int minCostClimbingStairs(vector<int>& cost) {
            assert(cost.size() >= 2);
            vector<int> dp(cost.size());
            dp[0] = cost[0];
            dp[1] = cost[1];
            const size_t len = cost.size();
            for (size_t i = 2; i < len; ++i) {
                dp[i] = min(dp[i - 2] + cost[i], dp[i - 1] + cost[i]);
            }
            return min(dp[len - 1], dp[len - 2]);
        }
};
