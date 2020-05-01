/**
 * @file Reducing-Dishes.cpp
 * @brief Reducing Dishes(https://leetcode.com/problems/reducing-dishes/)
 * @author Finalcheat
 * @date 2020-05-01
 */

/**
 * A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.
 * Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level  i.e.  time[i]*satisfaction[i]
 * Return the maximum sum of Like-time coefficient that the chef can obtain after dishes preparation.
 * Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.
 * Example 1:
 * Input: satisfaction = [-1,-8,0,5,-9]
 * Output: 14
 * Explanation: After Removing the second and last dish, the maximum total Like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14). Each dish is prepared in one unit of time.
 * Example 2:
 * Input: satisfaction = [4,3,2]
 * Output: 20
 * Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)
 * Example 3:
 * Input: satisfaction = [-1,-4,-5]
 * Output: 0
 * Explanation: People don't like the dishes. No dish is prepared.
 * Example 4:
 * Input: satisfaction = [-2,5,-1,0,3,-3]
 * Output: 35
 * Constraints:
 * * n == satisfaction.length
 * * 1 <= n <= 500
 * * -10^3 <= satisfaction[i] <= 10^3
 */

/**
 * 动态规划，dp[i]代表i个时间内最佳满意度，dp[1]是数组内最大的数值，dp[2]呢？必定是数组内最大的两个数值构成，依次类推到dp[i]，最后求dp数组内的最大数即可，这里遍历过程中保存最大值就可以省下dp数组的空间使用了。
 */

class Solution {
    public:
        int maxSatisfaction(vector<int>& satisfaction) {
            assert(!satisfaction.empty());
            std::sort(satisfaction.begin(), satisfaction.end());
            int maximum = 0;
            int curSum = maximum;
            for (int idx = satisfaction.size() - 1; idx >= 0; --idx) {
                vector<int>::const_iterator iter = satisfaction.begin() + idx;
                maximum = std::max(maximum, calSum(iter, satisfaction.end()));
            }
            return maximum;
        }
    private:
        int calSum(vector<int>::const_iterator first, vector<int>::const_iterator last) {
            int time = 1;
            int sum = 0;
            while (first != last) {
                sum += ((*first) * time);
                ++time;
                ++first;
            }
            return sum;
        }
};
