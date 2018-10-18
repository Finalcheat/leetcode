/**
 * @file Escape-The-Ghosts.cpp
 * @brief 逃脱阻碍者(https://leetcode.com/problems/escape-the-ghosts/description/)
 * @author Finalcheat
 * @date 2018-09-23
 */

/**
 * You are playing a simplified Pacman game. You start at the point (0, 0), and your destination is (target[0], target[1]). There are several ghosts on the map, the i-th ghost starts at (ghosts[i][0], ghosts[i][1]).
 * Each turn, you and all ghosts simultaneously *may* move in one of 4 cardinal directions: north, east, west, or south, going from the previous point to a new point 1 unit of distance away.
 * You escape if and only if you can reach the target before any ghost reaches you (for any given moves the ghosts may take.)  If you reach any square (including the target) at the same time as a ghost, it doesn't count as an escape.
 * Return True if and only if it is possible to escape.
 * Example 1:
 * Input:
 * ghosts = [[1, 0], [0, 3]]
 * target = [0, 1]
 * Output: true
 * Explanation:
 * You can directly reach the destination (0, 1) at time 1, while the ghosts located at (1, 0) or (0, 3) have no way to catch up with you.
 * Example 2:
 * Input:
 * ghosts = [[1, 0]]
 * target = [2, 0]
 * Output: false
 * Explanation:
 * You need to reach the destination (2, 0), but the ghost at (1, 0) lies between you and the destination.
 * Example 3:
 * Input:
 * ghosts = [[2, 0]]
 * target = [1, 0]
 * Output: false
 * Explanation:
 * The ghost can reach the target at the same time as you.
 */

/**
 * 算出到达target所需要的步数，如果ghosts里面有比它小的直接返回false，否则最后返回true。
 */


class Solution {
    public:
        bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
            const int distance = std::abs(target[0]) + std::abs(target[1]);
            for (const vector<int>& g : ghosts) {
                const int d = std::abs(g[0] - target[0]) + std::abs(g[1] - target[1]);
                if (d <= distance) {
                    return false;
                }
            }
            return true;
        }
};
