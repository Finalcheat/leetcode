/**
 * @file Rabbits-in-Forest.cpp
 * @brief 森林中的兔子(https://leetcode.com/problems/rabbits-in-forest/description/)
 * @author Finalcheat
 * @date 2018-09-24
 */

/**
 * In a forest, each rabbit has some color. Some subset of rabbits (possibly all of them) tell you how many other rabbits have the same color as them. Those answers are placed in an array.
 * Return the minimum number of rabbits that could be in the forest.
 * Examples:
 * Input: answers = [1, 1, 2]
 * Output: 5
 * Explanation:
 * The two rabbits that answered "1" could both be the same color, say red.
 * The rabbit than answered "2" can't be red or the answers would be inconsistent.
 * Say the rabbit that answered "2" was blue.
 * Then there should be 2 other blue rabbits in the forest that didn't answer into the array.
 * The smallest possible number of rabbits in the forest is therefore 5: 3 that answered plus 2 that didn't.
 * Input: answers = [10, 10, 10]
 * Output: 11
 * Input: answers = []
 * Output: 0
 */

/**
 * 用hashtable存储相对答案个数，最后遍历将相同答案分组计算。
 */


class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            std::unordered_map<int, int> u;
            int count = 0;
            for (const int num : answers) {
                if (num == 0) {
                    ++count;
                } else {
                    ++u[num];
                }
            }
            for (const pair<int, int>& p : u) {
                const int c = p.first + 1;
                count += (p.second / c) * c;
                if (p.second % c != 0) {
                    count += c;
                }
            }
            return count;
        }
};
