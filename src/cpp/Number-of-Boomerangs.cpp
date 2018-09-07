/**
 * @file Number-of-Boomerangs.cpp
 * @brief 回旋镖的数量(https://leetcode.com/problems/number-of-boomerangs/description/)
 * @author Finalcheat
 * @date 2018-09-01
 */

/**
 * Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).
 * Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).
 * Example:
 * Input:
 * [[0,0],[1,0],[2,0]]
 * Output:
 * 2
 * Explanation:
 * The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
 */

/**
 * 二重遍历计算每两个节点之间的距离，遍历过程中用hash记录距离的出现出现次数，出现两次以上的说明构成结果。
 */


class Solution {
    public:
        int numberOfBoomerangs(vector<pair<int, int>>& points) {
            int result = 0;
            for (const pair<int, int>& pi : points) {
                std::unordered_map<int, int> u;
                for (const pair<int, int>& pj : points) {
                    const int distanceX = pi.first - pj.first;
                    const int distanceY = pi.second - pj.second;
                    const int distance = distanceX * distanceX + distanceY * distanceY;
                    ++u[distance];
                }
                for (const pair<int, int>& p : u) {
                    if (p.second > 1) {
                        result += p.second * (p.second - 1);
                    }
                }
            }
            return result;
        }
};
