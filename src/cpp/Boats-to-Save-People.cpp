/**
 * @file Boats-to-Save-People.cpp
 * @brief 船救人需要的最小数量(https://leetcode.com/problems/boats-to-save-people/description/)
 * @author Finalcheat
 * @date 2018-10-01
 */

/**
 * The i-th person has weight people[i], and each boat can carry a maximum weight of limit.
 * Each boat carries at most 2 people at the same time, provided the sum of the weight of those people is at most limit.
 * Return the minimum number of boats to carry every given person.  (It is guaranteed each person can be carried by a boat.)
 * Example 1:
 * Input: people = [1,2], limit = 3
 * Output: 1
 * Explanation: 1 boat (1, 2)
 * Example 2:
 * Input: people = [3,2,2,1], limit = 3
 * Output: 3
 * Explanation: 3 boats (1, 2), (2) and (3)
 * Example 3:
 * Input: people = [3,5,3,4], limit = 5
 * Output: 4
 * Explanation: 4 boats (3), (3), (4), (5)
 */

/**
 * 排序然后用双指针从首尾遍历，同时注意一艘船最多只能搭载两个人。
 */


class Solution {
    public:
        int numRescueBoats(vector<int>& people, int limit) {
            std::sort(people.begin(), people.end());
            int first = 0;
            int last = people.size() - 1;
            int count = 0;
            while (first <= last) {
                int l = limit;
                int c = 0;
                while (c < 2 && first <= last && people[last] <= l) {
                    l -= people[last];
                    --last;
                    ++c;
                }
                while (c < 2 && first <= last && people[first] <= l) {
                    l -= people[first];
                    ++first;
                    ++c;
                }
                ++count;
            }
            return count;
        }
};
