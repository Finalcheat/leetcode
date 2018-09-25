/**
 * @file Hand-of-Straights.cpp
 * @brief 一手顺子(https://leetcode.com/problems/hand-of-straights/description/)
 * @author Finalcheat
 * @date 2018-09-14
 */

/**
 * Alice has a hand of cards, given as an array of integers.
 * Now she wants to rearrange the cards into groups so that each group is size W, and consists of W consecutive cards.
 * Return true if and only if she can.
 * Example 1:
 * Input: hand = [1,2,3,6,2,3,4,7,8], W = 3
 * Output: true
 * Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8].
 * Example 2:
 * Input: hand = [1,2,3,4,5], W = 4
 * Output: false
 * Explanation: Alice's hand can't be rearranged into groups of 4.
 */

/**
 * 构造map，每次遍历W个连续数字，map找不到则直接返回false。
 */


class Solution {
    public:
        bool isNStraightHand(vector<int>& hand, int W) {
            int n = hand.size() / W;
            if (hand.size() % W != 0) {
                return false;
            }
            std::map<int, int> u;
            for (const int num : hand) {
                ++u[num];
            }
            while (n-- > 0) {
                int idx = 0;
                auto iter = u.begin();
                while (++idx < W) {
                    const int nextNum = iter->first + idx;
                    auto nextIter = u.find(nextNum);
                    if (nextIter == u.end()) {
                        return false;
                    }
                    if (--(nextIter->second) == 0) {
                        u.erase(nextIter);
                    }
                }
                if (--(iter->second) == 0) {
                    u.erase(iter);
                }
            }
            return true;
        }
};
