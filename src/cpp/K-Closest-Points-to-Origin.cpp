/**
 * @file K-Closest-Points-to-Origin.cpp
 * @brief K个最接近原点的点(https://leetcode.com/problems/k-closest-points-to-origin/)
 * @author Finalcheat
 * @date 2019-01-22
 */

/**
 * We have a list of points on the plane.  Find the K closest points to the origin (0, 0).
 * (Here, the distance between two points on a plane is the Euclidean distance.)
 * You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)
 * Example 1:
 * Input: points = [[1,3],[-2,2]], K = 1
 * Output: [[-2,2]]
 * Explanation:
 * The distance between (1, 3) and the origin is sqrt(10).
 * The distance between (-2, 2) and the origin is sqrt(8).
 * Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
 * We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].
 * Example 2:
 * Input: points = [[3,3],[5,-1],[-2,4]], K = 2
 * Output: [[3,3],[-2,4]]
 * (The answer [[-2,4],[3,3]] would also be accepted.)
 */

/**
 * 记录距离原点的距离，排序选取前K个元素即可。
 */


class Solution {
    public:
        vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
            assert(points.size() >= K);
            vector<PointValueIndex> v;
            for (size_t i = 0; i < points.size(); ++i) {
                const vector<int>& point = points[i];
                const int sqrtValue = point[0] * point[0] + point[1] * point[1];
                v.push_back(PointValueIndex(sqrtValue, i));
            }

            std::sort(v.begin(), v.end(), [](const PointValueIndex& l, const PointValueIndex& r) {
                return l.sqrtValue < r.sqrtValue;
            });

            vector<vector<int>> result;
            vector<PointValueIndex>::const_iterator last = v.begin() + K;
            for (vector<PointValueIndex>::const_iterator iter = v.begin(); iter != last; ++iter) {
                result.push_back(points[iter->idx]);
            }
            return result;
        }
    private:
        typedef struct PointValueIndex {
            PointValueIndex(const int _s, const size_t _i) : sqrtValue(_s), idx(_i) {}
            int sqrtValue;
            size_t idx;
        } PointValueIndex;
};
