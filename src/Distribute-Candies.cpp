/**
 * @file Distribute-Candies.cpp
 * @brief 分糖果(https://leetcode.com/problems/distribute-candies/description/)
 * @author Finalcheat
 * @date 2018-04-01
 */

/**
 * Given an integer array with even length, where different numbers in this array represent different kinds of candies. Each number means one candy of the corresponding kind. You need to distribute these candies equally in number to brother and sister. Return the maximum number of kinds of candies the sister could gain.
 * Example 1:
 * Input: candies = [1,1,2,2,3,3]
 * Output: 3
 * Explanation:
 * There are three different kinds of candies (1, 2 and 3), and two candies for each kind.
 * Optimal distribution: The sister has candies [1,2,3] and the brother has candies [1,2,3], too.
 * The sister has three different kinds of candies.
 * Example 2:
 * Input: candies = [1,1,2,3]
 * Output: 2
 * Explanation: For example, the sister has candies [2,3] and the brother has candies [1,1].
 * The sister has two different kinds of candies, the brother has only one kind of candies.
 */

/**
 * 假设糖果的种类为n，每一种种类只有1个，则最大的可能就是糖果数量的一半；否则就是糖果的种类数n。
 */


class Solution {
    public:
        int distributeCandies(vector<int>& candies) {
            std::set<int> s;
            for (const int c : candies) {
                s.insert(c);
            }
            return std::min(candies.size() / 2, s.size());
        }
};
