/**
 * @file X-of-a-Kind-in-a-Deck-of-Cards.cpp
 * @brief 卡牌分组(https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards)
 * @author Finalcheat
 * @date 2018-12-05
 */

/**
 * In a deck of cards, each card has an integer written on it.
 * Return true if and only if you can choose X >= 2 such that it is possible to split the entire deck into 1 or more groups of cards, where:
 * * Each group has exactly X cards.
 * * All the cards in each group have the same integer.
 * Example 1:
 * Input: [1,2,3,4,4,3,2,1]
 * Output: true
 * Explanation: Possible partition [1,1],[2,2],[3,3],[4,4]
 * Example 2:
 * Input: [1,1,1,2,2,2,3,3]
 * Output: false
 * Explanation: No possible partition.
 * Example 3:
 * Input: [1]
 * Output: false
 * Explanation: No possible partition.
 * Example 4:
 * Input: [1,1]
 * Output: true
 * Explanation: Possible partition [1,1]
 * Example 5:
 * Input: [1,1,2,2,2,2]
 * Output: true
 * Explanation: Possible partition [1,1],[2,2],[2,2]
 */

/**
 * 其实就是求数字的出现次数的最大公约数是否大于等于2。
 */


class Solution {
    public:
        bool hasGroupsSizeX(vector<int>& deck) {
            std::unordered_map<int, int> u;
            for (const int num : deck) {
                ++u[num];
            }
            int result = 1;
            std::unordered_map<int, int>::const_iterator iter = u.begin();
            if (iter != u.end()) {
                result = iter->second;
            }
            ++iter;
            for (; iter != u.end(); ++iter) {
                result = gcd(result, iter->second);
            }
            return result != 1;
        }
    private:
        int gcd(int m, int n) {
            if (m < n) {
                std::swap(m, n);
            }
            if (n == 0) {
                return m;
            }
            return gcd(n, m % n);
        }
};
