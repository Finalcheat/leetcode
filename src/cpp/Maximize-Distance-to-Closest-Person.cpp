/**
 * @file Maximize-Distance-to-Closest-Person.cpp
 * @brief 最接近人的距离最大化(https://leetcode.com/problems/maximize-distance-to-closest-person/description/)
 * @author Finalcheat
 * @date 2018-08-14
 */

/**
 * In a row of seats, 1 represents a person sitting in that seat, and 0 represents that the seat is empty. 
 * There is at least one empty seat, and at least one person sitting.
 * Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized.
 * Return that maximum distance to closest person.
 * Example 1:
 * Input: [1,0,0,0,1,0,1]
 * Output: 2
 * Explanation:
 * If Alex sits in the second open seat (seats[2]), then the closest person has distance 2.
 * If Alex sits in any other open seat, the closest person has distance 1.
 * Thus, the maximum distance to the closest person is 2.
 * Example 2:
 * Input: [1,0,0,0]
 * Output: 3
 * Explanation:
 * If Alex sits in the last seat, the closest person is 3 seats away.
 * This is the maximum distance possible, so the answer is 3.
 */

/**
 * 首先求出中间1的间隔最大，最后与首尾相比较较大的就是最大化。
 */


class Solution {
    public:
        int maxDistToClosest(vector<int>& seats) {
            vector<int> v;
            for (size_t i = 0; i < seats.size(); ++i) {
                if (seats[i] == 1) {
                    v.push_back(i);
                }
            }
            assert(v.size() >= 1);
            int maximum = v[0];
            for (int i = 1; i < v.size(); ++i) {
                maximum = std::max(maximum, (v[i] - v[i - 1]) / 2);
            }
            int last = seats.size() - v[v.size() - 1] - 1;
            maximum = std::max(maximum, last);
            return maximum;
        }
};
